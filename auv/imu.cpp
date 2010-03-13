/***************************************************************************
                          imu.cpp  -  description
                             -------------------
    begin                : |04/02/2004|
    copyright            : (C) |2004| by |ASCL| and |AUVT|
    email                : |ASCL@listserv.vt.edu|
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "imu.h"
#include <iostream>
#include <fcntl.h>
#include <string>
#include <iomanip>
using std::cout;
using std::cerr;
using std::endl;

#define _IMU_ERROR_SUCCESS_        0
#define _IMU_ERROR_NO_PACKET_    -1
#define    _IMU_ERROR_PART_PACKET    -2
#define    _IMU_ERROR_BAD_PACKET_    -3

IMU::IMU(const char* dev)
{
	port = new UART(dev, 38400, 48);
    initStatus();
	if(pthread_mutex_init(&statMutex, 0)) cout << "Can't create mutex";
	port->addUARTList(this);
	
    bufferInit(&rdbuf, rdbufChars, 128);
	char cmd[3] = {0x10, 0x00, 0x31};
	port->write(cmd, 3);
}
void IMU::initStatus()
{
    status.command = status.tmticks = status.chksum = status.update = 0;
    status.roll = status.yaw = status.pitch
    = status.rollrate = status.pitchrate = status.yawrate
    = status.rollacc = status.pitchacc = status.yawacc = -1;
    status.magDecl = -7.85;
}
IMU::~IMU()
{
    delete port;
}
UART* IMU::getPort()
{
	return port;
}
imu_data IMU::getData()
{
    pthread_mutex_lock(&statMutex);
    imu_data result = status;
    status.update = 0;
    pthread_mutex_unlock(&statMutex);
    return result;
}
void IMU::setMagDecl(double decl)
{
    pthread_mutex_lock(&statMutex);
    status.magDecl = decl;
    pthread_mutex_unlock(&statMutex);
}

const double pi = 3.1416;
const double scaleAngle = (180.0/32768.0);    // = 180/(2^15);
const double scaleRate = (8.5/32768.0)*(180.0/pi);
const double scaleAcc = (7.0/32768.0)*9.81;

void IMU::process(const char* data, int len)
{
	//cout << "process()";
	bufferAddToEnd(&rdbuf, (unsigned char*)data, len);
	if (rdbuf.datalength >= 23)
	{
		int i;
		for (i = ((int)rdbuf.datalength)-23; 
			i >= 0 && bufferGetAtIndex(&rdbuf, i) != 49; i--);
		if (i >= 0) //if beginning of message found
		{
			bufferDumpFromFront(&rdbuf, i);
			
			if (ExtractIMUVars((char*)(rdbuf.dataptr + rdbuf.dataindex), tmpStatus) == _IMU_ERROR_SUCCESS_)
			{
				pthread_mutex_lock(&statMutex);
			    // copy vars to imu_status 
			    // angles
			    status.roll = scaleAngle*tmpStatus.roll;
			    status.pitch = scaleAngle*tmpStatus.pitch;
			    status.yaw = scaleAngle*tmpStatus.yaw + status.magDecl;
			    if(status.yaw < 0) status.yaw += 360;        // keep yaw within [0, 360]
			    if(status.yaw > 360) status.yaw -= 360;        // keep yaw within [0, 360]
			    // angular rates
			    status.rollrate = scaleRate*tmpStatus.rollrate;
			    status.pitchrate = scaleRate*tmpStatus.pitchrate;
			    status.yawrate = scaleRate*tmpStatus.yawrate;
			    // angular accelerations    
			    status.rollacc = scaleAcc*tmpStatus.rollacc;
			    status.pitchacc = scaleAcc*tmpStatus.pitchacc;
			    status.yawacc = scaleAcc*tmpStatus.yawacc;
			
			    // indicate that all variables were updated
			    status.update = 1;
			    //cout<<status.yaw<<"\t"<<status.pitch<<"\t"<<status.roll<<endl;
			    pthread_mutex_unlock(&statMutex);
			}
			else
			{
				//std::cerr<<"Bad IMU packet."<<endl;
			}
			bufferDumpFromFront(&rdbuf, 23);
		}
	}
}

bool sample = false;
void* sample4Cal(void* hd)
{
    int fd = (int)hd;
    char collect[] = {0x41};
    char r[255];
    int numRead = -1;
    while (sample)
    {
        write(fd, collect, 1);
        numRead = read(fd, r, 30);
        if (numRead != 23)
        {
            cerr<<"Only "<<numRead<<" bytes read!"<<endl;
        }
        usleep(100000);
    }
    tcflush(fd, TCIFLUSH);
    pthread_exit(NULL);
    return 0;
}
using std::cout;
using std::string;
using std::cin;
using std::hex;
using std::dec;

/*
bool IMU::calibrate()
{
    char received[255];
    char init[] = {0x40, 0x71, 0x3E};
    cout<<"Starting calibration sequence..."<<endl;
    port->write(init, 3);
    //read(fd, received, 5);
    short command = (short)received[0];
    short tmticks = (short)((received[1] << 8)|(received[2]));
    short chksum = (short)((received[3] << 8)|(received[4]));
    if (command + tmticks != chksum)
    {
        cerr<<"Calibration initialization failed!"<<endl;
        return false;
    }
    cout<<"Type \"s\" to start collecting data!"<<endl;
    cout<<"Use \"p\" to pause/start again."<<endl;
    cout<<"Type \"stop\" to end calibration."<<endl;
    cout<<"Type \"exit\" or \"q\" to quit program and leave"<<
        "IMU in default mode."<<endl;
    
    string input;
    pthread_t collector;
    cin>>input;
    while (input != "stop")
    {
        if (input == "s" || input == "p")
        {
            if (sample)
            {
                cout<<"Pausing data collection..."<<endl;
                sample = false;
                pthread_join(collector, 0);
            }
            else
            {
                cout<<"Starting data collection..."<<endl;
                sample = true;
                //pthread_create(&collector, 0, sample4Cal, (void*)fd);
            }
        }
        else if (input == "q" || input == "exit")
        {
            cout<<"Exiting..."<<endl;
            sample = false;
            pthread_join(collector, 0);
            return true;
        }
        else
        {
            cout<<"Do not recognize: "<<input<<endl;
        }
        cin>>input;
    }
    cout<<"Ending hard iron calibration..."<<endl;
    if (sample)
    {
        sample = false;
        pthread_join(collector, 0);
    }
    cout<<"Was this a 3D or 2D calibration (type 3D or 2D)? ";
    cin>>input;
    while (!(input == "3D" || input == "2D"))
    {
        cin>>input;
    }
    char done[] = {0x42, 0x71, 0x3E, 0x0, 0x0, 0x0};
    int magZ;
    
    if (input == "2D")
    {
        cout<<"Please enter Z magnitude: ";
        cin>>magZ;
        while (cin.fail())
        {
            cin.clear();
            cout<<"Invalid input - try again."<<endl;
            cin>>magZ;
        }
        done[3] = 0x01;
        done[4] = (char)(magZ >> 8);
        done[5] = (char)magZ;
    }
    //write(fd, done, 6);
    /int numRead = read(fd, received, 11); 
    if (numRead != 11)
    {
        cerr<<"Calibration failed!  Only "<<numRead<<" read!"<<endl;
        return false;
    }/
    
    command = (short)received[0];
    short offsetX = (short)((received[1] << 8)|(received[2]));
    short offsetY = (short)((received[3] << 8)|(received[4]));
    short offsetZ = (short)((received[5] << 8)|(received[6]));
    tmticks = (short)((received[7] << 8)|(received[8]));
    chksum = (short)((received[9] << 8)|(received[10]));
    
    short calChksum = (command + offsetX + offsetY + offsetZ + tmticks);
     
    if (chksum == calChksum)
    {
        cout<<"Calibration complete!"<<endl;
        return true;
    }
    else
    {
        cerr<<"Calibration failed!  Checksum incorrect!\n"<<
        hex<<chksum<<" != "<<hex<<calChksum<<dec<<endl;
        return false;
    }
}
*/


int IMU::DecodeIMUData(const char *data, int len)
{
	//cerr << "decoding data" << endl;
    if(data == NULL || len < 23) return -1;
    
    int sync = _IMU_ERROR_NO_PACKET_;    // no valid packet yet
    unsigned char *localdata = (unsigned char *)data;
    imu_data tempIMUStat;

    int iter = 0;
    while(sync != _IMU_ERROR_SUCCESS_)
    {
        for(; iter < len; iter++)
        {
            if(localdata[iter] == 49) 
                break;
        }
        if(iter == len)
        {
            cout << "error - no imu packet\n\r";
            return _IMU_ERROR_NO_PACKET_;    // error
        }
         // make sure we have 23 bytes, including ptoken
        if(len - iter < 23)
        {
            cout << "error - incomplete imu packet\n\r";
            return _IMU_ERROR_PART_PACKET;    // error
        }
         // extract variables
        sync = ExtractIMUVars(&data[iter], tempIMUStat);
        iter++;
    }
    
    pthread_mutex_lock(&statMutex);    
    // copy vars to imu_status 
    // angles
    status.roll = scaleAngle*tempIMUStat.roll;
    status.pitch = scaleAngle*tempIMUStat.pitch;
    status.yaw = scaleAngle*tempIMUStat.yaw + status.magDecl;
    if(status.yaw < 0) status.yaw += 360;        // keep yaw within [0, 360]
    // angular rates
    status.rollrate = scaleRate*tempIMUStat.rollrate;
    status.pitchrate = scaleRate*tempIMUStat.pitchrate;
    status.yawrate = scaleRate*tempIMUStat.yawrate;
    // angular accelerations    
    status.rollacc = scaleAcc*tempIMUStat.rollacc;
    status.pitchacc = scaleAcc*tempIMUStat.pitchacc;
    status.yawacc = scaleAcc*tempIMUStat.yawacc;

    // indicate that all variables were updated
    status.update = 1;
    
    pthread_mutex_unlock(&statMutex);
    //return iter - 1;     // success - return packet start index
    return _IMU_ERROR_SUCCESS_;
}

int IMU::ExtractIMUVars(const char *data, imu_data& imu_status)
{
    if(data == NULL) return -1;
    unsigned char *localdata = (unsigned char *)data;


    short command = (short)localdata[0];
    short roll = (short)((localdata[1] << 8)|(localdata[2]));
    short pitch = (short)((localdata[3] << 8)|(localdata[4]));
    short yaw = (short)((localdata[5] << 8)|(localdata[6]));
    short rollacc = (short)((localdata[7] << 8)|(localdata[8]));
    short pitchacc = (short)((localdata[9] << 8)|(localdata[10]));
    short yawacc = (short)((localdata[11] << 8)|(localdata[12]));
    short rollrate = (short)((localdata[13] << 8)|(localdata[14]));
    short pitchrate = (short)((localdata[15] << 8)|(localdata[16]));
    short yawrate = (short)((localdata[17] << 8)|(localdata[18]));
    short tmticks = (short)((localdata[19] << 8)|(localdata[20]));
    short chksum = (short)((localdata[21] << 8)|(localdata[22]));

    // compute checksum
    short calchksum = (short)(command + yaw + roll + pitch + 
    		yawrate + rollrate + pitchrate + yawacc + rollacc +
            pitchacc + tmticks);
    
    if(calchksum == chksum)
    {
        imu_status.command = command;
        imu_status.roll = roll;
        imu_status.pitch = pitch;
        imu_status.yaw = yaw;
        imu_status.rollacc = rollacc;
        imu_status.pitchacc = pitchacc;
        imu_status.yawacc = yawacc;
        imu_status.rollrate = rollrate;
        imu_status.pitchrate = pitchrate;
        imu_status.yawrate = yawrate;
        imu_status.tmticks = tmticks;
        imu_status.chksum = chksum;        
        return _IMU_ERROR_SUCCESS_;
    }
    else
        return _IMU_ERROR_BAD_PACKET_;
}

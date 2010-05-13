#include "microstrain.h"
#include "config.h"

#ifndef MAGNETIC_DECLINATION
#define MAGNETIC_DECLINATION -7.85
#endif

#define _Microstrain_ERROR_SUCCESS_        0
#define _Microstrain_ERROR_NO_PACKET_    -1
#define    _Microstrain_ERROR_PART_PACKET    -2
#define    _Microstrain_ERROR_BAD_PACKET_    -3

Microstrain::Microstrain(const QString & dev){
	initStatus();
	port = new QextSerialPort(dev, QextSerialPort::EventDriven);

	port->setBaudRate(BAUD38400);
	port->setStopBits(STOP_1);
	port->setParity(PAR_NONE);
	port->setDataBits(DATA_8);
	port->setFlowControl(FLOW_OFF);

	if (port->open(QIODevice::ReadWrite) == true) {
		connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
	}else {
		qDebug() << "device failed to open:" << port->errorString();
	}
	// put the AHRS in continuous mode (constantly sending results from command 0x31, which is "Send Gyro-Stabilized Euler Angles & Accel & Rate Vector")
	char cmd[3] = {0x10, 0x00, 0x31};
	//qDebug() << "AHRS Continuous command:" << cmd;
	port->write(cmd, 3);

	packetCount = corruptedCount = 0;

	buf = new QByteArray();
}

void Microstrain::initStatus(){
    status.command = status.tmticks = status.chksum = status.update = 0;
    status.roll = status.yaw = status.pitch
    = status.rollrate = status.pitchrate = status.yawrate
    = status.rollacc = status.pitchacc = status.yawacc = -1;
    status.magDecl = MAGNETIC_DECLINATION;
}
Microstrain::~Microstrain(){
	// end continuous mode (calibration doesn't work in continuous mode)
	char cmd[3] = {0x10, 0x00, 0x00};
	port->write(cmd, 3);
	delete port;
}
imu_data Microstrain::getData(){
    imu_data result = status;
    status.update = 0;
    return result;
}
void Microstrain::setMagDecl(double decl){
    status.magDecl = decl;
}


void Microstrain::onReadyRead(){
	QByteArray bytes;
	int a = port->bytesAvailable();
	bytes.resize(a);
	port->read(bytes.data(), bytes.size());
	//qDebug() << "Microstrain bytes read:" << bytes.size();
	//qDebug() << "Microstrain data:" << bytes;
	buf->append(bytes);


	if(!buf->startsWith(49)){
		int i = buf->indexOf(49);
		if(i > 0)
			buf->remove(0,i);
		else if(i < 0) return;
	}
	while(buf->startsWith(49) && buf->size() >= 23){
		QByteArray tmp = buf->left(23);
		process(tmp);
		buf->remove(0, 23);
	}
}

const double pi = 3.1415926535;
const double scaleAngle = (180.0/32768.0);    // = 180/(2^15);
const double scaleRate = (8.5/32768.0)*(180.0/pi);
const double scaleAcc = (7.0/32768.0)*9.81;

// format = 23 bytes starting with decimal 49
/** 
 * \todo document magDecl
 */
void Microstrain::process(QByteArray & data){

	//packetCount++;

	short command = (short)data[0];
	if(command != 49) {
		qDebug() << "Something weird happened";
		return;
	}
	short yaw = (((data[5]<< 8)&0xFF00) | (data[6]&0x00FF));
	short roll = (((data[1] << 8)&0xFF00)|(data[2]&0x00FF));
	short pitch = (((data[3] << 8)&0xFF00)|(data[4]&0x00FF));
	short rollacc = (((data[7] << 8)&0xFF00)|(data[8]&0x00FF));
	short pitchacc = (((data[9] << 8)&0xFF00)|(data[10]&0x00FF));
	short yawacc = (((data[11] << 8)&0xFF00)|(data[12]&0x00FF));
	short rollrate = (((data[13] << 8)&0xFF00)|(data[14]&0x00FF));
	short pitchrate = (((data[15] << 8)&0xFF00)|(data[16]&0x00FF));
	short yawrate = (((data[17] << 8)&0xFF00)|(data[18]&0x00FF));
	short tmticks = (((data[19] << 8)&0xFF00)|(data[20]&0x00FF));
	short chksum = (((data[21] << 8)&0xFF00)|(data[22]&0x00FF));

	// compute checksum
	short calchksum = (short)(command + yaw + roll + pitch + 
			yawrate + rollrate + pitchrate + yawacc + rollacc +
			pitchacc + tmticks);

	if(calchksum != chksum){
		qDebug() << "Corrupted IMU packet!";
		//corruptedCount++;
		//qDebug() << "Corruption rate: " + QString::number(corruptedCount*100.0/packetCount) + "%";
		//qDebug() << "Yaw: " << QString::number(data[5],16) << QString::number(data[6],16) << QString::number(yaw,16);
		//qDebug() << "Sum should be: " + QString::number(chksum,16) + " but it is " + QString::number(calchksum,16);
		return;
	}
	// copy vars to imu_status // angles
	status.roll = scaleAngle*roll;
	status.pitch = scaleAngle*pitch;
	status.yaw = scaleAngle*yaw + status.magDecl;
	while(status.yaw < 0) status.yaw += 360;        // keep yaw within [0, 360]
	while(status.yaw > 360) status.yaw -= 360;        // keep yaw within [0, 360]
	// angular rates
	status.rollrate = scaleRate*rollrate;
	status.pitchrate = scaleRate*pitchrate;
	status.yawrate = scaleRate*yawrate;
	// angular accelerations    
	status.rollacc = scaleAcc*rollacc;
	status.pitchacc = scaleAcc*pitchacc;
	status.yawacc = scaleAcc*yawacc;

	// indicate that all variables were updated
	status.update = 1;

}

/*

// sample4Cal runs in a thread during calibration

bool sample = false;
void* sample4Cal(void* hd)
{
    int fd = *(int*)hd;
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

bool Microstrain::calibrate()
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
        "Microstrain in default mode."<<endl;
    
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


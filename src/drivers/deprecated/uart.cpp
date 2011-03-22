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

#include "uart.h"
#include <cstdlib>
#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <iomanip>
#include <unistd.h>
//using std::cerr;
//using std::endl;
using namespace std;

UART::UART(const char* dev, int baud, int sz)
{
	pcktSize = sz;
	pthread_mutex_init(&dataMutex, 0);
	pthread_mutex_init(&portMutex, 0);
	pthread_mutex_init(&listMutex, 0);
    running = false;
    fd = -1;
    if (dev == 0)
    {
        bad_port = true;
    }
    else
    {
        useDev(dev, baud);
    }
}
UART::~UART()
{
    stop();
    if (fd > 0)
    {
        close(fd);
    }
}
bool UART::useDev(const char* dev, int baud)
{
    if (dev == 0)
    {
        return false;
    }
    stop();
    if (fd > 0)
    {
        close(fd);
    }
    fd = open(dev, O_RDWR | O_NOCTTY);
    if (fd <= 0)
    {
        cerr<<"Could not open port: "<<dev<<endl;
        bad_port = true;
        return false;
    }
    
    struct termios options;
    if (tcgetattr(fd, &options))
    {
        cerr<<"Invalid port: "<<dev<<endl;
        bad_port = true;
        return false;
    }
    else
    {
        bad_port = false;
    }
    
    options.c_iflag = IGNPAR;
    options.c_iflag &= ~(INPCK);
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cflag = CS8 | CLOCAL | CREAD;
    options.c_cflag &= ~(PARENB);  // clear parity enable
    options.c_cc[VTIME] = 1;   // inter-character timer unused
    options.c_cc[VMIN] = 0;
    switch (baud)
    {
	case 9600:
	    cfsetispeed(&options, B9600);
	    cfsetospeed(&options, B9600);
    	break;
	case 19200:
	    cfsetispeed(&options, B19200);
	    cfsetospeed(&options, B19200);
    	break;
	case 38400:
	    cfsetispeed(&options, B38400);
	    cfsetospeed(&options, B38400);
    	break;
	case 57600:
	    cfsetispeed(&options, B57600);
	    cfsetospeed(&options, B57600);
    	break;
    default:
        cerr << "Cannot set baud rate" << endl;
        break;
    }
    tcflush(fd, TCIOFLUSH);
    
    tcsetattr(fd, TCSANOW, &options);
    start();
    return true;
}
bool UART::isGood()
{
	return !bad_port;
}
bool UART::write(const char* data, int len)
{
	if (bad_port || data == 0)
	{
		return false;
	}
	if (len < 0)
	{
		len = strlen(data);
	}
	if (len < 0)
	{
		return false;
	}
	message m;
	m.msg = new char[len];
	memcpy(m.msg, data, sizeof(char)*len);
	m.len = len;
	pthread_mutex_lock(&dataMutex);
	messages.push(m);
	pthread_mutex_unlock(&dataMutex);
	
	return true;
}

int UART::read(char* data, int len)
{
	pthread_mutex_lock(&portMutex);
	int result = ::read(fd, data, len);
	pthread_mutex_unlock(&portMutex);
	return result;
}
void UART::addUARTList(UARTList* list)
{
	pthread_mutex_lock(&listMutex);
	lists.push_back(list);
	pthread_mutex_unlock(&listMutex);
}

void UART::start()
{
    if (!running && !bad_port)
    {
        running = true;
        pthread_create(&myPthread, 0, runUART, this);
        return;
    }
}
void UART::stop()
{
    if (running)
    {
        running = false;
        pthread_join(myPthread, 0);
        return;
    }
}
bool UART::isRunning()
{
    return running;
}

#include <iostream>
using std::cout;
using std::endl;
int UART::run()
{
	char* data = new char[pcktSize];
	message m;
	int numRead = 0;
	while(running)
	{
		pthread_mutex_lock(&dataMutex);
		while (!messages.empty() )
		{
			m = messages.front();
			pthread_mutex_lock(&portMutex);
			::write(fd, m.msg, m.len);
			pthread_mutex_unlock(&portMutex);
			delete [] m.msg;
			messages.pop();
		}
		pthread_mutex_unlock(&dataMutex);
		
		pthread_mutex_lock(&listMutex);
		if (!lists.empty())
		{
			pthread_mutex_lock(&portMutex);
			if ( (numRead = ::read(fd, data, pcktSize)) )
			{
				pthread_mutex_unlock(&portMutex);
				for (unsigned int x = 0; x < lists.size(); x++)
				{
					lists[x]->process(data, numRead);
				}
			}
			else
			{
				//cout << "not read";
				pthread_mutex_unlock(&portMutex);
			}
		}
		pthread_mutex_unlock(&listMutex);
		
		usleep(1000);
	}
	pthread_mutex_lock(&dataMutex);
	while (!messages.empty() )
	{
		m = messages.front();
		pthread_mutex_lock(&portMutex);
		::write(fd, m.msg, m.len);
		pthread_mutex_unlock(&portMutex);
		delete [] m.msg;
		messages.pop();
	}
	pthread_mutex_unlock(&dataMutex);
	return 0;
}

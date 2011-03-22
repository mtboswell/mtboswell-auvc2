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

#include "adc.h"
#include <iostream>
using namespace std;

ADC::ADC(const char* dev, int baudrate)
{
    port = new UART(dev, baudrate);
    pthread_mutex_init(&dataMutex, 0);
	
	port->addUARTList(this);
    bufferInit(&rdbuf, rdbufChars, 128);
}

ADC::~ADC()
{
	delete port;
}

unsigned int ADC::getValue(string desc)
{
	pthread_mutex_lock(&dataMutex);
	unsigned int result = values[desc];
	pthread_mutex_unlock(&dataMutex);
	return result;
}

bool ADC::sendValue(char cmd){
	return port->write(&cmd, 1);
}


void ADC::process(const char* data, int len)
{
	bufferAddToEnd(&rdbuf, (unsigned char*)data, len);
	
	int start, end;
	string name;
	int x;
	while (rdbuf.datalength > 0)
	{
		// increment start from 0 until we get to a non-digit or non-space/underscore character
		for (start = 0; start < rdbuf.datalength && (bufferGetAtIndex(&rdbuf, start) == '_' 
					|| std::isspace(bufferGetAtIndex(&rdbuf, start)) 
					|| std::isdigit(bufferGetAtIndex(&rdbuf, start))); start++);
		// check to make sure we found the start of a name 
		if (start >= rdbuf.datalength)
		{
			return;
		}
		// increment end from start until we get to a space or underscore
		for (end = start+1; end < rdbuf.datalength && !(bufferGetAtIndex(&rdbuf, end) == '_' 
					|| std::isspace(bufferGetAtIndex(&rdbuf, end))); end++);
		// check to make sure we found something
		if (end >= rdbuf.datalength)
		{
			return;
		}
/*		
		cout << "Raw data: ";
		for (x = start; x != end; x++)
		{
			cout<< (char) bufferGetAtIndex(&rdbuf, x);
		}
		cout<<endl;
*/		
		// put all chars into a string until we get to a digit
		name = "";
		for (x = start; x != end && !std::isdigit(bufferGetAtIndex(&rdbuf, x)); x++)
		{
			name.append(1, bufferGetAtIndex(&rdbuf, x));
		}
		
		// put all following digits into an int
		unsigned int val=0;
		for (x = x; x != end && std::isdigit(bufferGetAtIndex(&rdbuf, x)); x++)
		{
			val = val*10 + (bufferGetAtIndex(&rdbuf, x) - '0');
		}
		
		// drop parsed value from buffer
		bufferDumpFromFront(&rdbuf, x);
		
		// add parsed value to values array
		pthread_mutex_lock(&dataMutex);
		values[name] = val;
		pthread_mutex_unlock(&dataMutex);
		
//		cout<<"Name: "<<name<<"\tValue: "<<val<<endl;
	}
}

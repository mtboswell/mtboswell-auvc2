/***************************************************************************
                          power.cpp  -  controls custom power switches
                             -------------------
    begin                : |04/02/2004|
    copyright            : (C) |2009| by |ASCL| and |AUVT|
    email                : |VTAUVT@listserv.vt.edu|
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "power.h"
#include <string.h>
#include <iostream>
#include <cstdlib>
using namespace std;

Power::Power(const char* dev)
{
    port = new UART(dev, 57600);
    pthread_mutex_init(&dataMutex, 0);
	
	port->addUARTList(this);
    bufferInit(&rdbuf, rdbufChars, 128);

	// drop parsed value from buffer
	bufferFlush(&rdbuf);
}

Power::~Power()
{
	delete port;
}

bool Power::turnOn(){
	char cmd[4];
	cmd[0] = 's';
	cmd[1] = '1';
	cmd[2] = '\n';
	cmd[3] = '\r';
	state = 1;
 	return port->write(cmd, 4);
}
bool Power::turnOff(){
	char cmd[4];
	cmd[0] = 's';
	cmd[1] = '0';
	cmd[2] = '\n';
	cmd[3] = '\r';
	state = 0;
 	return port->write(cmd, 4);
}


bool Power::setState(bool newState){
    if(state == newState) return true;
    if(newState) return turnOn();
    else return turnOff();
}
	
	
double Power::getVoltage(){
	pthread_mutex_lock(&dataMutex);
	double result = voltage;
	pthread_mutex_unlock(&dataMutex);
	return result;
}
double Power::getCurrent(){
	pthread_mutex_lock(&dataMutex);
	double result = current;
	pthread_mutex_unlock(&dataMutex);
	return result;
}

void Power::process(const char* data, int len)
{
	//cerr << "Processing Data!" << endl;
	//cerr << "Data: " << data << endl;
	
	if(len < 20) return;
	
	int voltindex = 7;
	int voltlength = 6;
	int curindex = 14;
	int curlength = 5;
	char voltStr[voltlength+1];
	char curStr[curlength+1];
	
	for(int i = voltlength-1; i >= 0; i--){
		voltStr[i] = data[i+voltindex];
		//cerr << "Processing: " << data[i+voltindex] << endl;
	}	
	for(int i = curlength-1; i >= 0; i--){
		curStr[i] = data[i+curindex];
		//cerr << "Processing: " << data[i+curindex] << endl;
	}
	
	//cerr << "Voltage: " << voltStr << " Current: " << curStr << endl;
	
	// add parsed value to values array
	pthread_mutex_lock(&dataMutex);
	voltage = atof(voltStr);
	current = atof(curStr);
	pthread_mutex_unlock(&dataMutex);

	//cout<<"Name: "<<name<<"\tValue: "<<val<<endl;
}



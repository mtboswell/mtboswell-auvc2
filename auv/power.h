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

#ifndef POWER_H_
#define POWER_H_

#include "buffer.h"
#include "uart.h"
#include <string>
#include <map>
using std::map;
using std::string;

/**
 * Class Power
 * @author Micah Boswell for the Virginia Tech AUVT (micah27@vt.edu)
 * @version Aug. 12, 2009
 */
class Power : public UART::UARTList
{
	public:
    /**
     * This is the constructor.  
     * @param dev is the device file name for the desired serial 
     * port.
     */
	Power(const char* dev = 0);
    /**
     * This is the destructor.
     */
	~Power();
    
	double getVoltage();
	double getCurrent();
	
	bool turnOn();
	bool turnOff();
	bool setState(bool newState);
	
    void process(const char* data, int len);
	private:
	pthread_mutex_t dataMutex;
	bool state;
	double voltage;
	double current;
	UART* port;
	unsigned char rdbufChars[256];
	cBuffer rdbuf;
};

#endif /*POWER_H_*/

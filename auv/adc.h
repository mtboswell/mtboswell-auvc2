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

#ifndef ADC_H_
#define ADC_H_

#include "buffer.h"
#include "uart.h"
#include <string>
#include <map>
using std::map;
using std::string;

/**
 * Class ADCComm
 * @author Kevin Stefanik for the Virginia Tech AUVT (stefanik@vt.edu)
 * @version Oct. 7, 2006
 */
class ADC : public UART::UARTList
{
	public:
    /**
     * This is the constructor.  
     * @param dev is the device file name for the desired serial 
     * port.
     */
	ADC(const char* dev = 0, int baudrate = 38500);
    /**
     * This is the destructor.
     */
	~ADC();
    
	unsigned int getValue(string desc);
	
    void process(const char* data, int len);
	private:
	pthread_mutex_t dataMutex;
	map<string, int> values;
	UART* port;
	unsigned char rdbufChars[256];
	cBuffer rdbuf;
};

#endif /*ADC_H_*/

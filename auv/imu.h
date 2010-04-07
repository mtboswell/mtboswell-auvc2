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

#ifndef IMU_H_
#define IMU_H_

#include "uart.h"
#include "buffer.h"

typedef struct
 {
	 int command, tmticks, chksum;
	 double magDecl;					// local magnetic declination
	 double roll, pitch, yaw;		// orientation
	 double rollrate, pitchrate, yawrate;	// angular rates
	 double rollacc, pitchacc, yawacc;		// accelerations
	 int update; //1 if not yet given to the user, 0 if already given
 } imu_data;


/**
 * Class IMUComm handles all communication to a microstrain 3dm-gx1
 * IMU.  It will perform hard iron calibration with user interaction
 * through the standard input stream and will query the imu for both
 * temperature and gyro-stabilized angles, rates and accelerations.
 * @author Kevin Stefanik for the Virginia Tech AUVT (stefanik@vt.edu)
 * @version Oct. 7, 2006
 */
class IMU : public UART::UARTList
{
	public:
    /**
     * This is the constructor.  
     * @param dev is the device file name for the desired serial 
     * port.
     */
	IMU(const char* dev);
    /**
     * This is the destructor.
     */
	~IMU();
	
	UART* getPort();
    
    void process(const char* data, int len);
    
	imu_data getData();
    
	/**
     * setMagDecl(double decl) - sets the magnetic declination
     * @param decl is the new magnetic declination to use
     */
    void setMagDecl(double decl);
    
    bool calibrate();
    
	private:
	pthread_mutex_t statMutex;
	UART* port;
	
	void initStatus();
	
	unsigned char rdbufChars[256];
	cBuffer rdbuf;
	
	imu_data status, tmpStatus;
	
	int DecodeIMUData(const char *data, int len);
	int ExtractIMUVars(const char *, imu_data &);
	
	//int DecodeIMUTemp(const unsigned char *data, int len);
};

#endif /*IMU_H_*/

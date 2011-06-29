#ifndef MAESTRO_H
#define MAESTRO_H

#include "serialdevice.h"

#include <QStringList>

/**
 * Controls sensor data from various input devices and sends commands to the servos
 * through the serial port on the board
 * 
 * TODO: check pointer arithmatic in the construction of the QList for emit dataReady()
 * TODO: double check equation to convert sensor data into an integer
 */
class Maestro : public QObject {
	
	Q_OBJECT
	public:
		
		//use this functin if the maestro will be the child of the SAL
		//it is up to the sal to make calls to the step() and update StateData
		//
		//Note: maestro still runs in the main thread when spawned by the SAL. grrr.
		Maestro(QObject* parent = 0);
		
		int getDepth();
		

		
	private:
		//convert a 2-byte array from Maestro into an integer
		int byteArrayToInt(QByteArray in);
		
		//a qextSerialDevice to talk to the maestro
		SerialDevice* device;
	

};

#endif

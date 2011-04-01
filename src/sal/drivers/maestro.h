#ifndef MAESTRO_H
#define MAESTRO_H

#include "module.h"
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
		// Use this functin to run the code as a seperate module. will call step on a timer
		// currently the code will not update state data on its own but signal dataReady.
		// 
		// Note: When run as a module, Maestro currently runs in the main thread instead of its own
		Maestro(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
		
		//use this functin if the maestro will be the child of the SAL
		//it is up to the sal to make calls to the step() and update StateData
		//
		//Note: maestro still runs in the main thread when spawned by the SAL. grrr.
		Maestro(QObject* parent = 0);
		
	protected slots:
	
		// polls the sensors connected to channels 0 - 11 on the maestro
		// and writes the sensor data to stateData.
		// The different sensors are hard coded. The current list is below
		//
		// Channel 10: Rangefinder
		void step();
		
	private:
		//convert a 2-byte array from Maestro into an integer
		int byteArrayToInt(QByteArray in);
		
		//a qextSerialDevice to talk to the maestro
		SerialDevice* device;
		bool isModule;
		QTimer* timer;
	
	signals:
		void dataReady(QList<VDatum>);

};

#endif

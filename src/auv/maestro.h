#ifndef MAESTRO_H
#define MAESTRO_H

#include "../module.h"
#include "serialdevice.h"

#include <QStringList>

/**
 * Controls sensor data from various input devices and sends commands to the servos
 * through the serial port on the board
 */
class Maestro : public Module, public SerialDevice {
	
	Q_OBJECT
	public:
		Maestro(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
		
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

};

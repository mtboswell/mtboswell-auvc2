#ifndef MAESTRO_H
#define MAESTRO_H

#include "sensor.h"
#include "serialdevice.h"

#include <QStringList>

class Maestro : public Sensor, public SerialDevice {
	Q_OBJECT
	public:
		Maestro():SerialDevice("/dev/ttyACM1", BAUD115200,  false, QByteArray delimiter = " "){
			numberOfChannels = 12;

			channelDatumIDs[1] = "Z";
			channelDatumIDs[2] = "YawAcc";
			channelDatumIDs[3] = "RollAcc";
			// etc.

			channelSensorIDs[1] = "MSP-300";
			channelSensorIDs[2] = "SF_Gyros";
			channelSensorIDs[3] = "SF_Gyros";
			// etc.


			QByteArray readQuery;
			for(int i = 1; i <= numberOfChannels; i++){
				readQuery << 0x90;
				readQuery << i;
			}
			// set to read all inputs every 100 msecs
			setPollQuery(readQuery, 2*numberOfChannels, 100); // from SerialDevice
		}
	private slots:
		// this function processes the data received from the maestro
		// called by SerialDevice when we receive data from a scheduled device query
		virtual void processQueryData(QByteArray data){
			// check to make sure we have received the right amount of data
			if(data.size() != 2*numberOfChannels) return;
			int inputData[numberOfChannels];
			for(int i = 1; i <= numberOfChannels; i++){
				// extract the data for each channel from the input stream
				inputData[i] = (((int)data[(i*2)-2])&0x0F) | (((int)data[(i*2)-1]<<8)&0xF0);
				// add the data to the local store (sensor.h)
				addData(channelDatumIDs[i], inputData[i], channelSensorIDs[i]);
			}
			// emit signal that sends out the data (sensor.h)
			sendNewData();
		}

	private:
		int numberOfChannels;
		QHash<int, QString> channelDatumIDs;
		QHash<int, QString> channelSensorIDs;
};

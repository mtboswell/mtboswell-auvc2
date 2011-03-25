#ifndef SENSOR_H
#define SENSOR_H

#include "../state.h"

class Sensor : public QObject {
	Q_OBJECT
	public:
		Sensor();
		//! for collecting data about this sensor.  thisSensorMeta should be
		QMap<QString, QVariant> getMeta(){return thisSensorMeta;}
	signals:
		//! sends data to everyone else
		void dataReady(QList<sensorValue> data);
	protected:
		//! sends all of the stored sensor data
		void sendAllData();
		//! sends only sensor data that has changed since the last send
		void sendNewData();
		//! adds or updates data in the local data store
		void addData(QString datumID, QVariant datum, QString sensorID = thisSensorID);

		QMap<QString, sensorValue> sensorData;
		QString thisSensorID;
		QMap<QString, QVariant> thisSensorMeta;
		QTime lastDataSend;
};

#endif

#include "sensor.h"


void Sensor::sendAllData(){
	emit dataReady(sensorData.values());
	lastDataSend = QTime::currentTime();
}
void Sensor::sendNewData() {
	QList<sensorValue> newDatums;
	foreach(sensorValue datum, sensorData){
		if(datum.timestamp > lastDataSend){
			newDatums << datum;
		}
	}
	emit dataReady(newDatums);
	lastDataSend = QTime::currentTime();
}
void Sensor::addData(QString datumID, QVariant datum, QString sensorID){
	// create sensorValue struct for this data
	sensorValue newData;
	newData.datumID = datumID;
	newData.sensorID = sensorID;
	newData.value = datum;
	newData.timestamp = QTime::currentTime();
	// add new struct to local data store
	sensorData[datumID] = newData;
}

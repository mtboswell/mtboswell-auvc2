#include "maestro.h"
#include <QDebug>

Maestro::Maestro(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0)
	:SerialDevice( "/dev/ttyAMC0", BAUD9600) , Module(configIn, stateIn, parent) {
		stepTimer->setInterval(100);
	}

void Maestro::step() {
	//create QByteArrays for sending data and recieving data
	QByteArray outData(0, 2);
	QByteArray inData(0, 2);
	outData[0] = 0x90;
	//...................//
	
	//Querry channel 10....//
	outData[1] = 0x0A;
	inData = sendQuery(outData, 2);
	
	//convert maestro output and write to stateData
	int dataValue = byteArrayToInt(inData);
	qDebug() << "Writing Channel 10: " << dataValue << "to stateData...";
	stateData.setData("RangeFinder_RAW", dataValue);
	qDebug() << " Done";
	
	/**
	TODO: add the rest of the channels
	*/
}

int byteArrayToInt(QByteArray in) {
	//TODO: this formula needs to be double checked
	return (((int)in[0])&0x0F) | (((int)in[2]<<8)&0xF0);
}

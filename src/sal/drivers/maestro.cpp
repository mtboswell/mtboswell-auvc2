#include "maestro.h"
#include <QDebug>


	
Maestro::Maestro(QObject* parent) {
		isModule = false;
		timer = new QTimer(this);
		timer->start(100);
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(step()));
		device = new SerialDevice("/dev/ttyACM0", BAUD9600);
}

void Maestro::step() {
		
	//create QByteArrays for sending data and recieving data
	QByteArray outData(2, '0');
	QByteArray inData(2, '0');
	outData[0] = 0x90;
	//...................//
	

		QList<VDatum> list;
		//qDebug("Maestro capturing data in thread (SAL mode): %d", (int) QThread::currentThreadId());
		VDatum element;
		int dataValue;
		//Querry channel 0....//
		outData[1] = 0x00;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		dataValue = byteArrayToInt(inData);
		list.append(element);
		list.last().id = "Maestro.Depth_Raw";
		list.last().value = dataValue;
		list.append(element);
		list.last().id = "Position.Depth";
		float val = (dataValue - 95) / 4.0;
		list.last().value = val;
		//End of channel 0 query...//
		//Querry channel 4....//
		outData[1] = 0x04;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		dataValue = byteArrayToInt(inData);
		list.append(element);
		list.last().id = "Power.Thruster.Current";
		list.last().value = dataValue;
		//End of channel 4 query...//
		//Querry channel 5....//
		outData[1] = 0x05;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		dataValue = byteArrayToInt(inData);
		list.append(element);
		list.last().id = "Power.Thruster.Voltage";
		list.last().value = dataValue;
		//End of channel 5 query...//
		//Querry channel 6....//
		outData[1] = 0x06;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		dataValue = byteArrayToInt(inData);
		list.append(element);
		list.last().id = "Power.Computer.Current";
		list.last().value = dataValue;
		//End of channel 6 query...//
		//Querry channel 7....//
		outData[1] = 0x07;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		dataValue = byteArrayToInt(inData);
		list.append(element);
		list.last().id = "Power.Computer.Voltage";
		list.last().value = dataValue;
		//End of channel 7 query...//
		//Querry channel 9....//
		outData[1] = 0x09;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		dataValue = byteArrayToInt(inData);
		list.append(element);
		list.last().id = "Acceleration.X";
		list.last().value = dataValue;
		//End of channel 9 query...//
		//Querry channel 10....//
		outData[1] = 0x0A;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		dataValue = byteArrayToInt(inData);
		list.append(element);
		list.last().id = "Acceleration.Y";
		list.last().value = dataValue;
		//End of channel 10 query...//
		
		//This debug line is part on an ongoing investigation into why the
		//GUI hangs waiting for the query to return fron device->sendQuery.
		
		emit dataReady(list);

}

int Maestro::byteArrayToInt(QByteArray in) {
	// Assuming most significant byte second
	return ((int)in[0])&0x00FF | (((int)in[1])<<8)&0xFF00;
}

int Maestro::getDepth() {
	QByteArray outData(2, '0');
	QByteArray inData(2, '0');
	outData[0] = 0x90;
	outData[1] = 0x00;
	inData = device->sendQuery(outData, 2);
	return byteArrayToInt(inData);
}

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
		qDebug("Maestro capturing data in thread (SAL mode): %d", (int) QThread::currentThreadId());
		//Querry channel 10....//
		outData[1] = 0x0A;
		inData = device->sendQuery(outData, 2);
		//convert maestro output and write to stateData
		int dataValue = byteArrayToInt(inData);
		VDatum element;
		list.append(element);
		list.last().id = "Channel 10";
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

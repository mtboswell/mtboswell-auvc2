#include "depthMaestro.h"
#include <QDebug>


	
Maestro::Maestro(QObject* parent) {
		device = new SerialDevice("/dev/ttyACM0", BAUD9600);
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

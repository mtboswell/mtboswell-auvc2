#include "serialdevice.h"
#include <QDebug>

SerialDevice::SerialDevice(const QString & portName, BaudRateType baudRate, bool listen, QByteArray delimiter){
	setIncomingDelimiter(delimiter);
	open(portName, baudRate, listen);
	pollTimer = new QTimer;
}

SerialDevice::~SerialDevice(){
	close();
	delete pollTimer;
}

void SerialDevice::open(QString portName, BaudRateType baud,  bool listen){
	port = new QextSerialPort(portName, QextSerialPort::EventDriven);
	//port->setBaudRate(BAUD9600);
	port->setBaudRate(baud);
	port->setStopBits(STOP_1);
	port->setParity(PAR_NONE);
	port->setDataBits(DATA_8);
	port->setFlowControl(FLOW_OFF);
	
	if(listen) connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
	if (port->open(QIODevice::ReadWrite)) {
		qDebug() << "Port opened:" << port->portName();
	}else {
		qDebug() << "Device failed to open:" << port->errorString();
	}
	buf = new QByteArray();
}

void SerialDevice::close() {
	delete port;
	delete buf;
}

void SerialDevice::setIncomingDelimiter(QByteArray delimiter){
	incomingDelimiter = delimiter;
}
void SerialDevice::setIncomingMaxLength(int maxLength){
	incomingMaxLength = maxLength;
}


void SerialDevice::onReadyRead(){
	QByteArray bytes;
	int a = port->bytesAvailable();
	bytes.resize(a);
	port->read(bytes.data(), bytes.size());
	buf->append(bytes);
	if(buf->contains(incomingDelimiter) || buf->size() > incomingMaxLength){
		QByteArray tmp;
		int ind = 0;
		while((ind = buf->indexOf(incomingDelimiter)) != -1){
			tmp = buf->left(ind);
			processData(tmp);
			buf->remove(0, ind + incomingDelimiter.size());
		}
	}
}

void SerialDevice::setPollCmd(QByteArray cmd, int period){
	pollCmd = cmd;
	connect(pollTimer, SIGNAL(timeout()), this, SLOT(sendPollCmd()));
	pollTimer->start(period);
}
void SerialDevice::setPollQuery(QByteArray cmd, int responseLength, int period){
	pollCmd = cmd;
	pollResponseLength = responseLength;
	connect(pollTimer, SIGNAL(timeout()), this, SLOT(sendPollQuery()));
	pollTimer->start(period);
}

void SerialDevice::sendData(QByteArray data){
	//qDebug() << "Sending Port Data " << data;
	port->write(data.data(), data.size());
	port->flush();
}

QByteArray SerialDevice::sendQuery(QByteArray data, int responseLength){
	sendData(data);
	// get response
	QDataStream in(port);
	QByteArray inData;
	while (inData.size() < responseLength)
		in >> inData;
	return inData;
}
QByteArray SerialDevice::sendQuery(QByteArray data, QByteArray endOfResponseMarker){
	sendData(data);
	// get response
	QDataStream in(port);
	QByteArray inData;
	while (!inData.endsWith(endOfResponseMarker))
		in >> inData;
	return inData;
}

void SerialDevice::sendPollCmd(){
	sendData(pollCmd);
}
void SerialDevice::sendPollQuery(){
	processData(sendQuery(pollCmd, pollResponseLength));
}



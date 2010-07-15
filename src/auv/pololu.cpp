#include "pololu.h"
#include "../configloader.h"
#include <QDebug>
#include <QTime>

Pololu::Pololu(const QString & portName)
{
	if(config.isEmpty()) loadConfigFile(config);
	port = new QextSerialPort(portName);
	port->setBaudRate(BAUD19200);
	port->setStopBits(STOP_1);
	port->setParity(PAR_NONE);
	port->setDataBits(DATA_8);
	port->setFlowControl(FLOW_OFF);

	if (port->open(QIODevice::ReadWrite) == true) {
		qDebug() << "Pololus on" << port->portName();
	}else {
		qDebug() << "device failed to open:" << port->errorString();
	}
}
Pololu::~Pololu()
{
    delete port;
}

void Pololu::setServoParams(char servoNum, bool on, bool reverse, char range){
	char data = 0;
	if(on) data = data|0x40;
	if(reverse) data = data|0x20;
	data = data|(range & 0x1F);
	sendServoCmd(0, servoNum, data);
}
void Pololu::setServoSpeed(char servoNum, char speed){
	sendServoCmd(1, servoNum, speed & 0x7F);
}
void Pololu::setServoNeutral(char servoNum, short int neutral){
	sendServoCmd(5, servoNum, (neutral/128) % 2, neutral % 128);
}

void Pololu::setServoPosition(char servoNum, unsigned char position){
	sendServoCmd(3, servoNum, (position / 128) % 2, position % 128);
}
void Pololu::setServoPosAbs(char servoNum, short int absPos){
	int val = absPos;
	if (val < 500) val = 500;
	else if (val > 5500) val = 5500;
	if(servoNum < 12) setMaestroServoPos(servoNum, val);
	else sendServoCmd(4, servoNum, val / 128, val % 128); 
}
void Pololu::setMaestroServoPos(char servoNum, short int absPos){
	sendServoCmd(0x84, // Command byte: Set Target.
			servoNum, // First data byte holds channel number.
			absPos & 0x7F, // Second byte holds the lower 7 bits of target.
			(absPos >> 7) & 0x7F,   // Third data byte holds the bits 7-13 of target.
			true);
}

void Pololu::sendServoCmd(char command, char servoNum, char data1, char data2, bool maestro){
	QByteArray cmd;
	if(maestro){
		cmd.append(0xAA);
		cmd.append(0x0C);
	}else{
		cmd.append(0x80);
		cmd.append(0x01);
	}
	cmd.append(command);
	cmd.append(servoNum);
	cmd.append(data1);
	if(data2) cmd.append(data2);
	port->write(cmd);

}
void Pololu::sendTrexCmd(char device, char command, QByteArray data){
	if(config["Debug"]=="true") qDebug() << "Sending command:" << QString::number(command, 16) << "to device" << QString::number(device, 16) << "with data" << data.toHex();
	QByteArray cmd;
	cmd.append(0x80);
	cmd.append(device & 0x7F);
	cmd.append(command & 0x7F);
	// clear MSBs here?
	cmd.append(data);
	port->write(cmd);
}
QByteArray Pololu::sendTrexQuery(char device, char command, int responseLength, QByteArray data){
	sendTrexCmd(device, command, data);
	// get response
	QDataStream in(port);
	QByteArray inData;
	while (inData.size() < responseLength)
		in >> inData;
	return inData;
}

bool Pololu::setTrexConfig(char device, char param, char value){
	QByteArray data;
	data.append(param);
	data.append(value);
	data.append(0x55);
	data.append(0x2A);
	char response = sendTrexQuery(device, 0x2F, 1, data)[0];
	if (response == 0) return true;
	else return false;
}


void Pololu::setMotorSpeed(int motorNum, int motorSpeed){
	static QTime time;
	qDebug() << "Trex talk rate:" << time.restart();
	if(config["Debug"]=="true") qDebug() << "Setting motor " + QString::number(motorNum) + " to " + QString::number(motorSpeed);
	if(motorSpeed > 127) motorSpeed = 127;
	else if(motorSpeed < -127) motorSpeed = -127;

	char device = (0x07 + (motorNum/2)) & 0x7F;  // TReX default device number is 7, let's assume they're numbered sequentially

	// Start with the base command 0xCO, add 8 if it's the second motor on that controller, add 2 for reverse, 1 for forward, and 0 for stop, then make sure bit 7 isn't set
	char command = ((0xC4 | ((motorNum%2)*0x08)) | ((motorSpeed > 0)?2:(motorSpeed == 0)?0:1)) & 0x7F;

	QByteArray data;
	data.append(((motorSpeed > 0)?motorSpeed:-motorSpeed) & 0x7F);

	sendTrexCmd(device, command, data);
}


int Pololu::getAnalogInput(char inputNum){
	if(config["Debug"] == "true") qDebug() << "Reading input " << QString::number(inputNum);
	sendServoCmd(0x10, inputNum, NULL, NULL, true); 
	char response[2];
	int reads = 0;
	do{
		reads += port->read(response, 2);
		if(reads < 0) return -1;
	}while(reads < 2);
	int input = ((response[1] << 8)& 0xFF00) | (response[0] & 0x00FF);
	if(config["Debug"] == "true") qDebug() << "Read input " << QString::number(inputNum) << " to be " << QString::number(input);
	return input;
}


int Pololu::getDigitalInput(char inputNum){
	int analog = getAnalogInput(inputNum);
	if(analog < 0) return -1;
	else if(analog < 600) return 0;
	else if(analog >= 600) return 1;
	//return qMin(1,analog); //(analog == 1023) ?1:((analog == -1)?-1:0);
}

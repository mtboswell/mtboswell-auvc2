#include "pololu.h"
#include "../config.h"
#include <QDebug>

Pololu::Pololu(const QString & portName)
{
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
	sendServoCmd(4, servoNum, val / 128, val % 128); 
}

void Pololu::sendServoCmd(char command, char servoNum, char data1, char data2){
	QByteArray cmd;
	cmd.append(0x80);
	cmd.append(0x01);
	cmd.append(command);
	cmd.append(servoNum);
	cmd.append(data1);
	if(data2) cmd.append(data2);
	port->write(cmd);

}
void Pololu::sendTrexCmd(char device, char command, QByteArray data){
	if(DEBUG) qDebug() << "Sending command:" << QString::number(command) << "to device" << QString::number(device) << "with data" << data.toUInt();
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
	if(DEBUG) qDebug() << "Setting motor " + QString::number(motorNum) + " to " + QString::number(motorSpeed);
	if(motorSpeed > 127) motorSpeed = 127;
	else if(motorSpeed < -127) motorSpeed = -127;

	char device = (0x07 + (motorNum/2)) & 0x7F;  // TReX default device number is 7, let's assume they're numbered sequentially

	// Start with the base command 0xCO, add 8 if it's the second motor on that controller, add 2 for reverse, 1 for forward, and 0 for stop, then make sure bit 7 isn't set
	char command = ((0xC4 | ((motorNum%2)*0x08)) | ((motorSpeed > 0)?2:(motorSpeed == 0)?0:1)) & 0x7F;

	QByteArray data;
	data.append(((motorSpeed > 0)?motorSpeed:-motorSpeed) & 0x7F);

	sendTrexCmd(device, command, data);
}

#include "pololu.h"

#include <iostream>
using std::cout;
using std::endl;

Pololu::Pololu(const QString & portName)
{
	port = new QextSerialPort(portName, QextSerialPort::EventDriven);
	port->setBaudRate(BAUD19200);

	if (port->open(QIODevice::ReadWrite) == true) {

		connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

		qDebug() << "listening for data on" << port->portName();
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
	sendCmd(0, servoNum, data);
}
void Pololu::setServoSpeed(char servoNum, char speed){
	sendCmd(1, servoNum, speed & 0x7F);
}
void Pololu::setServoNeutral(char servoNum, short int neutral){
	sendCmd(5, servoNum, (neutral/128) % 2, neutral % 128);
}

bool Pololu::setServoPosition(int servoNum, int position)
{
	return sendCmd(3, servoNum, (position / 128) % 2, position % 128);
}
bool Pololu::setServoPosAbs(int servoNum, int absPos)
{
	int val = absPos;
	if (val < 500){
		val = 500;
	}else if (val > 5500){
		val = 5500;
	} 
	return sendCmd(4, servoNum, val / 128, val % 128); 
}
bool Pololu::sendCmd(char command, char servoNum, char data1, char data2)
{
	if (!port->isGood())
	{
		return false;
	}
    msg[0] = 0x80;
    msg[1] = 0x01;
    msg[2] = command;
    msg[3] = servoNum;
    msg[4] = data1;
    msg[5] = data2;
 	if (command > 2)
 	{
 		len = 6;
 	}
 	else
 	{
 		len = 5;
 	}
 	return port->write(msg, len);
}

bool Pololu::setTrexConfig(char param, char value)
{
	if (!port->isGood())
	{
		return false;
	}
    msg[0] = 0x80; // -127
    msg[1] = 0x07; // 7
    msg[2] = 0xAF & 0x7F; // 47
    msg[3] = param;
    msg[4] = value;
    msg[5] = 0x55; // 85
    msg[6] = 0x2A; // 42
	len = 7;
 	if(port->write(msg, len)){
 		// this code was intended to read the response byte, but this is entirely the wrong way to go about it if you want it to work
 		/*char readmsg[1];
 		//usleep(1000);
 		port->read(readmsg, 1);
 		if(readmsg[0] == 0) return true;
 		else{
 			cout << "Serial Dump:" << endl;
 			cout << (int) readmsg[0] << endl;
 			return false;
 		};
 		usleep(50000);*/
 		return true;
 	}else{
 		return false;
 	}
}


bool Pololu::setTrexSpeed(int motorNum, int motorSpeed)
{
	if (!port->isGood())
	{
		return false;
	}
	
	if(motorSpeed > 127) motorSpeed = 127;
	else if(motorSpeed < -127) motorSpeed = -127;
	
    msg[0] = 0x0080;  // -127
    msg[1] = (0x07 + (motorNum/2)) & 0x7F;  // TReX default device number is 7, let's assume they're numbered sequentially
    // Start with the base command 0xCO, add 8 if it's the second motor on that controller, add 2 for reverse, 1 for forward, and 0 for stop, then make sure bit 7 isn't set
    msg[2] = ((0xC4 | ((motorNum%2)*0x08)) | ((motorSpeed > 0)?2:(motorSpeed == 0)?0:1)) & 0x7F;
    msg[3] = ((motorSpeed > 0)?motorSpeed:-motorSpeed) & 0x7F;
 	len = 4;
 	//for(int i = 0; i < len; i++)
    //	printf("0x%0x ", msg[i]);
 	//cout << endl;
 	return port->write(msg, len);
}

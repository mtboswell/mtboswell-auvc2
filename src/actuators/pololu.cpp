/*
  References used:
    1)  Pololu TReX User's Guide (web):   http://www.pololu.com/docs/0J1/all
    2)  TReX Command Documentation (PDF):   http://www.pololu.com/catalog/product/777/resources

  Notes:
    Assimilation of this files returned data into the format of the HAL will occur in maestro.cpp
  */
#include "pololu.h"
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
void Pololu::setMaestroServoPos(char servoNum, short int absPos){
	sendServoCmd(0x84, // Command byte: Set Target.
			servoNum, // First data byte holds channel number.
			absPos & 0x7F, // Second byte holds the lower 7 bits of target.
			(absPos >> 7) & 0x7F,   // Third data byte holds the bits 7-13 of target.
			true);
}

void Pololu::sendServoCmd(char command, char servoNum, char data1, char data2, bool maestro){
	QByteArray cmd;
	if(maestro)
		cmd.append(0xAA);
	else
		cmd.append(0x80);
	cmd.append(0x01);
	cmd.append(command);
	cmd.append(servoNum);
	cmd.append(data1);
	if(data2) cmd.append(data2);
	port->write(cmd);

}
void Pololu::sendTrexCmd(char device, char command, QByteArray data){
	//if(config["Debug"]=="true") qDebug() << "Sending command:" << QString::number(command) << "to device" << QString::number(device) << "with data" << data.toUInt();
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

/* This function currently returns 7 bytes as follows:
    'T', 'R', 'e', 'X', major byte, '.', minor byte
   for example: " TReX1.0 "
  */
QString Pololu::getTrexSignature(char device){
    QByteArray data;
    QString info = sendTrexQuery(device, 0x81, 1, data);
    return(info);
}

/* This function currently returns 1 byte indicating the mode of the device,
   the format of which is as follows:
    'R' (0x52) = RC mode
    'A' (0x41) = Analog mode
    'r' (0x72) = Serial mode with channels configured for RC input signals
    'a' (0x61) = Serial mode with channels configured for analog input signals

    (see reference #2)
  */
char Pololu::getTrexMode(char device){
    QByteArray data;
    char info = sendTrexQuery(device, 0x82, 1, data)[0];
    return(info);
}

/* This function currently returns current in Amps (to get mA, divide by 1000)
    It is using the default device # of 0x07 since the device # is not needed to getMotorCurrent
    The commands 0x8D and 0x8E are classified as "Data-Query Commands" by reference #2 (see line 4 above)
   */
double Pololu::getMotorCurrent(char motorNum){
    QByteArray data;
    //if( motorNum == '1' ){
        char device = (0x07 + (motorNum/2)) & 0x7F;
        char info = sendTrexQuery(device, ( (0x8D) + (motorNum%2)), 1, data)[0];
        double currToAmps = info;
        return( currToAmps * 0.15);
    /*}
    if( motorNum == '2' ){
        char info = sendTrexQuery(0x07, 0x8E, 1, data)[0];
        double currToAmps = info[0];
        return( currToAmps * 0.15);
    }*/
}

/*  Currently not needed
void setSaneTrexParams(char device){
}
*/

void Pololu::setMotorSpeed(int motorNum, int motorSpeed){
	//if(config["Debug"]=="true") qDebug() << "Setting motor " + QString::number(motorNum) + " to " + QString::number(motorSpeed);
	if(motorSpeed > 127) motorSpeed = 127;
	else if(motorSpeed < -127) motorSpeed = -127;

	char device = (0x07 + (motorNum/2)) & 0x7F;  // TReX default device number is 7, let's assume they're numbered sequentially

	// Start with the base command 0xCO, add 8 if it's the second motor on that controller, add 2 for reverse, 1 for forward, and 0 for stop, then make sure bit 7 isn't set
	char command = ((0xC4 | ((motorNum%2)*0x08)) | ((motorSpeed > 0)?2:(motorSpeed == 0)?0:1)) & 0x7F;

	QByteArray data;
	data.append(((motorSpeed > 0)?motorSpeed:-motorSpeed) & 0x7F);

	sendTrexCmd(device, command, data);
}

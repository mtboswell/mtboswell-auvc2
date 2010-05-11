#include "power.h"
#include <QDebug>

Power::Power(const QString & portName){
	port = new QextSerialPort(portName, QextSerialPort::EventDriven);
	port->setBaudRate(BAUD57600);
	
	if (port->open(QIODevice::ReadWrite) == true) {
		connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
		qDebug() << "listening for data on" << port->portName();
	}else{
		qDebug() << "device failed to open:" << port->errorString();
	}
	buf = new QByteArray();
}

Power::~Power(){
	delete port;
}

// separator = \n\r
void Power::onReadyRead(){
	QByteArray bytes;
	int a = port->bytesAvailable();
	bytes.resize(a);
	port->read(bytes.data(), bytes.size());
	buf->append(bytes);
	//*buf = buf->simplified();  // does this remove the line breaks?
	if(buf->contains("\n\r")){
		QByteArray tmp;
		int ind = 0;
		while((ind = buf->indexOf("\n\r")) != -1){
			tmp = buf->left(ind);
			process(tmp);
			buf->remove(0, ind + 2);
		}
	}
}

bool Power::turnOn(){
	char cmd[4];
	cmd[0] = 's';
	cmd[1] = '1';
	cmd[2] = '\n';
	cmd[3] = '\r';
	state = 1;
 	return port->write(cmd, 4);
}
bool Power::turnOff(){
	char cmd[4];
	cmd[0] = 's';
	cmd[1] = '0';
	cmd[2] = '\n';
	cmd[3] = '\r';
	state = 0;
 	return port->write(cmd, 4);
}

bool Power::setState(bool newState){
    if(state == newState) return true;
    if(newState) return turnOn();
    else return turnOff();
}
	
	
double Power::getVoltage(){
	return voltage;
}
double Power::getCurrent(){
	return current;
}

void Power::process(QByteArray data){
	// format: $ASVIS,[volts],[amps]*
	// or: [millivolts],[milliamps]
	QRegExp rx;
	int multiplier;
	if(data.contains("$ASVIS")){
		rx.setPattern("\\$ASVIS,([\\d\\.]+),([\\d\\.]+)\\*?");
		multiplier = 1;
	}else{
		rx.setPattern("\\([\\d\\.]+),([\\d\\.]+)");
		multiplier = 1000;
	}
	
	QString voltStr, curStr;
	if(rx.exactMatch(data)){
		voltStr = rx.cap(1);
		curStr = rx.cap(2);
	}
	
	// add parsed value to values array
	voltage = voltStr.toDouble()*multiplier;
	current = curStr.toDouble()*multiplier;

}



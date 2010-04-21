#include "arduino.h"
#include <QDebug>

Arduino::Arduino(const QString & portName){
	port = new QextSerialPort(portName, QextSerialPort::EventDriven);
	port->setBaudRate(BAUD9600);

    if (port->open(QIODevice::ReadWrite) == true) {

        connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        connect(port, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)));

        if (!(port->lineStatus() & LS_DSR))
            qDebug() << "warning: device is not turned on";
        qDebug() << "listening for data on" << port->portName();
    }else {
        qDebug() << "device failed to open:" << port->errorString();
    }

}

Arduino::~Arduino(){
	delete port;
}

void Arduino::onReadyRead(){
	QByteArray bytes;
	int a = port->bytesAvailable();
	bytes.resize(a);
	port->read(bytes.data(), bytes.size());
	qDebug() << "bytes read:" << bytes.size();
	qDebug() << "bytes:" << bytes;
	buf->append(bytes);
	*buf = buf->simplified();
	if(buf->contains(" ")){
		QByteArray tmp;
		int ind = 0;
		while((ind = buf->indexOf(" ")) != -1){
			tmp = buf->left(ind);
			process(tmp);
			buf->remove(0, ind + 1);
		}
	}
}


void Arduino::onDsrChanged(bool status){
    if (status)
        qDebug() << "device was turned on";
    else
        qDebug() << "device was turned off";
}


unsigned int Arduino::getValue(const QString & desc){
	unsigned int result = values[desc];
	return result;
}

bool Arduino::sendCmd(char cmd){
	return port->write(&cmd, 1);
}


// processes data in format: [A-Za-z]*[0-9]*
void Arduino::process(QByteArray data){

	QString name, value;
	QRegExp rx("(\\w+)(\\d+)");
	if(rx.exactMatch(data)){
		name = rx.cap(1);
		value = rx.cap(2);
	}

	if(name.isNull() || value.isNull()) return;

	bool conversionWorked;
	unsigned int val = value.toUInt(&conversionWorked);
	if(!conversionWorked) return;

	values[name] = val;

}

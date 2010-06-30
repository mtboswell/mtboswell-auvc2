#include "arduino.h"
#include <QDebug>

Arduino::Arduino(const QString & portName){
	port = new QextSerialPort(portName, QextSerialPort::EventDriven);
	port->setBaudRate(BAUD9600);
	port->setStopBits(STOP_1);
	port->setParity(PAR_NONE);
	port->setDataBits(DATA_8);
	port->setFlowControl(FLOW_OFF);

	if (port->open(QIODevice::ReadWrite) == true) {
		connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
		qDebug() << "listening for data on" << port->portName();
	}else {
		qDebug() << "device failed to open:" << port->errorString();
	}
	buf = new QByteArray();

}

Arduino::~Arduino(){
	delete port;
}

void Arduino::onReadyRead(){
	QByteArray bytes;
	int a = port->bytesAvailable();
	bytes.resize(a);
	port->read(bytes.data(), bytes.size());
	//qDebug() << "Arduino bytes read:" << bytes.size();
	//qDebug() << "Arduino data:" << bytes;
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


int Arduino::getValue(const QString & desc){
	int result = -1;
	if(values.contains(desc)) result = (int) values[desc];
	return result;
}

bool Arduino::sendCmd(char cmd){
	return port->write(&cmd, 1);
}


// processes data in format: [A-Za-z]*[0-9]*
void Arduino::process(QByteArray data){

	QString name, value;
	QRegExp rx("(\\D+\\d+)");
	QStringList list;
	int pos = 0;

	while ((pos = rx.indexIn(data, pos)) != -1) {
		list << rx.cap(1);
		pos += rx.matchedLength();
	}

	foreach(QString str, list){
		QRegExp rx2("(\\D+)(\\d+)");
		if(rx2.exactMatch(data)){
			name = rx2.cap(1);
			value = rx2.cap(2);
		}

		if(name.isNull() || value.isNull()) continue;

		bool conversionWorked;
		unsigned int val = value.toUInt(&conversionWorked);
		if(!conversionWorked) continue;

		values[name] = val;
		emit newValueReady(name, val);
	}

}

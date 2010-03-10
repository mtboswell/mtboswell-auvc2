#include "server.h"

server::server(){
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));

	socket = new QUdpSocket(this);
	socket->bind(QHostAddress::LocalHost, DATA_PORT);
	//socket->connectToHost("192.168.3.255", DATA_PORT);
	//if (socket->waitForConnected(1000))
	//	qDebug("Connected!");
	connect(socket, SIGNAL(readyRead()),
	     this, SLOT(readPendingDatagrams()));
}

void server::run(){
	timer->start(STEP_TIME);
	exec();
}

void server::readPendingDatagrams()
{
	while (socket->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(socket->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;

		socket->readDatagram(datagram.data(), datagram.size(),
				 &sender, &senderPort);

		processDatagram(datagram);
	}
}

void server::processDatagram(QByteArray datagram){
	

}

void server::sendData(){


}

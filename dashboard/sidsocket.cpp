#include "SIDSocket.h"
#include <QDebug>

// COMMAND_TIMEOUT = time we wait for a response from the AUV before trying again
#define COMMAND_TIMEOUT 1000

SIDSocket::SIDSocket(quint16 bindPort, quint16 remotePort, 
		QHostAddress remoteAddr = QHostAddress::Broadcast, 
		QHostAddress bindAddr = QHostAddress::Any){
	m_Sock.bind(bindPort);
	m_remoteAddr = remoteAddr;
	m_remotePort = remotePort;
	QObject::connect(&m_Sock, SIGNAL(readyRead()),
			this, SLOT(handleDatagram()));
	QObject::connect(&safetyCheckTimer, SIGNAL(timeout()), this, SLOT(checkForLostDatagrams()));
	safetyCheckTimer.start(COMMAND_TIMEOUT/2);
}

SIDSocket::~SIDSocket() {
}

void SIDSocket::setRemoteAddr(QString addr){
	if(!QHostAddress(addr).isNull()) m_remoteAddr = addr;
}

void SIDSocket::sendSID(QString ID, QString data) {
	QByteArray out;
	out.append(ID);
	out.append("=");
	out.append(data);
	out.append(";");
	sendDatagram(out);
}

// sends data and checks for acks
void SIDSocket::sendDatagram(QByteArray out, bool resend) {
	bool send = true;
	if(m_Acks.size() > 15 && !resend){
		//qDebug() << QString::number(m_Acks.size()) + " commands still unacknowledged";
		flaky = true;
		emit AUVNotResponding(m_Acks.size());
	}else if(m_Acks.size() > 25){
		send = false;
	}
	if(send){
		m_Sock.writeDatagram(out, m_remoteAddr, m_remotePort);

		if(out.contains("Connect")){ 
			flaky = false;
			m_Acks.clear(); // discard old commands on reconnect
		}else{ 
			m_Acks.insert(out, QTime::currentTime());
		}
	}	
}
void Server::readPendingDatagrams()
{
	while (socket->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(socket->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;

		socket->readDatagram(datagram.data(), datagram.size(),
				 &sender, &senderPort);

		processDatagram(datagram, sender, senderPort);
	}
}
void Server::processDatagram(QByteArray datagram, QHostAddress fromAddr, quint16 fromPort){
	//qDebug() << "Processing Datagram:" << datagram;
	QList<QByteArray> data = datagram.split(';');	
	QByteArray datum;
	foreach(datum, data){
		if(datum.isNull() || datum.isEmpty() || !datum.contains('=')) continue;
		qDebug() << "Received command:" << datum;
		QString key, type, name, value;
		QList<QByteArray> field = datum.split('=');
		if(field.size() > 0){
			key = field.at(0);
			if(field.size() > 1){
				value = field.at(1);
				QList<QString> cmd = key.split('.');
				if(cmd.size() > 0) type = cmd.at(0);
				if(cmd.size() > 1) name = cmd.at(1);
			}
		}
		doAction(type, name, value, fromAddr, fromPort);	
	}
	//qDebug() << "Processed Datagram, echoing";
	if(!remoteHost.isNull()) socket->writeDatagram(datagram, remoteHost, CLIENT_DATA_PORT);
}


void SIDSocket::handleDatagrams() {
	QList<QByteArray> pairs;
	QStringList pair;
	QString type, name, val;
	while (m_Sock.hasPendingDatagrams()) {
		m_Buf.resize(m_Sock.pendingDatagramSize());
		m_Sock.readDatagram(m_Buf.data(),m_Buf.size());
		// echo for ack
		m_Sock.writeDatagram(out, m_remoteAddr, m_remotePort);
		if(m_Acks.contains(m_Buf)){
			m_Acks.remove(m_Buf);
			//qDebug() << QString::number(m_Acks.size()) + " pending commands";
			return;
		}
		pairs = m_Buf.split(';');
		foreach (QString p, pairs) {
			if (p.contains('=')) {
				pair = p.split('=').at(0).split('.');
				val = p.split('=').at(1);
				type = pair.at(0);
				if (pair.size() > 1)
					name = pair.at(1);
				else
					name = "";
				emit sidReceived(type, name, val);
			}
		}
	}
}

// checks for old sent datagrams that have not ben acked and resends them
void SIDSocket::checkForLostDatagrams(){
	if(m_Acks.isEmpty()) {
		if(flaky) emit connectionRestored();
		flaky = false;
		return;
	}
	QHashIterator<QByteArray, QTime> i(m_Acks);
	while (i.hasNext()) {
		i.next();
		if(i.value().elapsed() > COMMAND_TIMEOUT) {
			if(!i.key().contains("RC")){
				qDebug() << "Re-sending:" << i.key();
				SendParam(i.key(), true);		
			}
		}
	}
}

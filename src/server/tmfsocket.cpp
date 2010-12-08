#include "tmfsocket.h"
#include <QDebug>

VDataSocket::VDataSocket(quint16 bindPort, quint16 remotePort, bool server,
		     QHostAddress remoteAddr, 
		     QHostAddress bindAddr){
	if(!m_Sock.bind(bindAddr, bindPort, QUdpSocket::ShareAddress)) qDebug() << "Failed to bind to port" << bindPort;
	m_remoteAddr = remoteAddr;
	m_remotePort = remotePort;
	m_Server = server;
	m_buffer = false;
	m_flaky = false;
	QObject::connect(&m_Sock, SIGNAL(readyRead()),
			this, SLOT(handlePendingDatagrams()));
	m_AckTimeout = 2000;

	if(config.isEmpty()) loadConfigFile(config);
}

VDataSocket::~VDataSocket() {
}

void VDataSocket::setRemoteAddr(QString addr, quint16 port){
	if(!QHostAddress(addr).isNull()) m_remoteAddr = addr;
	if(port != 0) m_remotePort = port;
}

void VDataSocket::sendVData(VData message, bool critical) {
	m_outBuffer.append("VData");
	m_outBuffer.append(serializeVData(message));
	if(!m_buffer) {
		sendDatagram(m_outBuffer, critical);
		m_outBuffer.clear();
	}
}

// sends data and checks for acks
void VDataSocket::sendDatagram(QByteArray out, bool force) {
	if(force || m_Server){
		// skip error checking
	}else if(m_outQueue.size() > 10){
		qDebug() << "Queue Overflow";
		emit remoteNotResponding();
		return;
	}else if(m_flaky){
		qDebug() << "Still Flaky";
		m_outQueue.enqueue(out);
		QTimer::singleShot(500,this,SLOT(sendDatagram())); 
		return;
	}else if(m_Acks.size() > 5){
		qDebug() << "Acks overflow";
		//qDebug() << QString::number(m_Acks.size()) + " commands still unacknowledged";
		m_flaky=true;
		// the first time we have unacked packets, send a connect datagram
		sendDatagram("Connect", true);
		emit reconnecting();
		return;
	}
	m_Sock.writeDatagram(out, m_remoteAddr, m_remotePort);
	if(config["Debug"] == "true") qDebug() << "Sent" << out << "to " + m_remoteAddr.toString() + ":" + QString::number(m_remotePort);

	if(!m_Server){
		m_Acks.insert(out, QTime::currentTime());
		// remove acks more than AckTimeout old and let everyone know what went missing
		foreach(QByteArray datagram, m_Acks.keys()){
			if(m_Acks[datagram].msecsTo(QTime::currentTime()) > m_AckTimeout){
				emit(noAck(datagram));
				m_Acks.remove(datagram);
			}
		}
	}
}

void VDataSocket::setAckTimeout(int msecs){
	m_AckTimeout = msecs;
}

void VDataSocket::sendDatagram(){
	if(!m_outQueue.isEmpty()) sendDatagram(m_outQueue.dequeue());
}


void VDataSocket::handlePendingDatagrams() {
	static QByteArray datagram;
	static QHostAddress sender;
	static quint16 senderPort;
	while (m_Sock.hasPendingDatagrams()) {

		datagram.resize(m_Sock.pendingDatagramSize()); // prep buffer

		m_Sock.readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

		if(!m_Server && m_Acks.contains(datagram)){ // check to see if incoming is an acknowledgement
			if(datagram == "Connect") {
				m_flaky = false;
				while(!m_outQueue.isEmpty()) sendDatagram();
			}
			m_Acks.remove(datagram); // and remove from unanswered list 
		}else{
			// server echos to acknowledge received
			//if(m_Server) m_Sock.writeDatagram(datagram, sender, senderPort);
			if(m_Server) m_Sock.writeDatagram(datagram, m_remoteAddr, senderPort);

			// TODO - start in thread
			processDatagram(datagram, sender, senderPort);
		}

	}
}

void VDataSocket::processDatagram(QByteArray datagram, QHostAddress fromAddr, quint16 fromPort){

	static QList<QString> VDatas;
	VData receivedMessage;

	if(fromPort){}

	VDatas = QString(datagram).split("VData");
	foreach (QString msg, VDatas) {
		receivedMessage = parseVData(msg.toAscii());
		emit tmfReceived(receivedMessage, fromAddr);
	}
}

void VDataSocket::buffer(){
	m_buffer = true;
}

void VDataSocket::flush(){
	m_buffer = false;
	sendDatagram(m_outBuffer);
	m_outBuffer.clear();
}

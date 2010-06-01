#include "sidsocket.h"
#include <QDebug>

SIDSocket::SIDSocket(quint16 bindPort, quint16 remotePort, bool server,
		     QHostAddress remoteAddr, 
		     QHostAddress bindAddr){
	if(!m_Sock.bind(bindPort)) qDebug() << "Failed to bind to port" << bindPort;
	m_remoteAddr = remoteAddr;
	m_remotePort = remotePort;
	m_Server = server;
	m_buffer = false;
	m_flaky = false;
	QObject::connect(&m_Sock, SIGNAL(readyRead()),
			this, SLOT(handlePendingDatagrams()));
	m_AckTimeout = 2000;
}

SIDSocket::~SIDSocket() {
}

void SIDSocket::setRemoteAddr(QString addr, quint16 port){
	if(!QHostAddress(addr).isNull()) m_remoteAddr = addr;
	if(port != 0) m_remotePort = port;
}

void SIDSocket::sendSID(QString ID, QString data) {
	m_outBuffer.append(ID);
	m_outBuffer.append("=");
	m_outBuffer.append(data);
	m_outBuffer.append(";");
	if(!m_buffer) {
		sendDatagram(m_outBuffer);
		m_outBuffer.clear();
	}
}

// sends data and checks for acks
void SIDSocket::sendDatagram(QByteArray out, bool force) {
	if(force || m_Server){
		// skip error checking
	}else if(m_outQueue.size() > 10){
		qDebug() << "Queue Overflow";
		emit remoteNotResponding(id(out), data(out));
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
	//if(config["Debug"] == "true") qDebug() << "Sent" << out << "to " + m_remoteAddr.toString() + ":" + QString::number(m_remotePort);

	if(!m_Server){
		m_Acks.insert(out, QTime::currentTime());
		// remove acks more than AckTimeout old and let everyone know what went missing
		foreach(QByteArray datagram, m_Acks.keys()){
			if(m_Acks[datagram].msecsTo(QTime::currentTime()) > m_AckTimeout){
				emit(noAck(id(datagram),data(datagram)));
				m_Acks.remove(datagram);
			}
		}
	}
}

void SIDSocket::setAckTimeout(int msecs){
	m_AckTimeout = msecs;
}

void SIDSocket::sendDatagram(){
	if(!m_outQueue.isEmpty()) sendDatagram(m_outQueue.dequeue());
}

QString SIDSocket::id(QByteArray datagram){
	QString gram = QString(datagram);
	return QStringList(gram.split(';')[0].split('='))[0];
}
QString SIDSocket::data(QByteArray datagram){
	QString gram = QString(datagram);
	return QStringList(gram.split(';')[0].split('='))[1];

}

void SIDSocket::handlePendingDatagrams() {
	static QByteArray datagram;
	static QHostAddress sender;
	static quint16 senderPort;
	while (m_Sock.hasPendingDatagrams()) {

		datagram.resize(m_Sock.pendingDatagramSize()); // prep buffer

		m_Sock.readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

		if(!m_Server && m_Acks.contains(datagram)){ // check to see if incoming is an acknowledgement
			m_Acks.remove(datagram); // and remove from unanswered list 
			if(datagram == "Connect") {
				m_flaky = false;
				while(!m_outQueue.isEmpty()) sendDatagram();
			}
		}else{
			// server echos to acknowledge received
			if(m_Server) m_Sock.writeDatagram(datagram, sender, senderPort);

			// TODO - start in thread
			processDatagram(datagram, sender, senderPort);
		}

	}
}

void SIDSocket::processDatagram(QByteArray datagram, QHostAddress fromAddr, quint16 fromPort){

	static QList<QByteArray> SIDs;
	static QStringList ID;

	SIDs = datagram.split(';');
	foreach (QString SID, SIDs) {
		if (((ID=SID.split('=')).size() == 2)) {
//			emit sidReceived(ID[0], ID[1]);
			emit sidReceived(ID[0], ID[1], fromAddr);
		}
	}
}

void SIDSocket::buffer(){
	m_buffer = true;
}

void SIDSocket::flush(){
	m_buffer = false;
	sendDatagram(m_outBuffer);
	m_outBuffer.clear();
}

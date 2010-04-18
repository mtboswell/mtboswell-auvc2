#include "DashSocket.h"
#include <QDebug>

// COMMAND_TIMEOUT = time we wait for a response from the AUV before trying again
#define COMMAND_TIMEOUT 1000

DashSocket::DashSocket(QHostAddress addr, quint16 port) {
	m_Sock.bind(port);
	m_Addr = AUV_IP;
	m_Port = SERVER_DATA_PORT;
	QObject::connect(&m_Sock, SIGNAL(readyRead()),
					 this, SLOT(HandleDatagram()));
	QObject::connect(&safetyCheckTimer, SIGNAL(timeout()), this, SLOT(checkForLostDatagrams()));
	safetyCheckTimer.start(1000);
}

DashSocket::~DashSocket() {
}

void DashSocket::setRemoteAddr(QString addr){
	if(!QHostAddress(addr).isNull()) m_Addr = addr;
}

void DashSocket::SendParam(QString key, QString value) {
	QByteArray out;
	out.clear();
	out.append(key);
	out.append("=");
	out.append(value);
	out.append(";");
	SendParam(out);
}

void DashSocket::SendParam(QByteArray out, bool resend) {
	m_Sock.writeDatagram(out, m_Addr, m_Port);
	if(!out.contains("Connect") && !out.contains("GetParams") && !out.contains("Dashboard")) m_Acks.insert(out, QTime::currentTime());
	else{ 
		flaky = false;
		m_Acks.clear(); // discard old commands on reconnect
	}
//	qDebug() << "Wrote datagram: " << out;
	if(m_Acks.size() > 15 && !resend){
		//qDebug() << QString::number(m_Acks.size()) + " commands still unacknowledged";
		flaky = true;
		emit AUVNotResponding(m_Acks.size());
	}
}

void DashSocket::HandleDatagram() {
	QList<QByteArray> pairs;
	QStringList pair;
	QString type, name, val;
	while (m_Sock.hasPendingDatagrams()) {
		m_Buf.resize(m_Sock.pendingDatagramSize());
		m_Sock.readDatagram(m_Buf.data(),m_Buf.size());
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
				emit GotAUVUpdate(type, name, val);
			}
		}
	}
}

// checks for old sent datagrams that have not ben acked and resends them
void DashSocket::checkForLostDatagrams(){
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

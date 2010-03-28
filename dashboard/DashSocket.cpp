#include "DashSocket.h"
#include <QDebug>

DashSocket::DashSocket(QHostAddress addr, quint16 port) {
	m_Sock.bind(port);
	m_Addr = AUV_IP;
	m_Port = SERVER_DATA_PORT;
	QObject::connect(&m_Sock, SIGNAL(readyRead()),
					 this, SLOT(HandleDatagram()));
}

DashSocket::~DashSocket() {
}

void DashSocket::SendParam(QString key, QString value) {
	QByteArray out;
	out.clear();
	out.append(key);
	out.append("=");
	out.append(value);
	out.append(";");
	m_Sock.writeDatagram(out, m_Addr, m_Port);
	qDebug() << "Wrote datagram: " << out;
}

void DashSocket::HandleDatagram() {
	QList<QByteArray> pairs;
	QStringList pair;
	QString type, name, val;
	while (m_Sock.hasPendingDatagrams()) {
		m_Buf.resize(m_Sock.pendingDatagramSize());
		m_Sock.readDatagram(m_Buf.data(),m_Buf.size());
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


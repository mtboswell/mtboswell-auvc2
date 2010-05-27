/**
 * @file sidsocket.h
 * Class provides a SID (Simple Id/Data Format) Network Socket
 */
#ifndef __SIDSOCKET_H
#define __SIDSOCKET_H

#include <QUdpSocket>
#include <QHostAddress>
#include "config.h"

class SIDSocket : public QObject {
	Q_OBJECT
	public:
		SIDSocket(quint16 bindPort, quint16 remotePort, QHostAddress remoteAddr = QHostAddress::Broadcast, QHostAddress bindAddr = QHostAddress::Any);
		virtual ~SIDSocket();

	signals:
		void dataReceived(QString ID, QString data);
		void remoteNotResponding(int NumberOfIgnoredPackets);
		void connectionRestored();

	public slots:
		void sendSID(QString ID, QString data);
		void setRemoteAddr(QString addr);

	private slots:
		void sendDatagram(QByteArray out, bool resend = false);
		void handleDatagram();
		void checkForLostDatagrams();

	private:
		QUdpSocket m_Sock;
		QHostAddress m_remoteAddr;
		QHostAddress m_localAddr;
		quint16 m_remotePort;
		quint16 m_localPort;
		QByteArray m_Buf;
		QHash<QByteArray,QTime> m_Acks;
		QTimer m_safetyCheckTimer;
		bool m_flaky;
};

#endif //#ifndef __SIDSOCKET_H

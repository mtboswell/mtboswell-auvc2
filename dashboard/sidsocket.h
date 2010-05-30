/**
 * @file sidsocket.h
 * Class provides a SID (Simple Id/Data Format) Network Socket
 */
#ifndef __SIDSOCKET_H
#define __SIDSOCKET_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QQueue>
#include <QTimer>
#include <QTime>
#include <QHash>
#include <QStringList>

class SIDSocket : public QObject {
	Q_OBJECT
	public:
		SIDSocket(quint16 bindPort, quint16 remotePort, QHostAddress remoteAddr = QHostAddress::Broadcast, QHostAddress bindAddr = QHostAddress::Any);
		virtual ~SIDSocket();

	signals:
		/**
		 * Received a SID packet.
		 * @param ID data identifier
		 * @param data data identified by identifier
		 */
		void sidReceived(QString ID, QString data);
		/**
		 * Unused?
		 */
		void connectionRestored();
		/**
		 * May have lost some packets, sent data will be delayed by 500 ms until connection is confirmed.
		 */
		void reconnecting();
		/**
		 * Packet was not acked within AckTimeout msecs..
		 * Use this to deal with re-sending critical data.
		 * Params are last data to be not sent.
		 */
		void noAck(QString ID, QString data);
		/**
		 * Data is not getting through yet.
		 * Params are last data to be not sent.
		 */
		void remoteNotResponding(QString ID, QString data);

	public slots:
		/** 
		 * Send data to other host.
		 * @param ID data identifier
		 * @param data data
		 */
		void sendSID(QString ID, QString data);
		/**
		 * Send all data to the specified address and port.
		 */
		void setRemoteAddr(QString addr, quint16 port = 0);
		/** 
		 * Set time that we wait for data to be acknowledged on the other end.
		 * If you need low-latency, set this low.
		 * @param msec Duration of timeout, in milliseconds.
		 */
		void setAckTimeout(int msec);

	private slots:
		void sendDatagram(QByteArray out, bool resend = false);
		void sendDatagram();
		void handlePendingDatagrams();
		void processDatagram(QByteArray, QHostAddress, quint16);

	private:
		QString id(QByteArray);
		QString data(QByteArray);
		QUdpSocket m_Sock;
		QHostAddress m_remoteAddr;
		QHostAddress m_localAddr;
		quint16 m_remotePort;
		quint16 m_localPort;
		QHash<QByteArray,QTime> m_Acks;
		bool m_flaky;
		int m_AckTimeout;
		QQueue<QByteArray> m_outQueue;
};

#endif //#ifndef __SIDSOCKET_H

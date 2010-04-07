#ifndef __DASHSOCKET_H
#define __DASHSOCKET_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QtCore>
#include "../config.h"

class DashSocket : public QObject {
Q_OBJECT
public:
	DashSocket(QHostAddress addr = QHostAddress::Any, quint16 port = CLIENT_DATA_PORT);
	virtual ~DashSocket();

signals:
	void GotAUVUpdate(QString type, QString name, QString value);

public slots:
	void SendParam(QString key, QString value);
	void setRemoteAddr(QString addr);

private slots:
	void HandleDatagram();

private:
	QUdpSocket m_Sock;
	QHostAddress m_Addr;
	quint16 m_Port;
	QByteArray m_Buf;
	QList<QByteArray> m_Acks;
};

#endif //#ifndef __DASHSOCKET_H

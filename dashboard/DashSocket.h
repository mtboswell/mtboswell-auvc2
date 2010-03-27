#ifndef __DASHSOCKET_H
#define __DASHSOCKET_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QtCore>
#include "../config.h"

class DashSocket : public QObject {
Q_OBJECT
public:
	DashSocket(QHostAddress addr = QHostAddress(AUV_IP), quint16 port = SERVER_DATA_PORT);
	virtual ~DashSocket();

signals:
	void GotAUVUpdate(QString type, QString name, QString value);

public slots:
	void SendParam(QString key, QString value);

private slots:
	void HandleDatagram();

private:
	QUdpSocket m_Sock;
	QHostAddress m_Addr;
	quint16 m_Port;
	QByteArray m_Buf;
};

#endif //#ifndef __DASHSOCKET_H

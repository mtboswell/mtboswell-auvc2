#ifndef __VIDEOSOCKET_H
#define __VIDEOSOCKET_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QtCore>
//#include "../src/configloader.h"
#include <QImage>
#include <QImageReader>
#include <QThread>
#include <QString>

class VideoSocket : public QThread {
Q_OBJECT
public:
	VideoSocket(QString remoteAddr, unsigned short remotePort, unsigned short localPort, QObject* parent);
	virtual ~VideoSocket();
	void run();

signals:
	void frameReady(QImage*);

private slots:
	void readPendingDatagrams();

private:
	void processDatagram(QByteArray, QHostAddress fromAddr, quint16 fromPort);

	QUdpSocket *socket;
//	QImageReader* reader;
	QImage image;
	QByteArray imageData;
	bool validFrame;
	QByteArray SOI, EOI;
};

#endif //#ifndef __VIDEOSOCKET_H

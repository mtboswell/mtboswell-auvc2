#ifndef SERVER_H
#define SERVER_H

#include "../config.h"
#include <QUdpSocket>
#include <QThread>
#include <QTimer>
#include <QByteArray>


class server: public QThread
{
	Q_OBJECT
	public:
		server();
		
		
	signals:
		void go();
		void stop();
		void reset();
		void kill();
		void setParam(QString name, double value);
		void setInput(QString name, double value);
		
	private slots:
		void sendData();

	private:
		void processDatagram(QByteArray);
		portNumber; // 5233 = last 3 digits of UPC of aqua's aquarium album + track number of "Barbie Girl"
		QUdpSocket* socket;
		QTimer* timer;
};

#endif

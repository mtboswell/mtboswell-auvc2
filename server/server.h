#ifndef SERVER_H
#define SERVER_H

#include "../config.h"
#include "../brain/brain.h"
#include "../auv/auvtypes.h"
#include "../model/parameters.h"
#include <QUdpSocket>
#include <QThread>
#include <QTimer>
#include <QByteArray>
#include <QHostAddress>
#include <QStringList>
#include <QMutex>

class Server: public QThread
{
	Q_OBJECT
	public:
		Server(QMutex* sensorMutex);
		
		
	signals:
		void go();
		void stop();
		void reset();
		void kill();
		void calibrateDepth(double);
		void setParam(QString name, double value);
		void setInput(QString name, double value);
		void setRec(bool rec);
		void setLog(bool log);
		void whiteBalance();
	
	public slots:
		void sendSensorData(AUVSensors sens);
		void sendBrainData(ExternalOutputs_brain outs, int brainTime);
		void sendParams();
		
	private slots:
		void readPendingDatagrams();
		void doAction(QString, QString, QString);

	private:
		void processDatagram(QByteArray);
		void addDatum(QByteArray& datagram, QString type, QString name, QString value);
		QUdpSocket* socket;
		QTimer* timer;
		QHostAddress remoteHost;
		QMutex* sensorDataMutex;
};

#endif

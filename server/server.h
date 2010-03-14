/**
 * Server thread - communication layer between Brain/AUV and network
 * Author: Micah Boswell
 * Date created: 3/10/2010
 * Description: Accepts commands on a UDP port, parses them, and forwards
 * them to the appropriate signal, which should be connected to the right thread
 */

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
		// We do not actually need this mutex
		Server(QMutex* sensorMutex);
		
	signals:
		// AUV control
		void go();
		void stop();
		void reset();
		void kill();
		void calibrateDepth(double);
		void whiteBalance();
		void actuateMech(QString);
		// Brain stuff
		void setParam(QString name, double value);
		void setInput(QString name, double value);
		void setRec(bool rec);
		void setLog(bool log);
	
	public slots:
		// these get triggered from the other threads with the data the thread has
		void sendSensorData(AUVSensors sens);
		void sendBrainData(ExternalOutputs_brain outs, int brainTime);
		// sendParams() gets called when we get a GetParams command
		void sendParams();
		
	private slots:
		// readPendingDatagrams gets triggered every time the socket receives a datagram
		void readPendingDatagrams();
		// once a field is parsed, it get sent to this slot for actually doing stuff
		void doAction(QString type, QString name, QString value);

	private:
		// parse incoming data
		void processDatagram(QByteArray);
		// append a field to a datagram
		void addDatum(QByteArray& datagram, QString type, QString name, QString value);

		QUdpSocket* socket;
		// timer may be usused
		QTimer* timer;
		// the ip address to send all the data to; may be a broadcast address
		QHostAddress remoteHost;
		// this mutex is generally not used
		QMutex* sensorDataMutex;
};

#endif

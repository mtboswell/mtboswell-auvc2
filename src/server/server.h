#ifndef SERVER_H
#define SERVER_H

#include "../configloader.h"
#include "../brain/brain.h"
#include "../auv/auvtypes.h"
#include "../model/parameters.h"
#include "../version.h"
#include "sidsocket.h"
#include <QUdpSocket>
#include <QThread>
#include <QTimer>
#include <QByteArray>
#include <QHostAddress>
#include <QStringList>
#include <QMutex>
#include <QImage>
#include <QImageWriter>
#include <QNetworkInterface>

/**
 * Communication layer between Brain/AUV and network.
 * @author: Micah Boswell
 * @date 3/10/2010
 * Accepts commands on a UDP port, parses them, and forwards
 * them to the appropriate signal, which should be connected to the right thread
 */

class Server: public QThread
{
	Q_OBJECT
	public:
		/**
		 * Constructor
		 */
		Server();
		
	signals:
		// AUV control
		/**
		 * Received the "Mode=Start" command.
		 */
		void go();
		
		/**
		 * Received the "Mode=Stop" command.
		 */
		void stop();

		/**
		 * Received the "Mode=Reset" command.
		 */
		void reset();

		/**
		 * Received the "Mode=Kill" command.
		 */
		void kill();

		/**
		 * Received the "Calibrate.Depth=[value]" command.
		 * @param depth actual depth of the AUV to calibrate to.
		 */
		void calibrateDepth(double);
		/**
		 * Received the "Calibrate.WhiteBalance=once" command.
		 */
		void whiteBalance();
		/**
		 * Received the "Actuate.Mechanism=[mech]" command.
		 * @param mech Mechanism that should be actuated.
		 */
		void actuateMech(QString);
		/**
		 * Received the "Move.Camera=[x],[y]" command.
		 * @param x The horizontal camera position.
		 * @param y The vertical camera position.
		 */
		void moveCamera(double x, double y);

		void runScript(QString);
		void newScript(QString);



		// Brain stuff
		/**
		 * Set model parameter [name] to the value [value].
		 * @param name Simulink name of the parameter to be set.
		 * @param value numeric value of the parameter to be set.
		 */
		void setParam(QString name, double value);
		/**
		 * Set model input [name] to value [value].
		 * @param name Simulink name of the input to be set.
		 * @param value numeric value of the input to be set.
		 */
		void setInput(QString name, double value);


		/**
		 * Set the Record Video flag.
		 * @param rec True means start recording video, false means stop.
		 */
		void setRec(bool rec);
		/**
		 * Set the Log Data flag.
		 * @param log True means start logging data, false means stop.
		 */
		void setLog(bool log);

		void status(QString message);
	
	public slots:
		// these get triggered from the other threads with the data the thread has
		void sendSensorData(AUVSensors sens);
		void sendBrainData(ExternalOutputs_brain outs, int brainTime);
		// sendParams() gets called when we get a GetParams command
		void sendParams();
		void sendVideo();
		void selectVideoStream(int streamNumber);
		/**
		 * Send an error message to the network client.
		 * @param err Error message string.
		 */
		void sendError(QString err = "Unknown Error");
		/**
		 * Send a lower-priority status message to the network client.
		 * @param status Status message string
		 */
		void sendStatus(QString status);
		
	private slots:
		// once a field is parsed, it get sent to this slot for actually doing stuff
		void handleCmd(QString id, QString data, QHostAddress fromAddr);

	private:
		// append a field to a datagram
		void addDatum(QByteArray& datagram, QString type, QString name, QString value, bool log = false);

		SIDSocket* sidsocket;
		QUdpSocket* videoSocket;
		QFile* videoFile;
		QUdpSocket* bitmapSocket;
		// timer may be usused
		QTimer* timer;
		// the ip address to send all the data to; may be a broadcast address
		QHostAddress remoteHost;
		// this mutex is generally not used
		QMutex* sensorDataMutex;
        	QImage* videoFrame;
        	QImage* bwFrame;
        	QImage* rgbFrame;
        	QImageWriter* videoOut;
        	QImageWriter* recVideoOut;
        	QImageWriter* bitmapOut;

		//DataLogger* logger;
		
		bool recordVideo;
		bool streamRGBSecondary;
};

#endif

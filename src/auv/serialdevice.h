#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include <qextserialport.h>
#include <QString>
#include <QThread>
#include <QByteArray>
#include <QStringList>
#include <QRegExp>
#include <QTimer>
#include "../configloader.h"


/**
 * This is an abstract base class for serial devices.
 * It supports devices that send data continously, as well as devices that need to 
 * be polled periodically, and devices that just receive commands.
 */
class SerialDevice : public QThread
{
	Q_OBJECT
	public:
		/**
		 * Constructor.
		 * @param portName Name of the serial port the device is attached to.  E.g. /dev/ttyS0
		 * @param listen Start listening on the port, and call processData with each data string.
		 * @param delimiter Incoming data string separator
		 */
		SerialDevice(const QString & portName, BaudRateType baudRate,  bool listen = false, QByteArray delimiter = " ");
		~SerialDevice();


	protected:
		/**
		 * Sets port to send cmd every period msecs.
		 * @param cmd Data to be sent
		 * @param period Time period between sending each cmd, in msecs.
		 */
		void setPollCmd(QByteArray cmd, int period);
		/**
		 * Sets port to send cmd every period msecs, calls processData with result.
		 * This function is not normally used.  You most likely want to use setPollCmd() with processData().
		 * @param cmd Data to be sent
		 * @param responseLength Length of the response to be expected.
		 * @param period Time period between sending each cmd, in msecs.
		 */
		void setPollQuery(QByteArray cmd, int responseLength, int period);

		/**
		 * Sets the delimiter used to determine when the end of a data stream is received.
		 */
		void setIncomingDelimiter(QByteArray delimiter);
		/**
		 * Sets the maximum length of the incoming data stream that should be buffered before calling processData().
		 */
		void setIncomingMaxLength(int maxLength);

		QByteArray sendQuery(QByteArray data, int responseLength);
		QByteArray sendQuery(QByteArray data, QByteArray endOfResponseMarker);

	protected slots:
		// called with new data from the port
		virtual void processData(QByteArray data){QByteArray stuff(data);}
		// send data via the serial port
		void sendData(QByteArray data);

	private slots:
		// called when new data is ready on the serial port
		void onReadyRead();

		void sendPollCmd();
		void sendPollQuery();

		// open the port
		void open(QString portName, BaudRateType baud, bool listen);

		// close the port
		void close();

	private:
		// port stuff
		QextSerialPort* port;
		QByteArray* buf;
		int incomingMaxLength;

		// delimter used for incoming data
		QByteArray incomingDelimiter;

		QByteArray pollCmd;
		int pollResponseLength;

		QTimer* pollTimer;

};

#endif
		
	

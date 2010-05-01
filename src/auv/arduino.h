#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <qextserialport.h>
#include <QMap>
#include <QString>
#include <QThread>
#include <QByteArray>
#include <QStringList>
#include <QBuffer>
#include <QRegExp>

/**
 * Interface with an Arduino microcontroller running our comm driver.
 * This class takes care of reading data from the Arduino serial port in our simple format,
 * and can also send one-byte commands.
 */

class Arduino : public QThread
{
	Q_OBJECT
	public:
		/**
		 * Constructor
		 * @param portName Serial port connected to Arduino
		 */
		Arduino(const QString & portName = "");
		~Arduino();

		/**
		 * Looks for a value sent from the Arduino.
		 * This class processes data values sent from the Arduino.  Each value has
		 * an associated name.  This function returns the value corresponding to a
		 * given data field name.
		 * @param desc Name of the data field you want to retrieve.
		 * @return Value of the data field specified.  Zero if field doesn't exist.
		 */
		unsigned int getValue(const QString & desc);

		/**
		 * Send a one-byte command to the Arduino.
		 * Since an arduino has limited processing power, and it does not need to support
		 * many commands, one byte is generally sufficient.
		 * @param cmd is the byte to be sent to the Arduino.
		 */
		bool sendCmd(char cmd);

	signals:
		/**
		 * Emitted when a new data value is ready.
		 * @param field data field that has just been updated.
		 * @param value new value of that field.
		 */
		void newValueReady(QString field, unsigned int value);

	private slots:
		void onReadyRead();
		void onDsrChanged(bool status);
		void process(QByteArray data);
	private:
		QMap<QString, unsigned int> values;
		QextSerialPort* port;
		QByteArray* buf;
};

#endif /*ARDUINO_H_*/

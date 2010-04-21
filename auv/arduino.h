#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <qextserialport.h>
#include <QMap>
#include <QString>
#include <QThread>
#include <QByteArray>
#include <QBuffer>
#include <QRegExp>

class Arduino : public QThread
{
	Q_OBJECT
	public:
		Arduino(const QString & portName = "");
		~Arduino();

		unsigned int getValue(const QString & desc);
		bool sendCmd(char cmd);

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

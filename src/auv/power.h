#ifndef POWER_H_
#define POWER_H_
#include <qextserialport.h>
#include <QMap>
#include <QString>
#include <QThread>
#include <QByteArray>
#include <QStringList>
#include <QBuffer>
#include <QRegExp>

/**
 * Interface for the ASCL power boards.
 */
class Power : public QThread
{
	public:
		/**
		 * This is the constructor.  
		 * @param dev is the device file name for the desired serial 
		 * port.
		 */
		Power(const QString & portName = "");
		/**
		 * This is the destructor.
		 */
		~Power();

		/**
		 * Get the voltage data for this power supply.
		 * @return Power supply voltage, in volts.
		 */
		double getVoltage();
		/**
		 * Get the current data for this power supply.
		 * @return Power supply current, in amps.
		 */
		double getCurrent();

		/**
		 * Turn on this power switch.
		 */
		bool turnOn();

		/**
		 * Turn off this power switch.
		 * Be careful what you turn off with this!
		 */
		bool turnOff();

		/**
		 * Turn the switch on or off.
		 * @param newState the desired state of the switch (true = on).
		 */
		bool setState(bool newState);

	private slots:
		void onReadyRead();
		void process(QByteArray data);
	private:
		bool state;
		double voltage;
		double current;
		QextSerialPort* port;
};

#endif /*POWER_H_*/

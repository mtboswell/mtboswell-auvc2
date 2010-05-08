#ifndef POLOLU_H_
#define POLOLU_H_

#include <qextserialport.h>
#include <QMap>
#include <QString>
#include <QThread>
#include <QByteArray>
#include <QStringList>
#include <QBuffer>
#include <QRegExp>

/**
 * Interface for Pololu motor and servo controllers.
 * Supports multiple motor and servo controllers on one serial line.
 * Motors are number sequentially for each sequentially addressed TReX
 * motor controller.
 */

class Pololu : public QThread
{
	Q_OBJECT
	public:
		/**
		 * @param portName Serial port for pololu devices.
		 */
		Pololu(const QString & portName = "");
		~Pololu();
		bool setTrexConfig(char param, char value);
	public slots:
		void setServoParams(char servoNum, bool on, bool reverse = false, char range = 15);
		void setServoSpeed(char servoNum, char speed);
		void setServoNeutral(char servoNum, short int neutral = 3000);
		/**
		 * Sets the position of a servo (0-255 value).
		 * @param servoNum is the # of the servo to set
		 * @param position is the position to set it to
		 */
		void setServoPosition(char servoNum, unsigned char position);

		/**
		 * Sets the absolute position of the servo (500-5500).
		 * Center should be 3000
		 * @param servoNum is the servo to set
		 * @param absPos is the amount of time for the pulse width to be (500-5500)
		 */
		void setServoPosAbs(char servoNum, short int absPos);


		/**
		 * Set motor speed.
		 * @param motorNum Motor number (zero-indexed).
		 * @param motorSpeed Speed to run motor.  Range is -127 (full reverse) to 127 (full forward).
		 */
		void setMotorSpeed(int motorNum, int motorSpeed);

	private slots:
		
	private:
		QextSerialPort* port;
		/**
		 * sendCmd takes data and enqueues it to be sent
		 */
		bool sendCmd(char command, char servoNum, char data1=0, char data2=0);


};

#endif /*POLOLU_H_*/

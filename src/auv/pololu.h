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
#include "../configloader.h"

/**
 * Interface for Pololu motor and servo controllers.
 * Supports multiple motor and servo controllers on one serial line.
 * Assumes motors are numbered sequentially for each sequentially addressed TReX
 * motor controller.  For example, motors 0 and 1 are on controller 0x07 (default).
 * Motors 2 and 3 are on controller 0x08.  Motors 4 and 5 are on 0x09, etc. The
 * device address can be set via the configurator or the setTrexAddress() command.
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
		bool setTrexConfig(char device, char param, char value);

		QString getTrexSignature(char device);
		char getTrexMode(char device);
		//bool trexControl(char device);
		int getMotorCurrent(char motorNum);
		//char getTrexConfig(char device, char param);

		// emit RC or ananlog inputs periodically every msecs
		//void startTrexAutoInputMode(char device, int channel, int msecs);

		//enum TrexError { NONE, UART_ERROR, MOTOR_FAULT, MOTOR_OVERCURRENT };
		//enum UartError { TIMEOUT, FORMAT_ERROR, CRC_ERROR, FRAME_ERROR, DATA_OVERRUN, PARITY_ERROR, READ_OVERRUN, SEND_OVERRUN };

		//QHash<int, TrexError> getErrors();

		void setSaneTrexParams(char device);


		//int getAnalogInput(char inputNum);
		//int getDigitalInput(char inputNum);

	signals:
		//void trexError(char device, TrexError err);
		void trexInput(char device, int channel, char value);

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

		void setMaestroServoPos(char servoNum, short int absPos);

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

		//void setOutput(char outputNum, int output);

	private:
		QextSerialPort* port;
		/**
		 * sendCmd takes data and enqueues it to be sent
		 */
		void sendServoCmd(char command, char servoNum, char data1, char data2=0, bool maestro = false);
		void sendTrexCmd(char command, char motorNum, QByteArray data);
		QByteArray sendTrexQuery(char command, char motorNum, int responseLength, QByteArray data);


};

#endif /*POLOLU_H_*/

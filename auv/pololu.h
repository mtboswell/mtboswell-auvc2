#ifndef POLOLU_H_
#define POLOLU_H_

#include "uart.h"

/**
 * Interface for Pololu motor and servo controllers.
 * Supports multiple motor and servo controllers on one serial line.
 * Motors are number sequentially for each sequentially addressed TReX
 * motor controller.
 */

class Pololu
{
	public:
		/**
		 * @param dev Serial port for pololu devices.
		 */
		Pololu(const char* dev = 0);
		~Pololu();
		/**
		 * setPosition sets the position of a servo (0-255 value)
		 * @param servoNum is the # of the servo to set
		 * @param position is the position to set it to
		 */
		bool setPosition(int servoNum, int position);

		/**
		 * setPosAbs sets the absolute position of the servo (500-5500)
		 * @param servoNum is the servo to set
		 * @param absPos is the amount of time for the pulse width to be (500-5500)
		 */
		bool setPosAbs(int servoNum, int absPos);

		bool setTrexConfig(char param, char value);

		/**
		 * Set motor speed.
		 * @param motorNum Motor number (zero-indexed).
		 * @param motorSpeed Speed to run motor.  Range is -127 (full reverse) to 127 (full forward).
		 */
		bool setTrexSpeed(int motorNum, int motorSpeed);

	private:
		UART* port;
		char msg[7];
		int len;
		/**
		 * sendCmd takes data and enqueues it to be sent
		 */
		bool sendCmd(char command, char servoNum, char data1=0, char data2=0);


};

#endif /*POLOLU_H_*/

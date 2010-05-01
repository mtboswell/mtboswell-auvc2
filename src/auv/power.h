#ifndef POWER_H_
#define POWER_H_

#include "buffer.h"
#include "uart.h"
#include <string>
#include <map>
using std::map;
using std::string;

/**
 * Interface for the ASCL power boards.
 * @author Micah Boswell for the Virginia Tech AUVT (micah27@vt.edu)
 * @version Aug. 12, 2009
 */
class Power : public UART::UARTList
{
	public:
		/**
		 * This is the constructor.  
		 * @param dev is the device file name for the desired serial 
		 * port.
		 */
		Power(const char* dev = 0);
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

	private:
		void process(const char* data, int len);
		pthread_mutex_t dataMutex;
		bool state;
		double voltage;
		double current;
		UART* port;
		unsigned char rdbufChars[256];
		cBuffer rdbuf;
};

#endif /*POWER_H_*/

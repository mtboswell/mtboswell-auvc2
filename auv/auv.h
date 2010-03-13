/** 
 * AUV Thread - hardware/sensors interface 
 * Author: Micah Boswell (micah27@vt.edu)
 * Created: 12/11/2009
 * Description: polls hardware and emits sensor data, keeps track of hardware state, 
 * sends commands to serial ports when needed
 */

#ifndef AUV_H_
#define AUV_H_

// sensor datatypes defined in auvtypes.h
#include "auvtypes.h"
#include "../config.h"
#include "ports.h"
#include "calibration.h"
#include "imu.h"
#include "adc.h"
#include "pololu.h"
#include "power.h"
#include "mechanisms.h"
#include "../brain/brain.h"

#include <QThread>
#include <QTimer>
#include <QMutex>
#include <QProcess>
#include <QQueue>
#include <QMap>
#include <QMapIterator>
#include <iostream>
#include <string>

// possibly not needed
using namespace std;

class AUV : public QThread {

	Q_OBJECT

	public:
		// simulate was supposed to mean we shoudn't talk to the real serial ports	
		// it never got implemented and will most likely be obsolete soon
		AUV(QMutex* sensorMutex, bool hardwareOverrideDisabled = false);
		~AUV();
		
		// the setMotion api was a cool idea at one point, but we don't use it
		void setMotion(int forward, int yaw, int vertical);
		void setMotion(AUVMotion* velocity);

		// set all of the thruster speeds to 0
		void stopThrusters();

		// get data from compass and orientation sensor
		// orientation.yaw, roll, pitch
		imu_data getOrientation();
		
		// Returns Voltage of Thruster Battery pack in Volts
		double getThrusterVoltage();
		// Returns Current Draw on Thruster power supply in Amps
		double getThrusterCurrent();
		// Returns power being used by thrusters in Watts
		double getThrusterPower();
		
		// Reads the current depth from the depth sensor via the arduino.  Returns the depth in feet.  
		// Relies on calibration.h for accurate measurement
		double getDepth();
		
		// Reads the value of the external on/off switch.  Returns true for on, false for off.
		bool getGo();
		
		
	public slots:
		// Standard control levels
		void goAUV();
		void stop();
		void reset();
		void kill();

		// set thruster speeds
		void setThrusters(signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]);
		
		// Sets mode based on external switch. Not sure where this is called from.
		void externalControl();

		// Inputs from Brain (thruster speeds, etc.)
		void inputFromBrain(ExternalOutputs_brain inputs, int brainTime);

		// Calibrate depth sensor with actual depth.
		void setActualDepth(double depth = 0);

		// Starts the white-balance routine.  Takes 3 seconds to finish.
		void autoWhiteBalance();

		// runs the appropriate mechanism script to activate a given mechanism
		void activateMechanism(QString mech);
		void activateMechanism();

		// will be deprecated soon, maybe
		void look(cameraPosition pos);
		// use this instead
		void look(float x, float y);

		// Move a servo to a given position.  Used for actuating mechanisms.
		void moveServo(int servo, int position);
		void moveServo();
		
	signals:
		void sensorUpdate(AUVSensors data);
		void modelInputs(ExternalInputs_brain inputs);
		void hardwareOverride();
		
	protected:
		// Thread stuff.  Gets called from start()
		void run();
		
	private slots:
		void readSensors();
		// Turn off automatic white balancing (i.e. hold current setting). Gets called by autoWhiteBalance() 3s or so after it turns on automatic white balancing.
		void finishWhiteBalance();

	private:
		// checks sensors periodically
		QTimer *sensorTimer;
		// does nothing
		QTimer *wbTimer;
		// handles white balance app (v4ctl)
		QProcess* wbProc;
		// mutex, duh
		QMutex *dataMutex;

		// Hardware interfaces
		ADC* adc;
		IMU* imu;
		Pololu* pControllers;
		Power* thrusterPower;
		
		AUVSensors data;
		
		// this should be deprecated soon
		int stepTime;
		
		QQueue<QString> posQueue;
		QQueue<QString> mechQueue;
};

#endif /*AUV_H_*/

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
#include <iostream>
#include <string>

// possibly not needed
using namespace std;

class AUV : public QThread {

	Q_OBJECT

	public:
		// simulate was supposed to mean we shoudn't talk to the real serial ports	
		// it never got implemented and will most likely be obsolete soon
		AUV(bool simulate, QMutex* sensorMutex);
		~AUV();
		
		// the setMotion api was a cool idea at one point, but we don't use it
		void setMotion(int forward, int yaw, int vertical);
		void setMotion(AUVMotion* velocity);

		// set thruster speeds
		void setThrusters(signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]);

		// set all of the thruster speeds to 0
		void stopThrusters();

		// will be deprecated soon, maybe
		void look(cameraPosition pos);
		// use this instead
		void look(float x, float y);

		// runs the appropriate mechanism script
		void activateMechanism(mechanism mech);
	
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
		void goAUV();
		void stop();
		void reset();
		void kill();
		void externalControl();
		void inputFromBrain(ExternalOutputs_brain inputs, int brainTime);
		void setActualDepth(double depth = 0);
		void autoWhiteBalance();
		
	signals:
		void sensorUpdate(AUVSensors data);
		void modelInputs(ExternalInputs_brain inputs);
		
	protected:
		void run();
		
	private slots:
		void readSensors();
		void finishWhiteBalance();
		void moveServo(int servo, int position);

	private:
		QTimer *sensorTimer;
		QTimer *goTimer;
		QTimer *wbTimer;
		QProcess* wbProc;
		QMutex *dataMutex;
		ADC* adc;
		IMU* imu;
		Pololu* pControllers;
		Power* thrusterPower;
		
		AUVSensors data;
		
		int stepTime;


};

#endif /*AUV_H_*/

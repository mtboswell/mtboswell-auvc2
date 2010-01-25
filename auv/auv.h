/* 
 * This file represents the AUV interface that all controlling code interacts with/uses to control the AUV
 * Author: Micah Boswell (micah27@vt.edu)
 * Date: 12/11/2009
 */

#ifndef AUV_H_
#define AUV_H_

#include "auvtypes.h"
#include "ports.h"
#include "calibration.h"
#include "imu.h"
#include "adc.h"
#include "pololu.h"
#include "power.h"
#include "../brain/brain.h"

#include <QThread>
#include <QTimer>
#include <QMutex>
#include <iostream>
#include <string>

using namespace std;

class AUV : public QThread {

	Q_OBJECT

	public:
	
		AUV();
		~AUV();
		
		void setMotion(int forward, int yaw, int vertical);
		void setMotion(AUVMotion* velocity);
		// set thruster speeds
		void setThrusters(signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]);
		// set all of the thruster speeds to 0
		void stopThrusters();
		void look(cameraPosition pos);
		//void look(int x, int y);
		void dropLeft();
		void dropRight();
	
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
		void inputFromBrain(ExternalOutputs_brain inputs);
		void setActualDepth(double depth = 0);
		
	signals:
		void sensorUpdate(AUVSensors data);
		void modelInputs(ExternalInputs_brain inputs);
		
	protected:
		void run();
		
	private slots:
		void readSensors();

	private:
		QTimer *sensorTimer;
		QTimer *goTimer;
		QMutex *dataMutex;
		ADC* adc;
		IMU* imu;
		Pololu* pControllers;
		Power* thrusterPower;
		
		AUVSensors data;
		
		int stepTime;


};

#endif /*AUV_H_*/

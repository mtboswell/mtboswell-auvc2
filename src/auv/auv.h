#ifndef AUV_H_
#define AUV_H_

/**
 * \defgroup AUV Vehicle Interfaces
 */

// sensor datatypes defined in auvtypes.h
#include "../state.h"
#include "../configloader.h"
#include "ports.h"
#include "calibration.h"
#include "qwebcam.h"
#include "microstrain.h"
#include "os5000.h"
#include "arduino.h"
#include "pololu.h"
#include "power.h"
#include "lcd.h"
#include "mechanisms.h"
#include "../brain/brain.h"

#include <QThread>
#include <QTimer>
#include <QMutex>
#include <QProcess>
#include <QQueue>
#include <QMap>
#include <QMapIterator>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <string>

// possibly not needed
using namespace std;

/** 
 * Hardware/sensors interface.
 * Polls hardware and emits sensor data, keeps track of hardware state, 
 * sends commands to serial ports when needed
 * \ingroup AUV
 */

class AUV : public QThread {

	Q_OBJECT

	public:
		/**
		 * Constructor.
		 * @param sensorMutex Mutex to protect sensor data?
		 * @param hardwareOverrideDisabled If set to true, the hardware on/off switch will have no effect.
		 */
		AUV(QMutex* sensorMutex, bool hardwareOverrideDisabled = false);
		~AUV();
		
		// the setMotion api was a cool idea at one point, but we don't use it
		void setMotion(int forward, int yaw, int vertical);
		void setMotion(AUVMotion* velocity);

		/**
		 * Set all of the thruster speeds to 0.
		 */
		void stopThrusters();

		/**
		 * Get orientation data from compass and orientation sensor.
		 * orientation.yaw, roll, pitch
		 * @return imu_data struct containing acceleration and compass data for all 3 axes.
		 */
		imu_data getOrientation();
		/**
		 * Get current compass heading.
		 * If you don't need all of the AHRS data, this returns only the yaw, or heading.
		 * @return Heading, in degrees from North.
		 */
		double getHeading();
		
		/**
		 * Returns Voltage of Main Battery pack in Volts
		 */
		double getMainVoltage();
		/**
		 * Returns Current Draw on Main power supply in Amps
		 */
		double getMainCurrent();
		/**
		 * Returns power being used by main supply in Watts
		 */
		double getMainPower();


		/**
		 * Returns Voltage of Thruster Battery pack in Volts
		 */
		double getThrusterVoltage();
		/**
		 * Returns Current Draw on Thruster power supply in Amps
		 */
		double getThrusterCurrent();
		/**
		 * Returns power being used by thrusters in Watts
		 */
		double getThrusterPower();
		
		/**
		 * Reads the current depth from the depth sensor via the arduino.
		 * Relies on calibration.h for accurate measurement.
		 * @return the depth in feet.  
		 */
		double getDepth();
		
		/**
		 * Reads the value of the external on/off switch.  
		 * @return true for on, false for off.
		 */
		bool getGo();
		
		
	public slots:
		void messageIn(QString, QString);
		void sendSensorData(AUVSensors sens);
		// Standard control levels
		/**
		 * Turn on the thrusters and start accepting commands.
		 */
		void goAUV();
		/**
		 * Stop the thrusters and ignore commands until next go.
		 * This is the "soft" kill that is used to stop the AUV via software.
		 */
		void stop();
		/**
		 * Reset the AUV hardware after a hard kill.
		 */
		void reset();
		/**
		 * Cut power to moving parts.
		 * Generally only used in case of leaks, since "stop()" will
		 * almost always be sufficient to bring the AUV to a stop.
		 */
		void kill();

		/**
		 * Set individual thruster speeds.
		 * @param thrusterSpeeds Array of speed values for the thrusters.
		 * The array index corresponds to the sequential numbering of the 
		 * motor controller outputs.
		 */
		void setThrusters(signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]);
		void setThrusters(double thrusterSpeeds[NUMBER_OF_THRUSTERS]);
		
		// Sets mode based on external switch. Not sure where this is called from.
		void externalControl();

		// Inputs from Brain (thruster speeds, etc.)
		void inputFromBrain(ExternalOutputs_brain inputs);

		/**
		 * Calibrate depth sensor with actual depth.
		 * @param depth Actual depth of the AUV now.
		 */
		void setActualDepth(double depth = 0);

		/**
		 * Starts the camera white-balance routine.
		 * Takes 3 seconds to finish.
		 */
		void autoWhiteBalance();

		/**
		 * Runs the appropriate mechanism script to activate a given mechanism.
		 * @see mechanisms.h
		 * @param mech Mechanism to actuate.
		 */
		void activateMechanism(QString mech);

		// will be deprecated soon, maybe
		void look(cameraPosition pos);
		// use this instead
		/**
		 * Turn camera to specified coordinates.
		 * @param x horizontal position of camera gimbal.
		 * @param y vertical position of camera gimbal.
		 */
		void look(double x, double y);

		// Move a servo to a given position.  Used for actuating mechanisms.
		void moveServo(int servo, int position);
		void moveServo();

		/**
		 * Run a script that describes motions for the AUV to perform.
		 * @param scriptFile filename of script to load and run.
		 */
		void runScriptedMotion(QString scriptFile);

		void statusMessage(QString message);

		void statusField(QString name, QString msg);
		
	signals:
		void messageOut(QString, QString);
		/**
		 * Sensor data is available for processing.
		 * @param data sensor data in an AUVSensors struct.
		 */
		void sensorUpdate(AUVSensors data);
		void cameraFrame(QImage immy);
		void cameraFrame(QPixmap pixy);
		// Deprecated
		void setControllers(ExternalInputs_brain inputs);
		/**
		 * A script needs to set an input of the Brain to use the
		 * closed-loop controllers.
		 * @param name Brain input name
		 * @param value Brain input value
		 */
		void setBrainInput(QString, double);
		void hardwareOverride();
		/**
		 * Send a status message.
		 */
		void status(QString);
		/**
		 * Send an error message.
		 */
		void error(QString);
		
	protected:
		// Thread stuff.  Gets called from start()
		void run();
		
	private slots:
		void readSensors();
		// Turn off automatic white balancing (i.e. hold current setting). Gets called by autoWhiteBalance() 3s or so after it turns on automatic white balancing.
		void finishWhiteBalance();
		void activateMechanism();
		void doScriptAction();
		void setControllers(char desiredSpeed = -128, double desiredHeading = -1, double desiredDepth = -1, char desiredStrafe = -128);
		void releaseControllers();
		void runScriptedMotion();

	private:
		// checks sensors periodically
		QTimer *sensorTimer;
		// does nothing
		QTimer *wbTimer;
		// handles white balance app (v4ctl)
		QProcess* wbProc;
		// mutex, duh
		QMutex *dataMutex;

		enum compassTypes {MICROSTRAIN, OCEANSERVER5000} compass;

		// Hardware interfaces
		Arduino* arduino;
		Microstrain* microstrain;
		OS5000* os5000;
		Pololu* pControllers;
		Power* thrusterPower;
		Power* mainPower;
		LCD* statusLcd;
		QWebCam* camera;
		
		AUVSensors data;
		
		// this should be deprecated soon
		int stepTime;
		
		QQueue<QString> posQueue;
		QQueue<QString> mechQueue;
		QQueue<QString> scriptQueue;
		QQueue<QString> actionQueue;

		QStringList states;
};

#endif /*AUV_H_*/

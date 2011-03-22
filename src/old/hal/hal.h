#ifndef HAL_H_
#define HAL_H_

/**
 * \defgroup HAL Hardware Abstraction Layer Vehicle Interfaces
 */

// sensor datatypes defined in datatypes.h
#include "../state.h"
#include "../configloader.h"

#include <QThread>
#include <QTimer>
#include <QMutex>
#include <QProcess>
#include <QQueue>
#include <QMap>
#include <QMapIterator>
#include <iostream>
#include <string>

/** 
 * Hardware/sensors interface.
 * Polls hardware and emits sensor data, keeps track of hardware state, 
 * sends commands to serial ports when needed
 * \ingroup HAL
 */

class HAL : public QObject {

	Q_OBJECT

	public:
		/**
		 * Constructor.
		 */
		HAL();
		~HAL();


		struct SensorInfo {
			enum type{STATE,ENV,META};
			QMap<QString, QString> dataAvailable; // id,units 
			// data IDs: X,Y,Z,XRate,YRate,ZRate,XAcc,YAcc,ZAcc,Roll,Pitch,Yaw,RollRate,PitchRate,YawRate,RollAcc,PitchAcc,YawAcc,Temp,Light,deltaTime,clockTime,MagX,MagY,MagZ,deltaX,deltaY,deltaZ,
			// units: ft, ft/s, ft/s^2, deg, rad, deg/s, rad/s, degF, sec, millisec, gauss, etc.
			QMap<QString, double> dataAccuracy; // id, accuracy

		};
		struct ThrusterInfo {
			QVector3D effectOnXYZ;  // assuming symmetric thrusters; units are force on given (positive) axis at full (positive) throttle
			QVector3D effectOnRollPitchYaw;
			double responseTime;
		};
		struct cameraInfo {
			double whiteLevel;
			QImage fieldOfView; // ??
		};

		QMap<double, double> getData(QString dataID); // QMap: value, accuracy

		QMap<QString, SensorInfo> getSensorInfo(); // QMap: name, info
		QMap<QString, ThrusterInfo> getThrusterInfo(); // QMap: name, info
		QStringList getMechanismList();

		QMap<QString, double> getSensorData(QString sensor);
		void setThruster(QString name, double value);  // value = -1.0 to 1.0

		/**
		 * Set all of the thruster speeds to 0.
		 */
		virtual void stopThrusters();

		/**
		 * Get orientation data from compass and orientation sensor.
		 * orientation.yaw, roll, pitch
		 * @return imu_data struct containing acceleration and compass data for all 3 axes.
		 */
		virtual imu_data getOrientation(int sensorIndex);
		/**
		 * Get current compass heading.
		 * If you don't need all of the AHRS data, this returns only the yaw, or heading.
		 * @return Heading, in degrees from North.
		 */
		virtual double getHeading();
		
		/**
		 * Returns Information about the main battery packs and power supply 
		 */
		virtual power_data getMainPowerInfo();

		/**
		 * Returns Information about the actuator battery packs and power supply 
		 */
		virtual power_data getActuatorPowerInfo();

		/**
		 * Reads the current depth from the depth sensor.
		 * @return the depth in feet.  
		 */
		virtual double getDepth();
		
		/**
		 * Reads the value of the external on/off switch.  
		 * @return true for on, false for off.
		 */
		virtual bool getGo();
		
		
	public slots:
		// Standard control levels
		/**
		 * Turn on the thrusters and start accepting commands.
		 */
		virtual void start();
		/**
		 * Stop the thrusters and ignore commands until next go.
		 * This is the "soft" kill that is used to stop the vehicle via software.
		 */
		virtual void stop();
		/**
		 * Reset the vehicle hardware after a hard kill.
		 */
		virtual void reset();
		/**
		 * Cut power to moving parts.
		 * Generally only used in case of leaks, since "stop()" will
		 * almost always be sufficient to bring the vehicle to a stop.
		 */
		virtual void kill();

		/**
		 * Set individual thruster speeds.
		 * @param thrusterSpeeds Array of speed values for the thrusters.
		 * The array index corresponds to the sequential numbering of the 
		 * motor controller outputs.
		 */
		virtual void setThrusters(double thrusterSpeeds[NUMBER_OF_THRUSTERS]);
		
		// Sets mode based on external switch. Not sure where this is called from.
		void externalControl();

		// Inputs from Brain (thruster speeds, etc.)
		virtual void inputFromBrain(ExternalOutputs_brain inputs);

		/**
		 * Calibrate depth sensor with actual depth.
		 * @param depth Actual depth of the vehicle now.
		 */
		virtual void setActualDepth(double depth = 0);

		/**
		 * Starts the camera white-balance routine.
		 * Takes 3 seconds to finish.
		 */
		virtual void autoWhiteBalance();

		/**
		 * Runs the appropriate mechanism script to activate a given mechanism.
		 * @see mechanisms.h
		 * @param mech Mechanism to actuate.
		 */
		virtual void activateMechanism(QString mech);

		// use this instead
		/**
		 * Turn camera to specified coordinates.
		 * @param x horizontal position of camera gimbal.
		 * @param y vertical position of camera gimbal.
		 */
		virtual void look(double x, double y);

		/**
		 * Run a script that describes motions for the vehicle to perform.
		 * @param scriptFile filename of script to load and run.
		 */
		virtual void runScriptedMotion(QString scriptFile);

		// for displaying messages on the LCD
		virtual void statusMessage(QString message);

		// for displaying data on the LCD
		virtual void statusField(QString name, QString msg);
		
	signals:
		/**
		 * Sensor data is available for processing.
		 * @param data sensor data in an AUVSensors struct.
		 */
		void sensorUpdate(AUVSensors data);

		/**
		 * A script needs to set an input of the Brain to use the
		 * closed-loop controllers.
		 * @param name Brain input name
		 * @param value Brain input value
		 */
		void setBrainInput(QString, double);

		// emitted (continuously?) when the hardware switch is turned off
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
		
		AUVSensors data;
		
		// this should be deprecated soon
		int stepTime;
		
		QQueue<QString> posQueue;
		QQueue<QString> mechQueue;
		QQueue<QString> scriptQueue;
		QQueue<QString> actionQueue;

		QStringList states;
};

#endif /*HAL_H_*/

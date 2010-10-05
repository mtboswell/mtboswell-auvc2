#ifndef AUV_STATE
#define AUV_STATE
#include <QImage>
#include <QString>
#include <QMap>
#include <QMutex>
#include "auv/auvtypes.h"

#define NUMBER_OF_THRUSTERS 4
#define NO_OF_IR_SENSORS 1
#define SIZE_OF_MAESTRO 12

/// Datatype for 3D vectors, should use QVector3D instead
typedef struct{
	double x, y, z;
} axes;

/// Data from targeting system about identified objects
struct targetData {
	bool found;
	int progressPercentage;
	int x, y;   //  position (for visual tracking)
	int distance;	    //  distance (for buoy/window/pinger)
	int angle;	    //  orientation (for path/bin)
	int heading;	    //  heading (for pinger)
};


/**
 * Data container to contain data from the Microstrain 3DM-GX1.
 */
typedef struct
 {
 	// misc comm data
	 int command, tmticks, chksum;
	 /**
	  * Local magnetic declination
	  */
	 double magDecl;					// local magnetic declination
	 double roll;
	 double pitch;
	 double yaw;		// orientation
	 double rollrate;
	 double pitchrate;
	 double yawrate;	// angular rates
	 double rollacc;
	 double pitchacc;
	 double yawacc;		// accelerations
	 // deprecated:
	 int update; //1 if not yet given to the user, 0 if already given
 } AHRSdata;

/* defined in auvtypes.h - uncomment when we get rid of that file
typedef struct
{
	double power;
	double voltage;
	double current;
	bool state;
} powerData;
*/

/**
 * Sensor Data - from the HAL.
 * There are two ways to deal with this data, both shown here.
 */
/// old way:
struct sensorData {
	AHRSdata ahrs;
	double depth;
	QImage fwdCamera, downCamera;
	bool goSwitch;
	powerData mainPower;
	powerData thrusterPower;
	int irSensors[NO_OF_IR_SENSORS];
};
/// new way?
struct sensor{
	QString ID;
	QMap<double, double> values;
};

/** 
 * Represents the current position and other physical properties of the vehicle.
 * The coordinate system is absolute, with 0,0,0 being the AUV start or tare point.
 * Remember that +Z is down, +Y is right, +X is forward.
 */
struct physicalState {
	double roll, pitch, yaw;
	double rollRate, pitchRate, yawRate;
	double rollAcc, pitchAcc, yawAcc;
	double xPos, yPos, zPos;
	double xSpeed, ySpeed, zSpeed;
	double xAccel, yAccel, zAccel;
};

struct actuatorData {
	double thrusters[NUMBER_OF_THRUSTERS];
	int mechs[NUMBER_OF_MECHANISMS];
};

/**
 * AUV_State is the main shared dataset for all of the modules.
 */
struct AUV_State {
	/// Supervisor outputs
	QMutex supervisorMutex; // for supervisor
	enum status {STOPPED, RUNNING, KILLED};
	enum controlSource {DIRECTOR, RC};

	/// Director outputs
	QMutex directorMutex;
	QString currentTask;
	QString currentAction;
	QString currentTarget;
	QString currentCommand;

	/// Targeting outputs
	QMutex targeterMutex;
	struct targetData targetingResults;

	/// State estimator outputs
	QMutex stateMutex;
	struct physicalState currentState;

	/// Actor/Controllers output
	QMutex actorMutex;
	struct controlsData desiredActions;

	/// HAL outputs
	QMutex HALmutex;
	// new way?
	QList<sensor> sensors; // doesn't include cameras
	QImage fwdCam, downCam;
	// old way
	struct sensorData sensors; // includes cameras
	struct actuatorData actuators;
};

#endif

#ifndef AUV_STATE
#define AUV_STATE
#include <QImage>
#include <QString>
#include <QMap>
#include "auv/auvtypes.h"

#define NUMBER_OF_THRUSTERS 4
#define NO_OF_IR_SENSORS 1
#define SIZE_OF_MAESTRO 12

struct axes {
	double x, y, z;
};

struct targetData {
	bool found;
	int progressPercentage;
	int x, y;   //  position (for visual tracking)
	int distance;	    //  distance (for buoy/window/pinger)
	int angle;	    //  orientation (for path/bin)
	int heading;	    //  heading (for pinger)
};


/**
 * Data container to contain data from an AHRS, such as the Microstrain 3DM-GX1.
 */
typedef struct
 {
	 int command, tmticks, chksum;
	 /**
	  * Local magnetic declination
	  */
	 double magDecl;					// local magnetic declination
	 /**
	  * Roll angle of the vehicle
	  */
	 double roll;
	 /**
	  * Pitch angle of the vehicle
	  */
	 double pitch;
	 /**
	  * Yaw, or Heading, measured from North (0).
	  */
	 double yaw;		// orientation
	 /**
	  * Angular rate of rotation around the roll axis
	  */
	 double rollrate;
	 /**
	  * Angular rate of rotation around the pitch axis
	  */
	 double pitchrate;
	 /**
	  * Angular rate of rotation around the yaw axis
	  */
	 double yawrate;	// angular rates
	 /**
	  * Acceleration along the roll axis
	  */
	 double rollacc;
	 /**
	  * Acceleration along the pitch axis
	  */
	 double pitchacc;
	 /**
	  * Acceleration along the yaw axis
	  */
	 double yawacc;		// accelerations
	 int update; //1 if not yet given to the user, 0 if already given
 } AHRSdata;

/*
typedef struct
{
	double power;
	double voltage;
	double current;
	bool state;
} powerData;
*/

struct sensorData {
	AHRSdata ahrs;
	double depth;
	QImage fwdCamera, downCamera;
	bool goSwitch;
	powerData mainPower;
	powerData thrusterPower;
	int irSensors[NO_OF_IR_SENSORS];
};

struct physicalState {
	double roll, pitch, yaw;
	double rollRate, pitchRate, yawRate;
	double xPos, yPos, zPos;
	double xSpeed, ySpeed, zSpeed;
	double xAccel, yAccel, zAccel;
};

struct actuatorData {
	double thrusters[NUMBER_OF_THRUSTERS];
	int servos[SIZE_OF_MAESTRO];
};

struct AUV_State {
	enum status {STOPPED, RUNNING, KILLED};
	enum controlSource {DIRECTOR, RC};
	QString currentTask;
	QString currentAction;
	QString currentTarget;
	QString currentCommand;
	struct targetData targetingResults;
	struct physicalState currentState;
	struct physicalState desiredState;
	// Mechanism states (from HAL)
	struct sensorData sensors;
	struct actuatorData actuators;
	QMap<QString, double> params; // Module.paramname = value
};

#endif

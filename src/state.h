#ifndef AUV_STATE
#define AUV_STATE
#include <QImage>
#include <QString>
#include <QMap>
#include <QMutex>
#include "auv/auvtypes.h"

#define NUMBER_OF_THRUSTERS 4

/// Data from targeting system about identified objects
struct targetData {
	QMutex targeterMutex;
	bool found;
	int progressPercentage;
	int x, y;   //  position (for visual tracking)
	int distance;	    //  distance (for buoy/window/pinger)
	int angle;	    //  orientation (for path/bin)
	int heading;	    //  heading (for pinger)
};


/**
 * Sensor Data - from the HAL.
 */
struct sensor{
	QString ID;
	QMap<double, double> values; // value, certainty
};
struct HALdata {
	QMutex HALmutex;
	QList<sensor> sensors;
	QImage fwdCam, downCam;
	double thrusters[NUMBER_OF_THRUSTERS];
	QMap<QString, bool> mechs; // name, triggered state
};

/** 
 * Represents the current position and other physical properties of the vehicle.
 * The coordinate system is absolute, with 0,0,0 being the AUV start or tare point.
 * Remember that +Z is down, +Y is right, +X is forward.
 */
struct physicalState {
	QMutex stateMutex;
	enum coordinates {LOCAL, GLOBAL};
	QVector3D rotPos, rotRate, rotAcc; // roll,pitch,yaw
	QVector3D linPos, linRate, linAcc; // x,y,z
};

struct directorData {
	QMutex directorMutex;
	QString currentTask;
	QString currentAction;
	QString currentTarget;
	QString currentCommand;
};

struct actorData {
	QMutex actorMutex;
};

struct supervisorData {
	QMutex supervisorMutex; // for supervisor
	enum status {STOPPED, RUNNING, KILLED};
	enum controlSource {DIRECTOR, RC};
};


/**
 * AUV_State is the main shared dataset for all of the modules.
 */
struct AUV_State {
	/// Supervisor outputs
	struct supervisorData supervisor;

	/// Director outputs
	struct directorData direction;

	/// Targeting outputs
	struct targetData targetingResults;

	/// State estimator outputs
	struct physicalState physState;

	/// Actor/Controllers output
	struct actorData desiredActions;

	/// HAL outputs
	// old way
	struct HALdata sensors; // includes cameras

	bool simulate;
};

#endif

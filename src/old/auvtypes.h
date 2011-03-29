
#include "sal/sal.h"
struct target {
	QString targetID;
	enum type { VISUAL, ACOUSTIC }
	int expectedDepth;
        QColor color;
	//shape??
};


/// a value from a sensor
/// \ingroup HAL
struct sensorValue{
	QString datumID;
	QString sensorID;
	QVariant value;
	QTime timestamp;
};
qRegisterMetaType<sensorValue>("SensorValue");


/// Axes that a thruster can act upon
/// \ingroup HAL
typedef enum axes {posX,posY,posZ,posROLL,posPITCH,posYAW,negX,negY,negZ,negROLL,negPITCH,negYAW}; // does this work?


/** 
 * Represents the current position and other physical properties of the vehicle.
 * The coordinate system is absolute, with 0,0,0 being the AUV start or tare point.
 * Remember that +Z is down, +Y is right, +X is forward.
 * \ingroup State
 */
struct physicalState {
	QReadWriteLock stateLock;
	enum coordinates {LOCAL, GLOBAL};
	QVector3D rotPos, rotRate, rotAcc; // roll,pitch,yaw
	QVector3D linPos, linRate, linAcc; // x,y,z
};



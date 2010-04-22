#ifndef AUV_TYPES_
#define AUV_TYPES_

#include "imu.h"

#define NUMBER_OF_THRUSTERS 4

/**
 * Status of the AUV hardware/thrusters.
 * READY = Just started or reset
 * RUNNING = Thrusters accepting commands
 * PAUSED = Thrusters stopped, waiting for go
 * KILLED = Thrusters might not have power, need to reset before continuing.
 * \ingroup AUV
 */
enum auvStatus {READY, RUNNING, PAUSED, KILLED};
enum cameraPosition {FORWARD, UP, DOWN, LEFT, RIGHT, UNKNOWN};

/**
 * Container for data from a power supply.
 * \ingroup AUV
 */
typedef struct
{
	double power;
	double voltage;
	double current;
	bool state;
} powerData;

/**
 * Container for data representing the AUV state.
 * Contains all sensor data and AUV actuator states.
 * \ingroup AUV
 */
typedef struct {
	/**
	 * Current operating mode of the AUV.
	 */
	auvStatus status;
	/**
	 * Current orientation of the vehicle
	 * @see imudata.h
	 */
	imu_data orientation;
	/**
	 * Current depth of the vehicle, in feet.
	 */
	double depth;
	/**
	 * Current commanded speeds of the thrusters.
	 * Values range from -127 to 127.
	 */
	signed char thrusterSpeeds[NUMBER_OF_THRUSTERS];
	powerData thrusterPower;
	cameraPosition camera;
	double cameraX;
	double cameraY;
	bool droppedLeft;
	bool droppedRight;
	/**
	 * Whether or not the external switch is active.
	 */
	bool manualOverrideDisabled;
} AUVSensors;

/**
 * Old motion encapsulation method.
 * \ingroup AUV
 */
typedef struct
{
	int forward;
	int yaw;
	int vertical;
} AUVMotion;

#endif

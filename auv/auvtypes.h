#ifndef AUV_TYPES_
#define AUV_TYPES_

#include "imu.h"

#define NUMBER_OF_THRUSTERS 4

enum auvStatus {READY, RUNNING, PAUSED, KILLED};
enum cameraPosition {FORWARD, UP, DOWN, LEFT, RIGHT, UNKNOWN};

typedef struct
{
	double power;
	double voltage;
	double current;
	bool state;
} powerData;

typedef struct {
	auvStatus status;
	imu_data orientation;
	double depth;
	signed char thrusterSpeeds[NUMBER_OF_THRUSTERS];
	powerData thrusterPower;
	cameraPosition camera;
	float cameraX;
	float cameraY;
	bool droppedLeft;
	bool droppedRight;
	bool manualOverrideDisabled;
} AUVSensors;


typedef struct
{
	int forward;
	int yaw;
	int vertical;
} AUVMotion;

#endif

#ifndef CALIB_H_
#define CALIB_H_

// depthZero = sensor reading at surface
static volatile int depthZero = 89;

//#define DEPTHSCALE 6.125 
// 116 = 4ft - taken in Kona Kai Pool in 2009

// depthScale = sensor value change per foot of depth
static volatile double depthScale = 7.500; 

#define CAMERA_FRAME_WIDTH 640
#define CAMERA_FRAME_HEIGHT 480

// Camera Gimbal calibration
#define GIMBAL_X_SERVO 1
#define GIMBAL_X_ZERO 2300
#define GIMBAL_X_MAX 1500
#define GIMBAL_X_MIN 3500

#define GIMBAL_Y_SERVO 0
#define GIMBAL_Y_ZERO 2850
#define GIMBAL_Y_MAX 4200
#define GIMBAL_Y_MIN 2000

#endif /*CALIB_H_*/
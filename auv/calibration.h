#ifndef CALIB_H_
#define CALIB_H_

static volatile int depthZero = 89;
//#define DEPTHSCALE 6.125 
// 116 = 4ft - taken in Kona Kai Pool in 2009
static volatile int depthScale = 7.500; 

#define CAMERA_FRAME_WIDTH 640
#define CAMERA_FRAME_HEIGHT 480

#endif /*CALIB_H_*/

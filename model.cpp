#include "model.h"
#include "auv/auvtypes.h"
#include "auv/calibration.h"
#include "auv/camread.h"
#include <iostream>
#include <cstdlib>
#include <QDebug>
#include <QTime>

Model::Model(QMutex* mutex){
	
	// 100ms = 10Hz rate
	// 160ms = 6.25Hz
	stepTime = 160;

  /* Initialize model */
	qDebug("Initializing Brain");
	brain_initialize();
	  
	modelMutex = mutex;
  
	//qDebug("Setting Timer");
	  modelTimer = new QTimer(this);
	  
	connect(modelTimer, SIGNAL(timeout()), this, SLOT(rt_OneStep()));
	  
  
	//qDebug("Allocating Framebuffer");
	// Initialize framebuffer and start video capture 
	myframe.y = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT);
	myframe.cb = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT/4);
	myframe.cr = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT/4);
	//qDebug("Done");

  
}

Model::~Model(){
//	delete modelTimer;
	qDebug("Shutting Down Brain");
	camread_close();
	wait();
}

void Model::run(){
	modelTimer->start(stepTime);
	exec();
}

/* Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void Model::rt_OneStep(void)
{
	//qDebug("Stepping Model");

	/* Disable interrupts here */
	modelMutex->lock();

	/* Check for overrun */
	if (OverrunFlag++) {
	qDebug("Overrun!!");
	rtmSetErrorStatus(brain_M, "Overrun");
	return;
	}

	/* Save FPU context here (if necessary) */
	/* Re-enable timer or interrupt here */
	/* Set model inputs here */

	// Measure step time
//	QTime t;
//	 t.start();

	/* Step the model */
	brain_step();
	//qDebug("Model Stepped");
//	qDebug("Time elapsed: %d ms", t.elapsed());

	/* Get model outputs here */

	/* Indicate task complete */
	OverrunFlag--;

	/* Disable interrupts here */
	/* Restore FPU context here (if necessary) */
	/* Enable interrupts here */
	modelMutex->unlock();
	//qDebug("Model Unlocked, sending output");
	emit outputReady(brain_Y);
	//qDebug("Output Sent");
}
		
		
void Model::updateSensorsInput(AUVSensors values){
  	QMutexLocker locker(modelMutex);
	
	brain_U.CurrentDepth = values.depth;                 /* '<Root>/CurrentDepth' */
	brain_U.CurrentHeading = values.orientation.yaw;               /* '<Root>/CurrentHeading' */
	brain_U.Status = values.status;                       /* '<Root>/Status' */	
	
	// Transfer video frame into MATLAB, swapping buffers 
	camread_getframe(myframe);
	SwappyCopy(brain_U.Y, (unsigned char*)myframe.y, 640, 480);
	SwappyCopy(brain_U.Cb, (unsigned char*)myframe.cb, 320, 240);
	SwappyCopy(brain_U.Cr, (unsigned char*)myframe.cr, 320, 240);
	
	
	/* Values:
	auvStatus status;
	imu_data orientation;
	double depth;
	signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]
	powerData thrusterPower;
	cameraPosition camera;
	bool droppedLeft;
	bool droppedRight;
	*/
}

void Model::setState(int state){
	// TODO: set model state input
}

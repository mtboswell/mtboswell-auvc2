#include "model.h"
#include "../auv/auvtypes.h"
#include "../auv/calibration.h"
#include "../configloader.h"
#include <iostream>
#include <cstdlib>
#include <QDebug>
#include <QTime>

Model::Model(QMutex* mutex){

	if(config.isEmpty()) loadConfigFile(config);

	OverrunFlag = 0;
	
	// 100ms = 10Hz rate
	// 160ms = 6.25Hz
	// 200ms = 5Hz
	stepTime = 200;

  /* Initialize model */
	//qDebug("Initializing Brain");
	brain_initialize();
	  
	modelMutex = mutex;
  
	//qDebug("Setting Timer");
	  modelTimer = new QTimer(this);
	  
	connect(modelTimer, SIGNAL(timeout()), this, SLOT(rt_OneStep()));
	  
	if(parameters.isEmpty()) init_params(parameters);

	record_video = false;
	stepTimer.start();
}

Model::~Model(){
//	delete modelTimer;
	qDebug("Shutting Down Brain");
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
	if(config["Debug"]=="true") qDebug("Stepping Model");

	/* Check for overrun */
	if (OverrunFlag++) {
		emit error("Overrun!!");
		rtmSetErrorStatus(brain_M, "Overrun");
		return;
	}

	/* Disable interrupts here */
	modelMutex->lock();

	/* Save FPU context here (if necessary) */
	/* Re-enable timer or interrupt here */
	/* Set model inputs here */

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
	if(config["Debug"]=="true") qDebug("Model Unlocked, sending output");
	emit outputReady(brain_Y, stepTimer.restart());
	//if(config["Debug"]=="true") qDebug("Output Sent");
}
		
		
void Model::updateSensorsInput(AUVSensors values){
	if(config["Debug"]=="true") qDebug() << "Brain getting input from hardware";
  	QMutexLocker locker(modelMutex);
	
	brain_U.CurrentDepth = values.depth;                 /* '<Root>/CurrentDepth' */
	brain_U.CurrentHeading = values.orientation.yaw;               /* '<Root>/CurrentHeading' */
//	brain_U.CurrentPitch = values.orientation.pitch;
//	brain_U.CurrentRoll = values.orientation.roll;
	brain_U.Status = values.status;                       /* '<Root>/Status' */	
	
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

void Model::updateVideoFrame(QImage frame){
  	QMutexLocker locker(modelMutex);

	//qDebug() << "Processing QImage" << frame.size() << frame.format();

	unsigned int pixel;
	// potential for segfaults if the size isn't what matlab is expecting
	frame = frame.scaled(160,120);
	int height = frame.height();
	int width = frame.width();

	unsigned int *imgptr;
	imgptr = (unsigned int*) frame.bits();
	for(int x = frame.width()-1; x >= 0; --x){
		for(int y = height-1; y >= 0; --y){
			imgptr++;
			pixel = *(imgptr + width*y+x);
			brain_U.R[(height*x)+y] = ((pixel >> 24) & 0x000000ff) / 255.0f;
			brain_U.G[(height*x)+y] = ((pixel >> 16) & 0x000000ff) / 255.0f;
			brain_U.B[(height*x)+y] = ((pixel >> 8) & 0x000000ff) / 255.0f;
		}
	}
}

void Model::setState(int state){
	if(state < 0 || state > 5) return;
	brain_U.DesiredState = state;
}


void Model::setParam(QString name, double value){
	if(parameters.contains(name)) {
		*(parameters[name]) = value;
		emit status("Set parameter " + name + " to " + QString::number(value));
	}else emit error("Nonexistent parameter: " + name);
}

void Model::setInput(QString name, double value){
	if(name == "RC_Heading") brain_U.RC_Heading = value;
	else if(name == "RC_ForwardVelocity") brain_U.RC_ForwardVelocity = value;
	else if(name == "RC_Strafe") brain_U.RC_Strafe = value;
	else if(name == "RC_Depth") {
		brain_U.RC_Depth = value;
	}else if(name == "Status"){
		brain_U.Status = (int8_T) value;
	}else if(name == "DesiredState") {
		brain_U.DesiredState = (int8_T) value;
		if(value == 0) emit status("Autonomous");
		else emit status("Holding state");
	}else if(name == "RC") {
		brain_U.RC = (boolean_T) value;
		if(brain_U.RC) emit status("Entering Remote Control Mode");
		else emit status("Autonomous");
	}

	if(brain_U.RC) {
		emit status(
			"H" + QString::number(brain_U.RC_Heading)
			+ " D" + QString::number(brain_U.RC_Depth)
			+ " F" + QString::number(brain_U.RC_ForwardVelocity)
			+ " S" + QString::number(brain_U.RC_Strafe));
	}
}

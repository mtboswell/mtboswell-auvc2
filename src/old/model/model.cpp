#include "model.h"
#include "../auv/calibration.h"
//#include "../auv/camread.h"
#include "../configloader.h"
//#include <iostream>
//#include <cstdlib>
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
	  
  
	//qDebug("Allocating Framebuffer");
	// Initialize framebuffer and start video capture 
//	myframe.y = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT);
//	myframe.cb = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT/4);
//	myframe.cr = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT/4);
	//qDebug("Done");

	if(parameters.isEmpty()) init_params(parameters);

//	record_video = false;
	stepTimer.start();
}

Model::~Model(){
//	delete modelTimer;
	qDebug("Shutting Down Brain");
//	camread_close();
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
	brain_U.DeltaT = stepTimer.restart();

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
	if(brain_U.Tare) brain_U.Tare = 0;
	modelMutex->unlock();
	if(config["Debug"]=="true") qDebug("Model Unlocked, sending output");
	emit outputReady(brain_Y, stepTimer.elapsed());
	if(config["Debug"]=="true") qDebug("Output Sent");
}
		
		
void Model::updateSensorsInput(AUVSensors values){
	if(config["Debug"]=="true") qDebug() << "Brain getting input from hardware";
  	QMutexLocker locker(modelMutex);
	
	brain_U.CurrentDepth = values.depth;                 /* '<Root>/CurrentDepth' */
	brain_U.CurrentHeading = values.orientation.yaw;               /* '<Root>/CurrentHeading' */

	brain_U.YawRate = values.orientation.yawrate;               /* '<Root>/CurrentHeading' */
	brain_U.YawAccelB = values.orientation.yawacc;               /* '<Root>/CurrentHeading' */

	brain_U.PitchEuler = values.orientation.pitch;               /* '<Root>/CurrentHeading' */
	brain_U.PitchRate = values.orientation.pitchrate;               /* '<Root>/CurrentHeading' */
	brain_U.PitchAccelB = values.orientation.pitchacc;               /* '<Root>/CurrentHeading' */

	brain_U.RollEuler = values.orientation.roll;               /* '<Root>/CurrentHeading' */
	brain_U.RollRate = values.orientation.rollrate;               /* '<Root>/CurrentHeading' */
	brain_U.RollAccelB = values.orientation.rollacc;               /* '<Root>/CurrentHeading' */


	//qDebug() << values.orientation.pitchacc << values.orientation.yawacc << values.orientation. yawrate;
	brain_U.Status = values.status;                       /* '<Root>/Status' */	
	
/*
	// Transfer video frame into MATLAB, swapping buffers 
	if(!video_paused){
		if(config["Debug"]=="true") qDebug() << "Getting video frame";
		camread_getframe(myframe, record_video);
		//qDebug() << "SwappyCopy!";
		SwappyCopy(brain_U.Y, (unsigned char*)myframe.y, 640, 480);
		SwappyCopy(brain_U.Cb, (unsigned char*)myframe.cb, 320, 240);
		SwappyCopy(brain_U.Cr, (unsigned char*)myframe.cr, 320, 240);
		//qDebug() << "We survived the Swappy";
	}//else qDebug() << "Brain skipping video copy";
*/
	
	
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

	// potential for segfaults if the size isn't what matlab is expecting
	frame = frame.scaled(160,120);
	int height = frame.height();
	int width = frame.width();
	if(height != 120 || width != 160) {
		qDebug() << "Frame is wrong size";
		return;
	}

	unsigned int *imgptr = (unsigned int*) frame.bits();
	unsigned int pixel;
	for(int x = width-1; x >= 0; --x){
		for(int y = height-1; y >= 0; --y){
			pixel = *(imgptr + width*y+x);
			brain_U.R[(height*x)+y] = ((pixel >> 24) & 0x000000ff) / 255.0f;
			brain_U.G[(height*x)+y] = ((pixel >> 16) & 0x000000ff) / 255.0f;
			brain_U.B[(height*x)+y] = ((pixel >> 8) & 0x000000ff) / 255.0f;
		}
	}
}

void Model::setParam(QString name, double value){
	if(parameters.contains(name)) {
		*(parameters[name]) = value;
		emit status("Set parameter " + name + " to " + QString::number(value));
	}else emit error("Nonexistent parameter: " + name);	
}

void Model::setInput(QString name, double value){
	//if(config["Debug"] == "true") 
	//qDebug() << "Setting input: " + name + " to " + QString::number(value);
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
	}else if(name == "Tare"){
		brain_U.Tare = (boolean_T) value;
	}else if(name == "RC_Source"){
		brain_U.RC_Source = (boolean_T) value;
	}else{
		qDebug() << "Unrecognized brain input: " + name + " = " + QString::number(value);
	}

	if(brain_U.RC) {
		emit status(
			"H" + QString::number(brain_U.RC_Heading)
			+ " D" + QString::number(brain_U.RC_Depth)
			+ " F" + QString::number(brain_U.RC_ForwardVelocity)
			+ " S" + QString::number(brain_U.RC_Strafe));
	}
} 

void Model::messageIn(QString id, QString value){
	if(!id.startsWith("Brain")) return;
	QString type, name;
	QStringList ids = id.split('.');
	if(ids.size() > 1) type = ids[1];
	if(ids.size() > 2) name = ids[2];
	if(type == "Param" || type == "Parameter"){
		setParam(name, value.toDouble());
	}else if(type == "Input"){
		setInput(name, value.toDouble());
	}else if(type == "GetParams"){
		sendParams();
	}
}


void Model::sendParams(){
	qDebug() << "Sending Params";

	QHashIterator<QString, double*> i(parameters);
	 while (i.hasNext()) {
	     i.next();
	//	qDebug() << "Getting Parameter:" << i.key();
		emit messageOut("Brain.Parameter."+i.key(), QString::number(*(i.value())));
	 }
}


/* 
 * This file represents the AUV interface that all controlling code interacts with/uses to control the AUV
 * Author: Micah Boswell (micah27@vt.edu)
 * Date: 12/11/2009
 */

#ifndef AUV_CPP_
#define AUV_CPP_

#include "auv.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QTime>

AUV::AUV(bool simulate){
	// 160ms = 6.25Hz rate
	stepTime = 160;
	
	sensorTimer = new QTimer(this);
  	connect(sensorTimer, SIGNAL(timeout()), this, SLOT(readSensors()));
	goTimer = new QTimer(this);
  	connect(goTimer, SIGNAL(timeout()), this, SLOT(externalControl()));
  	
  	dataMutex = new QMutex();
	
	/* Initialize hardware */
	adc = new ADC(ARDUINOPORT, 9600);
	imu = new IMU(IMUPORT);
	pControllers = new Pololu(POLOLUPORT);
	thrusterPower = new Power(POWERPORT);

	if(simulate) data.manualOverrideDisabled = true;
	data.droppedLeft = false;
	data.droppedRight = false;
	reset();
}
AUV::~AUV(){
	qDebug("Shutting Down AUV Interface");
	stopThrusters();
	delete adc;
	delete imu;
	delete pControllers;
	delete thrusterPower;
	wait();
}

void AUV::run(){
  	sensorTimer->start(stepTime);
  	//goTimer->start(stepTime); // Now obsoleted by readSensors();  
	exec();
}

void AUV::readSensors(){
	//qDebug("Reading Sensor Data");
	QTime t;
  	dataMutex->lock();
	t.start();
	data.orientation = getOrientation();
	data.depth = getDepth();
	data.thrusterPower.voltage = getThrusterVoltage();
	data.thrusterPower.current = getThrusterCurrent();
	data.thrusterPower.power = getThrusterPower();
	// uncomment for manual switch override
	if(data.status == RUNNING && !data.manualOverrideDisabled && !getGo()) {
		qDebug("Waiting on Manual Switch");
		data.status = PAUSED;
	  	dataMutex->unlock();
		stopThrusters();
	}else dataMutex->unlock();
//	qDebug() << "Sensor Reading Time: " << QString::number(t.elapsed()) << "ms";
	emit sensorUpdate(data);
}


void AUV::inputFromBrain(ExternalOutputs_brain inputs, int brainTime){
	look((cameraPosition) (char) inputs.CameraPosition);
	setThrusters(inputs.Thrusters);
}

void AUV::goAUV(){
	qDebug("AUV received signal to start");
  	QMutexLocker locker(dataMutex);
	data.status = RUNNING;
}

void AUV::stop(){
	stopThrusters();
  	QMutexLocker locker(dataMutex);
	data.status = PAUSED;
}

void AUV::reset(){
	stopThrusters();
	/* Start up everything */
	thrusterPower->turnOn();
	usleep(10000);
	thrusterPower->turnOn();
  	QMutexLocker locker(dataMutex);
	data.thrusterPower.state = 1;
	// Reset servo controller
	adc->sendValue('r');
	data.status = READY;
}

void AUV::kill(){
	stopThrusters();
	thrusterPower->turnOff();
  	QMutexLocker locker(dataMutex);
	data.thrusterPower.state = 0;
	data.status = KILLED;
}

void AUV::externalControl(){
  	dataMutex->lock();
	/* Wait for go */
	if(!getGo()) {
		data.status = PAUSED;
		for(int i = 0; i < NUMBER_OF_THRUSTERS; i++)
			data.thrusterSpeeds[i] = 0;
		dataMutex->unlock();
		stopThrusters(); // must unlock dataMutex first!!
	}else{
		data.status = RUNNING;
		dataMutex->unlock();
	}
	// wait for switch
	//while(!getGo()) wait();  // should be pause()??
}

// get data from compass and orientation sensor
// orientation.yaw, roll, pitch
imu_data AUV::getOrientation(){return imu->getData();}

// set thruster speeds
void AUV::setThrusters(signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]){
	if(!data.thrusterPower.state || data.status == PAUSED || data.status == READY) return;
/*
	if(thrusterSpeeds[2] > 0){
		thrusterSpeeds[0] = 0;
		thrusterSpeeds[1] = 0;
	}
*/
	//qDebug("Conversing with TReXs");
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		if(i != 3 && thrusterSpeeds[i] > 40) thrusterSpeeds[i] = 40;
		if(i != 3 && thrusterSpeeds[i] < -40) thrusterSpeeds[i] = -40;
		pControllers->setTrexSpeed(i, thrusterSpeeds[i]);
	}
  	QMutexLocker locker(dataMutex);
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		data.thrusterSpeeds[i] = thrusterSpeeds[i];
	}
	//qDebug("Conversation Over");
}
// set all of the thruster speeds to 0
void AUV::stopThrusters(){
  	QMutexLocker locker(dataMutex);
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		pControllers->setTrexSpeed(i, 0);
		data.thrusterSpeeds[i] = 0;
	}
}

// Returns Voltage of Thruster Battery pack in Volts
double AUV::getThrusterVoltage() {return thrusterPower->getVoltage();}
// Returns Current Draw on Thruster power supply in Amps
double AUV::getThrusterCurrent() {return thrusterPower->getCurrent();}
// Returns power being used by thrusters in Watts
double AUV::getThrusterPower() {return thrusterPower->getVoltage()*thrusterPower->getCurrent();}

// reads the current depth from the depth sensor via the arduino
double AUV::getDepth(){return ((double)((double)adc->getValue("DEPTH")-depthZero))/(double)depthScale;}

void AUV::setActualDepth(double depth){
	if(depth == 0) depthZero = adc->getValue("DEPTH");
	else depthScale = (adc->getValue("DEPTH")-depthZero)/depth;
}

bool AUV::getGo(){return (bool)adc->getValue("GO");}

void AUV::look(cameraPosition pos){
  	if(data.camera != pos) {
		qDebug("Moving Camera");
		switch(pos){
			case FORWARD:
				pControllers->setPosAbs(0, 2600);
				break;
			case UP:
				pControllers->setPosAbs(0, 1600);
				break;
			case DOWN:
				pControllers->setPosAbs(0, 4000);
				break;
			default:
				break;
		}		
  		QMutexLocker locker(dataMutex);	
  		data.camera = pos;
	}
}
/*
void AUV::look(int x, int y){
	// TODO
}
*/

void AUV::dropLeft(){
	//cout << "dropping left" << endl;
	pControllers->setPosAbs(1, 600);
	usleep(1000000);
	pControllers->setPosAbs(1, 2500);
  	QMutexLocker locker(dataMutex);
	data.droppedLeft = true;
}

void AUV::dropRight(){
	pControllers->setPosAbs(1, 4400);
	usleep(1000000);
	pControllers->setPosAbs(1, 2500);
  	QMutexLocker locker(dataMutex);
	data.droppedRight = true;
}


/* setMotion - tell the AUV which way to go
 * params: forward, yaw, vertical
 * forward: forward velocity
 * 		range: -127 (backward) to 127 (forward)
 * yaw: clockwise yaw velocity
 * 		range: -127 (left) to 127 (right)
 * vertical: downward velocity
 * 		range: -127 (full speed up) to 127 (full speed down)
 */
void AUV::setMotion(int forward, int yaw, int vertical){

	if(forward > 127) forward = 127;
	else if(forward < -127) forward = -127;

	if(yaw > 127) yaw = 127;
	else if(yaw < -127) yaw = -127;

	if(vertical > 127) vertical = 127;
	else if(vertical < -127) vertical = -127;

	int motor1speed;
	int motor2speed;

	motor1speed = forward + yaw;
	motor2speed = forward - yaw;

	if(motor1speed > 127) motor1speed = 127;
	else if(motor1speed < -127) motor1speed = -127;
	if(motor2speed > 127) motor2speed = 127;
	else if(motor2speed < -127) motor2speed = -127;

	pControllers->setTrexSpeed(0, motor1speed);
	pControllers->setTrexSpeed(1, motor2speed);
	pControllers->setTrexSpeed(2, vertical);

}

void AUV::setMotion(AUVMotion* velocity){

	if(velocity->forward > 127) velocity->forward = 127;
	else if(velocity->forward < -127) velocity->forward = -127;

	if(velocity->yaw > 127) velocity->yaw = 127;
	else if(velocity->yaw < -127) velocity->yaw = -127;

	if(velocity->vertical > 127) velocity->vertical = 127;
	else if(velocity->vertical < -127) velocity->vertical = -127;

	int motor1speed;
	int motor2speed;

	motor1speed = velocity->forward + velocity->yaw/5;
	motor2speed = velocity->forward - velocity->yaw/5;

	if(motor1speed > 127) motor1speed = 127;
	else if(motor1speed < -127) motor1speed = -127;
	if(motor2speed > 127) motor2speed = 127;
	else if(motor2speed < -127) motor2speed = -127;

	pControllers->setTrexSpeed(0, motor1speed);
	pControllers->setTrexSpeed(1, motor2speed);
	pControllers->setTrexSpeed(2, velocity->vertical);

}

#endif /*AUV_CPP_*/

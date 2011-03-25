/* 
 * This file represents the AUV interface that all controlling code interacts with/uses to control the AUV
 * Author: Micah Boswell (micah27@vt.edu)
 * Date: 12/11/2009
 */

#ifndef AUV_CPP_
#define AUV_CPP_

#include "auv.h"
//#include "camread.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QTime>
#include <QFile>
#include <QStringList>

AUV::AUV(QMutex* sensorMutex, bool hardwareOverrideDisabled){
	if(config.isEmpty()) loadConfigFile(config);
	// 160ms = 6.25Hz rate
	//stepTime = 160;
	stepTime = config["StepTime.AUV"].toInt();

	// Initialize data
	data.status = READY;
	data.orientation.yaw = 0;
	data.orientation.pitch = 0;
	data.orientation.roll = 0;
	data.orientation.yawrate = 0;
	data.orientation.pitchrate = 0;
	data.orientation.rollrate = 0;
	data.orientation.yawacc = 0;
	data.orientation.pitchacc = 0;
	data.orientation.rollacc = 0;
	data.depth = 0;
	data.thrusterSpeeds[0] = 0;
	data.thrusterSpeeds[1] = 0;
	data.thrusterSpeeds[2] = 0;
	data.thrusterSpeeds[3] = 0;
	data.thrusterPower.voltage = 0;
	data.thrusterPower.current = 0;
	data.mainPower.state = 1;
	data.mainPower.voltage = 0;
	data.mainPower.current = 0;
	data.cameraX = 0;
	data.cameraY = 0;
	data.manualOverrideDisabled = false;
	
	// set up wb (white balance) process handling
	wbProc = new QProcess(this);
	
	// set up sensor reads
	sensorTimer = new QTimer(this);
  	connect(sensorTimer, SIGNAL(timeout()), this, SLOT(readSensors()));

	// Get mutex from main
  	dataMutex = sensorMutex;

	compass = MICROSTRAIN;
	
	/* Initialize hardware interfaces */
	qDebug() << "Bringing up Arduino";
	arduino = new Arduino(config["SerialPort.Arduino"]);
	qDebug() << "Bringing up Microstrain";
	microstrain = new Microstrain(config["SerialPort.Compass"]);
	qDebug() << "Bringing up OS5000";
	os5000 = new OS5000(config["SerialPort.OtherCompass"]);
	qDebug() << "Bringing up Pololu";
	pControllers = new Pololu(config["SerialPort.Pololu"]);
	qDebug() << "Bringing up Power";
	thrusterPower = new Power(config["SerialPort.ThrusterPower"]);
	qDebug() << "Bringing up Power";
	mainPower = new Power(config["SerialPort.MainPower"]);
	qDebug() << "Bringing up LCD";
	statusLcd = new LCD(config["SerialPort.LCD"]);

	qDebug() << "Initializing Camera";
	camera = new QWebCam();
	//camThread = new QThread(this);
	//camThread->start(); // maybe??
	//camera->moveToThread(camThread);
	//camThread->start(); // ??
	connect(camera, SIGNAL(newFrame(QImage)),this, SIGNAL(cameraFrame(QImage)));
	connect(camera, SIGNAL(newFrame(QPixmap)),this, SIGNAL(cameraFrame(QPixmap)));


	//connect(this, SIGNAL(status(QString)), this, SLOT(statusMessage(QString)));

	// dirty hack to disable off switch when we don't have one attached.
	data.manualOverrideDisabled = hardwareOverrideDisabled;

	// Initialize mechanisms database
	populateMechs(mechanisms);


	states << "Autonomous";
	states << "Startup";
	states << "Validation Gate";
	states << "Path to Buoys";
	states << "Buoys";
	states << "Path to Hedge";
	states << "Hedge";
	states << "Path to Weapons";
	states << "Weapons";
	states << "Path to Hedge";
	states << "Hedge";
	states << "Locating Pinger";
	states << "Surfacing";
	states << "Finished";
	states << "";
	states << "";
	states << "";
	states << "";
	states << "";
	states << "";
	states << "";

	// these flags may eventually be useful again
	data.droppedLeft = false;
	data.droppedRight = false;

	// make sure the AUV hardware is ready to go
	reset();
	emit status("Startup Complete");
}
AUV::~AUV(){
	qDebug("Shutting Down AUV Interface");
	stopThrusters();
	delete arduino;
	delete microstrain;
	delete os5000;
	delete pControllers;
	delete thrusterPower;
	delete mainPower;
	wait();
}

void AUV::run(){
	// start the periodic sensor updates
  	sensorTimer->start(stepTime);
	exec();
}

void AUV::readSensors(){
	if(config["Debug"]=="true") qDebug("Reading Sensor Data");
	QTime t;
  	dataMutex->lock();
	t.start();
	data.orientation = getOrientation();
	data.depth = getDepth();
	data.thrusterPower.voltage = getThrusterVoltage();
	data.thrusterPower.current = getThrusterCurrent();
	data.thrusterPower.power = getThrusterPower();
	data.mainPower.voltage = getMainVoltage();
	data.mainPower.current = getMainCurrent();
	data.mainPower.power = getMainPower();
	if(!data.manualOverrideDisabled){
		if(data.status == RUNNING && !getGo()) {
			emit status("Manual Switch Stop");
			data.status = PAUSED;
			dataMutex->unlock();
			stopThrusters();
			emit hardwareOverride();
		}else if (data.status == PAUSED && getGo()){
			emit status("Running!");
			data.status = RUNNING;
		}else if (data.status == READY && !getGo()){
			emit status("Diver has control.");
			data.status = PAUSED;
		}/*else if (data.status == READY && getGo()){
			emit status("Diver has lost control.");
			data.status = READY;
		}*/
	}
	if(config["Debug"]=="true") qDebug() << "Sensor Reading Time: " << QString::number(t.elapsed()) << "ms";
	dataMutex->unlock();
	emit sensorUpdate(data);
}


void AUV::inputFromBrain(ExternalOutputs_brain inputs){
	look((cameraPosition) (char) inputs.CameraPosition);
	// look(inputs.CameraX, inputs.CameraY);
	setThrusters(inputs.Thrusters);
	if(inputs.State >= 0) statusField("State",states[inputs.State]);
	else if(inputs.State == -1) statusField("State","Remote Control");
	else if(inputs.State == -2) statusField("State","Stopped");
}

void AUV::goAUV(){
  	QMutexLocker locker(dataMutex);
	if(data.manualOverrideDisabled){
		emit status("Running!");
		data.status = RUNNING;
	}else{
		if(data.status == PAUSED) emit status("Waiting on Diver.");
		else emit status("Switching to diver control.");
		data.status = PAUSED;
	}
}

void AUV::stop(){
	stopThrusters();
  	QMutexLocker locker(dataMutex);
	data.status = READY;
	emit status("Stopped");
}

void AUV::reset(){
	emit status("Resetting hardware");
	stopThrusters();
	/* Start up everything */
	thrusterPower->turnOn();
	usleep(10000);
	thrusterPower->turnOn();
  	QMutexLocker locker(dataMutex);
	data.thrusterPower.state = 1;
	// Reset servo controller
	arduino->sendCmd('r');
	data.status = READY;
	emit status("Reset done");
}

void AUV::kill(){
	stopThrusters();
	thrusterPower->turnOff();
  	QMutexLocker locker(dataMutex);
	data.thrusterPower.state = 0;
	data.status = KILLED;
	emit status("Power Cut");
}

// sets data.status based on the external switch
// deprecated
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
	// uncomment below loop to block.  this isn't necessary and prevents reading sensors.
	// wait for switch
	//while(!getGo()) wait();  // should be pause()??
}

// get data from compass and orientation sensor
// orientation.yaw, roll, pitch
imu_data AUV::getOrientation(){return microstrain->getData();}
double AUV::getHeading(){
	if(compass == MICROSTRAIN)
		return microstrain->getData().yaw;
	else if(compass == OCEANSERVER5000)
		return os5000->heading();
	else return -1;
}

// set thruster speeds
void AUV::setThrusters(signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]){
	if(!data.thrusterPower.state || data.status != RUNNING) return;
//	qDebug() << "Setting thrusters to" << thrusterSpeeds[0] << thrusterSpeeds[1] << thrusterSpeeds[2] << thrusterSpeeds[3];
/*
	if(thrusterSpeeds[2] > 0){
		thrusterSpeeds[0] = 0;
		thrusterSpeeds[1] = 0;
	}
*/
	if(config["Debug"]=="true") qDebug("Conversing with TReXs");
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		if(i != 3 && thrusterSpeeds[i] > 40) thrusterSpeeds[i] = 40;
		if(i != 3 && thrusterSpeeds[i] < -40) thrusterSpeeds[i] = -40;
		pControllers->setMotorSpeed(i, thrusterSpeeds[i]);
	}
  	QMutexLocker locker(dataMutex);
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		data.thrusterSpeeds[i] = thrusterSpeeds[i];
	}

	if(config["Debug"]=="true") qDebug("Conversation Over");
}
// set thruster speeds
void AUV::setThrusters(double thrusterSpeeds[NUMBER_OF_THRUSTERS]){
	if(!data.thrusterPower.state || data.status != RUNNING) return;
	if(config["Debug"] == "true") qDebug() << "Setting thrusters to" << thrusterSpeeds[0] << thrusterSpeeds[1] << thrusterSpeeds[2] << thrusterSpeeds[3];

	// [i][0] = upper limit for thruster i
	// [i][1] = lower limit for thruster i
	signed char thrusterLimit[NUMBER_OF_THRUSTERS][2];
	thrusterLimit[0][0] = 80;
	thrusterLimit[0][1] = -80;
	thrusterLimit[1][0] = 80;
	thrusterLimit[1][1] = -80;
	thrusterLimit[2][0] = 90;
	thrusterLimit[2][1] = -90;
	thrusterLimit[3][0] = 127;
	thrusterLimit[3][1] = -50;

	if(config["Debug"]=="true") qDebug("Conversing with TReXs");
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		pControllers->setMotorSpeed(i, qBound(thrusterLimit[i][1], (signed char) (thrusterSpeeds[i]*127), thrusterLimit[i][0]));
	}
  	QMutexLocker locker(dataMutex);
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		data.thrusterSpeeds[i] = qBound(thrusterLimit[i][1], (signed char) (thrusterSpeeds[i]*127), thrusterLimit[i][0]);
	}

}

// set all of the thruster speeds to 0
void AUV::stopThrusters(){
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		pControllers->setMotorSpeed(i, 0);
	}
  	QMutexLocker locker(dataMutex);
	for(int i = 0; i < NUMBER_OF_THRUSTERS; i++){
		data.thrusterSpeeds[i] = 0;
	}
}

// Returns Voltage of Main Battery pack in Volts
double AUV::getMainVoltage() {return mainPower->getVoltage();}
// Returns Current Draw on Main power supply in Amps
double AUV::getMainCurrent() {return mainPower->getCurrent();}
// Returns power being used by mains in Watts
double AUV::getMainPower() {return mainPower->getVoltage()*mainPower->getCurrent();}

// Returns Voltage of Thruster Battery pack in Volts
double AUV::getThrusterVoltage() {return thrusterPower->getVoltage();}
// Returns Current Draw on Thruster power supply in Amps
double AUV::getThrusterCurrent() {return thrusterPower->getCurrent();}
// Returns power being used by thrusters in Watts
double AUV::getThrusterPower() {return thrusterPower->getVoltage()*thrusterPower->getCurrent();}

// reads the current depth from the depth sensor via the arduino
double AUV::getDepth(){return ((double)((double)arduino->getValue("DEPTH")-depthZero))/(double)depthScale;}

void AUV::setActualDepth(double depth){
	if(depth == 0) depthZero = arduino->getValue("DEPTH");
	else depthScale = (arduino->getValue("DEPTH")-depthZero)/depth;
	emit status("Calibrated Depth Sensor to " + QString::number(depth) + " ft");
}

// values of -1 and 1 should mean on
bool AUV::getGo(){return (arduino->getValue("GO")==0)?false:true;}

// deprecated
void AUV::look(cameraPosition pos){
  	if(data.camera != pos) {
		//emit status("Moving Camera");
		switch(pos){
			case FORWARD:
				pControllers->setServoPosAbs(0, 2600);
				break;
			case UP:
				pControllers->setServoPosAbs(0, 1600);
				break;
			case DOWN:
				pControllers->setServoPosAbs(0, 4000);
				break;
			default:
				break;
		}		
  		QMutexLocker locker(dataMutex);	
  		data.camera = pos;
	}
}

void AUV::look(double x, double y){
	// Check input ranges
	if(((x>0)?x:-x) > 1 || ((y>0)?y:-y) > 1) return;

	int xpos = 0, ypos = 0;

	// Scale values
	if(x == 0) xpos = GIMBAL_X_ZERO;	
	else if(x > 0) xpos = (GIMBAL_X_MAX-GIMBAL_X_ZERO)*x + GIMBAL_X_ZERO;
	else if(x < 0) xpos = (GIMBAL_X_ZERO-GIMBAL_X_MIN)*x + GIMBAL_X_ZERO;
	if(y == 0) ypos = GIMBAL_Y_ZERO;	
	else if(y > 0) ypos = (GIMBAL_Y_MAX-GIMBAL_Y_ZERO)*y + GIMBAL_Y_ZERO;
	else if(y < 0) ypos = (GIMBAL_Y_ZERO-GIMBAL_Y_MIN)*y + GIMBAL_Y_ZERO;

	// [TODO] - check output ranges
	
	data.cameraX = x;
	data.cameraY = y;

	// Output to servos
	pControllers->setServoPosAbs(GIMBAL_Y_SERVO, ypos);
	pControllers->setServoPosAbs(GIMBAL_X_SERVO, xpos);
}


// Run servo sequence for given mechanism
void AUV::activateMechanism(QString mech){
	// Check to make sure we have that mech
	if(!mechanisms.contains(mech)) {
		emit error("Nonexistent Mechanism");
		return;
	}
	// If we are already running a mechanism, add to waitlist
	if(!posQueue.isEmpty()){
		mechQueue.enqueue(mech);
		QTimer::singleShot(300, this, SLOT(activateMechanism()));
		emit status("Queueing mech: " + mech);
		return;
	} 
	// Once we are ready, activate the mech
	emit status("Actuating Mechanism: " + mech);
	mechanism thisMech = mechanisms[mech];
	QMapIterator<int, int> i(thisMech.positions);
	while (i.hasNext()) {
		i.next();
		if(i.key() == 0) moveServo(thisMech.servo, i.value());
		else {
			posQueue.enqueue(QString::number(thisMech.servo) + ":" + QString::number(i.value()));
			QTimer::singleShot(i.key(), this, SLOT(moveServo()));
		}
	}
}
void AUV::activateMechanism(){
	if(mechQueue.isEmpty()) return;
	if(!posQueue.isEmpty()) QTimer::singleShot(300, this, SLOT(activateMechanism()));
	activateMechanism(mechQueue.dequeue());
}

// Abstraction!
void AUV::moveServo(int servo, int position){
	pControllers->setServoPosAbs(servo, position);
}
void AUV::moveServo(){
	QString pos = posQueue.dequeue();
	int servo = pos.split(':').value(0).toInt();
	int position = pos.split(':').value(1).toInt();
	pControllers->setServoPosAbs(servo, position);
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

	pControllers->setMotorSpeed(0, motor1speed);
	pControllers->setMotorSpeed(1, motor2speed);
	pControllers->setMotorSpeed(2, vertical);

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

	pControllers->setMotorSpeed(0, motor1speed);
	pControllers->setMotorSpeed(1, motor2speed);
	pControllers->setMotorSpeed(2, velocity->vertical);

}

void AUV::autoWhiteBalance(){
	emit status("White-balancing camera");
	//qDebug() << "Turning off camera...";
	//if(!camread_pause()) emit error("Failed to stop camera");
	wait(500);
	//qDebug() << "Sending White Balance command...";
	wbProc->execute("v4lctl setattr \"Auto White Balance\" on");
	//wait(500);
	//if(!camread_unpause()) emit error("Failed to turn on camera");
	qDebug() << "White balancing (3s)...";
	QTimer::singleShot(3000, this, SLOT(finishWhiteBalance()));
//	qDebug() << "counting down...";
//	wait(3000);
//	finishWhiteBalance();
}
void AUV::finishWhiteBalance(){
//	qDebug() << "Turning off camera...";
	//if(!camread_pause()) qDebug() << "Failed to stop camera";
	wait(500);
	qDebug() << "Stopping white ballancing";
	wbProc->execute("v4lctl setattr \"Auto White Balance\" off");
	wait(500);
	//if(!camread_unpause()) qDebug() << "Failed to turn on camera:";
	emit status("Done white balancing");
}


void AUV::runScriptedMotion(QString scriptFile){
	// Check to make sure we have that script
	if(!QFile::exists("scripts/" + scriptFile)) {
		emit error("Nonexistent Script");
		return;
	}
	// If we are already running a script or we are not running, add to waitlist
	if(!actionQueue.isEmpty() || data.status != RUNNING){
		scriptQueue.enqueue(scriptFile);
		QTimer::singleShot(300, this, SLOT(runScriptedMotion()));
		emit status("Queueing Script: " + scriptFile);
		return;
	} 
	// Once we are ready, activate the script
	qDebug() << "Running Script:" << scriptFile;
	//open script file
	QFile file("scripts/" + scriptFile);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	// parse file and schedule actions
	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		// each line must start with a time (in ms) followed by a ":"
		if(line=="" || !line.contains(":")) continue;
		int time = line.split(':').value(0).toInt();
		// the rest of the line is the command
		QString cmd = line.split(':').value(1);
		actionQueue.enqueue(cmd);
		// time zero is right now
		if(time == 0) doScriptAction();
		else {
			QTimer::singleShot(time, this, SLOT(doScriptAction()));
		}
	}
}

// checks to see if the current script has finished, and if it has, runs the next script. Otherwise it keeps checking every 300ms
void AUV::runScriptedMotion(){
	if(scriptQueue.isEmpty()) return;
	if(!actionQueue.isEmpty() || data.status != RUNNING) QTimer::singleShot(300, this, SLOT(runScriptedMotion()));
	else runScriptedMotion(scriptQueue.dequeue());
}

// gets the next script command from the queue and sends the proper input to the brain
void AUV::doScriptAction(){
	if(actionQueue.isEmpty()) return;
	QString action = actionQueue.dequeue();
	emit status("Doing script action: " + action);
	// parse action
	if(action == "") return;
	QStringList input = action.split(' ');
	QString cmd = input.value(0);
	double params[5];
	for(int i = input.size()-1; i > 0; --i){
		params[i-1] = input.value(i).toDouble();
	}
	// do action
	emit setBrainInput("RC", 1);
	if(cmd == "state"){
		emit setBrainInput("RC_ForwardVelocity", params[0]);
		emit setBrainInput("RC_Heading", params[1]+getHeading());
		emit setBrainInput("RC_Depth", params[2]+getDepth());
		emit setBrainInput("RC_Strafe", params[3]);
	}else if(cmd == "absstate"){ 
		emit setBrainInput("RC_ForwardVelocity", params[0]);
		emit setBrainInput("RC_Heading", params[1]);
		emit setBrainInput("RC_Depth", params[2]);
		emit setBrainInput("RC_Strafe", params[3]);
	}else if(cmd == "heading"){ // relative heading
		emit setBrainInput("RC_Heading", getHeading()+params[0]);
	}else if(cmd == "absheading"){
		emit setBrainInput("RC_Heading", params[0]);
	}else if(cmd == "depth"){ // relative depth
		emit setBrainInput("RC_Depth", params[0]+getDepth());
	}else if(cmd == "absdepth"){
		emit setBrainInput("RC_Depth", params[0]);
	}else if(cmd == "speed"){ // speed is always absolute
		emit setBrainInput("RC_ForwardVelocity", params[0]);
	}else if(cmd == "end" || cmd == "exit"){
		emit setBrainInput("RC", 0);
		stop();
	}else emit error("Unrecognized command");
}

void AUV::setControllers(char desiredSpeed, double desiredHeading, double desiredDepth, char desiredStrafe){
	ExternalInputs_brain inputs;
	static char currentDesiredSpeed = 0, currentDesiredStrafe = 0;
	static double currentDesiredHeading = 0, currentDesiredDepth = 0;
	inputs.RC = 1;

	if(desiredSpeed == -128) inputs.RC_ForwardVelocity = currentDesiredSpeed;
	else inputs.RC_ForwardVelocity = desiredSpeed;

	if(desiredHeading == -1) inputs.RC_Heading = currentDesiredHeading;
	else inputs.RC_Heading = desiredHeading;

	if(desiredDepth == -1) inputs.RC_Depth = currentDesiredDepth;
	else inputs.RC_Depth = desiredDepth;

	if(desiredStrafe == -128) inputs.RC_Strafe = currentDesiredStrafe;
	else inputs.RC_Strafe = desiredStrafe;

	emit setControllers(inputs);

	currentDesiredSpeed = desiredSpeed;
	currentDesiredStrafe = desiredStrafe;
	currentDesiredHeading = desiredHeading;
	currentDesiredDepth = desiredDepth;
}

void AUV::releaseControllers(){
	ExternalInputs_brain inputs;
	inputs.RC = 0;
	inputs.RC_Heading = 0;
	inputs.RC_Depth = 0;
	inputs.RC_ForwardVelocity = 0;
	inputs.RC_Strafe = 0;
	emit setControllers(inputs);
}

void AUV::statusMessage(QString message){
	statusLcd->dispMessage(message);
}
void AUV::statusField(QString name, QString msg){
	statusLcd->dispField(name, msg);
}

void AUV::messageIn(QString id, QString value){
	bool completedCommand = true;
	if(!id.startsWith("AUV")) return;
	QString type, name;
	QStringList ids = id.split('.');
	if(ids.size() > 1) type = ids[1];
	if(ids.size() > 2) name = ids[2];

	if(type == "Mode"){
		if(value == "Running" || value == "Run") goAUV();
		else if(value == "Stopped" || value == "Stop" || value == "Pause" || value == "Paused") stop();
		else if(value == "Killed" || value == "Kill" || value == "kill") kill();
		else if(value == "Reset") reset();
	}else if(type == "Actuate" || type == "Activate"){
		if(name == "SelfDestruct") qDebug() << "Self Destruct in 5...";
		else if(name =="Mech" || name == "Mechanism") emit activateMechanism(value);
		else if(name == "Script") runScriptedMotion(value);
		else completedCommand = false;
	}else if(type == "Move"){
		if(name == "Camera"){
			QStringList coords = value.split(",");
			if(coords.size() < 2) error("Invalid camera coords");
			else{
				double x = coords.at(0).toDouble();
				double y = coords.at(1).toDouble();
				look(x,y);
			}
		}else completedCommand = false;
	}else if(type == "Script"){
		if(name == "Run")
			runScriptedMotion(value);
	//	else if(name == "New")
	//		newScript(value);
	}else if(type == "Calibrate"){
		if(name == "Depth") setActualDepth(value.toDouble());
		else if(name == "WhiteBalance") autoWhiteBalance();
		else completedCommand = false;
	}
}


void AUV::sendSensorData(AUVSensors sens){
	if(config["Debug"]=="true") qDebug() << "Sending Sensor Data";

	static int sendCount = 0;


	// logging is now done in the dashboard
	//logger->logData(type + '.' + name, value);

	//sens.stuff;
	emit messageOut("AUV.Mode", QString::number(sens.status));
	emit messageOut("AUV.Heading", QString::number(sens.orientation.yaw));
	emit messageOut("AUV.Depth", QString::number(sens.depth));
	emit messageOut("AUV.LeftThruster", QString::number(sens.thrusterSpeeds[0]));
	emit messageOut("AUV.RightThruster", QString::number(sens.thrusterSpeeds[1]));
	emit messageOut("AUV.LateralThruster", QString::number(sens.thrusterSpeeds[2]));
	emit messageOut("AUV.VerticalThruster", QString::number(sens.thrusterSpeeds[3]));
	emit messageOut("AUV.CameraX", QString::number(sens.cameraX));
	emit messageOut("AUV.CameraY", QString::number(sens.cameraY));
	// some data gets updated less often
	if(sendCount%10 == 0){
		emit messageOut("AUV.ThrusterVoltage", QString::number(sens.thrusterPower.voltage));
		emit messageOut("AUV.ThrusterCurrent", QString::number(sens.thrusterPower.current));
		emit messageOut("AUV.ManualOverrideDisabled", sens.manualOverrideDisabled?"true":"false");
		sendCount = 0;
	}

}

#endif /*AUV_CPP_*/


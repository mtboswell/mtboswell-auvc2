#include <QtGui>
#include "dashboard.h"

Dashboard::Dashboard(QMainWindow *parent, QMutex *mutex)
     : QMainWindow(parent)
 {
 	modelMutex = mutex;
 
    setupUi(this);
     
 	connect(actionGo, SIGNAL(triggered()), this, SLOT(startAction()));
 	connect(actionStop, SIGNAL(triggered()), this, SLOT(stopAction()));
 	connect(actionReset, SIGNAL(triggered()), this, SLOT(resetAction()));
 	connect(actionKill, SIGNAL(triggered()), this, SLOT(killAction()));
 	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
 	connect(actionRecord_Video, SIGNAL(triggered(bool)), this, SLOT(recordVideo(bool)));
 	
 	// Set Default Values for gui inputs from model
 	
 	// controller gain initial settings
	fwdVelocitySpinBox->setValue(brain_P.Heading_Forward_Velocity);
	headingDGainSpinBox->setValue(brain_P.Heading_Kd);
	headingIGainSpinBox->setValue(brain_P.Heading_Ki);
	headingPGainSpinBox->setValue(brain_P.Heading_Kp);
	depthDGainSpinBox->setValue(brain_P.Depth_Kd);
	depthIGainSpinBox->setValue(brain_P.Depth_Ki);
	depthPGainSpinBox->setValue(brain_P.Depth_Kp);
	approachVelocitySpinBox->setValue(brain_P.Vision_Forward_Velocity);
	buoyDepthDGainSpinBox->setValue(brain_P.Cam_Forward_YPosition_Kd);
	buoyDepthIGainSpinBox->setValue(brain_P.Cam_Forward_YPosition_Ki);
	buoyDepthPGainSpinBox->setValue(brain_P.Cam_Forward_YPosition_Kp);
	buoyHeadingDGainSpinBox->setValue(brain_P.Cam_Forward_XPosition_Kd);
	buoyHeadingIGainSpinBox->setValue(brain_P.Cam_Forward_XPosition_Ki);
	buoyHeadingPGainSpinBox->setValue(brain_P.Cam_Forward_XPosition_Kp);
	pathHeadingDGainSpinBox->setValue(brain_P.Cam_Down_XPos_Kd);
	pathHeadingIGainSpinBox->setValue(brain_P.Cam_Down_XPos_Ki);
	pathHeadingPGainSpinBox->setValue(brain_P.Cam_Down_XPos_Kp);
	pathYDGainSpinBox->setValue(brain_P.Cam_Down_YPos_Kd);
	pathYIGainSpinBox->setValue(brain_P.Cam_Down_YPos_Ki);
	pathYPGainSpinBox->setValue(brain_P.Cam_Down_YPos_Kp);

	// Vision
	pathHueHighSpinBox->setValue(brain_P.Track_HueHigher);
	pathHueLowSpinBox->setValue(brain_P.Track_HueLower);
	pathSaturationSpinBox->setValue(brain_P.Track_Saturation);
	buoyHueHighSpinBox->setValue(brain_P.Buoy_HueHigher);
	buoyHueLowSpinBox->setValue(brain_P.Buoy_HueLower);
	buoySaturationSpinBox->setValue(brain_P.Buoy_Saturation);
 	
	// Populate State Combo Box

	QStringList states;
	states << "Not Started";
	states << "Startup";
	states << "Validation Gate";
	states << "Follow Track";
	states << "Find Buoy";
	states << "Approach Buoy";
	states << "Finished";
	stateComboBox->insertItems(0, states);
 
}
 
 
void Dashboard::startAction(){
	qDebug("Dashboard Attempting to start AUV");
	emit startAUV();
}
void Dashboard::stopAction(){
	emit stopAUV();
}
void Dashboard::resetAction(){
	emit resetAUV();
}
void Dashboard::killAction(){
	emit killAUV();
}

void Dashboard::recordVideo(bool record){
	record_video = record;
}

void Dashboard::updateSensorsView(AUVSensors values){
	
	depthLcdNumber->display(values.depth);
	headingLcdNumber->display(values.orientation.yaw);
	
	QString statuses[4];
	statuses[0] = "Ready";
	statuses[1] = "Running";
	statuses[2] = "Paused";
	statuses[3] = "Murdered";
	controlStateLabel->setText(statuses[values.status]);
	
	leftThrusterProgressBar->setValue(values.thrusterSpeeds[0]);
	rightThrusterProgressBar->setValue(values.thrusterSpeeds[1]);
	vertThrusterProgressBar->setValue(values.thrusterSpeeds[2]);
	
	/*
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

void Dashboard::updateBrainView(ExternalOutputs_brain values){
	
	//qDebug("Dashboard recieving data from Brain");

	
	//qDebug("Processing Brain Data");

	stateComboBox->setCurrentIndex(values.State);
//	stateLabel->setText(QString::number(values.State));
	desiredHeadingSpinBox->setValue(values.DesiredHeading);
	desiredDepthSpinBox->setValue(values.DesiredDepth);
	
	//qDebug("Brain Data on display");
	
}

// State Select
void Dashboard::on_stateComboBox_activated(int index){
	emit setState(index);
}

     
 // controller gains
void Dashboard::on_fwdVelocitySpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Heading_Forward_Velocity = value;
}
void Dashboard::on_headingDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Heading_Kd = value;
}
void Dashboard::on_headingIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Heading_Ki = value;
}
void Dashboard::on_headingPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Heading_Kp = value;
}
void Dashboard::on_depthDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Depth_Kd = value;
}
void Dashboard::on_depthIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Depth_Ki = value;
}
void Dashboard::on_depthPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Depth_Kp = value;
}
void Dashboard::on_approachVelocitySpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Vision_Forward_Velocity = value;
}
void Dashboard::on_buoyDepthDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Forward_YPosition_Kd = value;
}
void Dashboard::on_buoyDepthIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Forward_YPosition_Ki = value;
}
void Dashboard::on_buoyDepthPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Forward_YPosition_Kp = value;
}
void Dashboard::on_buoyHeadingDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Forward_XPosition_Kd = value;
}
void Dashboard::on_buoyHeadingIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Forward_XPosition_Ki = value;
} 
void Dashboard::on_buoyHeadingPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Forward_XPosition_Kp = value;
}
void Dashboard::on_pathHeadingDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Down_XPos_Kd = value;
}
void Dashboard::on_pathHeadingIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Down_XPos_Ki = value;
} 
void Dashboard::on_pathHeadingPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Down_XPos_Kp = value;
}
void Dashboard::on_pathYDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Down_YPos_Kd = value;
}
void Dashboard::on_pathYIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Down_YPos_Ki = value;
} 
void Dashboard::on_pathYPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Cam_Down_YPos_Kp = value;
}

// Vision
void Dashboard::on_pathHueHighSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Track_HueHigher = value;
}
void Dashboard::on_pathHueLowSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Track_HueLower = value;
}
void Dashboard::on_pathSaturationSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Track_Saturation = value;
}
void Dashboard::on_buoyHueHighSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Buoy_HueHigher = value;
}
void Dashboard::on_buoyHueLowSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Buoy_HueLower = value;
}
void Dashboard::on_buoySaturationSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
	brain_P.Buoy_Saturation = value;
}

// Calibration
void Dashboard::on_zeroDepthPushButton_clicked(){
	emit setDepth(0);
}
void Dashboard::on_setActualDepthPushButton_clicked(){
	emit setDepth(actualDepthDoubleSpinBox->value());
}

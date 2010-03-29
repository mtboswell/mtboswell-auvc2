#include <QtGui>
#include "dashboard.h"
#include <QByteArray>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QTime>

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
 	
 	connect(&m_DS, SIGNAL(GotAUVUpdate(QString,QString,QString)), this, SLOT(HandleAUVParam(QString,QString,QString)));
 	connect(this, SIGNAL(sendParam(QString,QString)), &m_DS, SLOT(SendParam(QString,QString)));
 	
 	// Set Default Values for gui inputs from model
 	
 	// controller gain initial settings
/*	fwdVelocitySpinBox->setValue(brain_P.Heading_Forward_Velocity);
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
//	pathHeadingDGainSpinBox->setValue(brain_P.Cam_Down_XPos_Kd);
//	pathHeadingIGainSpinBox->setValue(brain_P.Cam_Down_XPos_Ki);
//	pathHeadingPGainSpinBox->setValue(brain_P.Cam_Down_XPos_Kp);
//	pathYDGainSpinBox->setValue(brain_P.Cam_Down_YPos_Kd);
//	pathYIGainSpinBox->setValue(brain_P.Cam_Down_YPos_Ki);
//	pathYPGainSpinBox->setValue(brain_P.Cam_Down_YPos_Kp);

	// Vision
	pathHueHighSpinBox->setValue(brain_P.Track_HueHigher);
	pathHueLowSpinBox->setValue(brain_P.Track_HueLower);
	pathSaturationSpinBox->setValue(brain_P.Track_Saturation);
	buoyHueHighSpinBox->setValue(brain_P.Buoy_HueHigher);
	buoyHueLowSpinBox->setValue(brain_P.Buoy_HueLower);
	buoySaturationSpinBox->setValue(brain_P.Buoy_Saturation);
*/ 	
	// Populate State Combo Box

	states << "Autonomous";
	states << "Startup";
	states << "Validation Gate";
	states << "Follow Track";
	states << "Find Buoy";
	states << "Approach Buoy";
	states << "Finished";
	stateComboBox->insertItems(0, states);

	// Heading display graphics
	headingScene = new QGraphicsScene;
	headingLine = new QGraphicsLineItem(0, 0, 0, 50);
	headingScene->addItem(headingLine);

	headingGraphicsView->setScene(headingScene);

	// Processing rate display
	rateLabel = new QLabel("Processing at: 0 Hz");
	statusBar()->addPermanentWidget(rateLabel);

	// Set up video display
        videoPixmap = QPixmap(640,480);
        bwPixmap = QPixmap(160,120);
        videoFrame = QImage(640,480,QImage::Format_RGB32); // 4 = QImage::Format_RGB32
        bwFrame = QImage(160,120,QImage::Format_Mono);

        bwFrame.setColor(0, 0xFF000000); 
        bwFrame.setColor(1, 0xFFFF0000); 
        videoPixmap.fill(); 
        bwPixmap.fill(); 
	videoLabel->setScaledContents(true);
	bitVideoLabel->setScaledContents(true);

        verticalLayout_4->addWidget(&container);
     /* process = new QProcess(&container);

     QString executable("mplayer");

     QStringList arguments;

        arguments << "-wid";
     arguments << QString::number(container.winId());
        arguments << "udp://:7960";
	qDebug() << arguments;

     process->start(executable, arguments);*/

     //process.close();

	// Connect to AUV
	emit sendParam("Connect.Data", "This");
	emit sendParam("Connect.Video", "This");
	emit sendParam("GetParams", "all");
 
}

/*
// For future "reconnect" button
void Dashboard::reconnectAction(){
	emit sendParam("Connect.Data", "This");
	emit sendParam("Connect.Video", "This");
}
*/

void Dashboard::startAction(){
	statusBar()->showMessage(tr("Attempting to start AUV"), 2000);
	emit sendParam("Mode", "Run");
}
void Dashboard::stopAction(){
	statusBar()->showMessage(tr("Attempting to stop AUV"), 2000);
	emit sendParam("Mode", "Stop");
}
void Dashboard::resetAction(){
	statusBar()->showMessage(tr("Attempting to reset AUV"), 2000);
	emit sendParam("Mode", "Reset");
}
void Dashboard::killAction(){
	emit sendParam("Mode", "Kill");
}

void Dashboard::recordVideo(bool record){
/*	if(record) statusBar()->showMessage(tr("Recording..."), 2000);
	else statusBar()->showMessage(tr("Stopping Recording..."), 2000);
//	record_video = record;
	if(record) emit startRecordVideo();
	else emit stopRecordVideo();*/
}

void Dashboard::HandleAUVParam(QString type, QString name, QString value) {
	if (type == "AUV") {
		if (name == "Mode") {
			QString modes[4];
			modes[0] = "Ready";
			modes[1] = "Running";
			modes[2] = "Paused";
			modes[3] = "Killed";
			controlStateLabel->setText(modes[value.toInt()]);
		} else if (name == "Heading")
			headingLcdNumber->display(value.toInt());
		else if (name == "Depth")
			depthLcdNumber->display(value.toDouble());
		else if (name == "ThrusterVoltage")
			thVoltageLcdNumber->display(value.toDouble());
		else if (name == "ThrusterCurrent")
			thCurrentLcdNumber->display(value.toDouble());
		else if (name == "LeftThruster")
			leftThrusterProgressBar->setValue(value.toInt());
		else if (name == "RightThruster")
			rightThrusterProgressBar->setValue(value.toInt());
		else if (name == "LeftThruster")
			leftThrusterProgressBar->setValue(value.toInt());
		else if (name == "VerticalThruster")
			vertThrusterProgressBar->setValue(value.toInt());
		else if (name == "LateralThruster")
			strafeThrusterProgressBar->setValue(value.toInt());
		// cameraPosComboBox->setCurrentIndex
		// headingLine->setRotation
	} else if (type == "Brain") {
		if (name == "State") {
			stateLabel->setText(states.at(value.toInt()));
			missionProgressBar->setValue(value.toInt() * (100 / 6));
		} else if (name == "Time") {
			rateLabel->setText("Processing at: " + QString::number(1.0/(value.toDouble()/1000.0)) + " Hz (" + QString::number(round(100.0/(value.toDouble()/1000.0)/5))+ "%)" );
		}
	} else if (type == "Parameter") {
		double paramVal = value.toDouble();
		// update parameters
		// controller gain initial settings
		if(name == "Heading_Forward_Velocity") 
			fwdVelocitySpinBox->setValue(paramVal);
		else if(name == "Heading_Kd") 
			headingDGainSpinBox->setValue(paramVal);
		else if(name == "Heading_Ki") 
			headingIGainSpinBox->setValue(paramVal);
		else if(name == "Heading_Kp") 
			headingPGainSpinBox->setValue(paramVal);
		else if(name == "Depth_Kd") 
			depthDGainSpinBox->setValue(paramVal);
		else if(name == "Depth_Ki") 
			depthIGainSpinBox->setValue(paramVal);
		else if(name == "Depth_Kp") 
			depthPGainSpinBox->setValue(paramVal);
		else if(name == "Vision_Forward_Velocity") 
			approachVelocitySpinBox->setValue(paramVal);
		else if(name == "Cam_Forward_YPosition_Kd") 
			buoyDepthDGainSpinBox->setValue(paramVal);
		else if(name == "Cam_Forward_YPosition_Ki") 
			buoyDepthIGainSpinBox->setValue(paramVal);
		else if(name == "Cam_Forward_YPosition_Kp") 
			buoyDepthPGainSpinBox->setValue(paramVal);
		else if(name == "Cam_Forward_XPosition_Kd") 
			buoyHeadingDGainSpinBox->setValue(paramVal);
		else if(name == "Cam_Forward_XPosition_Ki") 
			buoyHeadingIGainSpinBox->setValue(paramVal);
		else if(name == "Cam_Forward_XPosition_Kp") 
			buoyHeadingPGainSpinBox->setValue(paramVal);
		// Vision
		else if(name == "Track_HueHigher") 
			pathHueHighSpinBox->setValue(paramVal);
		else if(name == "Track_HueLower") 
			pathHueLowSpinBox->setValue(paramVal);
		else if(name == "Track_Saturation") 
			pathSaturationSpinBox->setValue(paramVal);
		else if(name == "Buoy_HueHigher") 
			buoyHueHighSpinBox->setValue(paramVal);
		else if(name == "Buoy_HueLower") 
			buoyHueLowSpinBox->setValue(paramVal);
		else if(name == "Buoy_Saturation") 
			buoySaturationSpinBox->setValue(paramVal);

	}
}

/*void Dashboard::updateSensorsView(AUVSensors values){
	
	depthLcdNumber->display(values.depth);
	headingLcdNumber->display(values.orientation.yaw);
	thVoltageLcdNumber->display(values.thrusterPower.voltage);
	thCurrentLcdNumber->display(values.thrusterPower.current);
	
	QString modes[4];
	modes[0] = "Ready";
	modes[1] = "Running";
	modes[2] = "Paused";
	modes[3] = "Killed";
	controlStateLabel->setText(modes[values.status]);
	
	leftThrusterProgressBar->setValue(values.thrusterSpeeds[0]);
	rightThrusterProgressBar->setValue(values.thrusterSpeeds[1]);
	vertThrusterProgressBar->setValue(values.thrusterSpeeds[3]);
	strafeThrusterProgressBar->setValue(values.thrusterSpeeds[2]);

	cameraPosComboBox->setCurrentIndex(values.camera);

	headingLine->setRotation(values.orientation.yaw);

	/*
	auvStatus status;
	imu_data orientation;
	double depth;
	signed char thrusterSpeeds[NUMBER_OF_THRUSTERS]
	powerData thrusterPower;
	cameraPosition camera;
	bool droppedLeft;
	bool droppedRight;
	* /
}*/

/*void Dashboard::updateBrainView(ExternalOutputs_brain values, int brainTime){
	QTime bT;
	bT.start();

	if(brain_U.RC == 0) { // if we are operating autonomously
		if(values.State == 0)	stateLabel->setText("Not Started");
		else stateLabel->setText(states.at(values.State));
		missionProgressBar->setValue(values.State*(100/6)); // 6 = number of states
	//	stateComboBox->setCurrentIndex(values.State);
		desiredHeadingSpinBox->setValue(values.DesiredHeading);
		desiredDepthSpinBox->setValue(values.DesiredDepth);
	}else	stateLabel->setText("Remote Controlled");

	rateLabel->setText("Processing at: " + QString::number(1.0/((double)brainTime/1000.0)) + " Hz (" + QString::number(round(100.0/((double)brainTime/1000.0)/5))+ "%)" );

	// Get full color video
	// copy frame from signal to pixmap
	int x = 639;
	int y = 480;
	unsigned int videoPixel;
	for(int i = 307199; i >= 0; --i){
		y--;
		videoPixel = (0xFF000000) | ((((int)brain_B.RGBVid_R[i]) << 16)&0x00FF0000) | ((((int)brain_B.RGBVid_G[i]) << 8)&0x0000FF00) | (((int)brain_B.RGBVid_B[i])&0x000000FF); 
		videoFrame.setPixel(x, y, videoPixel);
		if(y <= 0){
			x--;
			y = 480;
		}
	}
	videoPixmap = QPixmap::fromImage(videoFrame);
	videoLabel->setPixmap(videoPixmap);
	
	if(brain_U.RC == 1) return;

	// Get processed video
	// copy frame from signal to pixmap
	x = 159;
	y = 120;
	for(int i = 19199; i >= 0; --i){
		y--;
		if(values.State == 2){
			bwFrame.setPixel(x, y, brain_B.BW_a[i]);
		}else if(values.State == 3){
			if(brain_DWork.countTo < 4){
				if(i < 9600)	bwFrame.setPixel(x, y, brain_B.BWleft_i[i]);
				else	bwFrame.setPixel(x, y, brain_B.BWright_e[i-9600]);
			}
			else{
				bwFrame.setPixel(x, y, brain_B.DataTypeConversion_h[i]);
			}
		}else if(values.State == 4){
			bwFrame.setPixel(x, y, brain_B.BW_p[i]);
		}else if(values.State == 5){
			bwFrame.setPixel(x, y, brain_B.BW[i]);
		}else bwFrame.setPixel(x, y, 1);

		if(y <= 0){
			x--;
			y = 120;
		}
	}

	bwPixmap = QPixmap::fromImage(bwFrame);
	bitVideoLabel->setPixmap(bwPixmap);
	
	//qDebug("Brain Data on display");
	//qDebug() << "Brain Display Time: " << QString::number(bT.elapsed()) << "ms";
	
}*/

// State Select
void Dashboard::on_stateComboBox_activated(int index){
	emit sendParam("Input.DesiredState", QString::number(index));
}

// controller gains
void Dashboard::on_fwdVelocitySpinBox_valueChanged(double value){
	emit sendParam("Parameter.Heading_Forward_Velocity", QString::number(value));
}
void Dashboard::on_headingDGainSpinBox_valueChanged(double value){
	emit sendParam("Parameter.Heading_Kd", QString::number(value));
}
void Dashboard::on_headingIGainSpinBox_valueChanged(double value){
	emit sendParam("Parameter.Heading_Ki", QString::number(value));
}
void Dashboard::on_headingPGainSpinBox_valueChanged(double value){
	emit sendParam("Parameter.Heading_Kp", QString::number(value));
}
void Dashboard::on_depthDGainSpinBox_valueChanged(double value){
	emit sendParam("Parameter.Depth_Kd", QString::number(value));
}
void Dashboard::on_depthIGainSpinBox_valueChanged(double value){
	emit sendParam("Parameter.Depth_Ki", QString::number(value));
}
void Dashboard::on_depthPGainSpinBox_valueChanged(double value){
	emit sendParam("Parameter.Depth_Kd", QString::number(value));
}
void Dashboard::on_approachVelocitySpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Vision_Forward_Velocity = value;
}
void Dashboard::on_buoyDepthDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Forward_YPosition_Kd = value;
}
void Dashboard::on_buoyDepthIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Forward_YPosition_Ki = value;
}
void Dashboard::on_buoyDepthPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Forward_YPosition_Kp = value;
}
void Dashboard::on_buoyHeadingDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Forward_XPosition_Kd = value;
}
void Dashboard::on_buoyHeadingIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Forward_XPosition_Ki = value;
} 
void Dashboard::on_buoyHeadingPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Forward_XPosition_Kp = value;
}

void Dashboard::on_pathHeadingDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Down_XPos_Kd = value;
}

void Dashboard::on_pathHeadingIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Down_XPos_Ki = value;
} 
void Dashboard::on_pathHeadingPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Down_XPos_Kp = value;
}
void Dashboard::on_pathYDGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Down_YPos_Kd = value;
}
void Dashboard::on_pathYIGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Down_YPos_Ki = value;
} 
void Dashboard::on_pathYPGainSpinBox_valueChanged(double value){
	QMutexLocker locker(modelMutex);
//	brain_P.Cam_Down_YPos_Kp = value;
}

// Vision
void Dashboard::on_pathHueHighSpinBox_valueChanged(double value){
//	QMutexLocker locker(modelMutex);
	emit sendParam("Parameter.Track_HueHigher", QString::number(value));
}
void Dashboard::on_pathHueLowSpinBox_valueChanged(double value){
//	QMutexLocker locker(modelMutex);
	emit sendParam("Parameter.Track_HueLower", QString::number(value));
}
void Dashboard::on_pathSaturationSpinBox_valueChanged(double value){
//	QMutexLocker locker(modelMutex);
	emit sendParam("Parameter.Track_Saturation", QString::number(value));
}
void Dashboard::on_buoyHueHighSpinBox_valueChanged(double value){
//	QMutexLocker locker(modelMutex);
	emit sendParam("Parameter.Buoy_HueHigher", QString::number(value));
}
void Dashboard::on_buoyHueLowSpinBox_valueChanged(double value){
//	QMutexLocker locker(modelMutex);
	emit sendParam("Parameter.Buoy_HueLower", QString::number(value));
}
void Dashboard::on_buoySaturationSpinBox_valueChanged(double value){
//	QMutexLocker locker(modelMutex);
	emit sendParam("Parameter.Buoy_Saturation", QString::number(value));
}

// Calibration
void Dashboard::on_zeroDepthPushButton_clicked(){
	emit sendParam("Calibrate.Depth", "0");
}
void Dashboard::on_setActualDepthPushButton_clicked(){
//	emit setDepth(actualDepthDoubleSpinBox->value());
	emit sendParam("Calibrate.Depth", QString::number(actualDepthDoubleSpinBox->value()));
}


void Dashboard::on_controlGroupBox_toggled(bool rc){
//	emit sendParam("Mode", "Stop");
	emit sendParam("Input.RC", rc?"1":"0");
}
void Dashboard::on_desiredDepthSlider_valueChanged(int value){
	QMutexLocker locker(modelMutex);
//	brain_U.RC_Depth = value;
	emit sendParam("Input.RC_Depth", QString::number(value));
}
void Dashboard::on_desiredStrafeSlider_valueChanged(int value){
	QMutexLocker locker(modelMutex);
//	brain_U.RC_Strafe = value;
	emit sendParam("Input.RC_Strafe", QString::number(value));
}
void Dashboard::on_desiredSpeedSlider_valueChanged(int value){
	QMutexLocker locker(modelMutex);
//	brain_U.RC_ForwardVelocity = value;
	emit sendParam("Input.RC_ForwardVelocity", QString::number(value));
}
void Dashboard::on_desiredHeadingSpinBox_valueChanged(int value){
	QMutexLocker locker(modelMutex);
//	brain_U.RC_Heading = value;
	emit sendParam("Input.RC_Heading", QString::number(value));
}
void Dashboard::on_setAllZeroButton_clicked(){
	desiredDepthSlider->setValue(0);
	desiredStrafeSlider->setValue(0);
	desiredSpeedSlider->setValue(0);
	desiredHeadingSpinBox->setValue(headingLcdNumber->value());
}


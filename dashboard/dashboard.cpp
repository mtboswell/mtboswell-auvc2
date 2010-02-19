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
        trackPixmap = QPixmap(640,480);
        videoFrame = QImage(640,480,QImage::Format_RGB32); // 4 = QImage::Format_RGB32
        trackFrame = QImage(640,480,QImage::Format_Mono);

        trackFrame.setColor(0, 0xFF000000); 
        trackFrame.setColor(1, 0xFFFF0000); 
        videoPixmap.fill(); 
        trackPixmap.fill(); 
	videoLabel->setScaledContents(true);
	bitVideoLabel->setScaledContents(true);
 
}
 
 
void Dashboard::startAction(){
//	qDebug("Dashboard Attempting to start AUV");
	statusBar()->showMessage(tr("Attempting to start AUV"), 2000);
	emit startAUV();
}
void Dashboard::stopAction(){
	statusBar()->showMessage(tr("Attempting to stop AUV"), 2000);
	emit stopAUV();
}
void Dashboard::resetAction(){
	statusBar()->showMessage(tr("Attempting to reset AUV"), 2000);
	emit resetAUV();
}
void Dashboard::killAction(){
	statusBar()->showMessage(tr("Attempting to terminate AUV"), 2000);
	emit killAUV();
}

void Dashboard::recordVideo(bool record){
	if(record) statusBar()->showMessage(tr("Recording..."), 2000);
	else statusBar()->showMessage(tr("Stopping Recording..."), 2000);
//	record_video = record;
	if(record) emit startRecordVideo();
	else emit stopRecordVideo();
}

void Dashboard::updateSensorsView(AUVSensors values){
	
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
	vertThrusterProgressBar->setValue(values.thrusterSpeeds[2]);

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
	*/
}

void Dashboard::updateBrainView(ExternalOutputs_brain values, int brainTime){
	
	//qDebug("Dashboard recieving data from Brain");

	
	//qDebug("Processing Brain Data");
	QTime bT;
	bT.start();

	stateComboBox->setCurrentIndex(values.State);
//	stateLabel->setText(QString::number(values.State));
	desiredHeadingSpinBox->setValue(values.DesiredHeading);
	desiredDepthSpinBox->setValue(values.DesiredDepth);
	rateLabel->setText("Processing at: " + QString::number(1.0/((double)brainTime/1000.0)) + " Hz (" + QString::number(round(100.0/((double)brainTime/1000.0))/6.25))+ "%)" );

	// copy frame from signal to pixmap
	int x = 639;
	int y = 480;
	unsigned int videoPixel;
	for(int i = 307200; i > 0; --i){
		y--;
		videoPixel = (0xFF000000) | ((((int)brain_B.vidR[i]) << 16)&0x00FF0000) | ((((int)brain_B.vidG[i]) << 8)&0x0000FF00) | (((int)brain_B.vidB[i])&0x000000FF); 
		videoFrame.setPixel(x, y, videoPixel);
		if(values.State == 2)
			trackFrame.setPixel(x, y, brain_B.track1Bitmap[i]);
		else if(values.State ==3){
			if(brain_DWork.ErrorCountY > 3)
				trackFrame.setPixel(x, y, brain_B.track3Bitmap[i]);
			else if(brain_DWork.ErrorCountX > 3){
				trackFrame.setPixel(x, y, brain_B.track3Bitmap[i]);
			}
			else{
				trackFrame.setPixel(x, y, brain_B.track2Bitmap[i]);
			}
		}
	//	if(x == 1) trackFrame.setPixel((int)brain_B.BlobCentroidX,y,1);
	//	if(y == 1) trackFrame.setPixel(x,(int)brain_B.BlobCentroidY,1);
//		qDebug(videoPixel);
		if(y <= 0){
			x--;
			y = 480;
		}
	}
	// show centroid
/*
	if(values.State == 2)
		//trackFrame.setPixel(x, y, brain_B.track1Bitmap[i]);
	else if(values.State ==3){
		if(brain_DWork.ErrorCountY > 3)
		//	trackFrame.setPixel(x, y, brain_B.track3Bitmap[i]);
		else if(brain_DWork.ErrorCountX > 3){
			trackFrame.setPixel(centX1, 2, 1);
		}
		else{
			trackFrame.setPixel(x, y, brain_B.track2Bitmap[i]);
		}
	}
*/

	videoPixmap = QPixmap::fromImage(videoFrame);
	trackPixmap = QPixmap::fromImage(trackFrame);
	videoLabel->setPixmap(videoPixmap);
	bitVideoLabel->setPixmap(trackPixmap);
	
	//qDebug("Brain Data on display");
	//qDebug() << "Brain Display Time: " << QString::number(bT.elapsed()) << "ms";
	
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

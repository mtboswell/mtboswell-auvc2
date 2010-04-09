#include <QtGui>
#include "dashboard.h"
#include <QByteArray>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QTime>
#include <QDir>

Dashboard::Dashboard(QMainWindow *parent)
     : QMainWindow(parent)
{
	setupUi(this);
	dashboardWidget->setEnabled(false);
     
	// Connect up Actions
 	connect(actionGo, SIGNAL(triggered()), this, SLOT(startAction()));
 	connect(actionStop, SIGNAL(triggered()), this, SLOT(stopAction()));
 	connect(actionReset, SIGNAL(triggered()), this, SLOT(resetAction()));
 	connect(actionKill, SIGNAL(triggered()), this, SLOT(killAction()));
 	connect(actionQuit, SIGNAL(triggered()), this, SLOT(stopAction()));
 	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
 	connect(actionRecord_Video, SIGNAL(triggered(bool)), this, SLOT(recordVideo(bool)));
 	connect(actionLogData, SIGNAL(triggered(bool)), this, SLOT(logData(bool)));
	connect(actionReconnect, SIGNAL(triggered()), this, SLOT(reconnectAction()));
	connect(actionTurn_Off_AUV, SIGNAL(triggered()), this, SLOT(turnOffAUVAction()));
	connect(actionBroadcast_Data, SIGNAL(triggered()), this, SLOT(broadcastAction()));
	connect(actionConnect_To, SIGNAL(triggered()), this, SLOT(connectToAddress()));

	// Connect to Network Sockets 	
 	connect(&m_DS, SIGNAL(GotAUVUpdate(QString,QString,QString)), this, SLOT(HandleAUVParam(QString,QString,QString)));
 	connect(&m_DS, SIGNAL(AUVNotResponding(int)), this, SLOT(disableDashboard(int)));
 	connect(&m_DS, SIGNAL(connectionRestored()), this, SLOT(enableDashboard()));

 	connect(this, SIGNAL(sendParam(QString,QString)), &m_DS, SLOT(SendParam(QString,QString)));
	connect(this, SIGNAL(setAddress(QString)), &m_DS, SLOT(setRemoteAddr(QString)));

	videoSocket = new VideoSocket(AUV_IP, VIDEO_PORT, DASH_VIDEO_PORT, this);
	bitmapSocket = new VideoSocket(AUV_IP, SECONDARY_VIDEO_PORT, DASH_SECONDARY_VIDEO_PORT, this);
	connect(videoSocket, SIGNAL(frameReady(QImage*)), this, SLOT(HandleVideoFrame(QImage*)));
	connect(bitmapSocket, SIGNAL(frameReady(QImage*)), this, SLOT(HandleBitmapFrame(QImage*)));
 	
	// Populate State Combo Box

	states << "Autonomous";
	states << "Startup";
	states << "Validation Gate";
	states << "Follow Track";
	states << "Find Buoy";
	states << "Approach Buoy";
	states << "Finished";
	stateComboBox->insertItems(0, states);

	// populate Script combo box
	QDir scriptDir("../scripts/");
	scripts = scriptDir.entryList(QDir::Files, QDir::Name | QDir::IgnoreCase);
	scriptsComboBox->insertItems(0, scripts);

	// Heading display graphics
/*
	headingScene = new QGraphicsScene;
	headingLine = new QGraphicsLineItem(0, 0, 0, 50);
	headingScene->addItem(headingLine);

	headingGraphicsView->setScene(headingScene);
*/

	// Processing rate display
	rateLabel = new QLabel("Not Connected");
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
/*
	process = new QProcess();

	QString executable("vlc");

	QStringList arguments;

	arguments << "udp://@:" + QString::number(DASH_VIDEO_PORT);

	process->start(executable, arguments);
*/
	// Connect to AUV
	emit sendParam("Connect.Data", "This");
	emit sendParam("Connect.Video", "This");
	emit sendParam("GetParams", "all");

	videoSocket->start();
	bitmapSocket->start();
 
}

/* *** Actions ******************************* */

void Dashboard::reconnectAction(){
	emit sendParam("Connect.Data", "This");
	emit sendParam("Connect.Video", "This");
	emit sendParam("GetParams", "all");
}

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
	statusBar()->showMessage(tr("Die, bad Robot! Die!"), 2000);
}

void Dashboard::turnOffAUVAction() {
	// TODO - do something with a dialog box to confirm
}

void Dashboard::recordVideo(bool record){
	if(record) statusBar()->showMessage(tr("Recording Video..."), 2000);
	else statusBar()->showMessage(tr("Stopping Video Recording..."), 2000);
	emit sendParam("Flag.Rec", record?"true":"false");
}

void Dashboard::logData(bool log){
	emit sendParam("Flag.Log", log?"true":"false");
}

void Dashboard::broadcastAction(){
	emit sendParam("Connect.Data", "Broadcast");
}

void Dashboard::connectToAddress(){
	bool ok;
	QString text = QInputDialog::getText(this, tr("What is the AUV's IP Address?"),
			  tr("Server Address:"), QLineEdit::Normal,
			  "192.168.3.5", &ok);
	if (ok && !text.isEmpty()) emit setAddress(text);
	reconnectAction();
}


/* *** Networking ******************************************** */

void Dashboard::HandleAUVParam(QString type, QString name, QString value) {
	bool badCmd = false;
	if (type == "AUV") {
		if (name == "Mode") {
			QString modes[4];
			modes[0] = "Ready";
			modes[1] = "Running";
			modes[2] = "Paused";
			modes[3] = "Killed";
			if(value.toInt() > 3 || value.toInt() < 0) badCmd = true;
			else controlStateLabel->setText(modes[value.toInt()]);
		} else if (name == "Heading")
			headingLcdNumber->display(value.toDouble());
			// headingLine->setRotation(value.toDouble());
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
		else if (name == "CameraX") cameraPosXLabel->setText("X: " + value);
		else if (name == "CameraY") cameraPosYLabel->setText("Y: " + value);
		else if (name == "ManualOverrideDisabled") if(value == "true") warningLabel->setText("Warning: Off switch disabled!");
			else warningLabel->setText("");
		else badCmd = true;
		// cameraPosComboBox->setCurrentIndex
	} else if (type == "Brain") {
		if (name == "State") {
			if(value.toInt() == -1) {
				stateLabel->setText("Remote Controlled");
				if(!controlGroupBox->isChecked()) controlGroupBox->setChecked(true); 
			// TODO - uncomment the following line when the brain is updated to output -1 for the RC state
			}//else if(controlGroupBox->isChecked()) controlGroupBox->setChecked(false);
			else stateLabel->setText(states.at(value.toInt()));
			missionProgressBar->setValue(value.toInt() * (100 / 6));
		} else if (name == "Time") {
			rateLabel->setText("Processing at: " + QString::number(1.0/(value.toDouble()/1000.0)) + " Hz (" + QString::number(round(100.0/(value.toDouble()/1000.0)/5))+ "%)" );
		}else badCmd = true;
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
		else badCmd = true;

	}else if(type == "Status"){
		if(value == "Connected") {
			enableDashboard();
		}
		statusBar()->showMessage(value, 5000);
	}
	if(badCmd) qDebug() << "Unrecognized data: " + type + "." + name + "=" + value;
} // end HandleAUVParam()

void Dashboard::HandleVideoFrame(QImage* frame) {
	videoPixmap = QPixmap::fromImage(*frame);
	videoLabel->setPixmap(videoPixmap);
}
void Dashboard::HandleBitmapFrame(QImage* frame) {
	bwPixmap = QPixmap::fromImage(*frame);
	bitVideoLabel->setPixmap(bwPixmap);
}

void Dashboard::disableDashboard(int severity){
	if(severity > 10){
		qDebug() << "Flaky connection or you are hitting buttons too fast";
	}
	if(severity > 20){
		qDebug() << QString::number(severity) + " missing packets, pausing";
		//dashboardWidget->setEnabled(false);
		controlGroupBox->setEnabled(false);
		tabContainer->setEnabled(false);
	}
}
void Dashboard::enableDashboard(){
	dashboardWidget->setEnabled(true);
	controlGroupBox->setEnabled(true);
	tabContainer->setEnabled(true);
}



/*void Dashboard::updateBrainView(ExternalOutputs_brain values, int brainTime){

		desiredHeadingSpinBox->setValue(values.DesiredHeading);
		desiredDepthSpinBox->setValue(values.DesiredDepth);

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


/* *** GUI event handlers **************************************** */

// State Select
void Dashboard::on_stateComboBox_activated(int index){
	emit sendParam("Input.DesiredState", QString::number(index));
}

// controller gains
void Dashboard::on_fwdVelocitySpinBox_editingFinished(){
	emit sendParam("Parameter.Heading_Forward_Velocity", QString::number(fwdVelocitySpinBox->value()));
}
void Dashboard::on_headingDGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Heading_Kd", QString::number(headingDGainSpinBox->value()));
}
void Dashboard::on_headingIGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Heading_Ki", QString::number(headingIGainSpinBox->value()));
}
void Dashboard::on_headingPGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Heading_Kp", QString::number(headingPGainSpinBox->value()));
}
void Dashboard::on_depthDGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Depth_Kd", QString::number(depthDGainSpinBox->value()));
}
void Dashboard::on_depthIGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Depth_Ki", QString::number(depthIGainSpinBox->value()));
}
void Dashboard::on_depthPGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Depth_Kd", QString::number(depthPGainSpinBox->value()));
}
void Dashboard::on_approachVelocitySpinBox_editingFinished(){
	emit sendParam("Parameter.Vision_Forward_Velocity", QString::number(approachVelocitySpinBox->value()));
}
void Dashboard::on_buoyDepthDGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Forward_YPosition_Kd", QString::number(buoyDepthDGainSpinBox->value()));
}
void Dashboard::on_buoyDepthIGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Forward_YPosition_Ki", QString::number(buoyDepthIGainSpinBox->value()));
}
void Dashboard::on_buoyDepthPGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Forward_YPosition_Kp", QString::number(buoyDepthPGainSpinBox->value()));
}
void Dashboard::on_buoyHeadingDGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Forward_XPosition_Kd", QString::number(buoyHeadingDGainSpinBox->value()));
}
void Dashboard::on_buoyHeadingIGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Forward_XPosition_Ki", QString::number(buoyHeadingIGainSpinBox->value()));
} 
void Dashboard::on_buoyHeadingPGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Forward_XPosition_Kp", QString::number(buoyHeadingPGainSpinBox->value()));
}
/*
void Dashboard::on_pathHeadingDGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Down_XPos_Kd", QString::number(pathHeadingDGainSpinBox->value()));
}

void Dashboard::on_pathHeadingIGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Down_XPos_Ki", QString::number(pathHeadingIGainSpinBox->value()));
} 
void Dashboard::on_pathHeadingPGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Down_XPos_Kp", QString::number(pathHeadingPGainSpinBox->value()));
}
void Dashboard::on_pathYDGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Down_YPos_Kd", QString::number(pathYDGainSpinBox->value()));
}
void Dashboard::on_pathYIGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Down_YPos_Ki", QString::number(pathYIGainSpinBox->value()));
} 
void Dashboard::on_pathYPGainSpinBox_editingFinished(){
	emit sendParam("Parameter.Cam_Down_YPos_Kp", QString::number(pathYPGainSpinBox->value()));
}
*/

// Vision
void Dashboard::on_pathHueHighSpinBox_editingFinished(){
	emit sendParam("Parameter.Track_HueHigher", QString::number(pathHueHighSpinBox->value()));
}
void Dashboard::on_pathHueLowSpinBox_editingFinished(){
	emit sendParam("Parameter.Track_HueLower", QString::number(pathHueLowSpinBox->value()));
}
void Dashboard::on_pathSaturationSpinBox_editingFinished(){
	emit sendParam("Parameter.Track_Saturation", QString::number(pathSaturationSpinBox->value()));
}
void Dashboard::on_buoyHueHighSpinBox_editingFinished(){
	emit sendParam("Parameter.Buoy_HueHigher", QString::number(buoyHueHighSpinBox->value()));
}
void Dashboard::on_buoyHueLowSpinBox_editingFinished(){
	emit sendParam("Parameter.Buoy_HueLower", QString::number(buoyHueLowSpinBox->value()));
}
void Dashboard::on_buoySaturationSpinBox_editingFinished(){
	emit sendParam("Parameter.Buoy_Saturation", QString::number(buoySaturationSpinBox->value()));
}
void Dashboard::on_whiteBalancePushButton_clicked(){
	emit sendParam("Calibrate.WhiteBalance", "once");
}

// Calibration
void Dashboard::on_zeroDepthPushButton_clicked(){
	emit sendParam("Calibrate.Depth", "0");
}
void Dashboard::on_setActualDepthPushButton_clicked(){
	emit sendParam("Calibrate.Depth", QString::number(actualDepthDoubleSpinBox->value()));
}


// RC Controls
void Dashboard::on_controlGroupBox_toggled(bool rc){
	emit sendParam("Mode", "Stop");
	emit sendParam("Input.RC", rc?"1":"0");
	if(rc) stateLabel->setText("Remote Controlled");
	else stateLabel->setText("Not Started");
}
void Dashboard::on_desiredDepthSlider_valueChanged(int value){
	emit sendParam("Input.RC_Depth", QString::number(value));
}
void Dashboard::on_desiredStrafeSlider_valueChanged(int value){
	emit sendParam("Input.RC_Strafe", QString::number(value));
}
void Dashboard::on_desiredSpeedSlider_valueChanged(int value){
	emit sendParam("Input.RC_ForwardVelocity", QString::number(value));
}
void Dashboard::on_desiredHeadingSpinBox_valueChanged(int value){
	emit sendParam("Input.RC_Heading", QString::number(value));
}
void Dashboard::on_setAllZeroButton_clicked(){
	desiredDepthSlider->setValue(0);
	desiredStrafeSlider->setValue(0);
	desiredSpeedSlider->setValue(0);
	desiredHeadingSpinBox->setValue((headingLcdNumber->value()>180)?headingLcdNumber->value()-360:headingLcdNumber->value());
}

void Dashboard::on_runScriptPushButton_clicked(){
	emit sendParam("Activate.Script", scriptsComboBox->currentText());
}


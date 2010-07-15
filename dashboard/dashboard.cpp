#include <QtGui>
#include "dashboard.h"
#include <QByteArray>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QTime>
#include <QDir>
#include "../src/auv/mechanisms.h"

QMap<QString, QString> config;

Dashboard::Dashboard(QMainWindow *parent)
     : QMainWindow(parent)
{
	setupUi(this);

	loadConfigFile(config);

	m_DS = new SIDSocket((quint16) config["Client.Port.Data"].toUInt(), (quint16) config["Server.Port.Data"].toUInt());

	videoLabel->hide();
	videoWidget = new VideoWidget(videoContainer);
	videoContainerLayout->addWidget(videoWidget);

	dashboardWidget->setEnabled(false);
     
	// Connect up Actions
 	connect(actionGo, SIGNAL(triggered()), this, SLOT(startAction()));
 	connect(actionStop, SIGNAL(triggered()), this, SLOT(stopAction()));
 	connect(actionReset, SIGNAL(triggered()), this, SLOT(resetAction()));
 	connect(actionKill, SIGNAL(triggered()), this, SLOT(killAction()));
 	connect(actionQuit, SIGNAL(triggered()), this, SLOT(stopAction()));
 	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
 	connect(actionRecord_Video, SIGNAL(triggered(bool)), this, SLOT(recordVideo(bool)));
	connect(actionReconnect, SIGNAL(triggered()), this, SLOT(reconnectAction()));
	connect(actionTurn_Off_AUV, SIGNAL(triggered()), this, SLOT(turnOffAUVAction()));
	connect(actionBroadcast_Data, SIGNAL(triggered()), this, SLOT(unbroadcastAction()));
	connect(actionConnect_To, SIGNAL(triggered()), this, SLOT(connectToAddress()));
	connect(actionConnect_to_LocalHost, SIGNAL(triggered()), this, SLOT(connectToLocalhost()));
	connect(actionLoad_Parameters, SIGNAL(triggered()), this, SLOT(loadParameters()));
	connect(actionSave_Parameters, SIGNAL(triggered()), this, SLOT(saveParameters()));
	connect(actionLoad_Script, SIGNAL(triggered()), this, SLOT(sendScript()));

	// Connect to Network Sockets 	
 	connect(m_DS, SIGNAL(sidReceived(QString,QString,QHostAddress)), this, SLOT(handleAUVParam(QString,QString)));
 	connect(m_DS, SIGNAL(remoteNotResponding(QString,QString)), this, SLOT(disableDashboard(QString,QString)));
 	connect(m_DS, SIGNAL(connectionRestored()), this, SLOT(enableDashboard()));

 	connect(this, SIGNAL(sendSID(QString,QString)), m_DS, SLOT(sendSID(QString,QString)));
	connect(this, SIGNAL(setAddress(QString)), m_DS, SLOT(setRemoteAddr(QString)));

	videoSocket = new VideoSocket(config["Server.IP"], config["Server.Port.Video1"].toUInt(), config["Client.Port.Video1"].toUInt(), this);
	bitmapSocket = new VideoSocket(config["Server.IP"], config["Server.Port.Video2"].toUInt(), config["Client.Port.Video2"].toUInt(), this);
	connect(videoSocket, SIGNAL(frameReady(QImage*)), this, SLOT(HandleVideoFrame(QImage*)));
	connect(bitmapSocket, SIGNAL(frameReady(QImage*)), this, SLOT(HandleBitmapFrame(QImage*)));
 	
	// Populate State Combo Box

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
	stateComboBox->insertItems(0, states);

	// populate Script combo box
	QDir scriptDir("../scripts/");
	scripts = scriptDir.entryList(QDir::Files, QDir::Name | QDir::IgnoreCase);
	scriptsComboBox->insertItems(0, scripts);

	// populate mech combo box
	populateMechs(mechanisms);
	mechsComboBox->insertItems(0, mechanisms.keys());

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
	//videoWidget->setScaledContents(true);
	//bitVideoLabel->setScaledContents(true);

	// init controls
	RC = desiredSpeed = desiredHeading = desiredDepth = desiredStrafe = desiredVideoStream = 0;
	desiredCameraX = desiredCameraY = 0;
	desiredSpeedSlider->setTracking(false);
	desiredDepthSlider->setTracking(false);
	desiredStrafeSlider->setTracking(false);
	desiredHeadingDial->setTracking(false);

	// Connect to AUV
	//emit sendSID("Connect.Data", "This");
	//emit sendSID("Connect.Video", "This");
	//emit sendSID("GetParams", "all");
	reconnectAction();

	videoSocket->start();
	bitmapSocket->start();

        logger = new DataLogger(this, "logs/data-" + QDateTime::currentDateTime().toString("yyyy-MM-dd+hh-mm") + ".csv", 1000, config["StepTime.DataLog"].toInt(), ",");
 	connect(actionLogData, SIGNAL(triggered(bool)), logger, SLOT(enable(bool)));
	connect(this, SIGNAL(sendSID(QString,QString)), this, SLOT(logCmd(QString, QString)));

	timeSinceLastDataReceived = new QTime();
	timeSinceLastDataReceived->start();
	dataTimeoutTimer = new QTimer();
	connect(dataTimeoutTimer, SIGNAL(timeout()), this, SLOT(checkForDataTimeout()));
	dataTimeoutTimer->start(100);

}

Dashboard::~Dashboard(){
	delete logger;
	delete videoSocket;
	delete bitmapSocket;
	delete m_DS;
}

/* *** Actions ******************************* */

void Dashboard::reconnectAction(){
	emit sendSID("Connect.Data", "Broadcast");
        emit sendSID("Connect.Video", "This");
	emit sendSID("GetParams", "all");
#ifndef _WIN32
	emit sendSID("Dashboard.Version", getVersion());
#endif
}

void Dashboard::startAction(){
	statusBar()->showMessage(tr("Attempting to start AUV"), 2000);
	emit sendSID("Mode", "Run");
	controlGroupBox->setEnabled(true);
}
void Dashboard::stopAction(){
	statusBar()->showMessage(tr("Attempting to stop AUV"), 2000);
	emit sendSID("Mode", "Stop");
	controlGroupBox->setEnabled(false);
}
void Dashboard::resetAction(){
	statusBar()->showMessage(tr("Attempting to reset AUV"), 2000);
	emit sendSID("Mode", "Reset");
	controlGroupBox->setEnabled(true);
}
void Dashboard::killAction(){
	emit sendSID("Mode", "Kill");
	statusBar()->showMessage(tr("Die, bad Robot! Die!"), 2000);
}

void Dashboard::turnOffAUVAction() {
	// TODO - do something with a dialog box to confirm
}

void Dashboard::recordVideo(bool record){
	if(record) statusBar()->showMessage(tr("Recording Video..."), 2000);
	else statusBar()->showMessage(tr("Stopping Video Recording..."), 2000);
	emit sendSID("Flag.Rec", record?"true":"false");
}

void Dashboard::logData(bool log){
	logger->enable(log);
	//emit sendSID("Flag.Log", log?"true":"false");
}
void Dashboard::logCmd(QString id, QString data){
	logger->logData("LastCommand", id + "=" + data+";");
}

void Dashboard::unbroadcastAction(){
	emit sendSID("Connect.Data", "This");
        emit sendSID("Connect.Video", "This");
	emit sendSID("GetParams", "all");
}

void Dashboard::connectToAddress(){
	bool ok;
	QString text = QInputDialog::getText(this, tr("What is the AUV's IP Address?"),
			  tr("Server Address:"), QLineEdit::Normal,
			  "192.168.3.5", &ok);
	if (ok && !text.isEmpty()) emit setAddress(text);
	reconnectAction();
}
void Dashboard::connectToLocalhost(){
	emit setAddress("127.0.0.1");
	emit sendSID("Connect.Data", "127.0.0.1");
	emit sendSID("Connect.Video", "127.0.0.1");
	emit sendSID("GetParams", "all");
}

void Dashboard::sendScript(){
	bool ok;
	QString scriptFilename = QFileDialog::getOpenFileName(this, tr("Open an AUVScript File"), QDir::homePath(), "*.avs");
	if (!scriptFilename.isEmpty()){
		QFile scriptFile(scriptFilename);
		if(!scriptFile.open(QIODevice::ReadOnly | QIODevice::Text)) return;
		QStringList script;
		while (!scriptFile.atEnd()) {
			QByteArray line = scriptFile.readLine();
			if(!line.startsWith("#") && !line.contains(";")) script.append(line.simplified());
		}

		emit sendSID("Script.New", scriptFilename+",,"+script.join(","));
	}
}


/* *** Networking ******************************************** */

/**
 * This gargantuan function is responsible for decoding the 
 * 	data received by the network port.  The data may be coming from
 * 	the AUV or other instances of the dashboard (via broadacst echo from the AUV).
 * 	If the data does not fit one of the many possibilities below, the event
 *	is logged with qDebug().
 */

void Dashboard::handleAUVParam(QString id, QString value) {
	bool badCmd = false;
	timeSinceLastDataReceived->restart();
	QString type, name;
	QStringList ids = id.split('.');
	if(ids.size() > 0) type = ids[0];
	else type = "";
	if(ids.size() > 1) name = ids[1];
	else name = "";
	if (type == "AUV") {
		if (name == "Mode") {
			QString modes[4];
			modes[0] = "Ready";
			modes[1] = "Running";
			modes[2] = "Stopped";
			modes[3] = "Killed";
			if(value.toInt() > 3 || value.toInt() < 0) badCmd = true;
			else controlStateLabel->setText(modes[value.toInt()]);
		} else if (name == "Heading"){
			headingLcdNumber->display(value.toDouble());
			headingDial->setValue(value.toDouble());
			// headingLine->setRotation(value.toDouble());
		}else if (name == "Depth"){
			depthLcdNumber->display(value.toDouble());
			depthBar->setValue(value.toDouble());
		}else if (name == "ThrusterVoltage")
			thVoltageLcdNumber->display(value.toDouble());
		else if (name == "ThrusterCurrent")
			thCurrentLcdNumber->display(value.toDouble());
		else if (name == "MainVoltage")
			mainVoltageLcdNumber->display(value.toDouble());
		else if (name == "MainCurrent")
			mainCurrentLcdNumber->display(value.toDouble());
		else if (name == "LeftThruster")
			leftThrusterProgressBar->setValue(value.toDouble());
		else if (name == "RightThruster")
			rightThrusterProgressBar->setValue(value.toDouble());
		else if (name == "VerticalThruster")
			vertThrusterProgressBar->setValue(value.toDouble());
		else if (name == "LateralThruster")
			strafeThrusterProgressBar->setValue(value.toDouble());
		else if (name == "CameraX") cameraPosXLabel->setText("X: " + value);
		else if (name == "CameraY") cameraPosYLabel->setText("Y: " + value);
		else if (name == "ManualOverrideDisabled") if(value == "true") warningLabel->setText("Warning: Off switch disabled!");
			else warningLabel->setText("");
		else badCmd = true;
		// cameraPosComboBox->setCurrentIndex
	} else if (type == "Brain") {
		if (name == "State") {
			if(value.toDouble() == -1) {
				// RC state
				stateLabel->setText("Remote Control");
				// set RC to make sure we don't send a command
				RC = 1;
				if(!controlGroupBox->isChecked()) {
					controlGroupBox->setChecked(true); 
					tabWidget->setCurrentWidget(controlsPage);
				}
			}else if(value.toDouble() == -2) {
				// stopped state
				stateLabel->setText("Stopped");
				// enter RC state as soon as we leave the stopped state
				/*
				if(!controlGroupBox->isChecked()) {
					controlGroupBox->setChecked(true); 
					tabWidget->setCurrentWidget(controlsPage);
				}
				*/
			}else{
				RC = 0;
				if(controlGroupBox->isChecked()){
					controlGroupBox->setChecked(false);
					tabWidget->setCurrentWidget(videoPage);
				}
				if(value.toInt() >= states.size() || value.toInt() < 0) badCmd = true;
				else stateLabel->setText(states.at(value.toInt()));
				missionProgressBar->setValue(value.toInt() * (100 / 6));
			}
		} else if (name == "Time") {
			// target brain step frequency
			// TODO - use actual define value
			int targetRate = 5;//Hz
			rateLabel->setText("Processing at: " 
				+ QString::number(1.0/(value.toDouble()/1000.0)) + " Hz (" 
				+ QString::number(round(100.0/(value.toDouble()/1000.0)/targetRate))
				+ "%)" );
		}else badCmd = true;
	}else if (type == "Input"){ // RC commands from other dashboards
		int intValue = value.toInt();
		if(name == "RC_Depth") {
			if(intValue != desiredDepth){
				desiredDepth = intValue;
				desiredDepthSlider->setValue(intValue);
			}
		}else if(name == "RC_Strafe"){
			if(intValue != desiredStrafe){
				desiredStrafe = intValue;
				desiredStrafeSlider->setValue(intValue);
			}
		}else if(name == "RC_ForwardVelocity") {
			if(intValue != desiredSpeed){
				desiredSpeed = intValue;
				desiredSpeedSlider->setValue(intValue);
			}
		}else if(name == "RC_Heading"){
			if(intValue != desiredHeading){
				desiredHeading = intValue;
				desiredHeadingSpinBox->setValue(intValue);
			}
		}else if(name == "RC") {
			RC = value.toInt();
			controlGroupBox->setChecked((value == "1")?true:false);
		}else if(name == "DesiredState") {
			stateComboBox->setCurrentIndex(value.toInt());
		}else badCmd = true;
	} else if (type == "Video" && name == "Stream"){
		int intValue = value.toInt();
		if(intValue != desiredVideoStream){
			desiredVideoStream = intValue;
			videoStreamComboBox->setCurrentIndex(intValue);
		}
	} else if (type == "Parameter") { // parameter values from Brain
		// these get set once at startup and if changed by another dashboard
		double paramVal = value.toDouble();
		// update parameters
		// controller gain initial settings

		// uses parameters.def to assign to the correct box
		if(false);
#define GEN_PARAM(guiParam,brainParam) \
		else if(name == #brainParam) guiParam->setValue(paramVal);
#include "parameters.def"
		else badCmd = true;

	}else if(type == "Status"){
		// wait for the Status=Connected packet before enabling the interface
		if(value == "Connected") {
			enableDashboard();
		}
		// display AUV status messages
		statusBar()->showMessage(value, 5000);
		if(value.contains("Error:")){
			QMessageBox::warning(this, "AUV Error", value);
		}
	}else if(type == "Connect" || type == "GetParams" || type == "Dashboard"){
		// these are special becuase the echos don't get filtered out.
		// that means it could be us or anyone connecting
		statusBar()->showMessage("Someone (maybe you) is connecting to the AUV...", 5000);
	}else badCmd = true;
	// catch and log unparsed commands or data
	if(badCmd) qDebug() << "Unrecognized data: " + type + "." + name + "=" + value;
	else if(type=="AUV" || type=="Brain" || type=="Parameter" || type=="Status") logger->logData(id, value);
	else logCmd(id, value);

} // end HandleAUVParam()

// copy video frames into video labels
void Dashboard::HandleVideoFrame(QImage* frame) {
	videoPixmap = QPixmap::fromImage(*frame);
	videoWidget->setPixmap(videoPixmap.scaled(videoWidget->size(),Qt::KeepAspectRatio));
}
void Dashboard::HandleBitmapFrame(QImage* frame) {
	bwPixmap = QPixmap::fromImage(*frame);
	bitVideoLabel->setPixmap(bwPixmap.scaled(bitVideoLabel->size(),Qt::KeepAspectRatio));
}

// disableDashboard gets called when the number of commands
//  that have not been acknowledged reaches 15 or higher
//  Severity is the number of commands that have not been acknowledged by the AUV.
void Dashboard::disableDashboard(QString missedId, QString missedData){
	qDebug() << "Flaky connection or you are hitting buttons too fast";
	// if enough packets go missing, disable the controls to prevent more pileup
	//dashboardWidget->setEnabled(false);
	controlGroupBox->setEnabled(false);
	tabContainer->setEnabled(false);
	if(missedId == "timeout")
		dashboardWidget->setEnabled(false);
}
void Dashboard::enableDashboard(){
	dashboardWidget->setEnabled(true);
	controlGroupBox->setEnabled(true);
	tabContainer->setEnabled(true);
}

void Dashboard::checkForDataTimeout(){
	if(dashboardWidget->isEnabled() && timeSinceLastDataReceived->elapsed() >= 1000) {
		disableDashboard("timeout", "");
	}else if(!dashboardWidget->isEnabled() && timeSinceLastDataReceived->elapsed() < 1000){
		enableDashboard();
	}
}


/* *** Keyboard event handler ******************************** */

void Dashboard::keyPressEvent(QKeyEvent* event){
	int key = event->key();
	switch(key){
		case Qt::Key_F1: startAction(); break;
		case Qt::Key_F2: stopAction(); break;
		case Qt::Key_F3: resetAction(); break;
		case Qt::Key_F4: killAction(); break;
		case Qt::Key_F5: reconnectAction(); break;
		case Qt::Key_F9: connectToLocalhost(); break;
		case Qt::Key_F35: qDebug() << "I want your keyboard!"; break;
		case Qt::Key_0:
			stateComboBox->setCurrentIndex(0);
			emit sendSID("Input.DesiredState", "0");
			break;
		case Qt::Key_1:
			stateComboBox->setCurrentIndex(1);
			emit sendSID("Input.DesiredState", "1");
			break;
		case Qt::Key_2:
			stateComboBox->setCurrentIndex(2);
			emit sendSID("Input.DesiredState", "2");
			break;
		case Qt::Key_3:
			stateComboBox->setCurrentIndex(3);
			emit sendSID("Input.DesiredState", "3");
			break;
		case Qt::Key_4:
			stateComboBox->setCurrentIndex(4);
			emit sendSID("Input.DesiredState", "4");
			break;
		case Qt::Key_5:
			stateComboBox->setCurrentIndex(5);
			emit sendSID("Input.DesiredState", "5");
			break;
		case Qt::Key_6: // we only have 5 states as of this writing break;
		case Qt::Key_7:
			break;
		case Qt::Key_8:
			break;
		case Qt::Key_9:
			break;
		case Qt::Key_BassBoost: qDebug() << "Party in the AUV!"; break;
		case Qt::Key_LightBulb: // TODO - turn on lights break;
		//case Qt::Key_Go: startAction(); break;
		//case Qt::Key_Execute: startAction(); break;
		case Qt::Key_Play: startAction(); break;
		case Qt::Key_Cancel: stopAction(); break;
		case Qt::Key_Sleep: stopAction(); break;
		case Qt::Key_Control:
			if(controlGroupBox->isChecked()) {
				controlGroupBox->setChecked(false);
				tabWidget->setCurrentWidget(videoPage);
				this->setFocus(Qt::OtherFocusReason);
			}else{
				controlGroupBox->setChecked(true);
				tabWidget->setCurrentWidget(controlsPage);
				this->setFocus(Qt::OtherFocusReason);
			}
			break;
		case Qt::Key_Left: 
			desiredHeadingDial->triggerAction(QAbstractSlider::SliderSingleStepSub); 
			if(desiredHeadingDial->value() == 0) desiredHeadingDial->setValue(360);
			break;
		case Qt::Key_Up: desiredSpeedSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd); break;
		case Qt::Key_Right: 
			desiredHeadingDial->triggerAction(QAbstractSlider::SliderSingleStepAdd); 
			if(desiredHeadingDial->value() == 360) desiredHeadingDial->setValue(0);
			break;
		case Qt::Key_Down: desiredSpeedSlider->triggerAction(QAbstractSlider::SliderSingleStepSub); break;
		case Qt::Key_PageUp: desiredDepthSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd); break;
		case Qt::Key_PageDown: desiredDepthSlider->triggerAction(QAbstractSlider::SliderSingleStepSub); break;
		case Qt::Key_W: desiredSpeedSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd); break;
		case Qt::Key_A: 
			desiredHeadingDial->triggerAction(QAbstractSlider::SliderSingleStepSub); 
			if(desiredHeadingDial->value() == 0) desiredHeadingDial->setValue(360);
			break;
		case Qt::Key_S: desiredSpeedSlider->triggerAction(QAbstractSlider::SliderSingleStepSub); break;
		case Qt::Key_D: 
			desiredHeadingDial->triggerAction(QAbstractSlider::SliderSingleStepAdd); 
			if(desiredHeadingDial->value() == 360) desiredHeadingDial->setValue(0);
			break;
		case Qt::Key_Q: desiredDepthSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd); break;
		case Qt::Key_E: desiredDepthSlider->triggerAction(QAbstractSlider::SliderSingleStepSub); break;
		case Qt::Key_Z: desiredStrafeSlider->triggerAction(QAbstractSlider::SliderSingleStepSub); break;
		case Qt::Key_C: desiredStrafeSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd); break;
		case Qt::Key_X: on_setAllZeroButton_clicked(); break;
		case Qt::Key_T: 
			camPosYSpinBox->stepDown();
			break;
		case Qt::Key_G:
			camPosYSpinBox->stepUp();
			break;
		case Qt::Key_F:
			camPosXSpinBox->stepDown();
			break;
		case Qt::Key_H:
			camPosXSpinBox->stepUp();
			break;
		case Qt::Key_K: stopAction(); break;
		default:
			QMainWindow::keyPressEvent(event);
			break;
	}
} // end Key Event Handler


/* *** GUI event handlers **************************************** */

void Dashboard::on_goButton_clicked(){
	startAction();
}
void Dashboard::on_stopButton_clicked(){
	stopAction();
}

// State Select
void Dashboard::on_stateComboBox_activated(int index){
	emit sendSID("Input.DesiredState", QString::number(index));
}

// White Balance Camera
void Dashboard::on_whiteBalancePushButton_clicked(){
	emit sendSID("Calibrate.WhiteBalance", "once");
}

void Dashboard::on_videoStreamComboBox_activated(int index){
	if(index != desiredVideoStream){
		desiredVideoStream = index;
		emit sendSID("Video.Stream", QString::number(index));
	}
}

// Depth Calibration
void Dashboard::on_zeroDepthPushButton_clicked(){
	emit sendSID("Calibrate.Depth", "0");
}
void Dashboard::on_setActualDepthPushButton_clicked(){
	emit sendSID("Calibrate.Depth", QString::number(actualDepthDoubleSpinBox->value()));
}

// RC Controls
void Dashboard::on_controlGroupBox_toggled(bool rc){
//	emit sendSID("Mode", "Stop");
	if(rc && RC == 0){
		emit sendSID("Input.RC", "1");
		on_setAllZeroButton_clicked();
	}else if(!rc && RC == 1){
		emit sendSID("Input.RC", "0");
	}
	RC = rc?1:0;
	if(RC == 1) stateLabel->setText("Remote Control");
	else stateLabel->setText("Confuzzled");
}
void Dashboard::on_desiredDepthSlider_valueChanged(int value){
	if(value != desiredDepth){
		desiredDepth = value;
		emit sendSID("Input.RC_Depth", QString::number(value));
	}	
}
void Dashboard::on_desiredStrafeSlider_valueChanged(int value){
	if(value != desiredStrafe){
		desiredStrafe = value;
		emit sendSID("Input.RC_Strafe", QString::number(value));
	}
}
void Dashboard::on_desiredSpeedSlider_valueChanged(int value){
	if(value != desiredSpeed){
		desiredSpeed = value;
		emit sendSID("Input.RC_ForwardVelocity", QString::number(value));
	}
}
void Dashboard::on_desiredHeadingDial_valueChanged(int value){
	if(value != desiredHeading){
		desiredHeading = value;
		emit sendSID("Input.RC_Heading", QString::number(value));
	}
}
void Dashboard::on_desiredHeadingSpinBox_editingFinished(){
	emit sendSID("Input.RC_Heading", QString::number(desiredHeadingSpinBox->value()));
}
void Dashboard::on_desiredDepthSpinBox_editingFinished(){
	emit sendSID("Input.RC_Depth", QString::number(desiredDepthSpinBox->value()));
}
void Dashboard::on_desiredSpeedSpinBox_editingFinished(){
	emit sendSID("Input.RC_ForwardVelocity", QString::number(desiredSpeedSpinBox->value()));
}
void Dashboard::on_desiredStrafeSpinBox_editingFinished(){
	emit sendSID("Input.RC_Strafe", QString::number(desiredStrafeSpinBox->value()));
}
void Dashboard::on_setAllZeroButton_clicked(){
	desiredDepthSlider->setValue(depthLcdNumber->value());
	desiredStrafeSlider->setValue(0);
	desiredSpeedSlider->setValue(0);
	desiredHeadingDial->setValue(headingLcdNumber->value());
}

// Other buttons
void Dashboard::on_runScriptPushButton_clicked(){
	emit sendSID("Activate.Script", scriptsComboBox->currentText());
}
void Dashboard::on_actuateMechPushButton_clicked(){
	emit sendSID("Actuate.Mechanism", mechsComboBox->currentText());
}


// Camera
void Dashboard::on_camPosXSpinBox_valueChanged(double value){
	emit sendSID("Move.Camera", QString::number(camPosXSpinBox->value()) + "," + QString::number(camPosYSpinBox->value())); 
}
void Dashboard::on_camPosYSpinBox_valueChanged(double value){
	emit sendSID("Move.Camera", QString::number(camPosXSpinBox->value()) + "," + QString::number(camPosYSpinBox->value())); 
}


/* Save/Load parameters ****************************** */
void Dashboard::saveParameters(){
	QString  saveFilename = QFileDialog::getSaveFileName (this, "Save parameters to file", "params/", "Parameter Matlab files (*.m)");
	QFile saveFile(saveFilename);

	if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
		return;

	QTextStream out(&saveFile);
	out << QString("% Parameters file generated ") + QDateTime::currentDateTime().toString() << endl;

#define GEN_PARAM(guiParam,brainParam) \
	out << QString(#brainParam) + " = " + QString::number(guiParam->value()) + ";" << endl;
#include "parameters.def"
	
	saveFile.close();

}
void Dashboard::loadParameters(){
	QString  loadFilename = QFileDialog::getOpenFileName (this, "Load parameters from file", "params/", "Parameter files (*.params *.m)");
	QFile loadFile(loadFilename);
	if (!loadFile.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	m_DS->buffer();
	QTextStream in(&loadFile);
	while (!in.atEnd()) {
		QString line = in.readLine();
		loadParameter(line.simplified());
	}

	loadFile.close();
	m_DS->flush();

}

void Dashboard::loadParameter(QString param){
	if(param.isEmpty() || param.startsWith("%") || !param.contains("=")) return;
	QStringList codeLines = param.split(";");
	foreach(QString codeLine, codeLines){
		if(!codeLine.contains("=")) continue;
		QStringList paramLine = codeLine.split("=");
		if(paramLine.size() < 2) continue;
		QString paramName = paramLine.at(0).trimmed();
		bool ok;
		double paramVal = paramLine.at(1).trimmed().toDouble(&ok);
		if(!ok) continue; 
		else{
			if(false);
#define GEN_PARAM(guiParam,brainParam) \
			else if(paramName == #brainParam){\
				guiParam->setValue(paramVal); \
				emit sendSID(QString("Parameter.") + QString(#brainParam), QString::number(paramVal)); \
			}
#include "parameters.def"
		}
	}
}


/* *** Parameters Interface ************************************** */
// Code Generation!
// Edit parameters.def to change the parameters

#define GEN_PARAM(guiParam,brainParam) \
void Dashboard::on_##guiParam##_editingFinished(){ \
	emit sendSID(QString("Parameter.") + QString(#brainParam), QString::number(guiParam->value())); \
}
#include "parameters.def"



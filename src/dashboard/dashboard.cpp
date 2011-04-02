#include <QtGui>
#include "dashboard.h"
#include <QByteArray>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QTime>
#include <QDir>

//QMap<QString, QString> config;

Dashboard::Dashboard(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QWidget* parent)
     : GuiModule(configIn, stateIn, parent)
{
	// create UI (generated by uic from designer file)
	setupUi(this);


	// setup video widget to support maximized/fullscreen video
	videoPlaceholder->hide();
	videoWidget = new VideoWidget(videoContainerWidget);
	// the video widget may need to be in a layout, this hasn't been tested
	//videoWidgetTargetLayout->addWidget(videoWidget);

	// disable interface until connected
	// comment out for testing
	//dashboardWidget->setEnabled(false);
     
	// Connect up Actions
 	connect(actionGo_Autonomous, SIGNAL(triggered()), this, SLOT(startAutonomousAction()));
 	connect(actionGo_RC, SIGNAL(triggered()), this, SLOT(startRCAction()));
 	connect(actionStop, SIGNAL(triggered()), this, SLOT(stopAction()));
 	connect(actionReset, SIGNAL(triggered()), this, SLOT(resetAction()));
 	connect(actionKill, SIGNAL(triggered()), this, SLOT(killAction()));
	connect(actionTurn_Off_AUV, SIGNAL(triggered()), this, SLOT(turnOffAUVAction()));

 	connect(actionQuit, SIGNAL(triggered()), this, SLOT(stopAction()));
 	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));

	connect(actionConnect_To, SIGNAL(triggered()), this, SLOT(connectToAddress()));
	connect(actionConnect_to_LocalHost, SIGNAL(triggered()), this, SLOT(connectToLocalhost()));
	connect(actionReconnect, SIGNAL(triggered()), this, SLOT(reconnectAction()));
	connect(actionBroadcast_Data, SIGNAL(triggered()), this, SLOT(unbroadcastAction()));

 	connect(actionRecord_Video, SIGNAL(triggered(bool)), this, SLOT(recordVideo(bool)));
	connect(actionLoad_Parameters, SIGNAL(triggered()), this, SLOT(loadParameters()));
	connect(actionSave_Parameters, SIGNAL(triggered()), this, SLOT(saveParameters()));
	connect(actionLoad_Script, SIGNAL(triggered()), this, SLOT(sendScript()));

	// Connect to Network Sockets 	
 	//connect(m_DS, SIGNAL(tmfReceived(VDatum,QHostAddress)), this, SLOT(handleAUVParam(VDatum)));
 	//connect(m_DS, SIGNAL(remoteNotResponding()), this, SLOT(disableDashboard()));
 	//connect(m_DS, SIGNAL(connectionRestored()), this, SLOT(enableDashboard()));

 	//connect(this, SIGNAL(sendMsg(VData)), m_DS, SLOT(sendVData(VData)));
 	//connect(this, SIGNAL(sendMsg(QString, QString)), m_DS, SLOT(sendVData(QString,QString)));
	//connect(this, SIGNAL(setAddress(QString)), m_DS, SLOT(setRemoteAddr(QString)));

	// video sockets setup
	videoSocket = new VideoSocket((config)["Server.IP"], (config)["Server.Port.Video1"].toUInt(), (config)["Client.Port.Video1"].toUInt(), this);
	bitmapSocket = new VideoSocket((config)["Server.IP"], (config)["Server.Port.Video2"].toUInt(), (config)["Client.Port.Video2"].toUInt(), this);
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
	//populateMechs(mechanisms);
	//mechsComboBox->insertItems(0, mechanisms.keys());

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

	// setup compasses
	QwtCompassMagnetNeedle* hNeedle = new QwtCompassMagnetNeedle();
	headingDial->setNeedle(hNeedle);
	QwtCompassMagnetNeedle* dHNeedle = new QwtCompassMagnetNeedle();
	desiredHeadingDial->setNeedle(dHNeedle);


	// init controls
	desiredSpeed = desiredHeading = desiredDepth = desiredStrafe = desiredVideoStream = 0;

	desiredSpeedSlider->setTracking(false);
	desiredDepthSlider->setTracking(false);
	desiredStrafeSlider->setTracking(false);
	desiredHeadingDial->setTracking(false);

	desiredDepthSlider->setRange(18, -5, 1, 3);
	desiredDepthSlider->setScaleMaxMajor(10);
	desiredDepthSlider->setScaleMaxMinor(5);

	// init parameter editor
	setupParamEdit();

	// Connect to AUV
	reconnectAction();

	// start receiveing video
	videoSocket->start();
	bitmapSocket->start();

	// setup idle timer for detection lost connections
	timeSinceLastDataReceived = new QTime();
	timeSinceLastDataReceived->start();
	dataTimeoutTimer = new QTimer();
	connect(dataTimeoutTimer, SIGNAL(timeout()), this, SLOT(checkForDataTimeout()));
	dataTimeoutTimer->start(100);

}


Dashboard::~Dashboard(){
	stopAction();
	delete videoSocket;
	delete bitmapSocket;
	//delete m_DS;
}


/* *** Connection Actions ************************* */
void Dashboard::reconnectAction(){
	setData("Connect.Data", "Broadcast");
        setData("Connect.Video", "This");
	setData("GetParams", "all");
#ifndef _WIN32
	setData("Dashboard.Version", getVersion());
#endif
}
void Dashboard::unbroadcastAction(){
	setData("Connect.Data", "This");
        setData("Connect.Video", "This");
	setData("GetParams", "all");
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
	setData("Connect.Data", "127.0.0.1");
	setData("Connect.Video", "127.0.0.1");
	setData("GetParams", "all");
}




/* *** Mode Actions ******************************* */
void Dashboard::on_goAutonomousButton_clicked(){
	startAutonomousAction();
}
void Dashboard::on_goRCButton_clicked(){
	startRCAction();
}
void Dashboard::on_stopButton_clicked(){
	stopAction();
}
void Dashboard::startAutonomousAction(bool sendToAUV){
	currentMode = AUTONOMOUS;
	if(sendToAUV)
		setData("Mode", "Autonomous");
	controlStateLabel->setText("Autonomous");
	statusBar()->showMessage(tr("Entering Autonomous mode"), 2000);

	// toggle buttons
	goAutonomousButton->setChecked(true);
	goRCButton->setChecked(false);
	stopButton->setChecked(false);

	// disable controls
	rcTab->setEnabled(false);
	// enable mission control
	missionControlGroupBox->setEnabled(true);
	// show processed video
	controlsTabWidget->setCurrentWidget(videoTab);
	// disable keybboard controls

}
void Dashboard::startRCAction(bool sendToAUV){
	currentMode = RC;
	if(sendToAUV)
		setData("Mode", "RC");
		setData("Command", "DeadReckon");
	controlStateLabel->setText("Remote Control");
	statusBar()->showMessage(tr("Entering RC Mode"), 2000);

	// toggle buttons
	goAutonomousButton->setChecked(false);
	goRCButton->setChecked(true);
	stopButton->setChecked(false);

	// enable and show controls
	on_setAllZeroButton_clicked();
	rcTab->setEnabled(true);
	controlsTabWidget->setCurrentWidget(rcTab);
	// enable keyboard controls

	// disable mission control
	missionControlGroupBox->setEnabled(false);
}
void Dashboard::stopAction(bool sendToAUV){
	if(sendToAUV)
		setData("Mode", "Stop");
	currentMode = STOPPED;
	controlStateLabel->setText("Stopped");
	statusBar()->showMessage(tr("Attempting to stop AUV"), 2000);

	// toggle buttons
	goAutonomousButton->setChecked(false);
	goRCButton->setChecked(false);
	stopButton->setChecked(true);

	// disable controls
	rcTab->setEnabled(false);
	// disable mission control
	missionControlGroupBox->setEnabled(false);
	// disable keyboard controls
}
void Dashboard::resetAction(bool sendToAUV){
	if(sendToAUV)
		setData("Mode", "Reset");
	stopAction();
	controlStateLabel->setText("Resetting...");
	statusBar()->showMessage(tr("Attempting to reset AUV"), 2000);
}
void Dashboard::killAction(bool sendToAUV){
	if(sendToAUV)
		setData("Mode", "Kill");
	currentMode = KILLED;
	controlStateLabel->setText("Killed");
	statusBar()->showMessage(tr("Die, bad Robot! Die!"), 2000);
}

void Dashboard::turnOffAUVAction() {
	//! \todo  TODO - do something with a dialog box to confirm
	statusBar()->showMessage("This feature is not currently implemented.", 2000);
}








void Dashboard::recordVideo(bool record){
	if(record) statusBar()->showMessage(tr("Recording Video..."), 2000);
	else statusBar()->showMessage(tr("Stopping Video Recording..."), 2000);
	setData("Flag.Rec", record?"true":"false");
}

void Dashboard::logData(bool log){
	setData("Flag.Log", log?"true":"false");
}


void Dashboard::sendScript(){
	//bool ok;
	QString scriptFilename = QFileDialog::getOpenFileName(this, tr("Open an AUVScript File"), QDir::homePath(), "*.avs");
	if (!scriptFilename.isEmpty()){
		QFile scriptFile(scriptFilename);
		if(!scriptFile.open(QIODevice::ReadOnly | QIODevice::Text)) return;
		QStringList script;
		while (!scriptFile.atEnd()) {
			QByteArray line = scriptFile.readLine();
			if(!line.startsWith("#") && !line.contains(";")) script.append(line.simplified());
		}

		setData("Script.New", scriptFilename+",,"+script.join(","));
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

void Dashboard::dataIn(VDatum datum) {
	bool badCmd = false;
	// reset idle timer
	timeSinceLastDataReceived->restart();

	// parse VData structure
	QString type, name;
	QStringList ids = datum.id.split('.');
	if(ids.size() > 0) type = ids[0];
	else type = "";
	if(ids.size() > 1) name = ids[1];
	else name = "";
	QString stringvalue = datum.value.toString();

	if(type == "Thrusters"){
		leftThrusterProgressBar->setValue(datum.value.value<QVector4D>().w()*100);
		rightThrusterProgressBar->setValue(datum.value.value<QVector4D>().z()*100);
		vertThrusterProgressBar->setValue(datum.value.value<QVector4D>().x()*100);
		strafeThrusterProgressBar->setValue(datum.value.value<QVector4D>().y()*100);
	}
	else if(type == "Orientation") {
		if(name == "Heading"){
			headingLcdNumber->display(datum.value.toDouble());
			headingDial->setValue(datum.value.toDouble());
		}
	}
	/*
	// set dashboard mode to match vehicle mode
	else if (type == "Mode") {

		// this is all wrong because mode should be a string, not an int

		QString modes[4];
		modes[0] = "Stopped";
		modes[1] = "Autonomous";
		modes[2] = "RC";
		modes[3] = "Killed";
		if(value.toInt() > 3 || value.toInt() < 0) badCmd = true;
		else controlStateLabel->setText(modes[value.toInt()]);

		switch(value.toInt()){
			case STOPPED:
				stopAction(false);
				break;
			case AUTONOMOUS:
				startAutonomousAction(false);
				break;
			case RC:
				startRCAction(false);
				break;
			case KILLED:
				killAction(false);
				break;
		}
	} 
	// vehicle status messages
	else if(type == "Status"){
		// wait for the Status=Connected packet before enabling the interface
		if(value == "Connected") {
			enableDashboard();
		}
		// display AUV status messages
		statusBar()->showMessage(value, 5000);
		if(value.contains("Error:")){
			QMessageBox::warning(this, "AUV Error", value);
		}
	}
	// Connect messages that might come from anywhere
	else if(type == "Connect" || type == "GetParams" || type == "Dashboard"){
		// these are special becuase the echos don't get filtered out.
		// that means it could be us or anyone connecting
		statusBar()->showMessage("Someone (probably you) is connecting to the AUV...", 5000);
	}
	// supervisory control data
	else if (type == "Supervisor") {
		if (name == "State") {
			if(value.toDouble() == -1) {
				// RC state
				currentState = "Remote Control";
				stateLabel->setText(currentState + ":" + currentSubState);
				// set RC to make sure we don't send a command
				startRCAction(false);
			}else if(value.toDouble() == -2) {
				// stopped state
				currentState = "Stopped";
				stateLabel->setText(currentState + ":" + currentSubState);
				stopAction(false);
			}else{
				if(value.toInt() >= states.size() || value.toInt() < 0) badCmd = true;
				else {
					currentState = states.at(value.toInt());
					stateLabel->setText(currentState + ":" + currentSubState);
				}
				missionProgressBar->setValue(value.toInt() * (100 / states.size()));
			}
		} else if (name == "SubState") {
			currentSubState = value;
			stateLabel->setText(currentState + ":" + currentSubState);
		} else if (name == "Time") {
			// target brain step frequency
			//! \todo  TODO - use actual define value
			int targetRate = 5;//Hz
			rateLabel->setText("Processing at: " 
				+ QString::number(1.0/(value.toDouble()/1000.0)) + " Hz (" 
				+ QString::number(round(100.0/(value.toDouble()/1000.0)/targetRate))
				+ "%)" );
		}
	} 
	// data from vehicle meta sensors
	else if (type == "Vehicle") {
		// technically heading and depth should be under PhysicalState
		if (name == "Heading"){
			headingLcdNumber->display(value.toDouble());
			headingDial->setValue(value.toDouble());
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
		else if (name == "ManualOverrideDisabled") if(value == "true") warningLabel->setText("Warning: Off switch disabled!");
			else warningLabel->setText("");
		else badCmd = true;
	} 
	// Data from state estimator/sensors
	else if (type == "PhysicalState") {
		if(name == "Pitch"){
			pitchLabel->setText(value);
		}else if(name == "Roll"){
			rollLabel->setText(value);
		}else if(name == "Yaw"){
			yawLabel->setText(value);
		}else if(name == "XPos"){
			xLabel->setText(value);
		}else if(name == "YPos"){
			yLabel->setText(value);
		}else if(name == "ZPos"){
			zLabel->setText(value);
		}else if(name == "XVel"){
			xVelLabel->setText(value);
		}else if(name == "YVel"){
			yVelLabel->setText(value);
		}else if(name == "ZVel"){
			zVelLabel->setText(value);
		}else if(name == "Pitch_Accel"){
			pitchAccelLabel->setText(value);
		}else if(name == "Roll_Accel"){
			rollAccelLabel->setText(value);
		}else if(name == "Yaw_Accel"){
			yawAccelLabel->setText(value);
		}else if(name == "YawRate_Out"){
			yawRateLabel->setText(value);
		}else if(name == "PitchRate_Out"){
			pitchRateLabel->setText(value);
		}else if(name == "RollRate_Out"){
			rollRateLabel->setText(value);
		}else badCmd = true;
	}
	// RC commands from other dashboards
	else if (type == "RC"){ 
		int intValue = value.toInt();
		if(name == "DesiredDepth") {
			if(intValue != desiredDepth){
				desiredDepth = intValue;
				desiredDepthSlider->setValue(intValue);
			}
		}else if(name == "DesiredStrafe"){
			if(intValue != desiredStrafe){
				desiredStrafe = intValue;
				desiredStrafeSlider->setValue(intValue);
			}
		}else if(name == "DesiredForwardVelocity") {
			if(intValue != desiredSpeed){
				desiredSpeed = intValue;
				desiredSpeedSlider->setValue(intValue);
			}
		}else if(name == "DesiredHeading"){
			if(intValue != desiredHeading){
				desiredHeading = intValue;
				desiredHeadingSpinBox->setValue(intValue);
			}
		}else if(name == "DesiredState") {
			stateComboBox->setCurrentIndex(value.toInt());
		}else badCmd = true;
	} 
	// Which video stream are we looking at?
	else if (type == "Video" && name == "Stream"){
		int intValue = value.toInt();
		if(intValue != desiredVideoStream){
			desiredVideoStream = intValue;
			videoStreamComboBox->setCurrentIndex(intValue);
		}
	} 
	// parameter values from Brain
	else if (type == "Parameter") { 
		//emit receivedParam(name, value);
	}
	// catch unparsed commands or data
	else badCmd = true;
	*/

	//if(badCmd) qDebug() << "Unrecognized data: " + type + "." + name + "=" + value;

} // end dataIn()

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
	//qDebug() << "Flaky connection or you are hitting buttons too fast";
	// if enough packets go missing, disable the controls to prevent more pileup
	//dashboardWidget->setEnabled(false);
	//rcTab->setEnabled(false);
	//controlsTabWidget->setEnabled(false);
	//if(missedId == "timeout")
		//dashboardWidget->setEnabled(false);
}
void Dashboard::enableDashboard(){
	dashboardWidget->setEnabled(true);
	controlsTabWidget->setEnabled(true);
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
		case Qt::Key_F1: 
			startAutonomousAction(); 
			break;
		case Qt::Key_F2: 
		case Qt::Key_Control:
			startRCAction(); 
			break;
		case Qt::Key_F3: 
			stopAction(); 
			break;
		case Qt::Key_F4: 
			resetAction(); 
			break;
		case Qt::Key_F5: 
		case Qt::Key_K: 
			killAction(); 
			break;
		case Qt::Key_F6: 
			reconnectAction(); 
			break;
		case Qt::Key_F9: 
			connectToLocalhost(); 
			break;

		case Qt::Key_W: // forward
			if(currentMode == RC){
				desiredSpeedSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd); 
			}
			break;
		case Qt::Key_A:  // turn left
			if(currentMode == RC){
				desiredHeadingDial->incValue(-1); 
			}
			break;
		case Qt::Key_S: // backward
			if(currentMode == RC){
				desiredSpeedSlider->triggerAction(QAbstractSlider::SliderSingleStepSub); 
			}
			break;
		case Qt::Key_D:  // turn right
			if(currentMode == RC){
				desiredHeadingDial->incValue(1); 
			}
			break;
		case Qt::Key_Q:  // down
			if(currentMode == RC){
				desiredDepthSlider->incValue(1); 
			}
			break;
		case Qt::Key_E:  // up
			if(currentMode == RC){
				desiredDepthSlider->incValue(-1); 
			}
			break;
		case Qt::Key_Z:  // strafe left
			if(currentMode == RC){
				desiredStrafeSlider->triggerAction(QAbstractSlider::SliderSingleStepSub); 
			}
			break;
		case Qt::Key_C:  // strafe right
			if(currentMode == RC){
				desiredStrafeSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd); 
			}
			break;
		case Qt::Key_X:  // hold position
			if(currentMode == RC){
				on_setAllZeroButton_clicked(); 
			}
			break;
		default:
			QMainWindow::keyPressEvent(event);
			break;
	}
} // end Key Event Handler


/* *** GUI event handlers **************************************** */


// State Select
void Dashboard::on_stateComboBox_activated(int index){
	setData("Input.DesiredState", QString::number(index));
}

// select processed video stream to view
void Dashboard::on_videoStreamComboBox_activated(int index){
	if(index != desiredVideoStream){
		desiredVideoStream = index;
		setData("Video.Stream", QString::number(index));
	}
}

// Depth Calibration
void Dashboard::on_zeroDepthPushButton_clicked(){
	setData("Calibrate.Depth", "0");
}
void Dashboard::on_setActualDepthPushButton_clicked(){
	setData("Calibrate.Depth", QString::number(actualDepthDoubleSpinBox->value()));
}

// tare IMU
void Dashboard::on_tareAccelPushButton_clicked(){
	setData("Input.Tare", "1");
}


/* ****** RC Controls **************************************************** */
void Dashboard::on_desiredDepthSlider_valueChanged(double value){
	if(value != desiredDepth){
		desiredDepth = value;
		setData("DeadReckon.Depth", QString::number(value));
	}	
}
void Dashboard::on_desiredStrafeSlider_valueChanged(int value){
	if(value != desiredStrafe){
		desiredStrafe = value;
		setData("RC.desiredStrafe", QString::number(value));
	}
}
void Dashboard::on_desiredSpeedSlider_valueChanged(int value){
	if(value != desiredSpeed){
		desiredSpeed = value;
		setData("DeadReckon.ForwardSpeed", QString::number(value));
	}
}
void Dashboard::on_desiredHeadingDial_valueChanged(double value){
	if(value != desiredHeading){
		desiredHeading = value;
		setData("DeadReckon.Heading", QString::number(value));
	}
}
void Dashboard::on_desiredHeadingSpinBox_editingFinished(){
	setData("DeadReckon.Heading", QString::number(desiredHeadingSpinBox->value()));
}
void Dashboard::on_desiredDepthSpinBox_editingFinished(){
	setData("DeadReckon.Depth", QString::number(desiredDepthSpinBox->value()));
}
void Dashboard::on_desiredSpeedSpinBox_editingFinished(){
	setData("DeadReckon.ForwardSpeed", QString::number(desiredSpeedSpinBox->value()));
}
void Dashboard::on_desiredStrafeSpinBox_editingFinished(){
	setData("RC.desiredStrafe", QString::number(desiredStrafeSpinBox->value()));
}
void Dashboard::on_setAllZeroButton_clicked(){
	desiredDepthSlider->setValue(depthLcdNumber->value());
	desiredStrafeSlider->setValue(0);
	desiredSpeedSlider->setValue(0);
	desiredHeadingDial->setValue(headingLcdNumber->value());
}

// Other buttons
void Dashboard::on_runScriptPushButton_clicked(){
	setData("Activate.Script", scriptsComboBox->currentText());
}
void Dashboard::on_actuateMechPushButton_clicked(){
	setData("Actuate.Mechanism", mechsComboBox->currentText());
}


/* *** Parameter Editor ************************** */
void Dashboard::setupParamEdit(){
	//QStringList headers;
	//headers << tr("Parameter") << tr("Value");

	//paramModel = new TreeModel(headers, this);

	// link model to view
	paramEditTreeView->setModel(state);

	// setup display/edit properties
	/*
	paramEditTreeView->header()->setStretchLastSection(false);
	paramEditTreeView->expandAll();
	for (int column = 0; column < model->columnCount(); ++column)
		paramEditTreeView->resizeColumnToContents(column);
	paramEditTreeView->collapseAll();
	*/

	// NOTE that this assumes all params are doubles!  You will not be able to edit anything else without adding more QItemEditorCreatorBases to the factory!
	/*
	QItemEditorFactory *factory = new QItemEditorFactory;
	QItemEditorCreatorBase *doubleEditorCreator = new QStandardItemEditorCreator<DoubleEditor>();
	factory->registerEditor(QVariant::Double, doubleEditorCreator);
	QItemEditorFactory::setDefaultFactory(factory);
	*/

	//connect(paramModel, SIGNAL(dataUpdated(VData)), this, SIGNAL(sendMsg(VData)));
	//connect(this, SIGNAL(receivedParam(VData)), paramModel, SLOT(setData(VData)));
}

/* Save/Load parameters ****************************** */
void Dashboard::saveParameters(){
	QString  saveFilename = QFileDialog::getSaveFileName (this, "Save parameters to file", "params/", "Parameter Matlab files (*.m)");
	QFile saveFile(saveFilename);

	if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
		return;

	QTextStream out(&saveFile);
	out << QString("% Parameters file generated ") + QDateTime::currentDateTime().toString() << endl;

	//! \todo TODO - save params to file


	saveFile.close();

}
void Dashboard::loadParameters(){
	QString  loadFilename = QFileDialog::getOpenFileName (this, "Load parameters from file", "params/", "Parameter files (*.params *.m)");
	QFile loadFile(loadFilename);
	if (!loadFile.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	//m_DS->buffer();
	QTextStream in(&loadFile);
	while (!in.atEnd()) {
		QString line = in.readLine();
		loadParameter(line.simplified());
	}

	loadFile.close();
	//m_DS->flush();

}

// warning: this function assumes parameter values are doubles
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
			setData(paramName, QString::number(paramVal));
		}

	}
}



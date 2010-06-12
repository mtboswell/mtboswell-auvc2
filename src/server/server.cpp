#include "server.h"
#include "camread.h"
#include <QDebug>
#include <QHashIterator>
#include <QDateTime>

Server::Server(){


//	timer = new QTimer(this);
//	connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));

	if(config.isEmpty()) loadConfigFile(config);

	sidsocket = new SIDSocket(config["Server.Port.Data"].toInt(), config["Client.Port.Data"].toInt(), true);
	videoSocket = new QUdpSocket(this);
	videoSocket->bind(config["Server.Port.Video1"].toInt());
	bitmapSocket = new QUdpSocket(this);
	bitmapSocket->bind(config["Server.Port.Video2"].toInt());
	connect(sidsocket, SIGNAL(sidReceived(QString, QString, QHostAddress)),
	     this, SLOT(handleCmd(QString, QString, QHostAddress)));

	videoFile = new QFile("recorded_video.mjpg");
	if (!videoFile->open(QIODevice::WriteOnly | QIODevice::Append))
		qDebug() << "Could not open video file";
	
        videoFrame = new QImage(640,480,QImage::Format_RGB32); // 4 = QImage::Format_RGB32
        videoOut = new QImageWriter(videoSocket, "jpeg");
	videoOut->setQuality(70);
        recVideoOut = new QImageWriter(videoFile, "jpeg");
	recVideoOut->setQuality(70);

        bwFrame = new QImage(160,120,QImage::Format_Mono);
        bwFrame->setColor(0, 0xFF000000); 
        bwFrame->setColor(1, 0xFFFF0000); 
        bitmapOut = new QImageWriter(bitmapSocket, "jpeg");

        rgbFrame = new QImage(160,120,QImage::Format_RGB32); // 4 = QImage::Format_RGB32
	streamRGBSecondary = false;

	if(parameters.isEmpty()) init_params(parameters);

	//qDebug() << "We have " << parameters.size() << " parameters";

	//logger = new DataLogger(this, "logs/data-" + QDateTime::currentDateTime().toString("yyyy-MM-dd+hh:mm") + ".csv", 1000, DATA_LOG_STEP_TIME, ",");
	//connect(this, SIGNAL(setLog(bool)), logger, SLOT(enable(bool)));
}

/* The default should work unless we need to do something weird
void Server::run(){
	timer->start(STEP_TIME);
	exec();
}
*/


void Server::handleCmd(QString id, QString value, QHostAddress fromAddr){
	bool completedCommand = true;
	QString type, name;
	QStringList ids = id.split('.');
	if(ids.size() > 0) type = ids[0];
	if(ids.size() > 1) name = ids[1];
	if(type == "Connect"){
		if(!value.contains('.')) {
			if(value.contains("This")) value = fromAddr.toString();
			else if(value.contains("Broadcast")) {
				value = "";
				// try to find our broadcast address
				QNetworkInterface interface;
				QList<QNetworkAddressEntry> addrs = interface.addressEntries();
				for (int i = 0; i < addrs.size(); ++i) {
					// localhost and ipv6 addresses don't have broadcast
					if (addrs.at(i).ip() != QHostAddress::LocalHost && addrs.at(i).broadcast().toIPv4Address()) {
						value = addrs.at(i).broadcast().toString();
						break;
					}
				}
				// fallback to default address (this doesn't really help, we should output an error, but if we aren't connected, where will the error go?)
				if(value == "") value = "192.168.3.255";
			}else qDebug() << "Invalid IP address alias.";
		}
		if(name == "Data") {
			// set remoteHost
			//qDebug() << "Attempting to connect to:" << value;
			if(remoteHost.setAddress(value)) qDebug() << "Sending all data to:" << value;
			else qDebug() << "Failed to set client address:" << value;
		}else if(name == "Video"){
			videoSocket->disconnectFromHost();
			videoSocket->connectToHost(value, config["Client.Port.Video1"].toInt(), QIODevice::WriteOnly);
			bitmapSocket->disconnectFromHost();
			bitmapSocket->connectToHost(value, config["Client.Port.Video2"].toInt(), QIODevice::WriteOnly);
		}else completedCommand = false;
		sendStatus("Connected");
	}else if(type == "Dashboard"){
		if(name == "Version"){
			if(value != getVersion()) sendError("Dashboard version does not match Agent version:" + getVersion());
		}else completedCommand = false;
	}else if(type == "Mode"){
		if(value == "Running" || value == "Run") emit go();
		else if(value == "Stopped" || value == "Stop" || value == "Pause" || value == "Paused") emit stop();
		else if(value == "Killed" || value == "Kill" || value == "kill") emit kill();
		else if(value == "Reset") emit reset();
	}else if(type == "Actuate" || type == "Activate"){
		if(name == "SelfDestruct") qDebug() << "Self Destruct in 5...";
		else if(name =="Mech" || name == "Mechanism") emit actuateMech(value);
		else if(name == "Script") emit runScript(value);
		else completedCommand = false;
	}else if(type == "Move"){
		if(name == "Camera"){
			QStringList coords = value.split(",");
			if(coords.size() < 2) sendError("Invalid camera coords");
			else{
				double x = coords.at(0).toDouble();
				double y = coords.at(1).toDouble();
				emit moveCamera(x,y);
			}
		}else completedCommand = false;
	}else if(type == "Script"){
		if(name == "Run")
			emit runScript(value);
		else if(name == "New")
			emit newScript(value);
	}else if(type == "Calibrate"){
		if(name == "Depth") emit calibrateDepth(value.toDouble());
		else if(name == "WhiteBalance") emit whiteBalance();
		else completedCommand = false;
	}else if(type == "Param" || type == "Parameter"){
		emit setParam(name, value.toDouble());
	}else if(type == "Input"){
		emit setInput(name, value.toDouble());
	}else if(type == "Flag"){
		if(name == "Rec") recordVideo = (value == "true"); //emit setRec(value == "true");
		else if(name == "noRec") recordVideo = false; //emit setRec(false);
		else if(name == "Log") emit setLog(value == "true");
		else if(name == "noLog") emit setLog(false);
		else completedCommand = false;
	}else if(type == "Video"){
		if(name == "Stream") selectVideoStream(value.toInt());
		else completedCommand = false;
	}else if(type == "GetParams"){
		sendParams();
	}else if(type == ""){
		qDebug() << "Error: Missing Command Family";
		return;
	}else{
		qDebug() << "Error: Invalid Command Family";
		return;
	}
	//qDebug() << "Action completed";
	if(completedCommand) ;//qDebug() << "Command Executed:" << type << "." << name << "=" << value;
	else sendError("Unknown Command");
}

void Server::sendSensorData(AUVSensors sens){
	if(config["Debug"]=="true") qDebug() << "Sending Sensor Data";

	static int sendCount = 0;

	if(remoteHost.isNull()) return;

	// logging is now done in the dashboard
	//logger->logData(type + '.' + name, value);

	sidsocket->buffer();

	//sens.stuff;
	sidsocket->sendSID("AUV.Mode", QString::number(sens.status));
	sidsocket->sendSID("AUV.Heading", QString::number(sens.orientation.yaw));
	sidsocket->sendSID("AUV.Depth", QString::number(sens.depth));
	sidsocket->sendSID("AUV.LeftThruster", QString::number((int) sens.thrusterSpeeds[0]));
	sidsocket->sendSID("AUV.RightThruster", QString::number((int) sens.thrusterSpeeds[1]));
	sidsocket->sendSID("AUV.LateralThruster", QString::number((int) sens.thrusterSpeeds[2]));
	sidsocket->sendSID("AUV.VerticalThruster", QString::number((int) sens.thrusterSpeeds[3]));
	sidsocket->sendSID("AUV.CameraX", QString::number(sens.cameraX));
	sidsocket->sendSID("AUV.CameraY", QString::number(sens.cameraY));
	// some data gets updated less often
	if(sendCount%10 == 0){
		sidsocket->sendSID("AUV.ThrusterVoltage", QString::number(sens.thrusterPower.voltage));
		sidsocket->sendSID("AUV.ThrusterCurrent", QString::number(sens.thrusterPower.current));
		sidsocket->sendSID("AUV.ManualOverrideDisabled", sens.manualOverrideDisabled?"true":"false");
		sendCount = 0;
	}

	// write to port
	sidsocket->flush();
	sendCount++;
}

void Server::sendBrainData(ExternalOutputs_brain outs, int brainTime){
	if(config["Debug"]=="true") qDebug() << "Sending Brain Data";
	// Model Outputs
	if(remoteHost.isNull()) return;
	
	sidsocket->buffer();
	//outs.stuff;
	sidsocket->sendSID("Brain.State", QString::number(outs.State));
	sidsocket->sendSID("Brain.Time", QString::number(brainTime));

	// write to port
	sidsocket->flush();
}

void Server::sendParams(){
	if(remoteHost.isNull()) return;
	qDebug() << "Sending Params";
	sidsocket->buffer();
	// parameters data
	// params.stuff

	 QHashIterator<QString, double*> i(parameters);
	 while (i.hasNext()) {
	     i.next();
	//	qDebug() << "Getting Parameter:" << i.key();
		sidsocket->sendSID("Parameter."+i.key(), QString::number(*(i.value())));
	 }

	// write to port
	sidsocket->flush();
}

void Server::sendError(QString err){
	sendStatus("Error: " + err);
}

void Server::sendStatus(QString stat){
	if(remoteHost.isNull()) return;
	qDebug() << stat;
	sidsocket->sendSID("Status", stat);
	// write to port
	emit status(stat);
}

// Sends a JPEG from the Brain over the VIDEO_PORT udp port.
void Server::sendVideo(){
	if(video_paused) return;
	// This can be confusing:  Being in the connected state does not mean that there is a computer on the other end receiving the data.  It just means we have an address to send data to.
	// The next line returns if we do not have an address to send to, but it doesn't know whether there is an actual receiver or not.
	if(videoSocket->state() != QAbstractSocket::ConnectedState) return;
	if(bitmapSocket->state() != QAbstractSocket::ConnectedState) qDebug() << "Bitmap socket not connected!";

	
	// Get jpeg from QImage from brain:
        // Get full color video (as opposed to the bitmaps)
        // copy frame from signal to pixmap
        int x = 639;
        int y = 480;
        unsigned int videoPixel;
        for(int i = 307199; i >= 0; --i){
                y--;
                videoPixel = (0xFF000000) | ((((int)brain_B.RGBVid_R[i]) << 16)&0x00FF0000) | ((((int)brain_B.RGBVid_G[i]) << 8)&0x0000FF00) | (((int)brain_B.RGBVid_B[i])&0x000000FF);
		// TODO - add filtered video overlay
                videoFrame->setPixel(x, y, videoPixel);
                if(y <= 0){
                        x--;
                        y = 480;
                }
        }

	if(streamRGBSecondary){
		// Get processed video
		// copy frame from signal to pixmap
		x = 159;
		y = 120*3;
		for(int i = (19200*3)-1; i >= 0; i = i-3){
			y--;
			videoPixel = (0xFF000000) | ((((int)brain_Y.RGBout[i]) << 16)&0x00FF0000) | ((((int)brain_Y.RGBout[i-1]) << 8)&0x0000FF00) | (((int)brain_Y.RGBout[i-2])&0x000000FF);
			rgbFrame->setPixel(x, y/3, videoPixel);
			if(y <= 0){
				x--;
				y = 120*3;
			}
		}

	}else{
		/* Get bitmap out of correct brain signal */
		// Get processed video
		// copy frame from signal to pixmap
		x = 159;
		y = 120;
		for(int i = 19199; i >= 0; --i){
			y--;
			bwFrame->setPixel(x, y, brain_Y.BWout[i]);
			if(y <= 0){
				x--;
				y = 120;
			}
		}
	}



        videoOut->write(*videoFrame);
	if(streamRGBSecondary){
		bitmapOut->write(*rgbFrame);
	}else{
		bitmapOut->write(*bwFrame);
	}
        if(recordVideo) recVideoOut->write(*videoFrame);
	if(config["Debug"]=="true") qDebug() << "Sending Video Frame";
}

void Server::selectVideoStream(int streamNumber){
	switch(streamNumber){
		case 0: streamRGBSecondary = false;
			break;
		case 1: streamRGBSecondary = true;
			break;

	}
}

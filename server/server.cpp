#include "server.h"
#include "camread.h"
#include <QDebug>
#include <QHashIterator>
#include <QDateTime>

Server::Server(QMutex* sensorMutex){

	sensorDataMutex = sensorMutex;

//	timer = new QTimer(this);
//	connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));

	socket = new QUdpSocket(this);
	socket->bind(QHostAddress::Any, SERVER_DATA_PORT);
	videoSocket = new QUdpSocket(this);
	videoSocket->bind(VIDEO_PORT);
	bitmapSocket = new QUdpSocket(this);
	bitmapSocket->bind(SECONDARY_VIDEO_PORT);
	connect(socket, SIGNAL(readyRead()),
	     this, SLOT(readPendingDatagrams()));

	
        videoFrame = new QImage(640,480,QImage::Format_RGB32); // 4 = QImage::Format_RGB32
        videoOut = new QImageWriter(videoSocket, "jpeg");
	videoOut->setQuality(70);

        bwFrame = new QImage(160,120,QImage::Format_Mono);
        bwFrame->setColor(0, 0xFF000000); 
        bwFrame->setColor(1, 0xFFFF0000); 
        bitmapOut = new QImageWriter(bitmapSocket, "jpeg");

	if(parameters.isEmpty()) init_params(parameters);

	//qDebug() << "We have " << parameters.size() << " parameters";

	logger = new DataLogger(this, "logs/data-" + QDateTime::currentDateTime().toString("yyyy-MM-dd+hh:mm") + ".csv", 1000, DATA_LOG_STEP_TIME, ",");
	connect(this, SIGNAL(setLog(bool)), logger, SLOT(enable(bool)));
}

/* The default should work unless we need to do something weird
void Server::run(){
	timer->start(STEP_TIME);
	exec();
}
*/

void Server::readPendingDatagrams()
{
	while (socket->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(socket->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;

		socket->readDatagram(datagram.data(), datagram.size(),
				 &sender, &senderPort);

		processDatagram(datagram, sender, senderPort);
	}
}


// called for every new incoming udp datagram
void Server::processDatagram(QByteArray datagram, QHostAddress fromAddr, quint16 fromPort){
	//qDebug() << "Processing Datagram:" << datagram;
	QList<QByteArray> data = datagram.split(';');	
	QByteArray datum;
	foreach(datum, data){
		if(datum.isNull() || datum.isEmpty() || !datum.contains('=')) continue;
		qDebug() << "Received command:" << datum;
		QString key, type, name, value;
		QList<QByteArray> field = datum.split('=');
		if(field.size() > 0){
			key = field.at(0);
			if(field.size() > 1){
				value = field.at(1);
				QList<QString> cmd = key.split('.');
				if(cmd.size() > 0) type = cmd.at(0);
				if(cmd.size() > 1) name = cmd.at(1);
			}
		}
		doAction(type, name, value, fromAddr, fromPort);	
	}
	//qDebug() << "Processed Datagram, echoing";
	if(!remoteHost.isNull()) socket->writeDatagram(datagram, remoteHost, CLIENT_DATA_PORT);
}

void Server::doAction(QString type, QString name, QString value, QHostAddress fromAddr, quint16 fromPort){
	bool completedCommand = true;
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
			videoSocket->connectToHost(value, DASH_VIDEO_PORT, QIODevice::WriteOnly);
			bitmapSocket->disconnectFromHost();
			bitmapSocket->connectToHost(value, DASH_SECONDARY_VIDEO_PORT, QIODevice::WriteOnly);
		}else completedCommand = false;
		sendStatus("Connected");
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
	}else if(type == "RunScript"){
		emit runScript(value);
	}else if(type == "Calibrate"){
		if(name == "Depth") emit calibrateDepth(value.toDouble());
		else if(name == "WhiteBalance") emit whiteBalance();
		else completedCommand = false;
	}else if(type == "Param" || type == "Parameter"){
		emit setParam(name, value.toDouble());
	}else if(type == "Input"){
		emit setInput(name, value.toDouble());
	}else if(type == "Flag"){
		if(name == "Rec") emit setRec(value == "true");
		else if(name == "noRec") emit setRec(false);
		else if(name == "Log") emit setLog(value == "true");
		else if(name == "noLog") emit setLog(false);
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
	//qDebug() << "Sending Sensor Data";
	//sensorDataMutex->lock();

	static int sendCount = 0;

	QByteArray sensordata;
	sensordata.reserve(300);
	//sens.stuff;
	addDatum(sensordata, "AUV", "Mode", QString::number(sens.status), true);
	addDatum(sensordata, "AUV", "Heading", QString::number(sens.orientation.yaw), true);
	addDatum(sensordata, "AUV", "Depth", QString::number(sens.depth), true);
	addDatum(sensordata, "AUV", "LeftThruster", QString::number((int) sens.thrusterSpeeds[0]), true);
	addDatum(sensordata, "AUV", "RightThruster", QString::number((int) sens.thrusterSpeeds[1]), true);
	addDatum(sensordata, "AUV", "LateralThruster", QString::number((int) sens.thrusterSpeeds[2]), true);
	addDatum(sensordata, "AUV", "VerticalThruster", QString::number((int) sens.thrusterSpeeds[3]), true);
	addDatum(sensordata, "AUV", "CameraX", QString::number(sens.cameraX), true);
	addDatum(sensordata, "AUV", "CameraY", QString::number(sens.cameraY), true);
	// some data gets updated less often
	if(sendCount%10 == 0){
		addDatum(sensordata, "AUV", "ThrusterVoltage", QString::number(sens.thrusterPower.voltage), true);
		addDatum(sensordata, "AUV", "ThrusterCurrent", QString::number(sens.thrusterPower.current), true);
		addDatum(sensordata, "AUV", "ManualOverrideDisabled", sens.manualOverrideDisabled?"true":"false");
		sendCount = 0;
	}
	sensordata.squeeze();
	//sensorDataMutex->unlock();

	if(remoteHost.isNull()) return;
	// write to port
	//qDebug() << "Sending Datagram:" << sensordata;
	socket->writeDatagram(sensordata, remoteHost, CLIENT_DATA_PORT);
	sendCount++;
}

void Server::sendBrainData(ExternalOutputs_brain outs, int brainTime){
	//qDebug() << "Sending Brain Data";
	QByteArray datagram;
	// Model Outputs
	
	//outs.stuff;
	addDatum(datagram, "Brain", "State", QString::number(outs.State), true);
	addDatum(datagram, "Brain", "Time", QString::number(brainTime), true);

	if(remoteHost.isNull()) return;
	// write to port
	//qDebug() << "Sending Datagram:" << datagram;
	socket->writeDatagram(datagram, remoteHost, CLIENT_DATA_PORT);
}

void Server::sendParams(){
	if(remoteHost.isNull()) return;
	qDebug() << "Sending Params";
	QByteArray datagram;
	// parameters data
	// params.stuff
/*
	QList<QString> params = parameters.keys();

	foreach(QString param, params){
		qDebug() << "Getting Parameter:" << param;
		addDatum(datagram, "Parameter", param, QString::number(*(parameters[param])));
	}
*/
	 QHashIterator<QString, double*> i(parameters);
	 while (i.hasNext()) {
	     i.next();
	//	qDebug() << "Getting Parameter:" << i.key();
		addDatum(datagram, "Parameter", i.key(), QString::number(*(i.value())));
	 }

	// write to port
	//qDebug() << "Sending Params Datagram:" << datagram;
	socket->writeDatagram(datagram, remoteHost, CLIENT_DATA_PORT);
}


void Server::addDatum(QByteArray& datagram, QString type, QString name, QString value, bool log){
	datagram += type;
	datagram += '.';
	datagram += name;
	datagram += '=';
	datagram += value;
	datagram += ';';
	if(log) logger->logData(type + '.' + name, value);
}

void Server::sendError(QString err){
	sendStatus("Error: " + err);
}

void Server::sendStatus(QString status){
	if(remoteHost.isNull()) return;
	QByteArray datagram;
	qDebug() << status;
	addDatum(datagram, "Status", "", status);

	// write to port
	socket->writeDatagram(datagram, remoteHost, CLIENT_DATA_PORT);
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
        videoOut->write(*videoFrame);
	bitmapOut->write(*bwFrame);

}

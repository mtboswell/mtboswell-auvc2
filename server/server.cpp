#include "server.h"
#include <QDebug>
#include <QHashIterator>

Server::Server(QMutex* sensorMutex){

	sensorDataMutex = sensorMutex;

//	timer = new QTimer(this);
//	connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));

	socket = new QUdpSocket(this);
	socket->bind(QHostAddress::Any, SERVER_DATA_PORT);
	videoSocket = new QUdpSocket(this);
	//socket->connectToHost("192.168.3.255", SERVER_DATA_PORT);
	//if (socket->waitForConnected(1000))
	//	qDebug("Connected!");
	connect(socket, SIGNAL(readyRead()),
	     this, SLOT(readPendingDatagrams()));

	
        videoFrame = new QImage(640,480,QImage::Format_RGB32); // 4 = QImage::Format_RGB32
        videoOut = new QImageWriter(videoSocket, "jpeg");

	if(parameters.isEmpty()) init_params(parameters);

	//qDebug() << "We have " << parameters.size() << " parameters";
}

/* The default should work
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

		processDatagram(datagram);
	}
}


// called for every new incoming udp datagram
void Server::processDatagram(QByteArray datagram){
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
		doAction(type, name, value);	
	}
	//qDebug() << "Processed Datagram, echoing";
	if(!remoteHost.isNull()) socket->writeDatagram(datagram, remoteHost, CLIENT_DATA_PORT);
}

void Server::doAction(QString type, QString name, QString value){
	bool completedCommand = true;
	if(type == "Connect"){
		if(name == "Data") {
			// set remoteHost
			//qDebug() << "Attempting to connect to:" << value;
			if(remoteHost.setAddress(value)) qDebug() << "Sending all data to:" << value;
			else qDebug() << "Failed to set client address";
		}else if(name == "Video"){
			videoSocket->connectToHost(value, VIDEO_PORT, QIODevice::WriteOnly);
		}else completedCommand = false;
	}else if(type == "Mode"){
		if(value == "Running" || value == "Run") emit go();
		else if(value == "Stopped" || value == "Stop" || value == "Pause" || value == "Paused") emit stop();
		else if(value == "Killed" || value == "Kill" || value == "kill") emit kill();
		else if(value == "Reset") emit reset();
	}else if(type == "Actuate" || type == "Activate"){
		if(name == "SelfDestruct") qDebug() << "Self Destruct in 5...";
		else if(name =="Mech" || name == "Mechanism") emit actuateMech(value);
		else completedCommand = false;
	}else if(type == "Calibrate"){
		if(name == "Depth") emit calibrateDepth(value.toDouble());
		else if(name == "WhiteBalance") emit whiteBalance();
		else completedCommand = false;
	}else if(type == "Param"){
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
	else qDebug() << "Error: Unknown command";
}

void Server::sendSensorData(AUVSensors sens){
	if(remoteHost.isNull()) return;
	//qDebug() << "Sending Sensor Data";
	//sensorDataMutex->lock();

	QByteArray sensordata;
	sensordata.reserve(300);
	//sens.stuff;
	addDatum(sensordata, "AUV", "Mode", QString::number(sens.status));
	addDatum(sensordata, "AUV", "Heading", QString::number(sens.orientation.yaw));
	addDatum(sensordata, "AUV", "Depth", QString::number(sens.depth));
	addDatum(sensordata, "AUV", "LeftThruster", QString::number((int) sens.thrusterSpeeds[0]));
	addDatum(sensordata, "AUV", "RightThruster", QString::number((int) sens.thrusterSpeeds[1]));
	addDatum(sensordata, "AUV", "LateralThruster", QString::number((int) sens.thrusterSpeeds[2]));
	addDatum(sensordata, "AUV", "VerticalThruster", QString::number((int) sens.thrusterSpeeds[3]));
	addDatum(sensordata, "AUV", "ThrusterVoltage", QString::number(sens.thrusterPower.voltage));
	addDatum(sensordata, "AUV", "ThrusterCurrent", QString::number(sens.thrusterPower.current));
	addDatum(sensordata, "AUV", "ManualOverrideDisabled", sens.manualOverrideDisabled?"true":"false");
	addDatum(sensordata, "AUV", "CameraX", QString::number(sens.cameraX));
	addDatum(sensordata, "AUV", "CameraY", QString::number(sens.cameraY));
	sensordata.squeeze();
	//sensorDataMutex->unlock();
	// write to port
	//qDebug() << "Sending Datagram:" << sensordata;
	socket->writeDatagram(sensordata, remoteHost, CLIENT_DATA_PORT);
}

void Server::sendBrainData(ExternalOutputs_brain outs, int brainTime){
	if(remoteHost.isNull()) return;
	//qDebug() << "Sending Brain Data";
	QByteArray datagram;
	// Model Outputs
	
	//outs.stuff;
	addDatum(datagram, "Brain", "State", QString::number(outs.State));
	addDatum(datagram, "Brain", "Time", QString::number(brainTime));
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


void Server::addDatum(QByteArray& datagram, QString type, QString name, QString value){
	datagram += type;
	datagram += '.';
	datagram += name;
	datagram += '=';
	datagram += value;
	datagram += ';';
}

// Sends a JPEG from the Brain over the VIDEO_PORT udp port.
void Server::sendVideo(){
	if(videoSocket->state() != QAbstractSocket::ConnectedState) return;
//  Code to get jpeg from QImage from brain:

        // Get full color video
        // copy frame from signal to pixmap
        int x = 639;
        int y = 480;
        unsigned int videoPixel;
        for(int i = 307199; i >= 0; --i){
                y--;
                videoPixel = (0xFF000000) | ((((int)brain_B.RGBVid_R[i]) << 16)&0x00FF0000) | ((((int)brain_B.RGBVid_G[i]) << 8)&0x0000FF00) | (((int)brain_B.RGBVid_B[i])&0x000000FF);
                videoFrame->setPixel(x, y, videoPixel);
                if(y <= 0){
                        x--;
                        y = 480;
                }
        }
        videoOut->write(*videoFrame);
	//bitmapOut->write(bitmapFrame);

}

#include "server.h"
#include <QDebug>

Server::Server(QMutex* sensorMutex){

	sensorDataMutex = sensorMutex;

//	timer = new QTimer(this);
//	connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));

	socket = new QUdpSocket(this);
	socket->bind(QHostAddress::LocalHost, DATA_PORT);
	//socket->connectToHost("192.168.3.255", DATA_PORT);
	//if (socket->waitForConnected(1000))
	//	qDebug("Connected!");
	connect(socket, SIGNAL(readyRead()),
	     this, SLOT(readPendingDatagrams()));

	if(parameters.size() == 0) init_params();

	qDebug() << "We have " << parameters.size() << " parameters";
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
		qDebug() << "Parsing command:" << datum;
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
	qDebug() << "Processed Datagram, echoing";
	if(!remoteHost.isNull()) socket->writeDatagram(datagram, remoteHost, 5325);
}

void Server::doAction(QString type, QString name, QString value){
	qDebug() << "Command Parsed, taking action." << type;
	if(type == "Connect"){
		// set remoteHost
		qDebug() << "Attempting to connect to:" << value;
		if(remoteHost.setAddress(value)) qDebug() << "Successfully set address";
		else qDebug() << "Failed to set address";
	}else if(type == "Mode"){
		if(value == "Running") emit go();
		else if(value == "Stopped") emit stop();
		else if(value == "Killed") emit kill();
		else if(value == "Reset") emit reset();
	}else if(type == "Calibrate"){
		emit calibrateDepth(value.toDouble());
	}else if(type == "Param"){
		emit setParam(name, value.toDouble());
	}else if(type == "Input"){
		emit setInput(name, value.toDouble());
	}else if(type == "Flag"){
		if(name == "Rec") emit setRec(value == "true");
		else if(name == "noRec") emit setRec(false);
		else if(name == "Log") emit setLog(value == "true");
		else if(name == "noLog") emit setLog(false);
	}else if(type == "GetParams"){
		sendParams();
	}else if(type == ""){
		qDebug() << "Error: Missing Command Family";
	}else{
		qDebug() << "Error: Invalid Command Family";
	}
	//qDebug() << "Action completed";
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
	socket->writeDatagram(sensordata, remoteHost, 5325);
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
	socket->writeDatagram(datagram, remoteHost, 5325);
}

void Server::sendParams(){
	if(remoteHost.isNull()) return;
	qDebug() << "Sending Params";
	QByteArray datagram;
	// parameters data
	// params.stuff

	QList<QString> params = parameters.keys();

	foreach(QString param, params){
		qDebug() << "Getting Parameter:" << param;
		addDatum(datagram, "Parameter", param, QString::number(*(parameters[param])));
	}

	// write to port
	qDebug() << "Sending Params Datagram:" << datagram;
	socket->writeDatagram(datagram, remoteHost, 5325);
}


void Server::addDatum(QByteArray& datagram, QString type, QString name, QString value){
	datagram += type;
	datagram += '.';
	datagram += name;
	datagram += '=';
	datagram += value;
	datagram += ';';
}

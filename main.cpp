#define USE_SERVER
#include <QApplication>
#include <QMutex>
#ifdef USE_SERVER
#include "server/server.h"
#else
#include "dashboard/dashboard.h"
#endif
#include "auv/auv.h"
//#include "brain/brain.h"
#include "auv/camread.h"
#include "model/model.h"
#include <iostream>
#include <QDebug>
using namespace std;

static bool simulateVideo = false;
static bool simulateSensors = false;

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
	QStringList args = app.arguments();
	QString arg;
	foreach(arg, args){
		if(arg == "-s" || arg == "--simulate") simulateSensors = true;
		else if(arg == "-h"){
			qDebug() << "Available Arguments:";
			qDebug() << "\t-s or --simulate : do not expect hardware to exist";
		}
	}

//	int appReturn;
	QMutex modelMutex;
	QMutex sensorMutex;
	
	/* Initialize hardware */
	qDebug("Initializing Camera");
	if(camread_open("/dev/video0", 640, 480)) {
//		if(!white_balance()) qDebug("White Balance failed.");
		qDebug("Camera Online");
	} else {
		simulateVideo = true;
		qDebug("Camera Not Found, Simulating");
	}

	qDebug("Initializing Hardware Interfaces");
	AUV* auv = new AUV(simulateSensors, &sensorMutex);
#ifndef USE_SERVER
	/* Initialize Dashboard */
	qDebug("Initializing Dashboard");
	Dashboard* gui = new Dashboard(0, &modelMutex);
#else
	/* Initialize Server */
	qDebug("Initializing Server");
	Server* server = new Server(&sensorMutex);
#endif
	/* Initialize Brain */
	qDebug("Initializing Model");
	Model* brain = new Model(&modelMutex);
	
	/* Connect Signals and Slots */
	qDebug("Connecting Components");
	// From AUV to Brain
	QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), brain, SLOT(updateSensorsInput(AUVSensors)));
	
	// From Brain to AUV
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), auv, SLOT(inputFromBrain(ExternalOutputs_brain, int)));
	

#ifndef USE_SERVER
	// From AUV to GUI
	QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), gui, SLOT(updateSensorsView(AUVSensors)));
	// From GUI to AUV
	QObject::connect(gui, SIGNAL(startAUV()), auv, SLOT(goAUV()));
	QObject::connect(gui, SIGNAL(stopAUV()), auv, SLOT(stop()));
	QObject::connect(gui, SIGNAL(resetAUV()), auv, SLOT(reset()));
	QObject::connect(gui, SIGNAL(killAUV()), auv, SLOT(kill()));
	QObject::connect(gui, SIGNAL(setDepth(double)), auv, SLOT(setActualDepth(double)));
	// From Brain to GUI
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), gui, SLOT(updateBrainView(ExternalOutputs_brain, int)));
	
	// From GUI to Brain
	// Not here (TODO)
	QObject::connect(gui, SIGNAL(setState(int)), brain, SLOT(setState(int)));
	QObject::connect(gui, SIGNAL(startRecordVideo()), brain, SLOT(startRecordVideo()));
	QObject::connect(gui, SIGNAL(stopRecordVideo()), brain, SLOT(stopRecordVideo()));
#else
	// From AUV to Server
	QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), server, SLOT(sendSensorData(AUVSensors)));
	// From server to AUV
	QObject::connect(server, SIGNAL(go()), auv, SLOT(goAUV()));
	QObject::connect(server, SIGNAL(stop()), auv, SLOT(stop()));
	QObject::connect(server, SIGNAL(reset()), auv, SLOT(reset()));
	QObject::connect(server, SIGNAL(kill()), auv, SLOT(kill()));
	QObject::connect(server, SIGNAL(calibrateDepth(double)), auv, SLOT(setActualDepth(double)));
	QObject::connect(server, SIGNAL(whiteBalance()), auv, SLOT(autoWhiteBalance()));

	// From Brain to server
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), server, SLOT(sendBrainData(ExternalOutputs_brain, int)));
	
	// From server to Brain
	QObject::connect(server, SIGNAL(setInput(QString, double)), brain, SLOT(setInput(QString, double)));
	QObject::connect(server, SIGNAL(setParam(QString, double)), brain, SLOT(setParam(QString, double)));
	QObject::connect(server, SIGNAL(setRec(bool)), brain, SLOT(setRecordVideo(bool)));
	
#endif


	qDebug("Starting Hardware Interfaces");
	auv->start();
	qDebug("Starting Model");
	brain->start();
#ifndef USE_SERVER
	qDebug("Starting Dashboard");
	gui->show();
#else
	qDebug("Starting Server");
	server->start();
#endif
	cerr << "Initialization Complete, System Online" << endl;

	// Wait for threads to end?
	// The main thread does nothing at the moment.
/*
	auv->wait();
	brain->wait();
	server->wait();
*/
//	while(1) pause();
	return app.exec();
}

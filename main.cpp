#include <QApplication>
#include <QMutex>
#include "dashboard/dashboard.h"
#include "auv/auv.h"
#include "brain/brain.h"
#include "auv/camread.h"
#include "model.h"
#include <iostream>
using namespace std;

static bool simulateVideo = false;
static bool simulateSensors = true;

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
//	int appReturn;
	QMutex modelMutex;
	
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
	AUV* auv = new AUV(simulateSensors);
	/* Initialize Dashboard */
	qDebug("Initializing Dashboard");
	Dashboard* gui = new Dashboard(0, &modelMutex);
	/* Initialize Brain */
	qDebug("Initializing Model");
	Model* brain = new Model(&modelMutex);
	
	/* Connect Signals and Slots */
	qDebug("Connecting Components");
	// From AUV to GUI
	QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), gui, SLOT(updateSensorsView(AUVSensors)));
	// From AUV to Brain
	QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), brain, SLOT(updateSensorsInput(AUVSensors)));
	
	// From GUI to AUV
	QObject::connect(gui, SIGNAL(startAUV()), auv, SLOT(goAUV()));
	QObject::connect(gui, SIGNAL(stopAUV()), auv, SLOT(stop()));
	QObject::connect(gui, SIGNAL(resetAUV()), auv, SLOT(reset()));
	QObject::connect(gui, SIGNAL(killAUV()), auv, SLOT(kill()));
	QObject::connect(gui, SIGNAL(setDepth(double)), auv, SLOT(setActualDepth(double)));
	
	// From Brain to AUV
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), auv, SLOT(inputFromBrain(ExternalOutputs_brain, int)));
	
	// From Brain to GUI
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), gui, SLOT(updateBrainView(ExternalOutputs_brain, int)));
	
	// From GUI to Brain
	// Not here (TODO)
	QObject::connect(gui, SIGNAL(setState(int)), brain, SLOT(setState(int)));
	QObject::connect(gui, SIGNAL(startRecordVideo()), brain, SLOT(startRecordVideo()));
	QObject::connect(gui, SIGNAL(stopRecordVideo()), brain, SLOT(stopRecordVideo()));
	
	qDebug("Starting Hardware Interfaces");
	auv->start();
	qDebug("Starting Model");
	brain->start();
	qDebug("Starting Dashboard");
	gui->show();
	cerr << "Initialization Complete, System Online" << endl;
	return app.exec();
//	appReturn = app.exec();
//
//	delete auv;
//	delete brain;
//	delete gui;
//
//	sleep(1000);
//
//	return appReturn;

}

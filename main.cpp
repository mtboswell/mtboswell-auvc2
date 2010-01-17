#include <QApplication>
#include <QMutex>
#include "dashboard/dashboard.h"
#include "auv/auv.h"
#include "brain/brain.h"
#include "auv/camread.h"
#include "model.h"
#include <iostream>
using namespace std;

extern "C" int camread_open(const char*, int, int);

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
	QMutex modelMutex;
	
	/* Initialize hardware */
	qDebug("Initializing Camera");
	camread_open("/dev/video0", 640, 480);
	
	qDebug("Initializing Hardware Interfaces");
	AUV* auv = new AUV();
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
	
	// From Brain to AUV
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain)), auv, SLOT(inputFromBrain(ExternalOutputs_brain)));
	
	// From Brain to GUI
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain)), gui, SLOT(updateBrainView(ExternalOutputs_brain)));
	
	// From GUI to Brain
	// Not here (TODO)
	
	qDebug("Starting Hardware Interfaces");
	auv->start();
	qDebug("Starting Model");
	brain->start();
	qDebug("Starting Dashboard");
	gui->show();
	cerr << "Initialization Complete, System Online" << endl;
	return app.exec();

}

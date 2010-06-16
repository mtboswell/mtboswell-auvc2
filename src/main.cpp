#include <QCoreApplication>
#include <QMutex>

#include "configloader.h"
QMap<QString, QString> config;

#include "server/server.h"
#include "auv/auv.h"
#include "auv/calibrateservos.h"
//#include "brain/brain.h"
#include "auv/camread.h"
#include "model/model.h"
#include <iostream>
#include <QDebug>
using namespace std;

static bool noCamera = false;
static bool stdCamera = false;
static bool noHardSwitch = false;

int main(int argc, char *argv[]){

	QCoreApplication app(argc, argv);
	QStringList args = app.arguments();
	QString arg;
	foreach(arg, args){
		// -s means the hardware switch is missing and is not needed.  This is necessary for debugging, since we won't start anything if the switch is off or missing.
		if(arg == "-s" || arg == "--simulate") noHardSwitch = true;
		// -c triggers servo calibration mode.  See docs in auv/calibrateservos.h.
		else if(arg == "-c" || arg == "--calibrate-servos") return calibrateServos();
		else if(arg == "-h"){
			qDebug() << "Available Arguments:";
			qDebug() << "\t-s or --simulate : disable hardware on/off switch";
			qDebug() << "\t-c or --calibrate-servos : enter servo calibration mode instead of running normally";
			return 0;
		}else if(arg == "-Y"){
			stdCamera = true;
		}
	}

	if(config.isEmpty())
		loadConfigFile(config);

	QMutex modelMutex;
	QMutex sensorMutex;
	
	/* Initialize camread  ************************************************************/
	qDebug("Initializing Camera");

	if(camread_open("/dev/video0", 640, 480, stdCamera)) {
		// We may or may not want to white balance when we start up
		//if(!white_balance()) qDebug("White Balance failed.");
		qDebug("Camera Online");
	} else {
		noCamera = true;
		qDebug("Error: Camera Not Found or Initialization Error");
	}

	/* Create and initialize objects ******************************************************/
	qDebug("Initializing Hardware Interfaces");

	AUV* auv = new AUV(&sensorMutex, noHardSwitch);

	/* Initialize Server */
	qDebug("Initializing Server");
	Server* server = new Server();

	/* Initialize Brain */
	qDebug("Initializing Model");
	Model* brain = new Model(&modelMutex);


	/* Connect Signals and Slots ****************************************************************** */
	qDebug("Connecting Components");

	// From AUV to Brain
	QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), brain, SLOT(updateSensorsInput(AUVSensors)));
	QObject::connect(auv, SIGNAL(setBrainInput(QString, double)), brain, SLOT(setInput(QString, double)));
	
	// From Brain to AUV
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), auv, SLOT(inputFromBrain(ExternalOutputs_brain)));
	//QObject::connect(brain, SIGNAL(status(QString)), auv, SLOT(statusMessage(QString)));

	// From AUV to Server
	QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), server, SLOT(sendSensorData(AUVSensors)));
	QObject::connect(auv, SIGNAL(status(QString)), server, SLOT(sendStatus(QString)));
	QObject::connect(auv, SIGNAL(error(QString)), server, SLOT(sendError(QString)));

	// From server to AUV
	QObject::connect(server, SIGNAL(go()), auv, SLOT(goAUV()));
	QObject::connect(server, SIGNAL(stop()), auv, SLOT(stop()));
	QObject::connect(server, SIGNAL(reset()), auv, SLOT(reset()));
	QObject::connect(server, SIGNAL(kill()), auv, SLOT(kill()));
	QObject::connect(server, SIGNAL(calibrateDepth(double)), auv, SLOT(setActualDepth(double)));
	QObject::connect(server, SIGNAL(whiteBalance()), auv, SLOT(autoWhiteBalance()));
	QObject::connect(server, SIGNAL(actuateMech(QString)), auv, SLOT(activateMechanism(QString)));
	QObject::connect(server, SIGNAL(runScript(QString)), auv, SLOT(runScriptedMotion(QString)));
	QObject::connect(server, SIGNAL(moveCamera(double, double)), auv, SLOT(look(double, double)));
	QObject::connect(server, SIGNAL(status(QString)), auv, SLOT(statusMessage(QString)));

	// From Brain to server
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), server, SLOT(sendBrainData(ExternalOutputs_brain, int)));
	QObject::connect(brain, SIGNAL(outputReady(ExternalOutputs_brain, int)), server, SLOT(sendVideo()));
	QObject::connect(brain, SIGNAL(status(QString)), server, SLOT(sendStatus(QString)));
	QObject::connect(brain, SIGNAL(error(QString)), server, SLOT(sendError(QString)));
	
	// From server to Brain
	QObject::connect(server, SIGNAL(setInput(QString, double)), brain, SLOT(setInput(QString, double)));
	QObject::connect(server, SIGNAL(setParam(QString, double)), brain, SLOT(setParam(QString, double)));
	QObject::connect(server, SIGNAL(setRec(bool)), brain, SLOT(setRecordVideo(bool)));
		

	/* Start threads ******************************************************************************/
	qDebug("Starting Hardware Interfaces");

	auv->start();

	qDebug("Starting Model");
	brain->start();

	qDebug("Starting Server");
	server->start();

	qDebug() << "Initialization Complete, System Online";


	/* Done, keep running forever *****************************************************************/
	// Start main event loop (does nothing)
	return app.exec();
}

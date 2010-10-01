#include <QCoreApplication>
#include <QMutex>

#include "configloader.h"
QMap<QString, QString> config;

#include "state.h"
#include "datahub/datahub.h"

//#include "server/server.h"
//#include "server-jaus/server-jaus.h"
#include "auv/auv.h"
#include "auv/calibrateservos.h"
//#include "brain/brain.h"
//#include "auv/camread.h"
#include "model/model.h"

#include <QDebug>

static bool simulate = false;

int main(int argc, char *argv[]){

	QCoreApplication app(argc, argv);
	QStringList args = app.arguments();
	QString arg;
	foreach(arg, args){
		// -s means the hardware switch is missing and is not needed.  This is necessary for debugging, since we won't start anything if the switch is off or missing.
		if(arg == "-s" || arg == "--simulate") simulate = true;
		// -c triggers servo calibration mode.  See docs in auv/calibrateservos.h.
		else if(arg == "-c" || arg == "--calibrate-servos") return calibrateServos();
		else if(arg == "-h"){
			qDebug() << "Available Arguments:";
			qDebug() << "\t-s or --simulate : disable hardware on/off switch";
			qDebug() << "\t-c or --calibrate-servos : enter servo calibration mode instead of running normally";
			return 0;
		}
	}

	if(config.isEmpty())
		loadConfigFile(config);

	AUV_State stateData;
	DataHub hub;

	QMutex modelMutex;
	QMutex sensorMutex;
	

	/* Create and initialize objects ******************************************************/
	qDebug("Initializing Hardware Interfaces");

	AUV* auv = new AUV(&sensorMutex, simulate);
	hub.addModule(auv);

	/* Initialize Server */
	//qDebug("Initializing Server");
	//Server* server = new Server();
	//hub.addModule(server);

	/* Initialize JAUS */
	//JAUSServer* jaus = new JAUSServer(116,1,1);

	/* Initialize Brain */
	qDebug("Initializing Brain");
	Model* brain = new Model(&modelMutex);
	hub.addModule(brain);


	/* Connect Signals and Slots ****************************************************************** */
/*
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

	// From AUV to JAUS
	//QObject::connect(auv, SIGNAL(sensorUpdate(AUVSensors)), jaus, SLOT(updateSensors(AUVSensors)));

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
		
*/

	/* Start threads ******************************************************************************/
	qDebug("Starting Hardware Interfaces");

	auv->start();

	qDebug("Starting Model");
	brain->start(QThread::HighPriority);

	//qDebug("Starting Server");
	//server->start();
	
	//qDebug("Starting JAUS");
	//jaus->start();

	qDebug() << "Initialization Complete, System Online";


	/* Done, keep running forever *****************************************************************/
	// Start main event loop (does nothing)
	return app.exec();
}

#include <QCoreApplication>
#include <QMutex>

#include "configloader.h"

#include "state.h"
#include "datahub/datahub.h"

// should this be here?
#include "auv/calibrateservos.h"

#include <QDebug>

static bool simulate = false;

int main(int argc, char *argv[]){

	QCoreApplication app(argc, argv);
	QStringList args = app.arguments();
	QString arg;
	foreach(arg, args){
		// -s means simulate, or, more specifically, ignore hardware
		if(arg == "-s" || arg == "--simulate") simulate = true;
		// -c triggers servo calibration mode.  See docs in auv/calibrateservos.h.
		else if(arg == "-c" || arg == "--calibrate-servos") return calibrateServos();
		else if(arg == "-h"){
			qDebug() << "Available Arguments:";
			qDebug() << "\t-s or --simulate : disable hardware";
			qDebug() << "\t-c or --calibrate-servos : enter servo calibration mode instead of running normally";
			return 0;
		}
	}

	QMap<QString, QString> config;
	loadConfigFile(config);

	AUV_State stateData;
	stateData.simulate = simulate;

	DataHub hub;



	/* Create Module objects and set hub as parent */
	Module* samp = new Sample(&config, &stateData, &hub);
	// OR	
	Sample2 samp2(&config, &stateData, &hub);



	/* Start everything */
	hub->initializeAndLaunchAllModules();
	// Start main event loop (for dataHub)
	return app.exec();
	/* Done, keep running forever */
}

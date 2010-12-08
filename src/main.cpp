#include <QApplication>
#include <QDebug>
#include <QMutex>

#include "configloader.h"

#include "state.h"
#include "datahub/datahub.h"

//! \todo should this be here?
//#include "auv/calibrateservos.h"

// modules
#include "actor/actor.h"

#include <QTreeView>


static bool simulate = false;

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
	QStringList args = app.arguments();
	QString arg;
	foreach(arg, args){
		// -s means simulate, or, more specifically, ignore hardware
		if(arg == "-s" || arg == "--simulate") simulate = true;
		// -c triggers servo calibration mode.  See docs in auv/calibrateservos.h.
//		else if(arg == "-c" || arg == "--calibrate-servos") return calibrateServos();
		else if(arg == "-h"){
			qDebug() << "Available Arguments:";
			qDebug() << "\t-s or --simulate : disable hardware";
			qDebug() << "\t-c or --calibrate-servos : enter servo calibration mode instead of running normally";
			return 0;
		}
	}

	// should we use QSettings?
	QMap<QString, QString> config;
	loadConfigFile(config);

	AUVC_State_Data stateData;
	stateData.setData("Simulate", simulate);

	DataHub hub(&stateData);

	/* Create Module objects and set hub as parent */
	//Module* samp = new Sample(&config, &stateData, &hub);
	// OR	
	//Sample2 samp2(&config, &stateData, &hub);

	Module* actor = new Actor(&config, &stateData, &hub);


	QTreeView *tree = new QTreeView();
	tree->setModel(&stateData);


	/* Start everything */
	hub.initializeAndLaunchAllModules();


	tree->show();

	// Start main event loop (for dataHub)
	return app.exec();

	/* Done, keep running forever */
	//! \todo add exit and shutdown features
}

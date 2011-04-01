#include <QApplication>
#include <QDebug>
#include <QMutex>

#include "misc/configloader.h"

#include "state/state.h"
#include "state/vdatum.h"
#include "module/modulehub.h"

// modules
#include "controllers/controllers.h"
#include "sal/sal.h"
//#include "actuators/actuators.h"

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
		//	qDebug() << "\t-c or --calibrate-servos : enter servo calibration mode instead of running normally";
			return 0;
		}
	}

	// Required for using VDatums in signals and slots
	qRegisterMetaType<VDatum>("VDatum");

	// should we use QSettings?
	QMap<QString, QString> config;
	loadConfigFile(config);

	AUVC_State_Data stateData;
	stateData.setData("Simulate", simulate);

	ModuleHub hub(&stateData, true, 5325, 5743);

	/* Create Module objects and set hub as parent */
	//Module* samp = new Sample(&config, &stateData, &hub);
	// OR	
	//Sample2 samp2(&config, &stateData, &hub);

	Controllers* controllers = new Controllers(&config, &stateData);
	hub.addModule(controllers);

	SAL* sal = new SAL(&config, &stateData);
	hub.addModule(sal);

//	Actuators* actuators = new Actuators(&config, &stateData);
//	hub.addModule(actuators);

	/* Start everything */
	hub.initializeAndLaunchAllModules();


	QTreeView *tree = new QTreeView();
	tree->setModel(&stateData);

	tree->show();

	qDebug("Main thread id: %d", (int) QThread::currentThreadId());

	// Start main event loop (for dataHub)
	return app.exec();

	/* Done, keep running forever */
	//! \todo add exit and shutdown features
}

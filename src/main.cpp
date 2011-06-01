
#define GUI

#ifdef GUI
#include <QApplication>
#else
#include <QCoreApplication>
#endif

#include <QDebug>
#include <QMutex>

#include "misc/configloader.h"

#include "state/state.h"
#include "state/vdatum.h"
#include "module/modulehub.h"

// modules
#include "controllers/controllers.h"
#include "sal/sal.h"
#include "actuators/actuators.h"
#include "director/director.h"
#include "cameraSAL/cameraSAL.h"

#include <QTreeView>


static bool simulate = false;
static bool thrustersON = true;
static bool directorON = true;
static QStringList debug;

int main(int argc, char *argv[]){

#ifdef GUI
	QApplication app(argc, argv);
#else
	QCoreApplication app(argc, argv);
#endif
	QStringList args = app.arguments();
	QString arg;
	foreach(arg, args){
		// -s means simulate, or, more specifically, ignore hardware
		if(arg == "-s" || arg == "--simulate") simulate = true;
		// -c triggers servo calibration mode.  See docs in auv/calibrateservos.h.
//		else if(arg == "-c" || arg == "--calibrate-servos") return calibrateServos();
		// if --no-thrusters in on then do not start actuator module
		else if(arg == "--no-thrusters" || arg == "-T") thrustersON = false;
		///if --no-director is on then do not start director module
		else if (arg == "--no-director" || arg == "-D") directorON = false;
		else if(arg.startsWith("-d:") || arg.startsWith("--debug:")){
			debug.append(arg.right(arg.size() - arg.indexOf(":") - 1));
		}
		else if(arg == "-h"){
			qDebug() << "Available Arguments:";
			qDebug() << "\t-s or --simulate : disable hardware";
			qDebug() << "\t-d:[ModuleName] or --debug:[ModuleName] : enable debugging for module [ModuleName]";
			qDebug() << "\t--no-thrusters : disable actuators module";
			qDebug() << "\t--no-director : disable director module";
		//	qDebug() << "\t-c or --calibrate-servos : enter servo calibration mode instead of running normally";
			return 0;
		}
	}

	// Required for using VDatums in signals and slots
	qRegisterMetaType<VDatum>("VDatum");
	qRegisterMetaType<QList<VDatum> >("QList<VDatum>");

	// should we use QSettings?
	QMap<QString, QString> config;
	loadConfigFile(config);

	AUVC_State_Data stateData;

	//Set inital Data
	stateData.setData("Simulate", simulate);
	stateData.setData("ThrustersON.Forward", true);
	stateData.setData("ThrustersON.Angled", true);

	ModuleHub hub(&stateData, &config, &debug, true, 5325, 5743);

	qDebug() << "Creating Controllers";
	hub.addModule(new Controllers());

	qDebug() << "Creating SAL";
	hub.addModule(new SAL());
	
	qDebug() << "Creating CameraSAL";
	hub.addModule(new CameraSAL());

	if (thrustersON) {
		qDebug() << "Creating Actuators";
		hub.addModule(new Actuators());
	}
	if (directorON) {
    		qDebug() << "Creating Director";    // Must have Lua 5.1+ libs installed for director
 	   	hub.addModule(new director());
	}

	/* Start everything */
	hub.initializeAndLaunchAllModules();


#ifdef GUI
	QTreeView *tree = new QTreeView();
	tree->setModel(&stateData);

	tree->show();
#endif

	qDebug("Main thread id: %d", (int) QThread::currentThreadId());

	// Start main event loop (for dataHub)
	return app.exec();

	/* Done, keep running forever */
	//! \todo add exit and shutdown features
}

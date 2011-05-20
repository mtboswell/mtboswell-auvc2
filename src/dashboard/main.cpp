#include <QApplication>
#include <QtGui>

#include "../module/modulehub.h"
#include "../misc/configloader.h"
#include "../state/state.h"

#include "dashboard.h"

#ifdef STATIC
#include <QtPlugin>

Q_IMPORT_PLUGIN(qjpeg)
Q_IMPORT_PLUGIN(qpng)
#endif

static QStringList debug;

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
	QStringList args = app.arguments();

	QApplication::setStyle(new QCleanlooksStyle); 

	// should we use QSettings?
	QMap<QString, QString> config;
	loadConfigFile(config);

	AUVC_State_Data stateData;

	debug.append("Dashboard");

	ModuleHub hub(&stateData, &config, &debug, false, 5743, 5325);

	/* Initialize Dashboard */
	qDebug("Initializing Dashboard");
	GuiModule* gui = new Dashboard();
	hub.addModule(gui);

//	QObject::connect(gui, SIGNAL(setData(VDatum)), hub, SLOT(messageIn(VDatum)));
	QObject::connect(gui, SIGNAL(sync()), &hub, SLOT(sync()));
	QObject::connect(gui, SIGNAL(setAddress(QString)), &hub, SLOT(setRemoteAddr(QString)));


	hub.initializeAndLaunchAllModules();

	qDebug("Starting Display");
	gui->show();

	// Start main event loop
	app.exec();

	delete gui;
	return 0;
}

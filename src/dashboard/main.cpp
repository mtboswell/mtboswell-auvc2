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

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
	QStringList args = app.arguments();

	QApplication::setStyle(new QCleanlooksStyle); 

	// should we use QSettings?
	QMap<QString, QString> config;
	loadConfigFile(config);

	AUVC_State_Data stateData;

	ModuleHub hub(&stateData, false, 5743, 5325);

	/* Initialize Dashboard */
	qDebug("Initializing Dashboard");
	GuiModule* gui = new Dashboard(&config, &stateData);
	hub.addModule(gui);

//	QObject::connect(gui, SIGNAL(setData(VDatum)), hub, SLOT(messageIn(VDatum)));
	QObject::connect(gui, SIGNAL(reconnect(VDatum)), &hub, SLOT(reconnect(VDatum)));


	hub.initializeAndLaunchAllModules();

	qDebug("Starting Display");
	gui->show();

	// Start main event loop
	app.exec();

	delete gui;
	return 0;
}

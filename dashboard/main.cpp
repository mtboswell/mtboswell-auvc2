#include <QtCore>
#include <QApplication>
#include <QtGui>
#include "dashboard.h"
#ifdef STATIC
#include <QtPlugin>

Q_IMPORT_PLUGIN(qjpeg)
Q_IMPORT_PLUGIN(qpng)
#endif

int main(int argc, char *argv[]){

	QApplication app(argc, argv);
	QStringList args = app.arguments();

	/* Initialize Dashboard */
	qDebug("Initializing Dashboard");
	Dashboard* gui = new Dashboard();

	qDebug("Starting Display");
	gui->show();

	// Start main event loop
	return app.exec();
}

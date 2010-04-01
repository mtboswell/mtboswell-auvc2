#include <QtCore>
#include <QApplication>
#include <QtGui>
#include "dashboard.h"

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

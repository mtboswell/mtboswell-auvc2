#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "../../os5000.h"
#include "os5000Thread.h"

int main(int argc, char *argv[]) {
	
	QCoreApplication app(argc, argv);
	
	os5000Thread* thread = new os5000Thread();
	
	qDebug() << "launching app.exec()";
	return app.exec();
	
}

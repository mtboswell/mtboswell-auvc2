
#include <QApplication>

#include "cameratester.h"

int main(int argc, char* argv[]){
	QApplication app(argc, argv);

	CameraTester tester;

	tester.show();

	return app.exec();
}

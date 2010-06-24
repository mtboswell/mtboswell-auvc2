
#include <QApplication>
#include "game.h"
#include "../src/auv/qextserialport/qextserialport.h"
#include "../src/auv/arduino.h"
#include "../dashboard/controlboard/controlboard.h"

int main(int argc, char* argv[]){

	QApplication app(argc, argv);

	Game* game = new Game();
	ControlBoard* cb = new ControlBoard("/dev/ttyUSB0");

	QObject::connect(cb, SIGNAL(joystickMoved(joystickPos)), game, SLOT(joystickInput(joystickPos)));

	game->show();

	return app.exec();
}

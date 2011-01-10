#include "controlboard.h"
#include <QLabel>

int main(){
	ControlBoard* cb = new ControlBoard("/dev/ttyUSB0");
	QLabel* label = new QLabel();
	QObject::connect(cb, SIGNAL()

}

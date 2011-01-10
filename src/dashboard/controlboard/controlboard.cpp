#include "controlboard.h"

ControlBoard::ControlBoard(const QString & serialPort){
	ard = new Arduino(serialPort);
	connect(ard, SIGNAL(newValueReady(QString, unsigned int)), this, SLOT(interpretRawData(QString, unsigned int)));
}

void ControlBoard::interpretRawData(QString name, unsigned int value){
	//qDebug() << "Received: " << name << value;
	if(name == "BUTTON"){
		if(!currentButtonState != (value == 0))
			if(value == 0) emit buttonPressed();
			else emit buttonReleased();
		currentButtonState = (value == 0);
		return;		
	}else if(name == "JSA"){
		jsPinState[0] = (value == 0);
	}else if(name == "JSB"){
		jsPinState[1] = (value == 0);
	}else if(name == "JSC"){
		jsPinState[2] = (value == 0);
	}else if(name == "JSD"){
		jsPinState[3] = (value == 0);
	}

	if(jsPinState[0]){
		if(jsPinState[1]) currentJoystickPosition = UPLEFT;
 		else if(jsPinState[3]) currentJoystickPosition = UPRIGHT;
 		else currentJoystickPosition = UP;
	}else if(jsPinState[1]){
		if(jsPinState[2]) currentJoystickPosition = DOWNLEFT;
		else currentJoystickPosition = LEFT;
	}else if(jsPinState[2]){
		if(jsPinState[3]) currentJoystickPosition = DOWNRIGHT;
		else currentJoystickPosition = DOWN;
	}else if(jsPinState[3]) currentJoystickPosition = RIGHT;
	else currentJoystickPosition = CENTER;
		
	if(currentJoystickPosition != oldJoystickPosition) emit joystickMoved(currentJoystickPosition);
	oldJoystickPosition = currentJoystickPosition;
	//qDebug() << "Joystick: " << currentJoystickPosition;

}

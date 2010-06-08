#ifndef CONTROLBOARD_H
#define CONTROLBOARD_H

#include "arduino.h"
#include <QDebug>
		
typedef enum joystickPos {CENTER, UP, UPLEFT, LEFT, DOWNLEFT, DOWN, DOWNRIGHT, RIGHT, UPRIGHT} joyPos;

class ControlBoard: public QObject 
{

	Q_OBJECT
	public:
		ControlBoard(const QString & serialPort);

	signals:
		void buttonPressed();
		void buttonReleased();
		void joystickMoved(joystickPos position);

	private slots:
		void interpretRawData(QString name, unsigned int value);

	private:
		joystickPos currentJoystickPosition, oldJoystickPosition;
		bool currentButtonState;
		bool jsPinState[4];
		Arduino* ard;

};

#endif

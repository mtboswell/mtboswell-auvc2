#include "calibrateservos.h"
#include "ports.h"
#include <iostream>
using namespace std;

int calibrateServos() {
	int servoNum;
	int servoPos;
	Pololu* pol = new Pololu(POLOLUPORT);
	do{
		cout << "Welcome to the Servo Calibration Tool." << endl
			<< "Which servo would you like to calibrate?" << endl
			<< "(enter -1 to exit)" << endl;
		cin >> servoNum;
		if(servoNum < 0) break;
		if(servoNum > 16){
			cout << "That doesn't seem like an appropriate number for a servo. Starting over..." << endl;
			cin.ignore();
			continue;
		}
		cout << "Calibrating servo " << servoNum << "." << endl
			<< "Please enter the positions that you would like the servo to move to (one on each line)." << endl
			<< "Enter 0 when you are finished." << endl;
		while(servoPos != 0){
			cin >> servoPos;
			if(servoPos > 5000 || servoPos < 800) continue;
			pol->setPosAbs(servoNum, servoPos);
		}
	}while(servoNum >= 0);
	return 0;
}

/**	gorc.cpp - Remote control and monitoring interface
 *	for the AUV.  Uses curses for the UI.
 *	Author: Micah Boswell
 *	Date: Aug. 15, 2009
 **/
#include <iostream>
#include <curses.h>
#include "auv.h"
#include "rc.h"
using namespace std;

// converts an int to a percentage string and displays
void mvaddpercent(int r, int c, int per);
// converts a float to a str and displays
void mvadddec(int r, int c, float dec);

int main()
{
	// init control and sensor objects
	RC* control = new RC();
    AUV* auv = new AUV();
	
	// set up curses interface
	WINDOW *wnd;
	wnd = initscr();
	cbreak();
	halfdelay(1);
	noecho();
	clear();
	
	// display UI field labels
	mvaddstr(0, (COLS - 11)/2, "RC AUV");
		mvaddstr(2, 0, "Forward: ");
		mvaddstr(3, 0, "Yaw: ");
		mvaddstr(4, 0, "Vertical: ");
		mvaddstr(5, 0, "Camera: ");
		mvaddstr(2, 30, "Depth: ");
		mvaddstr(3, 30, "Heading: ");
		mvaddstr(5, 30, "Thruster Voltage: ");
		mvaddstr(6, 30, "Thruster Current: ");
		mvaddstr(7, 30, "Thruster Power: ");
	move(8,0);
	refresh();

	// declare vars for input and sensor data
	char cmd;
	AUVMotion* velo;
	cameraPosition cam;
	imu_data orientation;
	float depth;
	double heading;
	double thrusterVoltage;
	double thrusterCurrent;
	double thrusterPower;
	
	// main loop
	while(1)
	{
		// get input char from keyboard
		cmd = getch();
		// exit on 'k'
		if(cmd == 'k') break;
		// send input char to rc controller method
		if(cmd > '0') control->wsad(cmd);
			else control->wsad('t');
		// get feedback from rc controller
		velo = control->getVelocity();
		cam = control->getCamera();
		// get data from sensors
    	depth = auv->getDepth();
    	orientation = auv->getOrientation();
    	heading = orientation.yaw;
    	thrusterPower = auv->getThrusterPower();
    	thrusterCurrent = auv->getThrusterCurrent();
    	thrusterVoltage = auv->getThrusterVoltage();
    
		mvaddpercent(2, 9, (int) (((float)velo->forward)/127 * 100));
		mvaddpercent(3, 5, (int) (((float)velo->yaw)/127 * 100));
		mvaddpercent(4, 10, (int) (((float)velo->vertical)/127 * 100));
		switch(cam){
			case UP:
				mvaddstr(5, 8, "UP     ");
				break;
			case FORWARD:
				mvaddstr(5, 8, "FORWARD");
				break;
			case DOWN:
				mvaddstr(5, 8, "DOWN   ");
				break;
			case LEFT:
				mvaddstr(5, 8, "LEFT   ");
				break;
			case RIGHT:
				mvaddstr(5, 8, "RIGHT  ");
				break;
		}
		
		mvadddec(2, 37, (float) depth);
		mvadddec(3, 37, (float) heading);
		mvadddec(5, 47, (float) thrusterVoltage);
		mvadddec(6, 47, (float) thrusterCurrent);
		mvadddec(7, 47, (float) thrusterPower);
		
    	move(8,0);
    	refresh();
	}
	endwin();
	delete control;
	delete auv;
	return 0;
}


void mvaddpercent(int r, int c, int per){
	char strout[] = "+000%";
	int tow = ((per > 0)?per:-per);
	strout[0] = per >= 0?'+':'-';
	strout[1] = (char) (tow/100 + '0');
	strout[2] = (char) ((tow/10)%10 + '0');
	strout[3] = (char) (tow%10 + '0');
	mvaddstr(r, c, strout);
}
void mvadddec(int r, int c, float dec){
	char strout[] = "+000.00";
	float tow = ((dec > 0)?dec:-dec);
	strout[0] = dec >= 0?'+':'-';
	strout[1] = (char) ((int) (tow/100) + '0');
	strout[2] = (char) (((int)(tow/10))%10 + '0');
	strout[3] = (char) (((int)tow)%10 + '0');
	strout[5] = (char) (((int)(tow*10))%10 + '0');
	strout[6] = (char) (((int)(tow*100))%10 + '0');
	mvaddstr(r, c, strout);
}




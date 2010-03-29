/*
 * File: auvlog.cpp
 *
 * Log Data for a scripted set of control inputs
 *
 *
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include "auv.h"
#include "alarm.h"
//#include "StraightLevelControl/StraightLevelControl.h"      /* Model's header file */
//#include "StraightLevelControl/rtwtypes.h"                  /* MathWorks types */

using namespace std;


int main(int argc, const char *argv[])
{


	/* Initialize Files */
	if(!(argc > 2)) {
		cerr << "Invalid command line args" << endl;
		return 1;
	}
	ifstream in(argv[1]);
	// open log file in append mode
	ofstream log(argv[2], ios::out | ios::app);
	if(!in.is_open()) return 2;
	if(!log.is_open()) return 3;
	string cmd;
	// Log column headings
	log << "x thruster1 thruster2 thruster3 time depth roll pitch yaw rollrate pitchrate yawrate rollacc pitchacc yawacc magDecl tCurrent tVoltage" << endl;

	/* Initialize hardware */
	AUV* auv = new AUV();
	
	int sample_rate = 50;

	/* Data Vars */
	imu_data orientation;
	float depth;
	signed char motorspeeds[3];
	double tVoltage, tCurrent;

	motorspeeds[0] = 0;
    	motorspeeds[1] = 0;
    	motorspeeds[2] = 0;
    	auv->setThrusters(motorspeeds);

	int x = 0; // main loop counter
	double counterDown = 0; // hold counter
    
	// set up alarm for timing simulink step calls
	initalarm();
  
	while (!in.eof()) {
		
		/* Wait for go */
		auv->externalControl(motorspeeds);
		
		/* Wait for next interval */
		while(!checkalarm()) pause(); 	// wait for step period (change the timing in alarm.h)
	   	resetalarm(); 					// if you don't reset it won't wait next time around

		// Only read next command if we are not waiting on a hold command
		if(counterDown <= 0){
			/* Read Inputs */
			getline(in, cmd);
			cout << endl << cmd << endl;

			/* Parse Input */
			stringstream prs(cmd);
			string tmp;
			int col = 0;
			string command[4];
			stringstream cmds[4];
	
			// Tokenize cmd into command[]
			while(prs >> tmp){
				command[col] = tmp;
				cmds[col] << tmp;
				col++;
			}	
			
			// convert cmd data from strings into ints
			int cmdata[3];
			cmds[1] >> cmdata[0];
			cmds[2] >> cmdata[1];
			cmds[3] >> cmdata[2];

			if(command[0] == "hold") counterDown = sample_rate*cmdata[0];
			else if(command[0] == "mhold") counterDown = sample_rate*cmdata[0]/1000.0;
		// rate command can be implemented after alarm.c is modified to support it
/*			else if(command[0] == "rate") {
				sample_rate = cmdata[0];
				setalarm((int) (1.0/sample_rate), (int) (1.0/sample_rate)*1000000);
			}
*/
			else if(command[0] == "cmd"){
		
				/* Get inputs from file */
				motorspeeds[0] = cmdata[0];
				motorspeeds[1] = cmdata[1];
				motorspeeds[2] = cmdata[2];
	
				/* Send data to other devices */
				auv->setThrusters(motorspeeds);
			//	auv->look((cameraPosition) AUVstateflow_Y.CameraPosition);
			}else if(command[0] == "") cout << "";
			else{
				cout << "Invalid Input: " << command[0] << endl;
			}

		}else counterDown--;

		/* Get data from other devices */
		depth = auv->getDepth();
		orientation = auv->getOrientation();
		tCurrent = auv->getThrusterCurrent();
		tVoltage = auv->getThrusterVoltage();

		
		/* Log Input and Sensor Data */
		log << x 
			<< " " << (int) motorspeeds[0] 
			<< " " << (int) motorspeeds[1] 
			<< " " << (int) motorspeeds[2] 
			<< " " << time(NULL)
			<< " " << depth 
			<< " " << orientation.roll 
			<< " " << orientation.pitch
			<< " " << orientation.yaw
			<< " " << orientation.rollrate
			<< " " << orientation.pitchrate
			<< " " << orientation.yawrate
			<< " " << orientation.rollacc
			<< " " << orientation.pitchacc
			<< " " << orientation.yawacc
			<< " " << orientation.magDecl
			<< " " << tCurrent
			<< " " << tVoltage
			<< endl;

		
		/* Increment loop counter */
		x++;
		
	} // end loop
	log << "Reached end of input file." << endl; 
	in.close();
	log.close();

	/* Terminate model */
	delete auv;
	
	return 0;
} // end main

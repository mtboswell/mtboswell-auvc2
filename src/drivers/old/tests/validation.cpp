/*
 * File: auvgo.cpp
 *
 * Test the ValidationGate simulink model
 *
 * See {modelname}/ert_main.cpp for code generation info
 *
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <iostream>
#include "ValidationGate/ValidationGate.h"      /* Model's header file */
#include "ValidationGate/rtwtypes.h"                  /* MathWorks types */
#include "auv.h"
#include "alarm.h"

#define RUNTIME 90

using namespace std;

static boolean_T OverrunFlag = 0;

// check for overrun and step the simulink model
void rt_OneStep(void)
{
  /* Check for overrun */
  if (OverrunFlag++) {
    rtmSetErrorStatus(ValidationGate_M, "Overrun");
    return;
  }

  /* Step the model */
  ValidationGate_step();

  OverrunFlag--;
}

int main(int argc, const char *argv[])
{

	/* Initialize hardware */
	AUV* auv = new AUV();
	
	/* Data Vars */
	imu_data orientation;
	real32_T depth;
	int8_T motorspeeds[3];

	/* Initialize model */
	ValidationGate_initialize();
    
	// set up alarm for timing simulink step calls
	initalarm();

// loop main loop
while(getchar() != 'q'){
	int x = 0; // main loop counter
	int reset = 0;
	
	// Reset thrusters
	motorspeeds[0] = 0;
    	motorspeeds[1] = 0;
    	motorspeeds[2] = 0;
    	auv->setThrusters(motorspeeds);

	// wait for reset
	cout << "Waiting for reset" << endl;
	while(auv->getGo()) pause();
 
	// main loop (looped) 
	while (rtmGetErrorStatus(ValidationGate_M) == (NULL) && x < RUNTIME*50) {
		
		/* Wait for go */
		auv->externalControl(motorspeeds, reset);
		if(reset) cout << "Reset!" << endl;
		
		/* Get data from other devices */
		depth = auv->getDepth();
		orientation = auv->getOrientation();
		
		/*  Transfer sensor data to simulink input values */
		ValidationGate_U.CurrentDepth = depth; // real32_T
		ValidationGate_U.CurrentHeading = orientation.yaw; // real_T
		ValidationGate_U.ResetSwitch = reset;
		if(reset) x = 0;
		
		/* Show inputs */
		cout << "Current Depth: " << depth;
		cout << "  Current Heading: " << ValidationGate_U.CurrentHeading;
		
		/* Run Simulink model */
		while(!checkalarm()) pause(); 	// wait for step period (change the timing in alarm.h)
	   	rt_OneStep();					// simulink!
	   	resetalarm(); 					// if you don't reset it won't wait next time around
	   	
		
		/* Get results from simulink */
		motorspeeds[0] = ValidationGate_Y.ChangetoLeft;
		motorspeeds[1] = ValidationGate_Y.ChangetoRight;
		motorspeeds[2] = -1.0 * ValidationGate_Y.ChangetoVertical;
		
		/* Show results of processing */
		cout << "  Left: " << (int) motorspeeds[0];
		cout << "  Right: " <<  (int) motorspeeds[1];
		cout << "  Vert: " << (int) motorspeeds[2] << endl;
		
		/* Send data to other devices */
		auv->setThrusters(motorspeeds);
		
		/* Increment loop counter */
		x++;
		
	} // end loop
	if(rtmGetErrorStatus(ValidationGate_M) != (NULL)) cout << "Termination error: " << rtmGetErrorStatus(ValidationGate_M) << endl; 
	else cout << "Time's up!" << endl;
} // end loop loop

	/* Terminate model */
	ValidationGate_terminate();
	delete auv;
	
	return 0;
} // end main

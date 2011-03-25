/*
 * File: pidtest.cpp
 *
 * Test the StraightLevelControl simulink model
 *
 * See {modelname}/ert_main.cpp for code generation info
 *
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <iostream>
//#include "ReallySimple/ReallySimple.h"              /* Model's header file */
#include "StraightLevelControl/StraightLevelControl.h"      /* Model's header file */
#include "StraightLevelControl/rtwtypes.h"                  /* MathWorks types */
#include "auv.h"
#include "alarm.h"

#define TARGET_HEADING 335
#define TARGET_DEPTH 5

using namespace std;

static boolean_T OverrunFlag = 0;

// check for overrun and step the simulink model
void rt_OneStep(void)
{
  /* Check for overrun */
  if (OverrunFlag++) {
    rtmSetErrorStatus(StraightLevelControl_M, "Overrun");
    return;
  }

  /* Step the model */
  StraightLevelControl_step();

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
	StraightLevelControl_initialize();
	//StraightLevelControl_U.DesiredDepth = TARGET_DEPTH; // real32_T
	//StraightLevelControl_U.DesiredHeading = TARGET_HEADING; // real_T
    
	motorspeeds[0] = 0;
    motorspeeds[1] = 0;
    motorspeeds[2] = 0;
    auv->setThrusters(motorspeeds);


	int x = 0; // main loop counter
    
    
	// set up alarm for timing simulink step calls
	initalarm();
  
	while (rtmGetErrorStatus(StraightLevelControl_M) == (NULL)) {
		
		/* Wait for go */
		auv->externalControl(motorspeeds);
		
		/* Get data from other devices */
		depth = auv->getDepth();
		orientation = auv->getOrientation();
		
		/*  Transfer sensor data to simulink input values */
		StraightLevelControl_U.CurrentDepth = depth; // real32_T
		StraightLevelControl_U.CurrentHeading = orientation.yaw; // real_T
		StraightLevelControl_U.DesiredDepth = TARGET_DEPTH; // real32_T
		StraightLevelControl_U.DesiredHeading = TARGET_HEADING; // real_T
		
		/* Show inputs */
		//	cout << "Current Depth: " << depth;
		//	cout << "Desired Depth: " << StraightLevelControl_U.DesiredDepth;
		//cout.width(8);
		cout << "  Current Heading: " << StraightLevelControl_U.CurrentHeading;
		cout << "  Desired Heading: " << StraightLevelControl_U.DesiredHeading;
		
		
		
		/* Run Simulink model */
		while(!checkalarm()) pause(); 	// wait for step period (change the timing in alarm.h)
	   	rt_OneStep();					// simulink!
	   	resetalarm(); 					// if you don't reset it won't wait next time around
	   	
		
		/* Get results from simulink */
		motorspeeds[0] = StraightLevelControl_Y.ChangetoLeft;
		motorspeeds[1] = StraightLevelControl_Y.ChangetoRight;
		int m2s = -20 - (int)StraightLevelControl_Y.ChangetoVertical;
		motorspeeds[2] = -1*StraightLevelControl_Y.ChangetoVertical;
		
		/* Other variations of above */
		/*
		// manual proportional control
		//motorspeeds[0] = (180 - orientation.yaw) * 0.20 + 50;
		//motorspeeds[1] = -1*((180 - orientation.yaw) * 0.20) + 50;
		
		// summing control
		// add changetoLeft to left motor speed and do bounds checking
		motorspeeds[0] = (int8_T) (((int) motorspeeds[0] + StraightLevelControl_Y.ChangetoLeft) > 27)?27:(((int) motorspeeds[0] + StraightLevelControl_Y.ChangetoLeft) < -27)?-27:(int) motorspeeds[0] + StraightLevelControl_Y.ChangetoLeft;
		// add changetoRight to right motor speed and do bounds checking
		motorspeeds[1] = (int8_T) (((int) motorspeeds[1] + StraightLevelControl_Y.ChangetoRight) > 27)?27:(((int) motorspeeds[1] + StraightLevelControl_Y.ChangetoRight) < -27)?-27:(int) motorspeeds[1] + StraightLevelControl_Y.ChangetoRight;
		// add changetoVert to vertical motor speed and do bounds checking
		motorspeeds[2] = (int8_T) (((int) motorspeeds[2] + StraightLevelControl_Y.ChangetoVertical) > 27)?27:(((int) motorspeeds[2] + StraightLevelControl_Y.ChangetoVertical) < -27)?-27:(int) motorspeeds[2] + StraightLevelControl_Y.ChangetoVertical;
		*/
		
		/* Show results of processing */
		cout << "  Error: " << (int) TARGET_HEADING-orientation.yaw;
		cout << "  VertError: " << (float) TARGET_DEPTH - depth;
		cout << "  Left: " << (int) motorspeeds[0];
		cout << "  Right: " <<  (int) motorspeeds[1];
		cout << "  Vert: " << (int) motorspeeds[2] << endl;
		
		/* Send data to other devices */
		auv->setThrusters(motorspeeds);
		
		/* Increment loop counter */
		x++;
		
	} // end loop

	/* Terminate model */
	StraightLevelControl_terminate();
	
	return 0;
} // end main

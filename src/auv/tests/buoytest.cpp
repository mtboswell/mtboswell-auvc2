/*
 * File: buoytest.cpp
 *
 * Test the Buoy simulink model
 *
 * See {modelname}/ert_main.cpp_ for code generation info
 *
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <iostream>
//#include "ReallySimple/ReallySimple.h"              /* Model's header file */
#include "Buoy/Buoy.h"      /* Model's header file */
#include "Buoy/rtwtypes.h"                  /* MathWorks types */
#include "auv.h"
#include "alarm.h"

using namespace std;

static boolean_T OverrunFlag = 0;

// check for overrun and step the simulink model
void rt_OneStep(void)
{
  /* Check for overrun */
  if (OverrunFlag++) {
    rtmSetErrorStatus(Buoy_M, "Overrun");
    return;
  }

  /* Step the model */
  Buoy_step();

  OverrunFlag--;
}

int main(int argc, const char *argv[])
{

	/* Initialize hardware */
	AUV* auv = new AUV();
	
	/* Data Vars */
	//imu_data orientation;
	//real32_T depth;
	int8_T motorspeeds[3];

	/* Initialize model */
	Buoy_initialize();
    
    motorspeeds[0] = 0;
    motorspeeds[1] = 0;
    motorspeeds[2] = 0;


	int x = 0; // main loop counter
    
    
	// set up alarm for timing simulink step calls
	initalarm();
  
	while (rtmGetErrorStatus(Buoy_M) == (NULL)) {
		
		/* Give loop control to diver's switch */
		auv->externalControl(motorspeeds);
							
		
		/* Run Simulink model */
		while(!checkalarm()) pause(); 	// wait for step period (change the timing in alarm.h)
	   	rt_OneStep();					// simulink!
	   	resetalarm(); 					// if you don't reset it won't wait next time around
	   	
		
		/* Get results from simulink */
		motorspeeds[0] = Buoy_Y.ChangetoLeft;
		motorspeeds[1] = Buoy_Y.ChangetoRight;
		motorspeeds[2] = Buoy_Y.ChangetoVert;
		
		/* Show results of processing */
		cout << "  Left: " << (int) motorspeeds[0];
		cout << "  Right: " <<  (int) motorspeeds[1];
		cout << "  Vert: " << (int) motorspeeds[2];
		cout << "  Centroid X: " << (int) Buoy_Y.CentroidX;
		cout << "  Centroid Y: " << (int) Buoy_Y.CentroidY << endl;
		
		/* Send data to other devices */
		auv->setThrusters(motorspeeds);
		
		/* Increment loop counter */
		x++;
		
	} // end loop

	/* Terminate model */
	Buoy_terminate();
	
	return 0;
} // end main

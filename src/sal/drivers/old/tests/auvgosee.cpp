/*
 * File: auvgo.cpp
 *
 * Test the AUVstateflow simulink model
 *
 * See {modelname}/ert_main.cpp for code generation info
 *
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <iostream>
#include <stdlib.h>
#include "AUVstateflow/AUVstateflow.h"      /* Model's header file */
#include "AUVstateflow/rtwtypes.h"                  /* MathWorks types */
#include "auv.h"
#include "alarm.h"
#include "camread.h"

using namespace std;

static boolean_T OverrunFlag = 0;

// check for overrun and step the simulink model
void rt_OneStep(void)
{
  /* Check for overrun */
  if (OverrunFlag++) {
    rtmSetErrorStatus(AUVstateflow_M, "Overrun");
    return;
  }

  /* Step the model */
  AUVstateflow_step();

  OverrunFlag--;
}

int main(int argc, const char *argv[])
{

	/* Initialize hardware */
	AUV* auv = new AUV();
	
	
	struct camframe myframe;
	
	/* Data Vars */
	imu_data orientation;
	real32_T depth;
	int8_T motorspeeds[3];

	/* Initialize model */
//	AUVstateflowModelClass* auvsim = new AUVstateflowModelClass;
	AUVstateflow_initialize();
    
	motorspeeds[0] = 0;
    	motorspeeds[1] = 0;
    	motorspeeds[2] = 0;
    	auv->setThrusters(motorspeeds);

	int x = 0; // main loop counter
    
	// set up alarm for timing simulink step calls
	initalarm();
	
	/* Initialize framebuffer and start video capture */
	myframe.y = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT);
	myframe.cb = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT/4);
	myframe.cr = malloc(CAMERA_FRAME_WIDTH*CAMERA_FRAME_HEIGHT/4);
	camread_open("/dev/video0", 640, 480);
  
	while (rtmGetErrorStatus(AUVstateflow_M) == (NULL)) {
		
		/* Wait for go */
		auv->externalControl(motorspeeds);
		
		/* Get data from other devices */
		depth = auv->getDepth();
		orientation = auv->getOrientation();
		
		/*  Transfer sensor data to simulink input values */
		AUVstateflow_U.CurrentDepth = depth; // real32_T
		AUVstateflow_U.CurrentHeading = orientation.yaw; // real_T
		
		/* Transfer video frame into MATLAB, swapping buffers */
		camread_getframe(myframe);
		SwappyCopy(AUVstateflow_U.Y, (unsigned char*)myframe.y, 640, 480);
		SwappyCopy(AUVstateflow_U.Cb, (unsigned char*)myframe.cb, 320, 240);
		SwappyCopy(AUVstateflow_U.Cr, (unsigned char*)myframe.cr, 320, 240);
		
		/* Show inputs */
		cout << "Current Depth: " << depth;
		cout << "  Current Heading: " << AUVstateflow_U.CurrentHeading;
		
		/* Run Simulink model */
		while(!checkalarm()) pause(); 	// wait for step period (change the timing in alarm.h)
	   	rt_OneStep();					// simulink!
	   	resetalarm(); 					// if you don't reset it won't wait next time around
	   	
		
		/* Get results from simulink */
		motorspeeds[0] = AUVstateflow_Y.ChangetoLeft;
		motorspeeds[1] = AUVstateflow_Y.ChangetoRight;
		motorspeeds[2] = AUVstateflow_Y.ChangetoVertical; /*AUVstateflow_Y.ChangetoVertical;*/
		
		/* Show results of processing */
		cout << "  Left: " << (int) motorspeeds[0];
		cout << "  Right: " <<  (int) motorspeeds[1];
		cout << "  Vert: " << (int) motorspeeds[2];
		cout << "  Buoy X Centroid: " << (int) AUVstateflow_Y.BuoyCentroidX;
		cout << "  Buoy Y Centroid: " << (int) AUVstateflow_Y.BuoyCentroidY;
		cout << "  Camera: " << (int) AUVstateflow_Y.CameraPosition << endl;
		
		/* Send data to other devices */
		auv->setThrusters(motorspeeds);
		auv->look((cameraPosition) AUVstateflow_Y.CameraPosition);
		
		/* Increment loop counter */
		x++;
		
	} // end loop
	camread_close();
	cout << "Termination error: " << rtmGetErrorStatus(AUVstateflow_M) << endl; 
	cerr << "Termination error: " << rtmGetErrorStatus(AUVstateflow_M) << endl; 

	/* Terminate model */
	AUVstateflow_terminate();
	delete auv;
	
	return 0;
} // end main

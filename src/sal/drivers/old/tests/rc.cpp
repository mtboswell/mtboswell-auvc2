#include <iostream>
#include "ports.h"
#include "rc.h"
using namespace std;

RC::RC(){
	auv = new AUV();
	
	velocityState = new AUVMotion;
	velocityState->forward = 0;
	velocityState->yaw = 0;
	velocityState->vertical = 0;
	prevVelo = new AUVMotion;
	prevVelo->forward = 0;
	prevVelo->yaw = 0;
	prevVelo->vertical = 0;
}

RC::~RC(){
	auv->setMotion(0,0,0);
	delete auv;
}

void RC::wsad(char input){

        //cout << "You said: " << input << endl;
		switch(input){
			case 'w':
				velocityState->forward += 13;
				break;
			case 's':
				velocityState->forward -= 13;
				break;
			case 'a':
				velocityState->yaw -= 13;
				break;
			case 'd':
				velocityState->yaw += 13;
				break;
			case 'x':
				velocityState->forward = 0;
				velocityState->yaw = 0;
				break;
			case 't':
				velocityState->yaw = 0;
				break;
			case 'c':
				velocityState->forward = 0;
				velocityState->yaw = 0;
				velocityState->vertical = 0;
				break;
			case 'q':
				velocityState->vertical += 10;
				break;
			case 'e':
				velocityState->vertical -= 10;
				break;
			case 'z':
				velocityState->vertical = 0;
				break;
			case 'r':
			    cameraState = UP;
			    break;
			case 'f':
			    cameraState = FORWARD;
			    break;
			case 'v':
			    cameraState = DOWN;
			    break;
			case 'n':
				auv->dropLeft();
				break;
			case 'm':
				auv->dropRight();
				break;
			case 'o':
			    auv->kill();
			    break;
			case 'i':
			    auv->reset();
			    break;
			case ' ':
			    usleep(1000000);
			    break;
			case '.':
			    usleep(5000000);
			    break;
		}
		
		if(velocityState->forward != prevVelo->forward || velocityState->yaw != prevVelo->yaw || velocityState->vertical != prevVelo->vertical) auv->setMotion(velocityState);
		if(cameraState != prevCam) auv->look(cameraState);
		*prevVelo = *velocityState;
		prevCam = cameraState;
}




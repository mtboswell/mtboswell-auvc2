#ifndef RC_H_
#define RC_H_

#include "auv.h"

class RC
{
	public:
		RC();
		~RC();
		
		void wsad(char input);
		
		AUVMotion* getVelocity(){return velocityState;}
		cameraPosition getCamera(){return cameraState;}
		
	private:
	
	    AUV*  auv;
	    AUVMotion*  velocityState;
	    AUVMotion*  prevVelo;
	    cameraPosition cameraState, prevCam;

};


#endif /*RC_H_*/

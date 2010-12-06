
#include "actor.h"

Actor::Actor(QMap<QString, QString>* configIn, AUV_State* stateIn, QObject* parent = 0):Module(configIn, stateIn, parent){

	// vim cmd to generate below code from generated list in MotionController.h: 
	// :s/\/\*.*\*\///
	// :s/  real_T \(.*\);/paramList["\1"] = \&MotionController_P.\1;/

	paramList["Compass_Yaw_Kp"] = &MotionController_P.Compass_Yaw_Kp;
	paramList["Compass_Yaw_Ki"] = &MotionController_P.Compass_Yaw_Ki;
	paramList["Compass_Yaw_Kd"] = &MotionController_P.Compass_Yaw_Kd;
	paramList["Depth_Kd"] = &MotionController_P.Depth_Kd;
	paramList["Depth_Ki"] = &MotionController_P.Depth_Ki;
	paramList["Depth_Kp"] = &MotionController_P.Depth_Kp;
	paramList["IMU_YVel_Kd"] = &MotionController_P.IMU_YVel_Kd;
	paramList["IMU_YVel_Ki"] = &MotionController_P.IMU_YVel_Ki;
	paramList["IMU_YVel_Kp"] = &MotionController_P.IMU_YVel_Kp;
	paramList["IMU_YawRate_Kd"] = &MotionController_P.IMU_YawRate_Kd;
	paramList["IMU_YawRate_Ki"] = &MotionController_P.IMU_YawRate_Ki;
	paramList["IMU_YawRate_Kp"] = &MotionController_P.IMU_YawRate_Kp;
	paramList["Target_Down_X_Kd"] = &MotionController_P.Target_Down_X_Kd;
	paramList["Target_Down_X_Ki"] = &MotionController_P.Target_Down_X_Ki;
	paramList["Target_Down_X_Kp"] = &MotionController_P.Target_Down_X_Kp;
	paramList["Target_Down_Y_Kd"] = &MotionController_P.Target_Down_Y_Kd;
	paramList["Target_Down_Y_Ki"] = &MotionController_P.Target_Down_Y_Ki;
	paramList["Target_Down_Y_Kp"] = &MotionController_P.Target_Down_Y_Kp;
	paramList["Target_Down_Yaw_Kd"] = &MotionController_P.Target_Down_Yaw_Kd;
	paramList["Target_Down_Yaw_Ki"] = &MotionController_P.Target_Down_Yaw_Ki;
	paramList["Target_Down_Yaw_Kp"] = &MotionController_P.Target_Down_Yaw_Kp;
	paramList["Target_Forward_Y_Kd"] = &MotionController_P.Target_Forward_Y_Kd;
	paramList["Target_Forward_Y_Ki"] = &MotionController_P.Target_Forward_Y_Ki;
	paramList["Target_Forward_Y_Kp"] = &MotionController_P.Target_Forward_Y_Kp;
	paramList["Target_Forward_Yaw_Kd"] = &MotionController_P.Target_Forward_Yaw_Kd;
	paramList["Target_Forward_Yaw_Ki"] = &MotionController_P.Target_Forward_Yaw_Ki;
	paramList["Target_Forward_Yaw_Kp"] = &MotionController_P.Target_Forward_Yaw_Kp;
	paramList["Target_Forward_Z_Kd"] = &MotionController_P.Target_Forward_Z_Kd;
	paramList["Target_Forward_Z_Ki"] = &MotionController_P.Target_Forward_Z_Ki;
	paramList["Target_Forward_Z_Kp"] = &MotionController_P.Target_Forward_Z_Kp;
	paramList["Thruster_Friction_Zero"] = &MotionController_P.Thruster_Friction_Zero;
	paramList["Thruster_LeftAngled_Gain"] = &MotionController_P.Thruster_LeftAngled_Gain;
	paramList["Thruster_LeftFwd_Gain"] = &MotionController_P.Thruster_LeftFwd_Gain;
	paramList["Thruster_RightAngled_Gain"] = &MotionController_P.Thruster_RightAngled_Gain;
	paramList["Thruster_RightFwd_Gain"] = &MotionController_P.Thruster_RightFwd_Gain;
	paramList["ZVelocity_Neg_Max"] = &MotionController_P.ZVelocity_Neg_Max;


	MotionController_initialize();
}
void Actor::runStep(){

	// identify current mandate
	currentCMD = state["Command"];
	

	// set inputs based on all relevant data (primarily the currentCMD)

	// vim cmd used to parse .h:
	// :s/\/\*.*\*\///
	// :s/  .*_T \(.*\);/MotionController_U.\1 = state->;/

	MotionController_U.TargetSelect = state->targeter.;                 
	MotionController_U.TargetFound = state->targeter.;                  

	MotionController_U.TargetX = state->targeter.;                      
	MotionController_U.TargetY = state->targeter.;                      
	MotionController_U.TargetZ = state->targeter.;                      
	MotionController_U.TargetYaw = state->targeter.;                    


	// sensors
	MotionController_U.MeasuredZ = state->;                    
	MotionController_U.MeasuredYAccel = state->;               
	MotionController_U.MeasuredYaw = state->;                  
	MotionController_U.MeasuredYawRate = state->;              

	MotionController_U.DesiredZ = state->;                     
	MotionController_U.DesiredXVelocity = state->;             
	MotionController_U.DesiredYaw = state->;                   

	// arrange stuff for current command
	switch(currentCMD){
		case TRACK:
			MotionController_U.DesiredTargetX = MotionController_U.TargetX;               
			MotionController_U.DesiredTargetY = MotionController_U.TargetY;               
			MotionController_U.DesiredTargetZ = MotionController_U.TargetZ;               
			MotionController_U.DesiredTargetYaw = MotionController_U.TargetYaw;       
			break;
		case APPROACH:
			MotionController_U.DesiredTargetX = 0;               
			MotionController_U.DesiredTargetY = 0;               
			MotionController_U.DesiredTargetZ = 0;               
			MotionController_U.DesiredTargetYaw = 0;             
			break;
	
	}


	// where does this info come from?
	MotionController_U.MaintainHeading = state->director.;             


	// step model
	MotionController_step();




	// set outputs
	QReadWriteLocker(state->actorData.actorLock);

	// vim cmd (as above)
	// :s/  .*_T \(.*\);/state-> = MotionController_Y.\1;/

	state->actorData. = MotionController_Y.LeftFwd;                      
	state->actorData. = MotionController_Y.RightFwd;                     
	state->actorData. = MotionController_Y.LeftAngled;                   
	state->actorData. = MotionController_Y.RightAngled;                  
}

void Actor::messageIn(SID message){
	if(message.ID[0] != "Actor") return;
	if(message.ID[1] == "Move"){
		currentCMD = MOVING;
	}
}

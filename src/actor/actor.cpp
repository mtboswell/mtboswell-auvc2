#include "actor.h"

Actor::Actor(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent):SimulinkModule(configIn, stateIn, parent){

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

	initializeParameters();

	MotionController_initialize();
}
void Actor::step(){
	//qDebug() << "Stepping Actor";

	updateParameters();

	// set inputs based on all relevant data (primarily the currentCMD)

	// vim cmd used to parse .h:
	// :s/\/\*.*\*\///
	// :s/  .*_T \(.*\);/MotionController_U.\1 = state->;/

	MotionController_U.TargetSelect = (state->value("TargetOptions.TargetSelect")=="Forward"); 

	MotionController_U.TargetFound = state->value("TargetData.Found").toBool();
	MotionController_U.TargetX = state->value("TargetData.Position.X").toDouble();
	MotionController_U.TargetY = state->value("TargetData.Position.Y").toDouble();
	MotionController_U.TargetZ = state->value("TargetData.Position.Z").toDouble(); 
	MotionController_U.TargetYaw = state->value("TargetData.Position.Bearing").toDouble();                    

	// sensors
	MotionController_U.MeasuredZ = state->value("Position.Depth").toDouble();
	MotionController_U.MeasuredYAccel = state->value("Motion.Accel.Y").toDouble();               
	MotionController_U.MeasuredYaw = state->value("Orientation.Heading").toDouble();                  
	MotionController_U.MeasuredYawRate = state->value("Motion.YawRate").toDouble();              


	// arrange stuff for current command
	if(state->value("Command") == "Target" && !state->value("TargetOptions.Approach").toBool()){
		MotionController_U.DesiredTargetX = MotionController_U.TargetX;               
		MotionController_U.DesiredTargetY = MotionController_U.TargetY;               
		MotionController_U.DesiredTargetZ = MotionController_U.TargetZ;               
		MotionController_U.DesiredTargetYaw = MotionController_U.TargetYaw;       
	}
	else if(state->value("Command") == "Target" && state->value("TargetOptions.Approach").toBool()){
		MotionController_U.DesiredTargetX = 0;               
		MotionController_U.DesiredTargetY = 0;               
		MotionController_U.DesiredTargetZ = 0;               
		MotionController_U.DesiredTargetYaw = 0;             
	}
	else if(state->value("Command") == "DeadReckon"){
		MotionController_U.DesiredZ = state->value("DeadReckon.Depth").toDouble();                     
		MotionController_U.DesiredXVelocity = state->value("DeadReckon.ForwardSpeed").toDouble();             
		MotionController_U.DesiredYaw = state->value("DeadReckon.Heading").toDouble(); 
	}


	MotionController_U.MaintainHeading = state->value("TargetOptions.MaintainHeading").toBool();             

	// step model
	MotionController_step();

	// set outputs

	// vim cmd (as above)
	// :s/  .*_T \(.*\);/state-> = MotionController_Y.\1;/

	state->setData("Thrusters.LeftFwd", MotionController_Y.LeftFwd);                      
	state->setData("Thrusters.RightFwd", MotionController_Y.RightFwd);                     
	state->setData("Thrusters.LeftAngled", MotionController_Y.LeftAngled);                   
	state->setData("Thrusters.RightAngled", MotionController_Y.RightAngled);                  
}


void Actor::messageIn(QString message){}
void Actor::messageIn(VData message){}
void Actor::newData(QString ID, QVariant value){}

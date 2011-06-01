#include "controllers.h"

Controllers::Controllers():SimulinkModule(){

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

	// can't do this in constructor
	//initializeParameters();

}
void Controllers::init(){
	stopped = false;
	qDebug("Controllers thread id: %d", (int) QThread::currentThreadId());
	stepTimer->start(20);
}
void Controllers::step(){
	//qDebug() << "Stepping Controllers";

	updateParameters();

	// set inputs based on all relevant data (primarily the currentCMD)

	// vim cmd used to parse .h:
	// :s/\/\*.*\*\///
	// :s/  .*_T \(.*\);/MotionController_U.\1 = state->;/

	MotionController_U.TargetSelect = (value("TargetOptions.TargetSelect")=="Forward"); 

	MotionController_U.TargetFound = boolValue("TargetData.Found");
	MotionController_U.TargetX = doubleValue("TargetData.Position.X");
	MotionController_U.TargetY = doubleValue("TargetData.Position.Y");
	MotionController_U.TargetZ = doubleValue("TargetData.Position.Z"); 
	MotionController_U.TargetYaw = doubleValue("TargetData.Position.Bearing");                    

	// sensors
	MotionController_U.MeasuredZ = doubleValue("Position.Depth");
	//qDebug() << MotionController_U.MeasuredZ;
	MotionController_U.MeasuredYAccel = doubleValue("Motion.Accel.Y");               
	MotionController_U.MeasuredYaw = doubleValue("Orientation.Heading");                  
	MotionController_U.MeasuredYawRate = doubleValue("Motion.YawRate");              


	// arrange stuff for current command
	if(value("Command") == "Target" && !boolValue("TargetOptions.Approach")){
		MotionController_U.DesiredTargetX = MotionController_U.TargetX;               
		MotionController_U.DesiredTargetY = MotionController_U.TargetY;               
		MotionController_U.DesiredTargetZ = MotionController_U.TargetZ;               
		MotionController_U.DesiredTargetYaw = MotionController_U.TargetYaw;       
	}
	else if(value("Command") == "Target" && boolValue("TargetOptions.Approach")){
		MotionController_U.DesiredTargetX = 0;               
		MotionController_U.DesiredTargetY = 0;               
		MotionController_U.DesiredTargetZ = 0;               
		MotionController_U.DesiredTargetYaw = 0;             
	}
	else if(value("Command") == "DeadReckon"){
		MotionController_U.DesiredZ = doubleValue("DeadReckon.Depth");                     
		MotionController_U.DesiredXVelocity = doubleValue("DeadReckon.ForwardSpeed");             
		MotionController_U.DesiredYaw = doubleValue("DeadReckon.Heading"); 
	}


	MotionController_U.MaintainHeading = boolValue("TargetOptions.MaintainHeading");             

	QVector4D thrusters;
	thrusters.setW(0);
	thrusters.setX(0);
	thrusters.setY(0);
	thrusters.setZ(0);
	
	// step model
	if (!stopped) {
		MotionController_step();

		// set outputs

		// vim cmd (as above)
		// :s/  .*_T \(.*\);/state-> = MotionController_Y.\1;/

		thrusters.setW(MotionController_Y.LeftFwd);
		thrusters.setX(MotionController_Y.LeftAngled);
		thrusters.setY(MotionController_Y.RightAngled);
		thrusters.setZ(MotionController_Y.RightFwd);
	}

	setData("Thrusters", thrusters);                      
}

void Controllers::dataIn(VDatum datum){
	if(datum.id != "Mode") return;	
	if(datum.value == "Stop") stopped = true;
	else stopped = false;
}



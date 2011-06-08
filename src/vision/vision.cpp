#include "vision.h"

Vision::Vision() : SimulinkModule()
{
// TODO --- place correct inputs into paramList
//    paramList["Depth_Kp"] = &VisionModel_P.Depth_Kp;
//    paramList["Depth_Kd"] = &VisionModel_P.Depth_Kd;
//    paramList["Depth_Ki"] = &VisionModel_P.Depth_Ki;
//    paramList["Heading_Kp"] = &VisionModel_P.Heading_Kp;
//    paramList["Heading_Kd"] = &VisionModel_P.Heading_Kd;
//    paramList["Heading_Ki"] = &VisionModel_P.Heading_Ki;
//    paramList["Track_HueHigher"] = &VisionModel_P.Track_HueHigher;
//    paramList["Track_HueLower"] = &VisionModel_P.Track_HueLower;
//    paramList["Track_Saturation"] = &VisionModel_P.Track_Saturation;
//    paramList["Min_Blob_Size"] = &VisionModel_P.Min_Blob_Size;
//    paramList["Max_Blob_Size"] = &VisionModel_P.Max_Blob_Size;
//    paramList["Max_Num_Blobs"] = &VisionModel_P.Max_Num_Blobs;
//    paramList["Track_Min_Eccentricity"] = &VisionModel_P.Track_Min_Eccentricity;
//    paramList["Track_Desired_Depth"] = &VisionModel_P.Track_Desired_Depth;
//    paramList["Cam_Down_Yaw_XPos_Kp"] = &VisionModel_P.Cam_Down_Yaw_XPos_Kp;
//    paramList["Cam_Down_Yaw_XPos_Kd"] = &VisionModel_P.Cam_Down_Yaw_XPos_Kd;
//    paramList["Cam_Down_Yaw_XPos_Ki"] = &VisionModel_P.Cam_Down_Yaw_XPos_Ki;
//    paramList["Cam_Down_Strafe_XPos_Kp"] = &VisionModel_P.Cam_Down_Strafe_XPos_Kp;
//    paramList["Cam_Down_Strafe_XPos_Kd"] = &VisionModel_P.Cam_Down_Strafe_XPos_Kd;
//    paramList["Cam_Down_Strafe_XPos_Ki"] = &VisionModel_P.Cam_Down_Strafe_XPos_Ki;
//    paramList["Cam_Down_YPos_Kp"] = &VisionModel_P.Cam_Down_YPos_Kp;
//    paramList["Cam_Down_YPos_Kd"] = &VisionModel_P.Cam_Down_YPos_Kd;
//    paramList["Cam_Down_YPos_Ki"] = &VisionModel_P.Cam_Down_YPos_Ki;
//    paramList["Buoy1_Hue"] = &VisionModel_P.Buoy1_Hue;
//    paramList["Buoy1_Saturation"] = &VisionModel_P.Buoy1_Saturation;
//    paramList["Buoy1_Value"] = &VisionModel_P.Buoy1_Value;
//    paramList["Buoy2_Hue"] = &VisionModel_P.Buoy2_Hue;
//    paramList["Buoy2_Saturation"] = &VisionModel_P.Buoy2_Saturation;
//    paramList["Buoy2_Value"] = &VisionModel_P.Buoy2_Value;
//    paramList["Iter_Segment_Thresh"] = &VisionModel_P.Iter_Segment_Thresh;
//    paramList["Buoy_Min_Eccentricity"] = &VisionModel_P.Buoy_Min_Eccentricity;
//    paramList["Buoy_Max_Eccentricity"] = &VisionModel_P.Buoy_Max_Eccentricity;
//    paramList["Buoy_Min_Extent"] = &VisionModel_P.Buoy_Min_Extent;
//    paramList["Buoy_Max_Extent"] = &VisionModel_P.Buoy_Max_Extent;
//    paramList["Max_Num_Blobs_Buoy"] = &VisionModel_P.Max_Num_Blobs_Buoy;
//    paramList["Cam_Forward_XPosition_Kp"] = &VisionModel_P.Cam_Forward_XPosition_Kp;
//    paramList["Cam_Forward_XPosition_Kd"] = &VisionModel_P.Cam_Forward_XPosition_Kd;
//    paramList["Cam_Forward_XPosition_Ki"] = &VisionModel_P.Cam_Forward_XPosition_Ki;
//    paramList["Cam_Forward_YPosition_Kp"] = &VisionModel_P.Cam_Forward_YPosition_Kp;
//    paramList["Cam_Forward_YPosition_Kd"] = &VisionModel_P.Cam_Forward_YPosition_Kd;
//    paramList["Cam_Forward_YPosition_Ki"] = &VisionModel_P.Cam_Forward_YPosition_Ki;
//    paramList["IMU_YVel_Kp"] = &VisionModel_P.IMU_YVel_Kp;
//    paramList["IMU_YVel_Kd"] = &VisionModel_P.IMU_YVel_Kd;
//    paramList["IMU_YVel_Ki"] = &VisionModel_P.IMU_YVel_Ki;
//    paramList["IMU_YawRate_Kp"] = &VisionModel_P.IMU_YawRate_Kp;
//    paramList["IMU_YawRate_Kd"] = &VisionModel_P.IMU_YawRate_Kd;
//    paramList["IMU_YawRate_Ki"] = &VisionModel_P.IMU_YawRate_Ki;
//    paramList["Heading_Forward_Velocity"] = &VisionModel_P.Heading_Forward_Velocity;
//    paramList["Vision_Forward_Velocity"] = &VisionModel_P.Vision_Forward_Velocity;
//    paramList["Buoy_Strafe"] = &VisionModel_P.Buoy_Strafe;
//    paramList["Hedge_Hue"] = &VisionModel_P.Hedge_Hue;
//    paramList["Hedge_Saturation"] = &VisionModel_P.Hedge_Saturation;
//    paramList["Hedge_Value"] = &VisionModel_P.Hedge_Value;
//    paramList["RC_Source"] = &VisionModel_P.RC_Source;
//    paramList["MissionPlan"] = &VisionModel_P.MissionPlan;

//    real_T R_forward_in[19200];          /* '<Root>/R_forward_in' */
//    real_T G_forward_in[19200];          /* '<Root>/G_forward_in' */
//    real_T B_forward_in[19200];          /* '<Root>/B_forward_in' */
//    real_T R_down_in[19200];             /* '<Root>/R_down_in' */
//    real_T G_down_in[19200];             /* '<Root>/G_down_in' */
//    real_T B_down_in[19200];             /* '<Root>/B_down_in' */

    paramList["Vision_ModeSelect"] = &VisionModel_U.ModeSelect;
    paramList["Vision_DesiredPathDirection"] = &VisionModel_U.DesiredPathDirection;
    paramList["Vision_DesiredBuoyColor"] = &VisionModel_U.DesiredBuoyColor;
    paramList["Vision_DesiredTorpedoColor"] = &VisionModel_U.DesiredTorpedoColor;
    paramList["Vision_ProceedToSecondTarget"] = &VisionModel_U.ProceedToSecondTarget;
    paramList["Vision_DefaultTaretShape"] = &VisionModel_U.DefaultTaretShape;
    paramList["Vision_DefaultTargetColor"] = &VisionModel_U.DefaultTargetColor;
}

/**
 *  Quit running this module if we receive a VDatum.value of "STOP"
 */
void Vision::dataIn(VDatum datum)
{
    if(datum.id != "Mode") return;
    if(datum.value == "Stop") stopped = true;
    else stopped = false;
}

/**
 * Initialize this Simulink Module by displaying
 *  Called by: constructor
 *  Pre-condition: None
 *  Post-condition: stopped is false
 */
void Vision::init()
{
    stopped = false;
    qDebug("Vision thread id: %d", (int) QThread::currentThreadId());
    stepTimer->start(20);   // execute the step() function 100 times per second (100 Hz)
}

void Vision::step()
{
    /**
     *  Queries the AUVC state data and makes sure we have the most current inputs
     *  before executing the Simulink function
     */
    updateParameters();

    // call the function
    VisionModel_step();

    // set the outputs of the function
    setData("Vision.Output.TargetSelect", VisionModel_Y.TargetSelect);
    setData("Vision.Output.TargetFound", VisionModel_Y.TargetFound);
    setData("Vision.Output.MaintainHeading", VisionModel_Y.MaintainHeading);
    setData("Vision.Output.TargetX", VisionModel_Y.TargetX);
    setData("Vision.Output.TargetY", VisionModel_Y.TargetY);
    setData("Vision.Output.TargetZ", VisionModel_Y.TargetZ);
    setData("Vision.Output.TargetYaw", VisionModel_Y.TargetYaw);
    setData("Vision.Output.DesiredTargetX", VisionModel_Y.DesiredTargetX);
    setData("Vision.Output.DesiredTargetY", VisionModel_Y.DesiredTargetY);
    setData("Vision.Output.DesiredTargetZ", VisionModel_Y.DesiredTargetZ);
    setData("Vision.Output.DesiredTargetYaw", VisionModel_Y.DesiredTargetYaw);
    setData("Vision.Output.MeasuredZ", VisionModel_Y.MeasuredZ);
    setData("Vision.Output.MeasuredYAccel", VisionModel_Y.MeasuredYAccel);
    setData("Vision.Output.MeasuredYaw", VisionModel_Y.MeasuredYaw);
    setData("Vision.Output.MeasuredYawRate", VisionModel_Y.MeasuredYawRate);
    setData("Vision.Output.DesiredZ", VisionModel_Y.DesiredZ);
    setData("Vision.Output.DesiredXVelocity", VisionModel_Y.DesiredXVelocity);
    setData("Vision.Output.DesiredYaw", VisionModel_Y.DesiredYaw);
}

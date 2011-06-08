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

}

/**
 *  Quit running this module if we receive a VDatum.value of "STOP"
 */
void Vision::dataIn(VDatum message)
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

    // do stuff with the vision params
}

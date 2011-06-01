#include "Vision.h"

Vision::Vision():SimulinkModule(){

    paramList["Depth_Kp"] = &Vision_P.Depth_Kp;
    paramList["Depth_Kd"] = &Vision_P.Depth_Kd;
    paramList["Depth_Ki"] = &Vision_P.Depth_Ki;
    paramList["Heading_Kp"] = &Vision_P.Heading_Kp;
    paramList["Heading_Kd"] = &Vision_P.Heading_Kd;
    paramList["Heading_Ki"] = &Vision_P.Heading_Ki;
    paramList["Track_HueHigher"] = &Vision_P.Track_HueHigher;
    paramList["Track_HueLower"] = &Vision_P.Track_HueLower;
    paramList["Track_Saturation"] = &Vision_P.Track_Saturation;
    paramList["Min_Blob_Size"] = &Vision_P.Min_Blob_Size;
    paramList["Max_Blob_Size"] = &Vision_P.Max_Blob_Size;
    paramList["Max_Num_Blobs"] = &Vision_P.Max_Num_Blobs;
    paramList["Track_Min_Eccentricity"] = &Vision_P.Track_Min_Eccentricity;
    paramList["Track_Desired_Depth"] = &Vision_P.Track_Desired_Depth;
    paramList["Cam_Down_Yaw_XPos_Kp"] = &Vision_P.Cam_Down_Yaw_XPos_Kp;
    paramList["Cam_Down_Yaw_XPos_Kd"] = &Vision_P.Cam_Down_Yaw_XPos_Kd;
    paramList["Cam_Down_Yaw_XPos_Ki"] = &Vision_P.Cam_Down_Yaw_XPos_Ki;
    paramList["Cam_Down_Strafe_XPos_Kp"] = &Vision_P.Cam_Down_Strafe_XPos_Kp;
    paramList["Cam_Down_Strafe_XPos_Kd"] = &Vision_P.Cam_Down_Strafe_XPos_Kd;
    paramList["Cam_Down_Strafe_XPos_Ki"] = &Vision_P.Cam_Down_Strafe_XPos_Ki;
    paramList["Cam_Down_YPos_Kp"] = &Vision_P.Cam_Down_YPos_Kp;
    paramList["Cam_Down_YPos_Kd"] = &Vision_P.Cam_Down_YPos_Kd;
    paramList["Cam_Down_YPos_Ki"] = &Vision_P.Cam_Down_YPos_Ki;
    paramList["Buoy1_Hue"] = &Vision_P.Buoy1_Hue;
    paramList["Buoy1_Saturation"] = &Vision_P.Buoy1_Saturation;
    paramList["Buoy1_Value"] = &Vision_P.Buoy1_Value;
    paramList["Buoy2_Hue"] = &Vision_P.Buoy2_Hue;
    paramList["Buoy2_Saturation"] = &Vision_P.Buoy2_Saturation;
    paramList["Buoy2_Value"] = &Vision_P.Buoy2_Value;
    paramList["Iter_Segment_Thresh"] = &Vision_P.Iter_Segment_Thresh;
    paramList["Buoy_Min_Eccentricity"] = &Vision_P.Buoy_Min_Eccentricity;
    paramList["Buoy_Max_Eccentricity"] = &Vision_P.Buoy_Max_Eccentricity;
    paramList["Buoy_Min_Extent"] = &Vision_P.Buoy_Min_Extent;
    paramList["Buoy_Max_Extent"] = &Vision_P.Buoy_Max_Extent;
    paramList["Max_Num_Blobs_Buoy"] = &Vision_P.Max_Num_Blobs_Buoy;
    paramList["Cam_Forward_XPosition_Kp"] = &Vision_P.Cam_Forward_XPosition_Kp;
    paramList["Cam_Forward_XPosition_Kd"] = &Vision_P.Cam_Forward_XPosition_Kd;
    paramList["Cam_Forward_XPosition_Ki"] = &Vision_P.Cam_Forward_XPosition_Ki;
    paramList["Cam_Forward_YPosition_Kp"] = &Vision_P.Cam_Forward_YPosition_Kp;
    paramList["Cam_Forward_YPosition_Kd"] = &Vision_P.Cam_Forward_YPosition_Kd;
    paramList["Cam_Forward_YPosition_Ki"] = &Vision_P.Cam_Forward_YPosition_Ki;
    paramList["IMU_YVel_Kp"] = &Vision_P.IMU_YVel_Kp;
    paramList["IMU_YVel_Kd"] = &Vision_P.IMU_YVel_Kd;
    paramList["IMU_YVel_Ki"] = &Vision_P.IMU_YVel_Ki;
    paramList["IMU_YawRate_Kp"] = &Vision_P.IMU_YawRate_Kp;
    paramList["IMU_YawRate_Kd"] = &Vision_P.IMU_YawRate_Kd;
    paramList["IMU_YawRate_Ki"] = &Vision_P.IMU_YawRate_Ki;
    paramList["Heading_Forward_Velocity"] = &Vision_P.Heading_Forward_Velocity;
    paramList["Vision_Forward_Velocity"] = &Vision_P.Vision_Forward_Velocity;
    paramList["Buoy_Strafe"] = &Vision_P.Buoy_Strafe;
    paramList["Hedge_Hue"] = &Vision_P.Hedge_Hue;
    paramList["Hedge_Saturation"] = &Vision_P.Hedge_Saturation;
    paramList["Hedge_Value"] = &Vision_P.Hedge_Value;
    paramList["RC_Source"] = &Vision_P.RC_Source;
    paramList["MissionPlan"] = &Vision_P.MissionPlan;







}

void Vision::dataIn(VDatum message){

}

void Vision::init(){

}

void Vision::step(){

}

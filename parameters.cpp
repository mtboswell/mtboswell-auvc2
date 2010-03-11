#include "parameters.h"
#include <QDebug>

void init_params(){
	// Parameter lookup table
	//parameters["Stuff"] = &brain_P.stuff;
	qDebug() << "Populating parameters";
	parameters["Buoy_HueHigher"] = &brain_P.Buoy_HueHigher;
	parameters["Buoy_HueLower"] = &brain_P.Buoy_HueLower;
	parameters["Buoy_Saturation"] = &brain_P.Buoy_Saturation;
	parameters["Cam_Forward_XPosition_Kd"] = &brain_P.Cam_Forward_XPosition_Kd;
	parameters["Cam_Forward_XPosition_Ki"] = &brain_P.Cam_Forward_XPosition_Ki;
	parameters["Cam_Forward_XPosition_Kp"] = &brain_P.Cam_Forward_XPosition_Kp;
	parameters["Cam_Forward_YPosition_Kd"] = &brain_P.Cam_Forward_YPosition_Kd;
	parameters["Cam_Forward_YPosition_Ki"] = &brain_P.Cam_Forward_YPosition_Ki;
	parameters["Cam_Forward_YPosition_Kp"] = &brain_P.Cam_Forward_YPosition_Kp;
	parameters["Depth_Kd"] = &brain_P.Depth_Kd;
	parameters["Depth_Ki"] = &brain_P.Depth_Ki;
	parameters["Depth_Kp"] = &brain_P.Depth_Kp;
	parameters["Heading_Forward_Velocity"] = &brain_P.Heading_Forward_Velocity;
	parameters["Heading_Kd"] = &brain_P.Heading_Kd;
	parameters["Heading_Ki"] = &brain_P.Heading_Ki;
	parameters["Heading_Kp"] = &brain_P.Heading_Kp;
	parameters["Track_HueHigher"] = &brain_P.Track_HueHigher;
	parameters["Track_HueLower"] = &brain_P.Track_HueLower;
	parameters["Track_Saturation"] = &brain_P.Track_Saturation;
	parameters["Vision_Forward_Velocity"] = &brain_P.Vision_Forward_Velocity;
}

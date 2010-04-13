#include "parameters.h"
#include <QDebug>

void init_params(QHash<QString, double*>& parameters){
	// Parameter lookup table
	//parameters.insert("Stuff", &brain_P.stuff;
	//qDebug() << "Populating parameters";
	parameters.insert("Buoy_HueHigher", &brain_P.Buoy_HueHigher);
	parameters.insert("Buoy_HueLower", &brain_P.Buoy_HueLower);
	parameters.insert("Buoy_Saturation", &brain_P.Buoy_Saturation);
	parameters.insert("Cam_Forward_XPosition_Kd", &brain_P.Cam_Forward_XPosition_Kd);
	parameters.insert("Cam_Forward_XPosition_Ki", &brain_P.Cam_Forward_XPosition_Ki);
	parameters.insert("Cam_Forward_XPosition_Kp", &brain_P.Cam_Forward_XPosition_Kp);
	parameters.insert("Cam_Forward_YPosition_Kd", &brain_P.Cam_Forward_YPosition_Kd);
	parameters.insert("Cam_Forward_YPosition_Ki", &brain_P.Cam_Forward_YPosition_Ki);
	parameters.insert("Cam_Forward_YPosition_Kp", &brain_P.Cam_Forward_YPosition_Kp);
	parameters.insert("Cam_Down_XPos_Kd", &brain_P.Cam_Down_XPos_Kd);
	parameters.insert("Cam_Down_XPos_Ki", &brain_P.Cam_Down_XPos_Ki);
	parameters.insert("Cam_Down_XPos_Kp", &brain_P.Cam_Down_XPos_Kp);
	parameters.insert("Cam_Down_YPos_Kd", &brain_P.Cam_Down_YPos_Kd);
	parameters.insert("Cam_Down_YPos_Ki", &brain_P.Cam_Down_YPos_Ki);
	parameters.insert("Cam_Down_YPos_Kp", &brain_P.Cam_Down_YPos_Kp);
	parameters.insert("Depth_Kd", &brain_P.StraightLevelControl.Depth_Kd);
	parameters.insert("Depth_Ki", &brain_P.StraightLevelControl.Depth_Ki);
	parameters.insert("Depth_Kp", &brain_P.StraightLevelControl.Depth_Kp);
	parameters.insert("Heading_Forward_Velocity", &brain_P.StraightLevelControl.Heading_Forward_Velocity);
	parameters.insert("Heading_Kd", &brain_P.StraightLevelControl.Heading_Kd);
	parameters.insert("Heading_Ki", &brain_P.StraightLevelControl.Heading_Ki);
	parameters.insert("Heading_Kp", &brain_P.StraightLevelControl.Heading_Kp);
	parameters.insert("Track_HueHigher", &brain_P.Track_HueHigher);
	parameters.insert("Track_HueLower", &brain_P.Track_HueLower);
	parameters.insert("Track_Saturation", &brain_P.Track_Saturation);
	parameters.insert("Vision_Forward_Velocity", &brain_P.Vision_Forward_Velocity);
	parameters.insert("Buoy_Min_Eccentricity", &brain_P.Buoy_Min_Eccentricity);
	parameters.insert("Buoy_Max_Eccentricity", &brain_P.Buoy_Max_Eccentricity);
	parameters.insert("Buoy_Min_Extent", &brain_P.Buoy_Min_Extent);
	parameters.insert("Buoy_Max_Extent", &brain_P.Buoy_Max_Extent);
}

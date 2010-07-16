%   AUV stateflow stuff
%   In particular these are the values set to the workspace before
%   generating code for the overall stateflow chart
%
Depth_Kp = 75;
Depth_Kd = 0.0;
Depth_Ki = 0.0;

Heading_Kp = 0.65;
Heading_Kd = 0.4;
Heading_Ki = 0.0;

Track_HueHigher = 0.75;
Track_HueLower = 0.4;
Track_Saturation = 0.05;

Min_Blob_Size = 15;
Max_Blob_Size = 19200;
Max_Num_Blobs = 1;

Track_Min_Eccentricity = 0.9;
Track_Desired_Depth = 8;

Cam_Down_Yaw_XPos_Kp = 0.6;
Cam_Down_Yaw_XPos_Kd = 0.0;
Cam_Down_Yaw_XPos_Ki = 0.0;

Cam_Down_Strafe_XPos_Kp = -1.0;
Cam_Down_Strafe_XPos_Kd = 0.0;
Cam_Down_Strafe_XPos_Ki = 0.0;

Cam_Down_YPos_Kp = 0.75;
Cam_Down_YPos_Kd = 0.0;
Cam_Down_YPos_Ki = 0.0;

Buoy1_Hue = 0.4;
Buoy1_Saturation = 1.0;
Buoy1_Value = 0.45;

Buoy2_Hue = 0.0;
Buoy2_Saturation = 1.0;
Buoy2_Value = 0.75;

Iter_Segment_Thresh = 60;

Buoy_Min_Eccentricity = 0;
Buoy_Max_Eccentricity = 0.7;
Buoy_Min_Extent = 0.7;
Buoy_Max_Extent = 0.9;

Max_Num_Blobs_Buoy = 10;

Cam_Forward_XPosition_Kp = 0.07;
Cam_Forward_XPosition_Kd = 0.0;
Cam_Forward_XPosition_Ki = 0.0;

Cam_Forward_YPosition_Kp = 0.8;
Cam_Forward_YPosition_Kd = 0.0;
Cam_Forward_YPosition_Ki = 0.0;

Heading_Forward_Velocity = 30;
Vision_Forward_Velocity = 15;

Buoy_Strafe = 40;

Hedge_Hue = .4;
Hedge_Saturation = 1;
Hedge_Value = .75;

MissionPlan = [1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0];

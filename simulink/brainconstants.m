%   AUV stateflow stuff
%   In particular these are the values set to the workspace before
%   generating code for the overall stateflow chart
%
Depth_Kp = 75;
Depth_Kd = 0.0;
Depth_Ki = 0.0;

Heading_Kp = 0.3;
Heading_Kd = 0.01;
Heading_Ki = 0.01;

Track_HueHigher = 0.9;
Track_HueLower = 0.25;
Track_Saturation = 0.4;

Min_Blob_Size = 15;
Max_Blob_Size = 19200;
Max_Num_Blobs = 1;

Track_Min_Eccentricity = 0.9;
Track_Desired_Depth = 8;

Cam_Down_XPos_Kp = 0.25;
Cam_Down_XPos_Kd = 0.001;
Cam_Down_XPos_Ki = 0.001;

Cam_Down_YPos_Kp = 0.20;
Cam_Down_YPos_Kd = 0.001;
Cam_Down_YPos_Ki = 0.001;

Buoy_HueLower = 0.15;
Buoy_HueHigher = 0.9;
Buoy_Saturation = 0.4;

Buoy1_Hue = 0.05;
Buoy1_Saturation = 0.7;
Buoy1_Value = 0.5;

Buoy_Min_Eccentricity = 0;
Buoy_Max_Eccentricity = 0.65;
Buoy_Min_Extent = 0.7;
Buoy_Max_Extent = 0.9;

Max_Num_Blobs_Buoy = 10;

Cam_Forward_XPosition_Kp =0.075;
Cam_Forward_XPosition_Kd = 0.001;
Cam_Forward_XPosition_Ki = 0.001;

Cam_Forward_YPosition_Kp = 0.8;
Cam_Forward_YPosition_Kd = 0.001;
Cam_Forward_YPosition_Ki = 0.001;

Heading_Forward_Velocity = 60;
Vision_Forward_Velocity = 15;


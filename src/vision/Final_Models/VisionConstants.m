%   AUV stateflow stuff
%   In particular these are the values set to the workspace before
%   generating code for the overall stateflow chart
%

%Forward_Camera_Dimensions = [160 120];
%Down_Camera_Dimensions = [120 160];
Forward_Camera_Dimensions = [752 480];
Down_Camera_Dimensions = [480 752];

% The following configuration has been tested with a high success rate on
% static images for the validation gate:
Scale_Forward_R = 0;
Scale_Forward_G = 1;
Scale_Forward_B = 0;
Scale_Forward_H = 1;
Scale_Forward_S = 1;
Scale_Forward_V = 5;

% The following has not been tested:
Scale_Down_R = 1;
Scale_Down_G = 1;
Scale_Down_B = 1;
Scale_Down_H = 1;
Scale_Down_S = 1;
Scale_Down_V = 5;


Depth_Kp = 75;
Depth_Kd = 0.0;
Depth_Ki = 0.0;

Heading_Kp = 0.65;
Heading_Kd = 0.4;
Heading_Ki = 0.0;

Track_HueHigher = .1;
Track_HueLower = .25;
Track_Saturation = 0.5;

% Old values:
%Track_HueHigher = 0.75;
%Track_HueLower = 0.4;
%Track_Saturation = 0.75;

Min_Blob_Size = 15;
Max_Blob_Size = 19200;
Max_Num_Blobs = 50;

Track_Min_Eccentricity = 0.9;
Track_Desired_Depth = 8;

Cam_Down_CCWRotation_Angle = 0;

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

% Minimum/maximum limits on buoy eccentricity and extent
Buoy_Min_Eccentricity = 0;
Buoy_Max_Eccentricity = 0.7;
Buoy_Min_Extent = 0.7;
Buoy_Max_Extent = 0.9;

% ?
Max_Num_Blobs_Buoy = 10;

% Minimum number of buoys that make an image "valid"
Buoy_Count_Min = 3;

% Maximum number of buoys this software will detect in one image
%   (artificial limit; may adjust)
Buoy_Count_Max = 50;

% Limits on torpedo target geometry
%{
Torpedo_Min_Area
Torpedo_Max_Area
Torpedo_Min_Centroid
Torpedo_Max_Centroid
Torpedo_Min_BoundingBox
Torpedo_Max_BoundingBox
Torpedo_Min_MajorAxisLength
Torpedo_Max_MajorAxisLength
Torpedo_Min_MinorAxisLength
Torpedo_Max_MinorAxisLength
Torpedo_Min_Orientation
Torpedo_Max_Orientation
Torpedo_Min_Eccentricity
Torpedo_Max_Eccentricity
Torpedo_Min_Diameter
Torpedo_Max_Diameter
Torpedo_Min_Extent
Torpedo_Max_Extent
Torpedo_Min_Perimeter
Torpedo_Max_Perimeter

Torpedo_Max_Num_Blobs
Torpedo_Min_Blob_Size
Torpedo_Max_Blob_Size
%}

% Limits on torpedo target colors



% Rotation to apply to forward camera image (physically mounted sideways)
Cam_Forward_CCWRotation_Angle = 90;

Cam_Forward_XPosition_Kp = 0.07;
Cam_Forward_XPosition_Kd = 0.0;
Cam_Forward_XPosition_Ki = 0.0;

Cam_Forward_YPosition_Kp = 0.8;
Cam_Forward_YPosition_Kd = 0.0;
Cam_Forward_YPosition_Ki = 0.0;

IMU_YVel_Kp = 0.25;
IMU_YVel_Kd = 0.0;
IMU_YVel_Ki = 0.0;

IMU_YawRate_Kp = 0.25;
IMU_YawRate_Kd = 0.0;
IMU_YawRate_Ki = 0.0;

Heading_Forward_Velocity = 30;
Vision_Forward_Velocity = 15;

Buoy_Strafe = 40;

Hedge_Hue = .4;
Hedge_Saturation = 1;
Hedge_Value = .75;

RC_Source = 1;
MissionPlan = [1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0];

%% Debugging
Buoy_Hue_HalfRange = 10;

Buoy1_Hue = 30;
Buoy1_Saturation = 1.0;
Buoy1_Value = 0.45;
    
Buoy2_Hue = 80;
Buoy2_Saturation = 1.0;
Buoy2_Value = 0.75;

Buoy3_Hue = 15;
Buoy3_Saturation = 1.0;
Buoy3_Value = 0.45;

Iter_Segment_Thresh = 60;

Buoy_Min_Eccentricity = 0;
Buoy_Max_Eccentricity = 1.2;
Buoy_Min_Extent = 0.1;
Buoy_Max_Extent = 0.9;

Max_Num_Blobs_Buoy = 10;



Min_Num_Buoys = 3;

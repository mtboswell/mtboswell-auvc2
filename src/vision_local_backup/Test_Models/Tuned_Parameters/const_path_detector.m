% AUV Vision Constants
%   These values are set to the workspace before generating C++ code


%% Camera dimensions
%Forward_Camera_Dimensions = [160 120];
Forward_Camera_Dimensions = [120 160];
Down_Camera_Dimensions = [120 160];
%Forward_Camera_Dimensions = [752 480];
%Down_Camera_Dimensions = [480 752];


%% Pre-filtering
Scale_Forward_R = 1;
Scale_Forward_G = 1;
Scale_Forward_B = 1;
Scale_Forward_H = 1;
Scale_Forward_S = 1;
Scale_Forward_V = 1;

Scale_Down_R = 1;
Scale_Down_G = 1;
Scale_Down_B = 1;
Scale_Down_H = 1;
Scale_Down_S = 1;
Scale_Down_V = 5;


%% Iterative segmentation default value
Iter_Segment_Thresh = 40;


%% Hedge constants
Hedge_Hue = .4;
Hedge_Saturation = 1;
Hedge_Value = .75;


%% Buoy constants
% Color ranges for buoys (Lab color space). Indices correspond to colors:
%   1 -> White
%   2 -> Black
%   3 -> Blue
%   4 -> Red
%   5 -> Orange
%   6 -> Yellow
%   7 -> Green
a_range = [0, 0, 0, 25, 0, 0, -128;
    0, 0, 0, 127, 0, 0, -25];
b_range = [0, 0, 0, 0, 0, 0, -5;
    0, 0, 0, 127, 0, 0, 127];

Buoy1_Hue = 0.4;
Buoy1_Saturation = 1.0;
Buoy1_Value = 0.45;

Buoy2_Hue = 0.0;
Buoy2_Saturation = 1.0;
Buoy2_Value = 0.75;

Buoy_Min_Eccentricity = 0;
Buoy_Max_Eccentricity = 1.2;
Buoy_Min_Extent = 0.6;
Buoy_Max_Extent = 0.9;

Max_Num_Blobs_Buoy = 10;

% Maximum number of buoys this software will detect in one image
%   (artificial limit; may adjust)
Buoy_Count_Max = 50;

Buoy_Strafe = 40;

% Blob limits
%Min_Blob_Size = 15;
%Max_Blob_Size = 19200;
%Max_Num_Blobs = 50;

%Track_Min_Eccentricity = 0.9;
%Track_Desired_Depth = 8;


%% Torpedo constants
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


%% Optical flow rotation constants
Cam_Down_CCWRotation_Angle = 0;

Heading_Forward_Velocity = 30;
Vision_Forward_Velocity = 15;


%% Unknown
RC_Source = 1;
MissionPlan = [1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0];

Track_HueHigher = .1;
Track_HueLower = .25;
Track_Saturation = 0.5;

% Old values:
%Track_HueHigher = 0.75;
%Track_HueLower = 0.4;
%Track_Saturation = 0.75;

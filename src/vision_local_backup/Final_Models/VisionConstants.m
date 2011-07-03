% AUV Vision Constants
%   These values are set to the workspace before generating C++ code


%% Camera dimensions
Forward_Camera_Dimensions = [160 120];
Down_Camera_Dimensions = [120 160];
Forward_Fov = 120;  % Field of view in degrees
Down_Fov = 120;


%% Pre-filtering
Scale_Forward_R = 1;
Scale_Forward_G = 1;
Scale_Forward_B = 1;
Scale_Forward_H = 1;
Scale_Forward_S = 1;
Scale_Forward_V = 2;

Scale_Down_R = 1;
Scale_Down_G = 1;
Scale_Down_B = 1;
Scale_Down_H = 1;
Scale_Down_S = 1;
Scale_Down_V = 5;


%% Colors
%a_lower = -10;
%a_upper = 10;
%b_lower = 0;
%b_upper = 50;

white_al = 0;
white_au = 0;
white_bl = 0;
white_bu = 0;

white_rrl = 0;
white_rru = 0;
white_ggl = 0;
white_ggu = 0;
white_bbl = 0;
white_bbu = 0;

black_al = 0;
black_au = 0;
black_bl = 0;
black_bu = 0;

black_rrl = 0;
black_rru = 0;
black_ggl = 0;
black_ggu = 0;
black_bbl = 0;
black_bbu = 0;

blue_al = 0;
blue_au = 0;
blue_bl = 0;
blue_bu = 0;

blue_rrl = 0;
blue_rru = 0;
blue_ggl = 0;
blue_ggu = 0;
blue_bbl = 0;
blue_bbu = 0;

red_al = 25;
red_au = 127;
red_bl = 0;
red_bu = 127;

red_rrl = 0;
red_rru = 0;
red_ggl = 0;
red_ggu = 0;
red_bbl = 0;
red_bbu = 0;

orange_al = 15;
orange_au = 30;
orange_bl = 50;
orange_bu = 70;

orange_rrl = 0;
orange_rru = 0;
orange_ggl = 0;
orange_ggu = 0;
orange_bbl = 0;
orange_bbu = 0;

yellow_al = 0;
yellow_au = 0;
yellow_bl = 0;
yellow_bu = 0;

yellow_rrl = 0;
yellow_rru = 0;
yellow_ggl = 0;
yellow_ggu = 0;
yellow_bbl = 0;
yellow_bbu = 0;

green_al = -128;
green_au = -25;
green_bl = -5;
green_bu = 127;

green_rrl = 0;
green_rru = 0;
green_ggl = 0;
green_ggu = 0;
green_bbl = 0;
green_bbu = 0;


%% Iterative segmentation default value
Iter_Segment_Thresh = 20;


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

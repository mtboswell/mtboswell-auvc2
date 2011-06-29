Forward_Camera_Dimensions = [120 160];

Scale_Down_R = 1;
Scale_Down_G = 1;
Scale_Down_B = 1;
Scale_Down_H = 1;
Scale_Down_S = 1;
Scale_Down_V = 5;

Iter_Segment_Thresh = 40;
% Color ranges for buoys (Lab color space). Indices correspond to colors:
%   1 -> White
%   2 -> Black
%   3 -> Blue
%   4 -> Red
%   5 -> Orange
%   6 -> Yellow
%   7 -> Green
a_range = [0, 0, 0, 25, -2, 0, -128;
    0, 0, 0, 127, -.1, 0, -25];
b_range = [0, 0, 0, 0, -14, 0, -5;
    0, 0, 0, 127, -10, 0, 127];

a_range = [0, 0, 0, 25, 5, 0, -128;
    0, 0, 0, 127, 10, 0, -25];
b_range = [0, 0, 0, 0, 30, 0, -5;
    0, 0, 0, 127, 34, 0, 127];

%some old test values (deleteable)
%   51.4618   -4.9515   37.1836
%   31.7274    7.6845   32.4105


extent_range = [0 0 0; 1 1 1];
eccent_range = [0 0 0; 1 1 1];



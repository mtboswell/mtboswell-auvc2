function [heading_y_deg, heading_z_deg] = Centroid2Heading(centroid_x, centroid_y)
%Author: Yama Habib
%Revision: 10/27/2010
%Centroid2Heading takes a raw matrix centroid coordinate and converts
%it into a correction heading, in degrees (i.e. heading_y_deg = -30,
%heading_z_deg = 45 means that in order to orient yourself so that the
%object in question is centered in the video feed, you need to turn 30
%degrees to the left and 45 degrees upwards, assuming the camera is mounted
%on the front) The probability that this function will return exactly 0
%degrees is laughably low, so applying a reasonable threshold to the
%result is strongly recommended.

%Should these be parameters? I think they're fine as constants.
WIDTH = 160;
HEIGHT = 120;
MAXANGLE = 130;

heading_y_deg = ((centroid_x-(WIDTH/2)) / (WIDTH/2)) * (MAXANGLE/2);
heading_z_deg = ((centroid_y-(HEIGHT/2)) / (HEIGHT/2)) * (MAXANGLE/2);
end

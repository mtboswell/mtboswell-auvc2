function [centroid_x, centroid_y] = HedgeCentroidFocal(bwMatrix)
%Author: Yama Habib
%Revision: 10/26/2010

%Should these be parameters? I think they're fine as constants.
WIDTH = 160;
HEIGHT = 120;

ADJUST_ERROR = 1;
AF_COEFFICIENT = 1.2691;
AF_EXPONENT = -0.031;

%changing this doesn't change the solution in theory, but if getting
%low precision, increase this value
RADIUS = 10;

%increase the x and y steps to increase efficiency. The further these
%numbers are from 1, the closer the hedge will have to be to be detected
%NOTE: find the max distance the hedge will be from the AUV, then find the
%optimal (lowest working) x and y steps for that distance!
X_STEP = 1;
Y_STEP = 1;

%if these arrays go out of bounds, the hedge is taking up more than half of
%the video feed, which means we're *probably* about to run into it
xCoords = empty(WIDTH*HEIGHT/2);
yCoords = empty(WIDTH*HEIGHT/2);

%Find data points
index = 1;
i = 1;
while(i <= WIDTH)
    j = 1;
    while(j <= HEIGHT)
        if(bwMatrix(i,j) ~= 0)
            xCoords(index) = i;
            yCoords(index) = j;
            index = index + 1;
        end
        j = j + Y_STEP;
    end
    i = i + X_STEP;
end

%Calculate parabola of best fit (Thank GOD there was a matlab function 
%for this)
p = polyfit(xCoords, yCoords, 2);

%Calculate minimum extrema of parabola (x0 = -b/2a, y0 = f(x0))
x0 = (-1*p(2))/(2*p(1));
y0 = p(1)*pow(x0,2)+p(2)*x0+p(3);

%calculate the depth of our parabola by plugging the radius we chose into
%the polynomial
depth = p(1)*pow((x0+RADIUS),2)+p(2)*(x0+RADIUS)+p(3)-y0;
centroid_y = (pow(RADIUS,2)/(4*depth));
if(ADJUST_ERROR)
    adjustment_factor = AF_COEFFICIENT*pow(index,AF_EXPONENT);
    centroid_y = centroid_y*adjustment_factor;
end
centroid_x = x0;
end


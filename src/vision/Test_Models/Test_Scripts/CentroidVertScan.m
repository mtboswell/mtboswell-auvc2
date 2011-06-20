function [centroid_x, centroid_y] = CentroidVertScan(bwMatrix)
%Author: Yama Habib
%Revision: 10/27/2010
%CentroidVertScan takes a black and white matrix (the expected output of
%the blob detection algorithm) with a single (rectangular) object detected,
%and returns the raw matrix coordinate of the centroid of the object. To
%convert to an angular heading, use the Centroid2Heading function.

%Should these be parameters? I think they're fine as constants.
WIDTH = 160;
HEIGHT = 120;

%increase the x step to increase efficiency. The further this
%number is from 1, the closer the object will have to be to be detected
%NOTE: find the max distance the hedge will be from the AUV, then find the
%optimal (lowest working) x step for that distance!
X_STEP = 1;

%Don't detect lines unless they are longer than HEIGHT*THRESHOLD
THRESHOLD = 0.1;

%Allocate arrays...allocate more or less memory depending on how many lines
%are found in the average case
lineLengths = zeros(WIDTH);
lineMidpts_y = zeros(WIDTH);
lineMidpts_x = zeros(WIDTH);

%Find vertical lines
index = 1;
i = 1;
while(i <= WIDTH)
    j = 1;
    while(j <= HEIGHT)
        %skip whitespace
        while(bwMatrix(floor(i),j) == 0)
            j = j+1;
            if(j > HEIGHT)
                break;
            end
        end
        %count contiguous blackspace
        if(j <= HEIGHT)
            length = 0;
            midpt = j;
            while(bwMatrix(floor(i),j) ~= 0)
                length = length+1;
                j = j+1;
                if(j > HEIGHT)
                    break;
                end
            end
            midpt = midpt + length/2;
            %only register as a line if longer than HEIGHT*THRESHOLD
            if(length > HEIGHT*THRESHOLD)
                lineLengths(index) = length;
                lineMidpts_y(index) = midpt;
                lineMidpts_x(index) = floor(i);
                index = index+1;
            end
        end
        %rinse, repeat
    end
    i = i+X_STEP;
end

%Find maximum (longest rightmost) and minimum (longest leftmost) vertical
%lines
i = 1;
min = 1;
max = 1;
while(i <= index);
    if(lineLengths(i)*(WIDTH-lineMidpts_x(i)) > lineLengths(min)*(WIDTH-lineMidpts_x(min)))
        min = i;
    end
    if(lineLengths(i)*(lineMidpts_x(i)) >= lineLengths(max)*(lineMidpts_x(max)))
        max = i;
    end
    i = i+1;
end

%The centroid is (should be) the midpoint between the max's midpoint and
%the min's midpoint
centroid_x = (lineMidpts_x(min) + lineMidpts_x(max))/2;
centroid_y = (lineMidpts_y(min) + lineMidpts_y(max))/2;
end


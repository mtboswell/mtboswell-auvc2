% Path Following test codes
stage1 = stage1(:,:,1);
stage2 = stage2(:,:,1);
stage3 = stage3(:,:,1);

figure(1); clf; surf([1:size(stage1,2)], [1:size(stage1,1)], stage1)
figure(2); clf; surf([1:size(stage2,2)], [1:size(stage2,1)], stage2)


% Make sparse
stage2_old = stage2;
stage2 = zeros(floor(.5*size(stage2_old)));
ii = 1;
for i = 1:2:size(stage2,1)
    jj = 1;
    for j = 1:2:size(stage2,2)
        stage2(ii,jj) = stage2_old(i,j);
        jj = jj + 1;
    end
    ii = ii + 1;
end


% Analyze bwImage for vertical lines
bwMatrix = stage3;



%function [centroid_x, centroid_y] = CentroidVertScan(bwMatrix)
%Author: Yama Habib
%Revision: 10/27/2010
%CentroidVertScan takes a black and white matrix (the expected output of
%the blob detection algorithm) with a single (rectangular) object detected,
%and returns the raw matrix coordinate of the centroid of the object. To
%convert to an angular heading, use the Centroid2Heading function.

%Should these be parameters? I think they're fine as constants.
WIDTH = size(bwMatrix, 2);
HEIGHT = size(bwMatrix, 1);
%WIDTH = 160;
%HEIGHT = 120;

%increase the x step to increase efficiency. The further this
%number is from 1, the closer the object will have to be to be detected
%NOTE: find the max distance the hedge will be from the AUV, then find the
%optimal (lowest working) x step for that distance!
X_STEP = 1;

%Don't detect lines unless they are longer than HEIGHT*THRESHOLD
THRESHOLD = 0.1;

%Allocate arrays...allocate more or less memory depending on how many lines
%are found in the average case
lineLengths = zeros(WIDTH,1);
lineMidpts_y = zeros(WIDTH,1);
lineMidpts_x = zeros(WIDTH,1);

%Find vertical lines
index = 1;
i = 280;
while(i <= 310)
    j = 1;
    while(j <= HEIGHT)
        %skip whitespace
        while(bwMatrix(j,floor(i)) == 0)
%        while(bwMatrix(floor(i),j) == 0)
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
    
    % The following comparisons seek to minimize and maximize the metric
    %   " length*( width - x_midpt ) ". This effectively finds the largest
    %   leftmost and rightmost vertical lines.
    
    % This if statement should be "<" instead of ">" ??
    if(lineLengths(i)*(WIDTH-lineMidpts_x(i)) > lineLengths(min)*(WIDTH-lineMidpts_x(min)))
        min = i;
    end
    % This if statement should be correct
    if(lineLengths(i)*(lineMidpts_x(i)) >= lineLengths(max)*(lineMidpts_x(max)))
        max = i;
    end
    i = i+1;
end

%The centroid is (should be) the midpoint between the max's midpoint and
%the min's midpoint
% The assumption made is that the rightmost and leftmost lines bound a
% vertically-oriented rectangular path
centroid_x = (lineMidpts_x(min) + lineMidpts_x(max))/2;
centroid_y = (lineMidpts_y(min) + lineMidpts_y(max))/2;


disp([centroid_x, centroid_x])

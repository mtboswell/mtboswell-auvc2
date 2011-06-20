% Path-finding test code
% Compress workspace data to one time step
stage3 = stage3(:,:,1);
BBox = BBox(:,:,1);

figure(1); clf; hold on
for i = 1:length(BBox)
    plot([BBox(1), BBox(1)+BBox(3)], [BBox(2), BBox(2) + BBox(4)], 'k')
end

for i = 1:size(stage3,1)
    for j = 1:size(stage3,2)
        if(stage3(i,j) ~= 0)
            plot(i,j,'k')
        end
    end
end


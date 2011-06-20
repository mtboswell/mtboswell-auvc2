% OpticalFlow test code
stage2_vector = zeros(size(stage2,3),1);
for i = 1:size(stage2,3)
    stage2_vector(i) = stage2(1,1,i);
end
figure(1); clf; plot(t, stage2_vector, 'k-')

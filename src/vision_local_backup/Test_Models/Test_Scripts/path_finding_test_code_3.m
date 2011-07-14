clc
theta_in = [0 30 -30 80 -80 120 -120 175 -175 185 200 360 500 900 -950].*pi/180;

theta_out = zeros(size(theta_in));


% Correct angles (in radians) to range [-pi/2, pi/2]
for i = 1:length(theta_in)
    
    theta_out(i) = mod(theta_in(i) + pi/2, pi) - pi/2;
    
    if(theta_out(i) > pi/2)
%        theta_out(i) = theta_out(i) - pi;
        %theta_out(i) = mod(theta_in(i), pi/2);
    elseif(theta_out(i) < -pi/2)
%        theta_out(i) = theta_out(i) + pi;
        %theta_out(i) = mod(theta_in(i), 180);
    end

end

theta_in.*180/pi
theta_out.*180/pi






max_num_paths = 3;
path_headings = [1 2 3];
path_locations = [1 2 3; 2 -5 25];



value = Down_Camera_Dimensions(2).*ones(1,max_num_paths);
j_index = ones(1,max_num_paths);
found = zeros(1,max_num_paths);

for p = 1:max_num_paths
    for j = 1:max_num_paths
        if(path_locations(2,j) < value(p) && found(j) == 0)
            value(p) = path_locations(2,j);
            j_index(p) = j;
        end
    end
    found(j_index(p)) = 1;
end


matr = [path_headings; path_locations];
for p = 1:max_num_paths
    path_headings(p) = matr(1,j_index(p));
    path_locations(1,p) = matr(2,j_index(p));
    path_locations(2,p) = matr(3,j_index(p));
end


[path_headings; path_locations]


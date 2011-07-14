% Validation gate test code


% 6-9-11

rows = 160;
cols = 120;
eps_rho = .1*max(rows,cols);
eps_theta = 10*pi/180;


max_num_lines = 7;


rho = [20 100 30 -30 0 0 0];
theta = [-2 2 88 -88 0 0 0].*pi/180;
rho_test = rho;
theta_test = theta;



% Effectively generate a small Hough table which contains only values of
%   interest for the validation gate application

rbinv = [0:(2*eps_rho):max(rows, cols)];  % Rho bins for vertical lines
nbinsv = length(rbinv);  % Number of rho bins for vertical lines
ravgv = zeros(1,nbinsv);  % Average rho values for each bin (note that the average value will generally differ slightly than the bin value)
tavgv = zeros(1,nbinsv);  % Average theta values for each bin
vbinv = zeros(1,nbinsv);  % Votes bins for vertical lines

rbinh = [0:(2*eps_rho):max(rows, cols)];
nbinsh = length(rbinh);
ravgh = zeros(1,nbinsh);
tavgh = zeros(1,nbinsh);
vbinh = zeros(1,nbinsh);

for i = 1:max_num_lines
    
    % Consider only lines that are either vertical or horizontal, within
    %   tolerance
    condition1 = ( abs(theta(i) - pi/2) <= eps_theta || abs(theta(i) + pi/2) <= eps_theta );  % Horizontal line
    condition2 = ( abs(theta(i) - 0) <= eps_theta );  % Vertical line
    
    if(condition2 && ~( rho(i) == 0 && theta(i) == 0 ))  % Analyze vertical lines (ignore lines exactly along the left side of the image)
        
        for b = 1:nbinsv
            
            % Place each rho value into a bin
            if( abs(rho(i) - rbinv(b)) <= eps_rho )
                ravgv(b) = ravgv(b) + rho(i);
                tavgv(b) = tavgv(b) + theta(i);
                vbinv(b) = vbinv(b) + 1;
                break;
            end
            
        end
        
    elseif(condition1)  % Analyze horizontal lines
        
        if( theta(i) < 0 )
            theta(i) = theta(i) + pi;
            rho(i) = -rho(i);
        end
        
        for b = 1:nbinsh
            
            % Place each rho value into a bin
            if( abs(rho(i) - rbinh(b)) <= eps_rho )
                ravgh(b) = ravgh(b) + rho(i);
                tavgh(b) = tavgh(b) + theta(i);
                vbinh(b) = vbinh(b) + 1;
                break;
            end
            
        end
        
    end
end

for b = 1:nbinsv
    if( vbinv(b) == 0 )
        ravgv(b) = 0;
        tavgv(b) = 0;
    else
        ravgv(b) = ravgv(b)./vbinv(b);
        tavgv(b) = tavgv(b)./vbinv(b);
    end
end

for b = 1:nbinsh
    if( vbinh(b) == 0 )
        ravgh(b) = 0;
        tavgh(b) = 0;
    else
        ravgh(b) = ravgh(b)./vbinh(b);
        tavgh(b) = tavgh(b)./vbinh(b);
    end
end



[rho; theta.*180/pi]

[rbinv; vbinv]
[rbinh; vbinh]

[ravgv; tavgv.*180/pi]
[ravgh; tavgh.*180/pi]







% 6-9-11
%{
x = [1:20];
y = [0 0 0 0 2 4 9 6 4 0 0 6 0  7 5 0  0 7 5 6];

% Compute the first-order finite difference
slope_firstorder = ( y(2:end) - y(1:end-1) )./( x(2:end) - x(1:end-1) );

% Compute the second-order finite difference
slope_secondorder = zeros(1, length(y));
for i = 1:length(y)
    
    if( i == 1 )
        
        % Handle left limit
        h = ( (x(i+1) - x(i)) + (x(i+2) - x(i+1)) )/2;
        slope_secondorder(i) = ( y(i+2) - 2*y(i+1) + y(i) )/( h^2 );
        
    elseif( i == length(y) )
        
        % Handle right limit
        h = ( (x(i) - x(i-1)) + (x(i-1) - x(i-2)) )/2;
        slope_secondorder(i) = ( y(i) - 2*y(i-1) + y(i-2) )/( h^2 );
        
    else
        
        % Prefer centered difference for interior points
        h = ( (x(i+1) - x(i)) + (x(i) - x(i-1)) )/2;
        slope_secondorder(i) = ( y(i+1) - 2*y(i) + y(i-1) )/( h^2 );
        
    end
    
end

figure(1); clf; plot(x, y, 'k-', x, slope_secondorder, 'b-')
%}


%{
% 5-29-11
rho = make_sparse(rho);
theta = make_sparse(theta);
hugh = make_sparse(hugh);

figure(1); clf; surface(rho', theta', hugh')
%}

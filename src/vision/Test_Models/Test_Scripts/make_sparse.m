function [matr_3D_out] = make_sparse(matr_3D_in)

matr_3D_out = zeros(floor(.5.*size(matr_3D_in)));

for i = 1:size(matr_3D_in,1)
    for j = 1:size(matr_3D_in,2)
        
        % If both i and j are odd
        if( i/2 ~= floor(i/2) && j/2 ~= floor(j/2) )
            matr_3D_out(floor(i/2)+1, floor(j/2)+1, :) = matr_3D_in(i,j,:);
        end
        
    end
end



% Validation gate test code
%
% 5-29-11

rho = make_sparse(rho);
theta = make_sparse(theta);
hugh = make_sparse(hugh);

figure(1); clf; surface(rho', theta', hugh')


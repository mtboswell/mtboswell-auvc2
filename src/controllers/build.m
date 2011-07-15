%{
example;
set_param(bdroot, 'PostCodeGenCommand', ...
'packNGo(buildInfo, {''packType'' ''flat''})')
rtwbuild(bdroot);
%}

%{
MotionController;
set_param(bdroot, 'PostCodeGenCommand', ...
'packNGo(buildInfo, {''packType'' ''flat''})')
rtwbuild(bdroot);
%}



MotionController;
set_param(bdroot, 'PostCodeGenCommand', ...
'packNGo(buildInfo, {''packType'' ''flat''})')
rtwbuild(bdroot);

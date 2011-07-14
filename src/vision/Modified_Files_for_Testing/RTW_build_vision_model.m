

buildInfo = RTW.BuildInfo;
packNGoFile = 'vision_model_mod';  % Model file to be compiled
packType = 'flat';

packNGo(buildInfo, {'fileName' packNGoFile, 'packType' packType});







packNGoFile = 'vision_model_mod';  % Model file to be compiled
set_param(packNGoFile,'PostCodeGenCommand','packNGo(buildInfo);');
%cd zingbat_grt_rtw;
load buildInfo.mat
packNGo(buildInfo, {'packType', 'hierarchical', ...
 'fileName', packNGoFile});


# comment out this line to enable warnings
CONFIG += warn_off

# determine distro
ISSUE = $$system(cat /etc/issue)
contains( ISSUE, [uU]buntu ) {
	CONFIG += ubuntu
}
contains( ISSUE, [aA]rch ){
	CONFIG += arch
}
contains( ISSUE, [fF]edora ){
	CONFIG += fedora
}

TEMPLATE = app
TARGET = ../agent
CONFIG += debug
QT += network 
MOC_DIR = tmp
OBJECTS_DIR = tmp
UI_DIR = tmp

# llua-5.1
ubuntu {
	LIBS +=  -llua5.1
} else {
	LIBS +=  -llua
}
# camera driver 
LIBS +=  -lueye_api
# old libs
#LIBS += -Lserver-jaus -ljauscore -ljausmobility -ltinyxml -lcxutils

DEPENDPATH += . \

INCLUDEPATH += . \
	     module \
	     state \
	     misc \
	     sal/drivers \
	     sal/drivers/qextserialport \
	     controllers/src \
	     cameraSAL \
	     /usr/include/lua5.1

# Main ####################################################
HEADERS += \
           misc/configloader.h \
           module/module.h \
           module/simulinkmodule.h \
           module/modulehub.h \
           state/state.h \
           state/vdatum.h \
           state/vdatasocket.h \
           state/treemodel/treeitem.h \
           state/treemodel/treemodel.h \ 
    vision/src/AudioDefs.h \
    vision/src/bio_sig.h \
    vision/src/blas.h \
    vision/src/blascompat32.h \
    vision/src/cg_matrx.h \
    vision/src/cg_sfun.h \
    vision/src/compare_fcn.h \
    vision/src/dll_utils_win.h \
    vision/src/dspallpole_rt.h \
    vision/src/dspbiquad_rt.h \
    vision/src/dspblms_rt.h \
    vision/src/dsp_blms_sim.h \
    vision/src/dsp_chol_sim.h \
    vision/src/dsp_dlyerr_sim.h \
    vision/src/dspendian_rt.h \
    vision/src/dspeph_rt.h \
    vision/src/dsp_fft_common_sim.h \
    vision/src/dsp_fft_sim.h \
    vision/src/dspfilterbank_rt.h \
    vision/src/dsp_filtstruct_sim.h \
    vision/src/dspfir_rt.h \
    vision/src/dsp_ic_rt.h \
    vision/src/dspiir_rt.h \
    vision/src/dsp_interp_sim.h \
    vision/src/dsp_iso_math_rt.h \
    vision/src/dspmmutils_rt.h \
    vision/src/dsp_offset_sim.h \
    vision/src/dspqrdc_rt.h \
    vision/src/dsprandsrc32bit_rt.h \
    vision/src/dsprandsrc64bit_rt.h \
    vision/src/dsprandsrc_rt.h \
    vision/src/dsp_randsrc_sim.h \
    vision/src/dsprebuff_rt.h \
    vision/src/dsp_rebuff_sim.h \
    vision/src/dsp_rt.h \
    vision/src/dspsizeof_rt.h \
    vision/src/dsp_sqdesign.h \
    vision/src/dspsrt_rt.h \
    vision/src/dsp_srt_sim.h \
    vision/src/dspsvd_rt.h \
    vision/src/dsp_vqdesign.h \
    vision/src/dt_info.h \
    vision/src/emlrt.h \
    vision/src/engine.h \
    vision/src/ext_share.h \
    vision/src/ext_svr.h \
    vision/src/ext_svr_transport.h \
    vision/src/ext_test.h \
    vision/src/ext_types.h \
    vision/src/ext_work.h \
    vision/src/fintrf.h \
    vision/src/fixedpoint.h \
    vision/src/fromwavedevice_ex_win32.h \
    vision/src/fromwavedevice_win32.h \
    vision/src/fromwavefile_ex_win32.h \
    vision/src/fromwavefile_win32.h \
    vision/src/HostLib_Audio.h \
    vision/src/HostLib_MMFile.h \
    vision/src/HostLib_Multimedia.h \
    vision/src/HostLib_Video.h \
    vision/src/io64.h \
    vision/src/lapack.h \
    vision/src/lexicmp.h \
    vision/src/mat.h \
    vision/src/matrix.h \
    vision/src/mdl_info.h \
    vision/src/mem_mgr.h \
    vision/src/mex.h \
    vision/src/mwmathutil.h \
    vision/src/mwutil.h \
    vision/src/odesup.h \
    vision/src/pt_info.h \
    vision/src/rtGetInf.h \
    vision/src/rtGetNaN.h \
    vision/src/rtiostream.h \
    vision/src/rt_logging.h \
    vision/src/rt_logging_mmi.h \
    vision/src/rt_math.h \
    vision/src/rt_matrx.h \
    vision/src/rtmcmacros.h \
    vision/src/rtmmacros.h \
    vision/src/rt_mxclassid.h \
    vision/src/rt_nonfinite.h \
    vision/src/rt_pow_snf.h \
    vision/src/rt_sim.h \
    vision/src/rtsplntypes.h \
    vision/src/rtw_capi.h \
    vision/src/rtw_capi_examples.h \
    vision/src/rtw_continuous.h \
    vision/src/rtw_extmode.h \
    vision/src/rtw_matlogging.h \
    vision/src/rtw_modelmap.h \
    vision/src/rtw_modelmap_logging.h \
    vision/src/rtw_solver.h \
    vision/src/rtwtypes.h \
    vision/src/sfcn_bridge.h \
    vision/src/sigmapdef_sfcn.h \
    vision/src/sigregdef.h \
    vision/src/simstruc.h \
    vision/src/simstruc_types.h \
    vision/src/simulink.h \
    vision/src/simulink2.h \
    vision/src/sl_datatype_access.h \
    vision/src/sl_fileio_rtw.h \
    vision/src/sl_fixpt.h \
    vision/src/sl_prodhwdevicetype.h \
    vision/src/sl_solver_rtw.h \
    vision/src/sl_types_def.h \
    vision/src/solver_zc.h \
    vision/src/sysran_types.h \
    vision/src/tmwtypes.h \
    vision/src/towavedevice_ex_win32.h \
    vision/src/towavedevice_win32.h \
    vision/src/towavefile_ex_win32.h \
    vision/src/towavefile_win32.h \
    vision/src/updown.h \
    vision/src/updown_util.h \
    vision/src/upsup_public.h \
    vision/src/VideoDefs.h \
    vision/src/vip_2dpad_sim.h \
    vision/src/vipblob_rt.h \
    vision/src/vipblockmatch_rt.h \
    vision/src/vipdrawtext_rt.h \
    vision/src/vipedge_rt.h \
    vision/src/vipfileread_rt.h \
    vision/src/vipfilewrite_rt.h \
    vision/src/vip_fourcclist_sim.h \
    vision/src/viphough_rt.h \
    vision/src/vip_imgcomplement_sim.h \
    vision/src/vipmdnfilter_rt.h \
    vision/src/vipopticalflow_rt.h \
    vision/src/vipprojective.h \
    vision/src/vipprojective_rt.h \
    vision/src/vip_sim.h \
    vision/src/VisionModel.h \
    vision/src/VisionModel_private.h \
    vision/src/VisionModel_types.h


SOURCES += \
	   misc/configloader.cpp \
           main.cpp \
           module/module.cpp \
           module/modulehub.cpp \
           module/simulinkmodule.cpp \
           state/vdatum.cpp \
           state/vdatasocket.cpp \
           state/treemodel/treeitem.cpp \
           state/treemodel/treemodel.cpp \
    vision/src/ert_main.cpp \
    vision/src/hough_d_rt.c \
    vision/src/hough_r_rt.c \
    vision/src/rtGetInf.cpp \
    vision/src/rtGetNaN.cpp \
    vision/src/rt_nonfinite.cpp \
    vision/src/rt_pow_snf.cpp \
    vision/src/VisionModel.cpp \
    vision/src/VisionModel_data.cpp

# Controllers ###############################################
HEADERS += \
           controllers/controllers.h \
           controllers/src/bio_sig.h \
           controllers/src/blas.h \
           controllers/src/blascompat32.h \
           controllers/src/cg_matrx.h \
           controllers/src/cg_sfun.h \
           controllers/src/dt_info.h \
           controllers/src/emlrt.h \
           controllers/src/engine.h \
           controllers/src/ext_share.h \
           controllers/src/ext_svr.h \
           controllers/src/ext_svr_transport.h \
           controllers/src/ext_test.h \
           controllers/src/ext_types.h \
           controllers/src/ext_work.h \
           controllers/src/fintrf.h \
           controllers/src/fixedpoint.h \
           controllers/src/io64.h \
           controllers/src/lapack.h \
           controllers/src/mat.h \
           controllers/src/matrix.h \
           controllers/src/mdl_info.h \
           controllers/src/mem_mgr.h \
           controllers/src/mex.h \
           controllers/src/MotionController.h \
           controllers/src/MotionController_private.h \
           controllers/src/MotionController_types.h \
           controllers/src/mwmathutil.h \
           controllers/src/mwutil.h \
           controllers/src/odesup.h \
           controllers/src/pt_info.h \
           controllers/src/rt_logging.h \
           controllers/src/rt_logging_mmi.h \
           controllers/src/rt_math.h \
           controllers/src/rt_matrx.h \
           controllers/src/rt_mxclassid.h \
           controllers/src/rt_sim.h \
           controllers/src/rtiostream.h \
           controllers/src/rtmcmacros.h \
           controllers/src/rtmmacros.h \
           controllers/src/rtsplntypes.h \
           controllers/src/rtw_capi.h \
           controllers/src/rtw_capi_examples.h \
           controllers/src/rtw_continuous.h \
           controllers/src/rtw_extmode.h \
           controllers/src/rtw_matlogging.h \
           controllers/src/rtw_modelmap.h \
           controllers/src/rtw_modelmap_logging.h \
           controllers/src/rtw_solver.h \
           controllers/src/rtwtypes.h \
           controllers/src/sfcn_bridge.h \
           controllers/src/sigmapdef_sfcn.h \
           controllers/src/sigregdef.h \
           #controllers/src/simstruc.h \
           controllers/src/simstruc_types.h \
           controllers/src/simulink.h \
           controllers/src/simulink2.h \
           controllers/src/sl_datatype_access.h \
           controllers/src/sl_fileio_rtw.h \
           controllers/src/sl_fixpt.h \
           controllers/src/sl_prodhwdevicetype.h \
           controllers/src/sl_solver_rtw.h \
           controllers/src/sl_types_def.h \
           controllers/src/solver_zc.h \
           controllers/src/sysran_types.h \
           controllers/src/tmwtypes.h \
           controllers/src/updown.h \
           controllers/src/updown_util.h \
           controllers/src/upsup_public.h 

SOURCES += \
           controllers/controllers.cpp \
           controllers/src/MotionController.cpp \
           controllers/src/MotionController_data.cpp 


# SAL ###############################################
HEADERS += \
           sal/sal.h \
	   sal/drivers/microstrain.h \
	   sal/drivers/camera.h \
	   sal/drivers/os5000.h \
	   sal/drivers/maestro.h \
	   cameraSAL/cameraSAL.h
SOURCES += \
           sal/sal.cpp \
	   sal/drivers/microstrain.cpp \
	   sal/drivers/camera.cpp \
	   sal/drivers/os5000.cpp \
	   sal/drivers/maestro.cpp \
	   cameraSAL/cameraSAL.cpp


# QExtSerialPort ###############################################
HEADERS += \
		sal/drivers/serialdevice.h \
		sal/drivers/qextserialport/qextserialenumerator.h \
		sal/drivers/qextserialport/qextserialport_global.h \
		sal/drivers/qextserialport/qextserialport.h

SOURCES += \
		sal/drivers/serialdevice.cpp \
		sal/drivers/qextserialport/qextserialport.cpp \
		sal/drivers/qextserialport/posix_qextserialport.cpp \
		sal/drivers/qextserialport/qextserialenumerator_unix.cpp 
#		sal/drivers/qextserialport/qextserialenumerator_win.cpp \
#		sal/drivers/qextserialport/win_qextserialport.cpp

# Actuators ###############################################
HEADERS += \
           actuators/actuators.h \
	   actuators/pololu.h
SOURCES += \
           actuators/actuators.cpp \
	   actuators/pololu.cpp

# director ################################################
HEADERS +=  \
            director/director.h \
            director/TransitionComparator.h \
           director/lua/QueryLua.h

SOURCES +=  \
            director/director.cpp \
            director/lua/QueryLua.cpp

# vision ################################################
HEADERS +=  \
    vision/vision.h \

SOURCES += \
     vision/vision.cpp \

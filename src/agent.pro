TEMPLATE = app
TARGET = ../agent
CONFIG += qt gui
QT += network  # phonon 

unix {
        CONFIG += link_pkgconfig
        PKGCONFIG += opencv
}

win32 {
        LIBS += cv.lib highgui.lib cvaux.lib cxcore.lib
}

DEPENDPATH += . \
	      auv \
	      brain \
	      server \
	      model \
	      /usr/local/Trolltech/Qt-4.6.1
INCLUDEPATH += . \
	     brain \
	     auv \
	     model \
	     auv/qextserialport \
	     server
# Input
HEADERS += server/server.h \
	server/sidsocket.h \
	version.h \
	configloader.h \
	model/parameters.h \
	model/model.h \
	auv/arduino.h \
	auv/auv.h \
	auv/auvtypes.h \
	auv/calibration.h \
	auv/imudata.h \
	auv/microstrain.h \
	auv/os5000.h \
	auv/pololu.h \
	auv/ports.h \
	auv/power.h \
	auv/qwebcam.h \
	auv/mechanisms.h \
	auv/calibrateservos.h \
	auv/serialdevice.h \
	auv/lcd.h \
	auv/qextserialport/qextserialenumerator.h \
	auv/qextserialport/qextserialport_global.h \
	auv/qextserialport/qextserialport.h
SOURCES += server/server.cpp \
	   server/sidsocket.cpp \
	   main.cpp \
	   version.cpp \
	   configloader.cpp \
	   model/model.cpp \
	   model/parameters.cpp \
	   auv/arduino.cpp \
	   auv/auv.cpp \
	   auv/microstrain.cpp \
	   auv/os5000.cpp \
	   auv/pololu.cpp \
	   auv/power.cpp \
	   auv/qwebcam.cpp \
	   auv/mechanisms.cpp \
	   auv/calibrateservos.cpp \
	   auv/serialdevice.cpp \
	   auv/lcd.cpp \
	   auv/qextserialport/posix_qextserialport.cpp \
	   auv/qextserialport/qextserialenumerator_unix.cpp \
	   auv/qextserialport/qextserialport.cpp

HEADERS += \
brain/AudioDefs.h \
brain/autobuild.h \
brain/bio_sig.h \
brain/blascompat32.h \
brain/blas.h \
brain/brain.h \
brain/brain_private.h \
brain/brain_types.h \
brain/cg_matrx.h \
brain/cg_sfun.h \
brain/compare_fcn.h \
brain/dll_utils_win.h \
brain/dspallpole_rt.h \
brain/dspbiquad_rt.h \
brain/dspblms_rt.h \
brain/dsp_blms_sim.h \
brain/dsp_chol_sim.h \
brain/dsp_dlyerr_sim.h \
brain/dspendian_rt.h \
brain/dspeph_rt.h \
brain/dsp_fft_common_sim.h \
brain/dsp_fft_sim.h \
brain/dspfilterbank_rt.h \
brain/dsp_filtstruct_sim.h \
brain/dspfir_rt.h \
brain/dsp_ic_rt.h \
brain/dspiir_rt.h \
brain/dsp_interp_sim.h \
brain/dsp_iso_math_rt.h \
brain/dspmmutils_rt.h \
brain/dsp_offset_sim.h \
brain/dspqrdc_rt.h \
brain/dsprandsrc32bit_rt.h \
brain/dsprandsrc64bit_rt.h \
brain/dsprandsrc_rt.h \
brain/dsp_randsrc_sim.h \
brain/dsprebuff_rt.h \
brain/dsp_rebuff_sim.h \
brain/dsp_rt.h \
brain/dspsizeof_rt.h \
brain/dsp_sqdesign.h \
brain/dspsrt_rt.h \
brain/dsp_srt_sim.h \
brain/dspsvd_rt.h \
brain/dsp_vqdesign.h \
brain/dt_info.h \
brain/emlrt.h \
brain/engine.h \
brain/ext_share.h \
brain/ext_svr.h \
brain/ext_svr_transport.h \
brain/ext_test.h \
brain/ext_types.h \
brain/ext_work.h \
brain/fintrf.h \
brain/fixedpoint.h \
brain/fromwavedevice_ex_win32.h \
brain/fromwavedevice_win32.h \
brain/fromwavefile_ex_win32.h \
brain/fromwavefile_win32.h \
brain/HostLib_Audio.h \
brain/HostLib_MMFile.h \
brain/HostLib_Multimedia.h \
brain/HostLib_Video.h \
brain/io64.h \
brain/lapack.h \
brain/lexicmp.h \
brain/mat.h \
brain/matrix.h \
brain/mdl_info.h \
brain/mem_mgr.h \
brain/mex.h \
brain/mwdebug.h \
brain/mwmathutil.h \
brain/mwutil.h \
brain/odesup.h \
brain/pt_info.h \
brain/rtGetInf.h \
brain/rtGetNaN.h \
brain/rtiostream.h \
brain/rt_logging.h \
brain/rt_logging_mmi.h \
brain/rt_matrx.h \
brain/rtmcmacros.h \
brain/rtmmacros.h \
brain/rt_mxclassid.h \
brain/rt_nonfinite.h \
brain/rt_pow32_snf.h \
brain/rt_pow_snf.h \
brain/rt_sim.h \
brain/rtsplntypes.h \
brain/rtw_capi_examples.h \
brain/rtw_capi.h \
brain/rtw_continuous.h \
brain/rtw_extmode.h \
brain/rtw_matlogging.h \
brain/rtw_modelmap.h \
brain/rtw_modelmap_logging.h \
brain/rtw_solver.h \
brain/rtwtypes.h \
brain/sfcn_bridge.h \
brain/sigmapdef_sfcn.h \
brain/sigregdef.h \
brain/simstruc.h \
brain/simstruc_types.h \
brain/simulink2.h \
brain/simulink.h \
brain/sl_datatype_access.h \
brain/sl_fileio_rtw.h \
brain/sl_solver_rtw.h \
brain/sl_types_def.h \
brain/solver_zc.h \
brain/sysran_types.h \
brain/tmwtypes.h \
brain/towavedevice_ex_win32.h \
brain/towavedevice_win32.h \
brain/towavefile_ex_win32.h \
brain/towavefile_win32.h \
brain/updown.h \
brain/updown_util.h \
brain/upsup_public.h \
brain/VideoDefs.h \
brain/vip_2dpad_sim.h \
brain/vipblob_rt.h \
brain/vipblockmatch_rt.h \
brain/vipdrawtext_rt.h \
brain/vipedge_rt.h \
brain/vipfileread_rt.h \
brain/vipfilewrite_rt.h \
brain/vip_fourcclist_sim.h \
brain/viphough_rt.h \
brain/vip_imgcomplement_sim.h \
brain/vipmdnfilter_rt.h \
brain/vipopticalflow_rt.h \
brain/vipprojective.h \
brain/vipprojective_rt.h \
brain/viprotate_rt.h \
brain/vip_sim.h

SOURCES += \
brain/hough_d_rt.c \
brain/hough_r_rt.c \
brain/brain.cpp \
brain/brain_data.cpp \
brain/rtGetInf.cpp \
brain/rtGetNaN.cpp \
brain/rt_nonfinite.cpp \
brain/rt_pow32_snf.cpp \
brain/rt_pow_snf.cpp


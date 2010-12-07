TEMPLATE = app
TARGET = ../agent
CONFIG += qt
QT += network  # phonon 
unix {
	CONFIG += link_pkgconfig
	PKGCONFIG += opencv
}

win32 {
	LIBS += cv.lib highgui.lib cvaux.lib cxcore.lib
}

#LIBS += -Lserver-jaus -ljauscore -ljausmobility -ltinyxml -lcxutils

DEPENDPATH += . \
              actor \
#              auv \
              datahub \
#              director \
#              hal \
              server \
              treemodel \
              actor/src \
#              auv/camera \
              auv/qextserialport 
INCLUDEPATH += . \
               treemodel \
               datahub \
               server \
#               auv \
               auv/qextserialport \
               actor \
               actor/src \
#               hal \
#               auv/camera 

# Input
HEADERS += \
           configloader.h \
#           datalogger.h \
           module.h \
           simulinkmodule.h \
           state.h \
           tmf.h \
           version.h \
           actor/actor.h \
#           actor/mechanisms.h \
#           auv/arduino.h \
#           auv/auv.h \
#           auv/auvmotion.h \
#           auv/auvtypes.h \
           auv/calibrateservos.h \
#           auv/lcd.h \
#           auv/maestro.h \
#           auv/microstrain.h \
#           auv/os5000.h \
#           auv/pololu.h \
#           auv/power.h \
#           auv/qwebcam.h \
#           auv/sensor.h \
#           auv/serialdevice.h \
           datahub/datahub.h \
#           director/director.h \
#           hal/datatypes.h \
#           hal/hal.h \
           server/tmfsocket.h \
           treemodel/treeitem.h \
           treemodel/treemodel.h \
           actor/src/bio_sig.h \
           actor/src/blas.h \
           actor/src/blascompat32.h \
           actor/src/cg_matrx.h \
           actor/src/cg_sfun.h \
           actor/src/dt_info.h \
           actor/src/emlrt.h \
           actor/src/engine.h \
           actor/src/ext_share.h \
           actor/src/ext_svr.h \
           actor/src/ext_svr_transport.h \
           actor/src/ext_test.h \
           actor/src/ext_types.h \
           actor/src/ext_work.h \
           actor/src/fintrf.h \
           actor/src/fixedpoint.h \
           actor/src/io64.h \
           actor/src/lapack.h \
           actor/src/mat.h \
           actor/src/matrix.h \
           actor/src/mdl_info.h \
           actor/src/mem_mgr.h \
           actor/src/mex.h \
           actor/src/MotionController.h \
           actor/src/MotionController_private.h \
           actor/src/MotionController_types.h \
           actor/src/mwmathutil.h \
           actor/src/mwutil.h \
           actor/src/odesup.h \
           actor/src/pt_info.h \
           actor/src/rt_logging.h \
           actor/src/rt_logging_mmi.h \
           actor/src/rt_math.h \
           actor/src/rt_matrx.h \
           actor/src/rt_mxclassid.h \
           actor/src/rt_sim.h \
           actor/src/rtiostream.h \
           actor/src/rtmcmacros.h \
           actor/src/rtmmacros.h \
           actor/src/rtsplntypes.h \
           actor/src/rtw_capi.h \
           actor/src/rtw_capi_examples.h \
           actor/src/rtw_continuous.h \
           actor/src/rtw_extmode.h \
           actor/src/rtw_matlogging.h \
           actor/src/rtw_modelmap.h \
           actor/src/rtw_modelmap_logging.h \
           actor/src/rtw_solver.h \
           actor/src/rtwtypes.h \
           actor/src/sfcn_bridge.h \
           actor/src/sigmapdef_sfcn.h \
           actor/src/sigregdef.h \
           actor/src/simstruc.h \
           actor/src/simstruc_types.h \
           actor/src/simulink.h \
           actor/src/simulink2.h \
           actor/src/sl_datatype_access.h \
           actor/src/sl_fileio_rtw.h \
           actor/src/sl_fixpt.h \
           actor/src/sl_prodhwdevicetype.h \
           actor/src/sl_solver_rtw.h \
           actor/src/sl_types_def.h \
           actor/src/solver_zc.h \
           actor/src/sysran_types.h \
           actor/src/tmwtypes.h \
           actor/src/updown.h \
           actor/src/updown_util.h \
           actor/src/upsup_public.h \
           auv/qextserialport/qextserialenumerator.h \
           auv/qextserialport/qextserialport.h \
           auv/qextserialport/qextserialport_global.h 
SOURCES += configloader.cpp \
           main.cpp \
           module.cpp \
           tmf.cpp \
           version.cpp \
           actor/actor.cpp \
           actor/mechanisms.cpp \
#           auv/arduino.cpp \
#           auv/auv.cpp \
#           auv/calibrateservos.cpp \
#           auv/camread.cpp \
#           auv/lcd.cpp \
#           auv/microstrain.cpp \
#           auv/os5000.cpp \
#           auv/pololu.cpp \
#           auv/power.cpp \
#           auv/qwebcam.cpp \
#           auv/sensor.cpp \
#           auv/serialdevice.cpp \
           server/tmfsocket.cpp \
           treemodel/treeitem.cpp \
           treemodel/treemodel.cpp \
           actor/src/MotionController.cpp \
           actor/src/MotionController_data.cpp \
           auv/qextserialport/posix_qextserialport.cpp \
           auv/qextserialport/qextserialenumerator_unix.cpp \
           auv/qextserialport/qextserialport.cpp 

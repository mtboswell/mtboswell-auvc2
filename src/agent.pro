TEMPLATE = app
TARGET = ../agent
CONFIG += qt
QT += network  # phonon 

#LIBS += -Lserver-jaus -ljauscore -ljausmobility -ltinyxml -lcxutils

DEPENDPATH += . \
              controllers \
#              auv \
              datahub \
#              director \
#              hal \
              server \
              treemodel \
              controllers/src \
#              auv/camera \
              auv/qextserialport 
INCLUDEPATH += . \
               treemodel \
               datahub \
               server \
#               auv \
               auv/qextserialport \
               controllers \
               controllers/src \
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
           controllers/controllers.h \
#           controllers/mechanisms.h \
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
           controllers/src/simstruc.h \
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
           controllers/src/upsup_public.h \
           auv/qextserialport/qextserialenumerator.h \
           auv/qextserialport/qextserialport.h \
           auv/qextserialport/qextserialport_global.h 
SOURCES += configloader.cpp \
           main.cpp \
           module.cpp \
           simulinkmodule.cpp \
           tmf.cpp \
           version.cpp \
           controllers/controllers.cpp \
           controllers/mechanisms.cpp \
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
           controllers/src/MotionController.cpp \
           controllers/src/MotionController_data.cpp \
           auv/qextserialport/posix_qextserialport.cpp \
           auv/qextserialport/qextserialenumerator_unix.cpp \
           auv/qextserialport/qextserialport.cpp 

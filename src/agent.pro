TEMPLATE = app
TARGET = ../agent
CONFIG += qt gui debug warn_off
QT += network 
MOC_DIR = tmp
OBJECTS_DIR = tmp
UI_DIR = tmp

#LIBS += -Lserver-jaus -ljauscore -ljausmobility -ltinyxml -lcxutils
LIBS +=  -lueye_api

DEPENDPATH += . \

INCLUDEPATH += . \
	     module \
	     state \
	     misc \
	     sal/drivers \
	     sal/drivers/qextserialport \
	     controllers/src 

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
           state/treemodel/treemodel.h 

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
	   sal/drivers/maestro.h
SOURCES += \
           sal/sal.cpp \
	   sal/drivers/microstrain.cpp \
	   sal/drivers/camera.cpp \
	   sal/drivers/os5000.cpp \
	   sal/drivers/maestro.cpp


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
#HEADERS += \
#           actuators/actuators.h 
#SOURCES += \
#           actuators/actuators.cpp 

#############################################################################
# Makefile for building: agent
# Generated by qmake (2.01a) (Qt 4.6.1) on: Wed Feb 17 17:57:10 2010
# Project:  agent.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.6.1/bin/qmake -Wnone -unix -o Makefile agent.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_PHONON_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -O2 -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.6.1/mkspecs/linux-g++ -I. -I/usr/local/Trolltech/Qt-4.6.1/include/QtCore -I/usr/local/Trolltech/Qt-4.6.1/include/QtGui -I/usr/local/Trolltech/Qt-4.6.1/include/phonon -I/usr/local/Trolltech/Qt-4.6.1/include -I. -Ibrain -Iauv -Idashboard -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/local/Trolltech/Qt-4.6.1/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.6.1/lib -lphonon -L/usr/local/Trolltech/Qt-4.6.1/lib -L/usr/X11R6/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.6.1/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = dashboard/dashboard.cpp \
		main.cpp \
		model.cpp \
		auv/adc.cpp \
		auv/auv.cpp \
		auv/buffer.cpp \
		auv/camread.cpp \
		auv/imu.cpp \
		auv/pololu.cpp \
		auv/power.cpp \
		auv/uart.cpp \
		brain/brain.cpp \
		brain/brain_data.cpp \
		brain/rt_nonfinite.cpp \
		brain/rtGetInf.cpp \
		brain/rtGetNaN.cpp moc_dashboard.cpp \
		moc_model.cpp \
		moc_auv.cpp
OBJECTS       = dashboard.o \
		main.o \
		model.o \
		adc.o \
		auv.o \
		buffer.o \
		camread.o \
		imu.o \
		pololu.o \
		power.o \
		uart.o \
		brain.o \
		brain_data.o \
		rt_nonfinite.o \
		rtGetInf.o \
		rtGetNaN.o \
		moc_dashboard.o \
		moc_model.o \
		moc_auv.o
DIST          = /usr/local/Trolltech/Qt-4.6.1/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/include_source_dir.prf \
		agent.pro
QMAKE_TARGET  = agent
DESTDIR       = 
TARGET        = agent

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_dashboard.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: agent.pro  /usr/local/Trolltech/Qt-4.6.1/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.6.1/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/Qt-4.6.1/lib/libphonon.prl \
		/usr/local/Trolltech/Qt-4.6.1/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.6.1/lib/libQtCore.prl
	$(QMAKE) -Wnone -unix -o Makefile agent.pro
/usr/local/Trolltech/Qt-4.6.1/mkspecs/common/g++.conf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/release.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.6.1/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/Qt-4.6.1/lib/libphonon.prl:
/usr/local/Trolltech/Qt-4.6.1/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.6.1/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -Wnone -unix -o Makefile agent.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/agent1.0.0 || $(MKDIR) .tmp/agent1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/agent1.0.0/ && $(COPY_FILE) --parents dashboard/dashboard.h model.h auv/adc.h auv/auv.h auv/auvtypes.h auv/buffer.h auv/calibration.h auv/camread.h auv/imu.h auv/pololu.h auv/ports.h auv/power.h auv/uart.h brain/AudioDefs.h brain/autobuild.h brain/bio_sig.h brain/blas.h brain/blascompat32.h brain/brain.h brain/brain_private.h brain/brain_types.h brain/cg_matrx.h brain/cg_sfun.h brain/compare_fcn.h brain/dll_utils_win.h brain/dsp_blms_sim.h brain/dsp_chol_sim.h brain/dsp_dlyerr_sim.h brain/dsp_fft_common_sim.h brain/dsp_fft_sim.h brain/dsp_filterbank_sim.h brain/dsp_filtstruct_sim.h brain/dsp_flip_sim.h brain/dsp_ic_rt.h brain/dsp_interp_sim.h brain/dsp_iso_math_rt.h brain/dsp_lms_sim.h brain/dsp_offset_sim.h brain/dsp_pad_sim.h brain/dsp_randsrc_sim.h brain/dsp_rebuff_sim.h brain/dsp_rt.h brain/dsp_sqdesign.h brain/dsp_srt_sim.h brain/dsp_vqdesign.h brain/dspallpole_rt.h brain/dspavi_rt.h brain/dspbiquad_rt.h brain/dspblms_rt.h brain/dspendian_rt.h brain/dspeph_rt.h brain/dspfbsub_rt.h brain/dspfilter_rt.h brain/dspfilterbank_rt.h brain/dspfir_rt.h brain/dspfirdn_rt.h brain/dspiir_rt.h brain/dsplms_rt.h brain/dspmmutils_rt.h brain/dsppolyval_rt.h brain/dspqrdc_rt.h brain/dsprandsrc32bit_rt.h brain/dsprandsrc64bit_rt.h brain/dsprandsrc_rt.h brain/dsprebuff_rt.h brain/dspsizeof_rt.h brain/dspsrt_rt.h brain/dspsvd_rt.h brain/dspunwrap_rt.h brain/dspupfir_rt.h brain/dspvfdly2_rt.h brain/dt_info.h brain/emlrt.h brain/engine.h brain/ertformat.h brain/ext_share.h brain/ext_svr.h brain/ext_svr_transport.h brain/ext_test.h brain/ext_types.h brain/ext_work.h brain/fintrf.h brain/fixedpoint.h brain/frommmfile_ex.h brain/frommmfile_win32.h brain/fromwavedevice_ex_win32.h brain/fromwavedevice_win32.h brain/fromwavefile_ex_win32.h brain/fromwavefile_win32.h brain/HostLib_Audio.h brain/HostLib_FromMMFile.h brain/HostLib_rtw.h brain/HostLib_Video.h brain/io64.h brain/lapack.h brain/lexicmp.h brain/mat.h brain/matrix.h brain/mdl_info.h brain/mem_mgr.h brain/mex.h brain/mwdebug.h brain/mwmathutil.h brain/odesup.h brain/pt_info.h brain/rt_logging.h brain/rt_logging_mmi.h brain/rt_matrx.h brain/rt_mxclassid.h brain/rt_nonfinite.h brain/rt_sim.h brain/rtGetInf.h brain/rtGetNaN.h brain/rtiostream.h brain/rtmcmacros.h brain/rtmmacros.h brain/rtsplntypes.h brain/rtw_capi.h brain/rtw_capi_examples.h brain/rtw_continuous.h brain/rtw_extmode.h brain/rtw_matlogging.h brain/rtw_modelmap.h brain/rtw_modelmap_logging.h brain/rtw_solver.h brain/rtwtypes.h brain/sfcn_bridge.h brain/sfun_frmad_wrapper.h brain/sfun_frmdft_wrapper.h brain/sfun_frmunbuff_wrapper.h brain/SharedLibUtils.h brain/sigmapdef_sfcn.h brain/sigregdef.h brain/simstruc.h brain/simstruc_types.h brain/simulink.h brain/simulink2.h brain/sl_solver_rtw.h brain/solver_zc.h brain/sysran_types.h brain/tmwtypes.h brain/tommfile_ex.h brain/tommfile_shared.h brain/tommfile_win32.h brain/towavedevice_ex_win32.h brain/towavedevice_win32.h brain/towavefile_ex_win32.h brain/towavefile_win32.h brain/updown.h brain/updown_util.h brain/upsup_public.h brain/VideoDefs.h brain/vip_2dpad_sim.h brain/vip_fileread_sim.h brain/vip_filewrite_sim.h brain/vip_fourcclist_sim.h brain/vip_imgcomplement_sim.h brain/vip_sim.h brain/vipblob_rt.h brain/vipblockmatch_rt.h brain/vipdrawshapes_rt.h brain/vipdrawtext_rt.h brain/vipedge_rt.h brain/viphough_rt.h brain/viphoughlines_rt.h brain/vipmdnfilter_rt.h brain/vipopticalflow_rt.h brain/vipprojective_rt.h brain/viprotate_rt.h .tmp/agent1.0.0/ && $(COPY_FILE) --parents dashboard/dashboard.cpp main.cpp model.cpp auv/adc.cpp auv/auv.cpp auv/buffer.cpp auv/camread.cpp auv/imu.cpp auv/pololu.cpp auv/power.cpp auv/uart.cpp brain/brain.cpp brain/brain_data.cpp brain/rt_nonfinite.cpp brain/rtGetInf.cpp brain/rtGetNaN.cpp .tmp/agent1.0.0/ && $(COPY_FILE) --parents dashboard/dashboard.ui .tmp/agent1.0.0/ && (cd `dirname .tmp/agent1.0.0` && $(TAR) agent1.0.0.tar agent1.0.0 && $(COMPRESS) agent1.0.0.tar) && $(MOVE) `dirname .tmp/agent1.0.0`/agent1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/agent1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_dashboard.cpp moc_model.cpp moc_auv.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_dashboard.cpp moc_model.cpp moc_auv.cpp
moc_dashboard.cpp: brain/ui_dashboard.h \
		auv/auvtypes.h \
		auv/imu.h \
		auv/uart.h \
		auv/buffer.h \
		brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		auv/camread.h \
		dashboard/dashboard.h
	/usr/local/Trolltech/Qt-4.6.1/bin/moc $(DEFINES) $(INCPATH) dashboard/dashboard.h -o moc_dashboard.cpp

moc_model.cpp: auv/auvtypes.h \
		auv/imu.h \
		auv/uart.h \
		auv/buffer.h \
		auv/camread.h \
		brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		model.h
	/usr/local/Trolltech/Qt-4.6.1/bin/moc $(DEFINES) $(INCPATH) model.h -o moc_model.cpp

moc_auv.cpp: auv/auvtypes.h \
		auv/imu.h \
		auv/uart.h \
		auv/buffer.h \
		auv/ports.h \
		auv/calibration.h \
		auv/adc.h \
		auv/pololu.h \
		auv/power.h \
		brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		auv/auv.h
	/usr/local/Trolltech/Qt-4.6.1/bin/moc $(DEFINES) $(INCPATH) auv/auv.h -o moc_auv.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_dashboard.h
compiler_uic_clean:
	-$(DEL_FILE) ui_dashboard.h
ui_dashboard.h: dashboard/dashboard.ui
	/usr/local/Trolltech/Qt-4.6.1/bin/uic dashboard/dashboard.ui -o ui_dashboard.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

dashboard.o: dashboard/dashboard.cpp dashboard/dashboard.h \
		brain/ui_dashboard.h \
		auv/auvtypes.h \
		auv/imu.h \
		auv/uart.h \
		auv/buffer.h \
		brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		auv/camread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dashboard.o dashboard/dashboard.cpp

main.o: main.cpp dashboard/dashboard.h \
		brain/ui_dashboard.h \
		auv/auvtypes.h \
		auv/imu.h \
		auv/uart.h \
		auv/buffer.h \
		brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		auv/camread.h \
		auv/auv.h \
		auv/ports.h \
		auv/calibration.h \
		auv/adc.h \
		auv/pololu.h \
		auv/power.h \
		model.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

model.o: model.cpp model.h \
		auv/auvtypes.h \
		auv/imu.h \
		auv/uart.h \
		auv/buffer.h \
		auv/camread.h \
		brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		auv/calibration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o model.o model.cpp

adc.o: auv/adc.cpp auv/adc.h \
		auv/buffer.h \
		auv/uart.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o adc.o auv/adc.cpp

auv.o: auv/auv.cpp auv/auv.h \
		auv/auvtypes.h \
		auv/imu.h \
		auv/uart.h \
		auv/buffer.h \
		auv/ports.h \
		auv/calibration.h \
		auv/adc.h \
		auv/pololu.h \
		auv/power.h \
		brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o auv.o auv/auv.cpp

buffer.o: auv/buffer.cpp auv/buffer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o buffer.o auv/buffer.cpp

camread.o: auv/camread.cpp auv/camread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camread.o auv/camread.cpp

imu.o: auv/imu.cpp auv/imu.h \
		auv/uart.h \
		auv/buffer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imu.o auv/imu.cpp

pololu.o: auv/pololu.cpp auv/pololu.h \
		auv/uart.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pololu.o auv/pololu.cpp

power.o: auv/power.cpp auv/power.h \
		auv/buffer.h \
		auv/uart.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o power.o auv/power.cpp

uart.o: auv/uart.cpp auv/uart.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o uart.o auv/uart.cpp

brain.o: brain/brain.cpp brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		brain/brain_private.h \
		brain/vipmdnfilter_rt.h \
		brain/viphoughlines_rt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o brain.o brain/brain.cpp

brain_data.o: brain/brain_data.cpp brain/brain.h \
		brain/rtwtypes.h \
		brain/viphough_rt.h \
		brain/dsp_rt.h \
		brain/dsp_iso_math_rt.h \
		brain/rtGetInf.h \
		brain/rtGetNaN.h \
		brain/rt_nonfinite.h \
		brain/brain_types.h \
		brain/brain_private.h \
		brain/vipmdnfilter_rt.h \
		brain/viphoughlines_rt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o brain_data.o brain/brain_data.cpp

rt_nonfinite.o: brain/rt_nonfinite.cpp brain/rt_nonfinite.h \
		brain/rtwtypes.h \
		brain/rtGetNaN.h \
		brain/rtGetInf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rt_nonfinite.o brain/rt_nonfinite.cpp

rtGetInf.o: brain/rtGetInf.cpp brain/rtGetInf.h \
		brain/rtwtypes.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rtGetInf.o brain/rtGetInf.cpp

rtGetNaN.o: brain/rtGetNaN.cpp brain/rtGetNaN.h \
		brain/rtwtypes.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rtGetNaN.o brain/rtGetNaN.cpp

moc_dashboard.o: moc_dashboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dashboard.o moc_dashboard.cpp

moc_model.o: moc_model.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_model.o moc_model.cpp

moc_auv.o: moc_auv.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_auv.o moc_auv.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


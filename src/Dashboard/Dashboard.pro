#-------------------------------------------------
#
# Project created by QtCreator 2011-03-24T21:11:13
#
#-------------------------------------------------

QT       += core gui

TARGET = ../../Dashboard
TEMPLATE = app

INCLUDEPATH += . ../ \
               ../treemodel/ /usr/include/QtNetwork/ \

SOURCES += main.cpp\
        mainwindow.cpp ../state/treemodel/treemodel.cpp  ../state/treemodel/treeitem.cpp \
# modulehub (tmf.cpp --> vdatum.cpp ... tmfsocket.cpp --> vdatasocket.cpp)
        ../state/vdatum.cpp ../module/module.cpp ../state/vdatasocket.cpp \
# configloader
        ../misc/configloader.cpp \
# controllers
        ../controllers/controllers.cpp \
        ../controllers/src/MotionController.cpp \
        ../controllers/src/MotionController_data.cpp \
# simulink
        ../module/simulinkmodule.cpp \

HEADERS  += mainwindow.h ../state/treemodel/treemodel.h ../state/treemodel/treeitem.h ../module/modulehub.h \
# modulehub
            ../state/state.h ../state/vdatum.h ../module/module.h ../state/vdatasocket.h \
# configloader
        ../misc/configloader.h \
# controllers
        ../controllers/controllers.h \
        ../controllers/src/MotionController.h \
        ../controllers/src/MotionController_private.h \
        ../controllers/src/MotionController_types.h \
# simulink
        ../module/simulinkmodule.h \

FORMS    += mainwindow.ui

LIBS += -lQtNetwork

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
        mainwindow.cpp ../treemodel/treemodel.cpp  ../treemodel/treeitem.cpp \
# datahub
        ../tmf.cpp ../module.cpp ../server/tmfsocket.cpp \
# configloader
        ../configloader.cpp \
# controllers
        ../controllers/controllers.cpp \
        ../controllers/src/MotionController.cpp \
        ../controllers/src/MotionController_data.cpp \
# simulink
        ../simulinkmodule.cpp \

HEADERS  += mainwindow.h ../treemodel/treemodel.h ../treemodel/treeitem.h ../datahub/datahub.h \
# datahub
            ../state.h ../tmf.h ../module.h ../server/tmfsocket.h \
# configloader
        ../configloader.h \
# controllers
        ../controllers/controllers.h \
        ../controllers/src/MotionController.h \
        ../controllers/src/MotionController_private.h \
        ../controllers/src/MotionController_types.h \
# simulink
        ../simulinkmodule.h \



FORMS    += mainwindow.ui

LIBS += -lQtNetwork

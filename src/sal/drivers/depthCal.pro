TEMPLATE = app
TARGET = ./depthCal
CONFIG += debug
QT += network 
MOC_DIR = tmp
OBJECTS_DIR = tmp
UI_DIR = tmp

DEPENDPATH += . 

INCLUDEPATH += . \
		qextserialport
			
HEADERS += depthMaestro.h serialdevice.h 

SOURCES += depthMaestro.cpp main.cpp serialdevice.cpp

HEADERS += \
		qextserialport/qextserialenumerator.h \
		qextserialport/qextserialport_global.h \
		qextserialport/qextserialport.h

SOURCES += \
		qextserialport/qextserialport.cpp \
		qextserialport/posix_qextserialport.cpp \
		qextserialport/qextserialenumerator_unix.cpp 



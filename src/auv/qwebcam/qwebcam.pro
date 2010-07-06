SOURCES  = main.cpp qwebcam.cpp
HEADERS  = qwebcam.h
TARGET   = qwebcam

CONFIG -= debug
CONFIG += release

#INCLUDEPATH += /usr/local/include/opencv
#INCLUDEPATH += /usr/include/opencv

#LIBS += -lm -lcv -lhighgui -lcvaux 


unix {
        CONFIG += link_pkgconfig
        PKGCONFIG += opencv
}

win32 {
        LIBS += cv.lib highgui.lib cvaux.lib cxcore.lib
}


TEMPLATE = app
TARGET = dashboard
CONFIG += qt gui # static
static { // Everything below takes effect with CONFIG += static
    QTPLUGIN += qpng qjpeg
    DEFINES += STATIC // Equivalent to "#define STATIC" in source code
    message("Static build.")
}
QT += network # phonon 
STYLE += gtk
DEPENDPATH += . \
	      ..
INCLUDEPATH += . \
	       .. \
#	       /usr/include/qwt-qt4 \
	       /usr/include/qwt
LIBS += -lqwt
#LIBS += -lqwt-qt4
# Input
HEADERS += dashboard.h \
	../src/tmf.h \
	../src/server/tmfsocket.h \
	videosocket.h \
	videowidget.h \
	../src/version.h \
	../src/configloader.h \
	parametereditor/doubleeditor.h \
	parametereditor/paramedit.h \
	parametereditor/treeitem.h \
	parametereditor/treemodel.h
FORMS += dashboard.ui \
	paths.ui
SOURCES += dashboard.cpp \
	../src/tmf.cpp \
	../src/server/tmfsocket.cpp \
	main.cpp \
	videosocket.cpp \
	../src/version.cpp \
	../src/configloader.cpp \
	parametereditor/doubleeditor.cpp \
	parametereditor/paramedit.cpp \
	parametereditor/treeitem.cpp \
	parametereditor/treemodel.cpp

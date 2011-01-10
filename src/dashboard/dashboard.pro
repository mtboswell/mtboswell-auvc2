TEMPLATE = app
TARGET = ../../dashboard
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
	       /usr/include/qt4 \
	       /usr/include/qwt-qt4
# for Ubuntu
# for Arch
#	       /usr/include/qwt
# for Arch
#LIBS += -lqwt
# for Ubuntu
LIBS += -lqwt-qt4
# Input
HEADERS += dashboard.h \
	../tmf.h \
	../server/tmfsocket.h \
	videosocket.h \
	videowidget.h \
	../version.h \
	../configloader.h \
	parametereditor/doubleeditor.h \
	parametereditor/paramedit.h \
	parametereditor/treeitem.h \
	parametereditor/treemodel.h
FORMS += dashboard.ui \
	paths.ui
SOURCES += dashboard.cpp \
	../tmf.cpp \
	../server/tmfsocket.cpp \
	main.cpp \
	videosocket.cpp \
	../version.cpp \
	../configloader.cpp \
	parametereditor/doubleeditor.cpp \
	parametereditor/paramedit.cpp \
	parametereditor/treeitem.cpp \
	parametereditor/treemodel.cpp

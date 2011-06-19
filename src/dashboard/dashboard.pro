TEMPLATE = app
TARGET = ../../dashboard
CONFIG += qt \
    gui \
    debug \
    warn_off # static
static { 
    // Everything below takes effect with CONFIG += static
    QTPLUGIN += qpng \
        qjpeg
    DEFINES += STATIC \
        // \
        Equivalent \
        to \
        " # define STATIC" in source code
    message("Static build.")
}
QT += network # phonon
STYLE += gtk
MOC_DIR = tmp
OBJECTS_DIR = tmp
UI_DIR = tmp
DEPENDPATH += . \
    ..
INCLUDEPATH += . \
    .. \
    /usr/include/qt4 \ # for Ubuntu:
    /usr/include/qwt-qt4

# for Arch:
# /usr/include/qwt
# for Ubuntu:
LIBS += -lqwt-qt4 -lSDL

# for Arch:
# LIBS += -lqwt
# Input
HEADERS += dashboard.h \
    ../state/vdatum.h \
    ../state/treemodel/treemodel.h \
    ../state/treemodel/treeitem.h \
    ../state/vdatasocket.h \
    ../module/module.h \
    ../module/modulehub.h \
    ../module/simulinkmodule.h \
    videosocket.h \
    videowidget.h \
    ../misc/version.h \
    ../misc/configloader.h \
    parametereditor/doubleeditor.h \
    joystick/joystick.h
FORMS += dashboard.ui \
    paths.ui
SOURCES += dashboard.cpp \
    ../state/vdatum.cpp \
    ../state/treemodel/treemodel.cpp \
    ../state/treemodel/treeitem.cpp \
    ../state/vdatasocket.cpp \
    ../module/module.cpp \
    ../module/modulehub.cpp \
    ../module/simulinkmodule.cpp \
    main.cpp \
    videosocket.cpp \
    ../misc/version.cpp \
    ../misc/configloader.cpp \
    parametereditor/doubleeditor.h \
    joystick/joystick.cpp

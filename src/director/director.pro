#-------------------------------------------------
#
# Project created by QtCreator 2011-04-08T18:41:44
#
#-------------------------------------------------

QT       += core network

LIBS    +=  -llua
#QT       -= gui

TARGET = ../../director
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += \
    director.h TransitionComparator.h lua/QueryLua.h \
    ../module/module.h ../state/treemodel/treemodel.h ../state/treemodel/treeitem.h ../misc/configloader.h \

SOURCES += \
    main.cpp director.cpp lua/QueryLua.cpp \
    ../module/module.cpp ../state/treemodel/treemodel.cpp ../state/treemodel/treeitem.cpp ../misc/configloader.cpp \

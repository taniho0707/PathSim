######################################################################
# Automatically generated by qmake (2.01a) ? 11? 27 19:05:44 2015
######################################################################

TEMPLATE = app
# TARGET = 
DEPENDPATH += .
INCLUDEPATH += . libmouse libpath
LIBS += -Llibmouse
LIBS += libmouse/libmouse_x86.so -ldl
CONFIG += c++14
QMAKE_LFLAGS += -Wl,-E
QMAKE_CXXFLAGS += -std=c++14
QT += qml quick widgets network gui

# Input
HEADERS += SimManage.h MazeField.h ParseHmaze.h PathField.h
SOURCES += main.cpp SimManage.cpp MazeField.cpp ParseHmaze.cpp PathField.cpp

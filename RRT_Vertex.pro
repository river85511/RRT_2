#-------------------------------------------------
#
# Project created by QtCreator 2016-09-15T00:13:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RRT_Vertex
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    simviewer.cpp \
    arrow.cpp \
    vertex.cpp \
    state.cpp \
    rrt.cpp

HEADERS  += mainwindow.h \
    simviewer.h \
    arrow.h \
    vertex.h \
    state.h \
    rrt.h

FORMS    += mainwindow.ui


INCLUDEPATH += -/usr/include/opencv
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lopencv_core -lopencv_imgproc -lopencv_highgui

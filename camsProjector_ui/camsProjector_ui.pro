#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T16:40:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#LIBS = -L../../lib -lflycapture${D} -ldl -lm `pkg-config --libs --cflags opencv`
#LIBS = -L../../lib -lflycapture${D}

TARGET = camsProjector_ui
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    stdafx.cpp

HEADERS  += mainwindow.h \
    resource.h \
    stdafx.h

FORMS    += mainwindow.ui

unix:!macx: LIBS += -L/usr/lib/ -lflycapture

INCLUDEPATH += /usr/include/flycapture
DEPENDPATH += /usr/include/flycapture

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv

DISTFILES +=

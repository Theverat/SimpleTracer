#-------------------------------------------------
#
# Project created by QtCreator 2012-05-05T12:41:21
#
#-------------------------------------------------

QT       += core gui

TARGET = SimpleTracer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp \
    sphere.cpp \
    raytracer.cpp

HEADERS  += mainwindow.h \
    ray.h \
    camera.h \
    sphere.h \
    geometry.h \
    raytracer.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2012-05-05T12:41:21
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleTracer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp \
    sphere.cpp \
    raytracer.cpp \
    object.cpp \
    material.cpp \
    triangle.cpp \
    plane.cpp \
    world.cpp \
    abs.cpp \
    light.cpp \
    integrator.cpp \
    pathtracer.cpp \
    rgbiimage.cpp \
    worldloader.cpp \
    film.cpp

HEADERS  += mainwindow.h \
    ray.h \
    camera.h \
    sphere.h \
    geometry.h \
    raytracer.h \
    object.h \
    material.h \
    triangle.h \
    plane.h \
    world.h \
    light.h \
    predefs.h \
    integrator.h \
    pathtracer.h \
    rgbiimage.h \
    worldloader.h \
    film.h

FORMS    += mainwindow.ui


LIBS += -fopenmp

QMAKE_CXXFLAGS += -fopenmp

CONFIG += gui

#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T20:56:01
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hw4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamebored.cpp \
    myrect.cpp \
    projectile.cpp \
    enemy.cpp \
    enemy2.cpp \
    score.cpp

HEADERS  += mainwindow.h \
    gamebored.h \
    myrect.h \
    projectile.h \
    enemy.h \
    enemy2.h \
    score.h

FORMS    += mainwindow.ui \
    gamebored.ui

DISTFILES +=

RESOURCES += \
    res.qrc

CONFIG += resources_big

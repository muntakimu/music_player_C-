#-------------------------------------------------
#Author: Muntakimur Rahaman
# Project created by QtCreator 2017-10-27T18:42:07
#
#-------------------------------------------------

QT       += core gui
QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newPlayer
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

RESOURCES += \
    icon.qrc

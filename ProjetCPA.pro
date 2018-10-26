#-------------------------------------------------
#
# Project created by QtCreator 2018-10-19T14:37:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetCPA
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    game.cpp \
    player.cpp \
    gameobject.cpp \
    mainwindow.cpp \
    map.cpp \
    terrain.cpp \
    plain.cpp \
    mountain.cpp \
    wood.cpp \
    river.cpp \
    road.cpp \
    bridge.cpp \
    sea.cpp \
    shoal.cpp \
    reef.cpp \
    building.cpp \
    city.cpp \
    factory.cpp \
    airport.cpp \
    unit.cpp \
    gamewindow.cpp \
    airunit.cpp \
    bomber.cpp \
    fighter.cpp \
    infantery.cpp \
    bazooka.cpp \
    recon.cpp \
    antiair.cpp \
    tank.cpp \
    mdtank.cpp \
    megatank.cpp \
    neotank.cpp

HEADERS += \
    game.h \
    player.h \
    gameobject.h \
    mainwindow.h \
    map.h \
    terrain.h \
    plain.h \
    mountain.h \
    wood.h \
    river.h \
    road.h \
    bridge.h \
    sea.h \
    shoal.h \
    reef.h \
    building.h \
    city.h \
    factory.h \
    airport.h \
    unit.h \
    gamewindow.h \
    airunit.h \
    bomber.h \
    fighter.h \
    infantery.h \
    bazooka.h \
    recon.h \
    antiair.h \
    tank.h \
    mdtank.h \
    megatank.h \
    neotank.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

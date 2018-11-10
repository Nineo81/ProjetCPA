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
    neotank.cpp \
    b_copter.cpp \
    cursor.cpp

HEADERS += \
    game.h \
    player.h \
    gameobject.h \
    mainwindow.h \
    map.h \
    terrain.h \
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
    neotank.h \
    b_copter.h \
    cursor.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Map1V1 \
    Map1V1.txt \
    1.png \
    2.png \
    3.png \
    4.png \
    5.png \
    6.png \
    7.png \
    8.png \
    9.png \
    10.png \
    11.png \
    12.png \
    13.png \
    14.png \
    15.png \
    16.png \
    17.png \
    18.png \
    19.png \
    20.png \
    21.png \
    22.png \
    23.png \
    24.png \
    25.png \
    26.png \
    27.png \
    28.png \
    29.png \
    30.png \
    31.png \
    32.png \
    33.png \
    34.png \
    35.png \
    36.png \
    38.png \
    39.png \
    40.png \
    43.png \
    44.png \
    45.png \
    101.png \
    102.png \
    103.png \
    104.png \
    105.png \
    106.png \
    107.png \
    108.png \
    109.png \
    110.png \
    113.png \
    114.png \
    115.png \
    116.png

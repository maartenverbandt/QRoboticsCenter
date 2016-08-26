#-------------------------------------------------
#
# Project created by QtCreator 2016-08-07T19:57:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRoboticsCenter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qrobotcoordinator.cpp \
    qbalancingrobot.cpp \
    qrobot.cpp \
    qballbot.cpp \
    qsegbot.cpp \
    qcircularlayout.cpp \
    qprintstitcher.cpp \
    qabstractrecorder.cpp \
    qgpiorecorder.cpp \
    qbalancingwidget.cpp \
    ballbotconfigdialog.cpp \
    qrecorderwidget.cpp

HEADERS  += mainwindow.h \
    qrobotcoordinator.h \
    qbalancingrobot.h \
    qrobot.h \
    qballbot.h \
    qsegbot.h \
    qcircularlayout.h \
    qprintstitcher.h \
    qabstractrecorder.h \
    qgpiorecorder.h \
    qbalancingwidget.h \
    ballbotconfigdialog.h \
    qrecorderwidget.h

FORMS    += mainwindow.ui \
    qbalancingwidget.ui

include(../../QtModules/QMavlinkConnection/src/qmavlinkconnection.pri)
include(../../QtModules/QGPIOWidget/src/qgpiowidget.pri)
include(../../QtModules/QRobotConfigDialog/src/qrobotconfigdialog.pri)

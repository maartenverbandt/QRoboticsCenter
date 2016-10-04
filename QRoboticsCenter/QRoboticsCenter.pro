#-------------------------------------------------
#
# Project created by QtCreator 2016-08-07T19:57:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRoboticsCenter
TEMPLATE = app

INCLUDEPATH += $$PWD #\
               #mavlink
#/ballbot_messagesavr/mavlink.h

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
    qrecorderwidget.cpp \
    qrobotbutton.cpp \
    qaboutdialog.cpp

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
    qrecorderwidget.h \
    qrobotbutton.h \
    qaboutdialog.h

FORMS    += mainwindow.ui \
    qbalancingwidget.ui \
    qaboutdialog.ui

RESOURCES += \
    icons.qrc

include(../../QtModules/QMavlinkConnection/src/qmavlinkconnection.pri)
include(../../QtModules/QGPIOWidget/src/qgpiowidget.pri)
include(../../QtModules/QRobotConfigDialog/src/qrobotconfigdialog.pri)
include(../../QtModules/QPolarPlot/src/qpolarplot.pri)
include(../../QtModules/QMapWidget/src/qmapwidget.pri)



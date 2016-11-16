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
    qcircularlayout.cpp \
    qprintstitcher.cpp \
    qbalancingwidget.cpp \
    ballbotconfigdialog.cpp \
    qrobotbutton.cpp \
    qaboutdialog.cpp \
    qexternalportdialog.cpp \
    qfileport.cpp \
    qattitudefileport.cpp \
    qexcitationdialog.cpp \
    qrobotrecordermanager.cpp \
    qbalancingrecordermanager.cpp \
    qabstractrobot.cpp \
    qrobotconnectionmanager.cpp \
    qrobotwindow.cpp \
    qbalancingwindow.cpp \
    qcar.cpp \
    qbalancingrobot.cpp \
    qbalancingconnectionmanager.cpp \
    qballbot.cpp \
    qstackedwindow.cpp \
    qrobotlog.cpp \
    qrobotconfig.cpp

HEADERS  += mainwindow.h \
    qrobotcoordinator.h \
    qsegbot.h \
    qcircularlayout.h \
    qprintstitcher.h \
    qbalancingwidget.h \
    ballbotconfigdialog.h \
    qrobotbutton.h \
    qaboutdialog.h \
    qexternalportdialog.h \
    qfileport.h \
    qattitudefileport.h \
    qexcitationdialog.h \
    qrobotrecordermanager.h \
    qbalancingrecordermanager.h \
    qabstractrobot.h \
    qrobotconnectionmanager.h \
    qrobotwindow.h \
    qbalancingwindow.h \
    #qbalancingrobot_old.h \
    #qballbot_old.h \
    #qrobot_old.h \
    qcar.h \
    qbalancingrobot.h \
    qbalancingconnectionmanager.h \
    qballbot.h \
    qstackedwindow.h \
    qrobotlog.h \
    qrobotconfig.h

FORMS    += mainwindow.ui \
    qbalancingwidget.ui \
    qaboutdialog.ui \
    qfileport.ui \
    qexcitationdialog.ui

RESOURCES += \
    icons.qrc

include(../../QtModules/QMavlinkConnection/src/qmavlinkconnection.pri)
include(../../QtModules/QGPIOWidget/src/qgpiowidget.pri)
include(../../QtModules/QRobotConfigDialog/src/qrobotconfigdialog.pri)
include(../../QtModules/QPolarPlot/src/qpolarplot.pri)
include(../../QtModules/QMapWidget/src/qmapwidget.pri)
include(../../QtModules/QControllerDevice/src/qcontrollerdevice.pri)
include(../../QtModules/QRecorder/src/qrecorder.pri)

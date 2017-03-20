#-------------------------------------------------
#
# Project created by QtCreator 2016-08-07T19:57:06
#
#-------------------------------------------------

QT       += core gui gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRoboticsCenter
TEMPLATE = app

INCLUDEPATH +=  $$PWD \
                BasicRobot \
                BalancingRobot \
               #mavlink
#/ballbot_messagesavr/mavlink.h

SOURCES += main.cpp\
        mainwindow.cpp \
        qprintstitcher.cpp \
        qaboutdialog.cpp \
        qexcitationdialog.cpp \
        BasicRobot/qrobotrecordermanager.cpp \
        BasicRobot/qrobotcoordinator.cpp \
        BasicRobot/qstackedwindow.cpp \
        BasicRobot/qrobotlog.cpp \
        BasicRobot/qrobotconfig.cpp \
        BasicRobot/qabstractrobot.cpp \
        BasicRobot/qrobotconnectionmanager.cpp \
        BasicRobot/qrobotwindow.cpp \
        BasicRobot/qrobotbutton.cpp  \
        BasicRobot/qunknownrobot.cpp \
        BasicRobot/qbasicrobot.cpp \
        BasicRobot/qcar.cpp \
        BasicRobot/qrobotcommandmanager.cpp \
        BalancingRobot/qbalancingwidget.cpp \
        BalancingRobot/ballbotconfigdialog.cpp \
        BalancingRobot/qbalancingrecordermanager.cpp \
        BalancingRobot/qbalancingwindow.cpp \
        BalancingRobot/qbalancingrobot.cpp \
        BalancingRobot/qbalancingconnectionmanager.cpp \
        BalancingRobot/qballbot.cpp \
        BalancingRobot/qballbotinput.cpp \
        BalancingRobot/qtiltingtable.cpp \
        BalancingRobot/qbalancingcommandmanager.cpp

HEADERS  += mainwindow.h \
        qprintstitcher.h \
        qaboutdialog.h \
        qexcitationdialog.h \
        BasicRobot/qrobotrecordermanager.h \
        BasicRobot/qrobotbutton.h \
        BasicRobot/qabstractrobot.h \
        BasicRobot/qrobotconnectionmanager.h \
        BasicRobot/qrobotwindow.h \
        BasicRobot/qrobotcoordinator.h \
        BasicRobot/qstackedwindow.h \
        BasicRobot/qrobotlog.h \
        BasicRobot/qrobotconfig.h \
        BasicRobot/qunknownrobot.h \
        BasicRobot/qbasicrobot.h \
        BasicRobot/qcar.h\
        BasicRobot/qrobotcommandmanager.h \
        BalancingRobot/qbalancingrecordermanager.h \
        BalancingRobot/qbalancingwindow.h \
        BalancingRobot/qbalancingrobot.h \
        BalancingRobot/qbalancingconnectionmanager.h \
        BalancingRobot/qballbot.h \
        BalancingRobot/qbalancingwidget.h \
        BalancingRobot/ballbotconfigdialog.h \
        BalancingRobot/qballbotinput.h \
        BalancingRobot/qtiltingtable.h \
        BalancingRobot/qbalancingcommandmanager.h \
        qrobotevents.h

FORMS   += mainwindow.ui \
        qaboutdialog.ui \
        qexcitationdialog.ui \
        BalancingRobot/qbalancingwidget.ui

RESOURCES += \
    icons.qrc

include(../../QtModules/QMavlinkConnection/src/qmavlinkconnection.pri)
include(../../QtModules/QGPIOWidget/src/qgpiowidget.pri)
include(../../QtModules/QRobotConfigDialog/src/qrobotconfigdialog.pri)
include(../../QtModules/QPolarPlot/src/qpolarplot.pri)
include(../../QtModules/QMapWidget/src/qmapwidget.pri)
include(../../QtModules/QControllerDevice/src/qcontrollerdevice.pri)
include(../../QtModules/QRecorder/src/qrecorder.pri)
include(../../QtModules/QExternalPort/src/qexternalport.pri)

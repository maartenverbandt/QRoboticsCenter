#include "qrobotlog.h"

QRobotLog::QRobotLog(QObject *parent) : QObject(parent)
{

}

void QRobotLog::open(QAbstractRobot* robot)
{
    _robot_log = new QFile(QDir::tempPath() + QDir::separator() + robot->getName() + ".txt",this);
        if(!_robot_log->open(QIODevice::WriteOnly | QIODevice::Text))
            qDebug() << "Error opening robot log file";
    QObject::connect(robot->getConnectionManager(),&QRobotConnectionManager::printReceived,this,&QRobotLog::write);
}

void QRobotLog::write(QString line)
{
    _robot_log->write(_stitcher->getLine().toLatin1());
    _robot_log->flush(); //force a quick update
}

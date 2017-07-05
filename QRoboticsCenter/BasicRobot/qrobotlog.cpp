#include "qrobotlog.h"

QRobotLog::QRobotLog(QObject *parent) : QObject(parent)
{

}

void QRobotLog::open(QString robot)
{
    _robot_log = new QFile(QDir::tempPath() + QDir::separator() + robot + ".txt",this);
    if(!_robot_log->open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Error opening robot log file";
}

void QRobotLog::write(QString line)
{
    _robot_log->write(line.toLatin1());
    _robot_log->flush(); //force a quick update
}

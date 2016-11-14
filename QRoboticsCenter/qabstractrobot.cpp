#include "qabstractrobot.h"

QAbstractRobot::QAbstractRobot(int id, QObject *parent) :
    QObject(parent),
    _id(id),
    _log(new QRobotLog(this))
{

}

int QAbstractRobot::id()
{
    return _id;
}

QString QAbstractRobot::getName()
{
    return getType() + QString::number(id());
}

QRobotLog *QAbstractRobot::getLog()
{
    return _log;
}

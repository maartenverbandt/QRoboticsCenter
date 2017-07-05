#include "qabstractrobot.h"

QAbstractRobot::QAbstractRobot(int id, QObject *parent) :
    QObject(parent),
    _id(id),
    _log(new QRobotLog(this))
{

}

void QAbstractRobot::setup()
{
    //setup robot log
    _log->open(getName());
    QObject::connect(getConnectionManager(),&QRobotConnectionManager::printReceived,_log,&QRobotLog::write);
    //setup window
    getWindow()->setWindowTitle(getName());
    getWindow()->setWindowIcon(getIcon());
    //restore state
    restoreState();
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

void QAbstractRobot::saveState()
{
    getWindow()->saveState(getName());
}

void QAbstractRobot::restoreState()
{
    getWindow()->restoreState(getName());
}

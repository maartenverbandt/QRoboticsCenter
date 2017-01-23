#include "qunknownrobot.h"

QUnknownRobot::QUnknownRobot(int id, QObject *parent) :
    QBasicRobot(id,parent)
{
    //do nothing
}

QString QUnknownRobot::getType()
{
    return "unknown";
}

QIcon QUnknownRobot::getIcon()
{
    return QIcon(":/icons/unknown.png");
}

#include "qballbot.h"

QBallbot::QBallbot(int id, QObject *parent) :
    QBalancingRobot(id,parent)
{

}

QString QBallbot::getType()
{
    return "Ballbot";
}

QIcon QBallbot::getIcon()
{
    return QIcon(":/icons/ballbot.png");
}

#include "qcar.h"

QCar::QCar(int id, QObject *parent) :
    QBasicRobot(id,parent)
{
    // do nothing
}

QString QCar::getType()
{
    return "car";
}

QIcon QCar::getIcon()
{
    return QIcon(":/icons/car.png");
}

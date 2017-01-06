#include "qcar.h"

QCar::QCar(int id, QObject *parent) :
    QBasicRobot(id,parent)
{
    setup();
}

QString QCar::getType()
{
    return "car";
}

QIcon QCar::getIcon()
{
    return QIcon(":/icons/car.png");
}

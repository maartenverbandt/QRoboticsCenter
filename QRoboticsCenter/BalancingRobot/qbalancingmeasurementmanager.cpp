#include "qbalancingmeasurementmanager.h"

QBalancingMeasurementManager::QBalancingMeasurementManager(QObject *parent) :
    QRobotMeasurementManager(parent)
{
    _udp->addPort(new QPoseUdpWriter(_udp));
    _udp->addPort(new QAttitudeUdpWriter(_udp));
}

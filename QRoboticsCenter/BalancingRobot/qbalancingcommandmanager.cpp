#include "qbalancingcommandmanager.h"

QBalancingCommandManager::QBalancingCommandManager(QObject *parent) :
    QRobotCommandManager(parent)
{
    //_csv->addPort(new QVelocityCmdCsvReader(_csv));
    _csv->addPort(new QPositionCmdCsvReader(_csv));
    //udp->addPort(new QVelocityCmdUdpReader(udp));
    _udp->addPort(new QPositionCmdUdpReader(_udp));
}

void QBalancingCommandManager::connect(QRobotConnectionManager *c)
{
    QObject::connect(this,&QBalancingCommandManager::commands,c,&QRobotConnectionManager::packetsSend);
}

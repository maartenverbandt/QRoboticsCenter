#include "qrobotmeasurementmanager.h"

QRobotMeasurementManager::QRobotMeasurementManager(QObject *parent) :
    QOutputDialog("Measurements",0),
    _udp(new QOutputWidget("UDP",this))
{
    addOutputWidget(_udp);
    _udp->addSender(new QGpioUdpSender(_udp));
}

void QRobotMeasurementManager::setupMainWindow(QMainWindow *m)
{
    m->menuBar()->addAction(getPopupAction());
}

void QRobotMeasurementManager::connect(QRobotConnectionManager *c)
{
    QObject::connect(c,&QRobotConnectionManager::packetReceived,this,&QRobotMeasurementManager::sendPacket);
}

QOutputWidget *QRobotMeasurementManager::getUdpOutputWidget()
{
    return _udp;
}

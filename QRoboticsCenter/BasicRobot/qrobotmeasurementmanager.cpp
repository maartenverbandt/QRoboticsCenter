#include "qrobotmeasurementmanager.h"

QRobotMeasurementManager::QRobotMeasurementManager(QObject *) :
    QMeasurementPortDialog("Measurements",0),
    _udp(new QOutputWidget("UDP",this))
{
    addOutputWidget(_udp);
    _udp->addPort(new QGpioUdpWriter(_udp));
}

void QRobotMeasurementManager::setupMainWindow(QMainWindow *m)
{
    m->menuBar()->addAction(getPopupAction());
}

void QRobotMeasurementManager::connect(QRobotConnectionManager *c)
{
    QObject::connect(c,&QRobotConnectionManager::packetReceived,this,&QRobotMeasurementManager::measurement);
}

QOutputWidget *QRobotMeasurementManager::getUdpOutputWidget()
{
    return _udp;
}

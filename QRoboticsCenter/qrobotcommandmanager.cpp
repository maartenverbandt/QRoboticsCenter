#include "qrobotcommandmanager.h"

QRobotCommandManager::QRobotCommandManager(QObject *parent) :
    QExternalPortDialog("Commands",0),
    _csv(new QInputWidget("CSV",this)),
    _udp(new QInputWidget("UDP",this))
{
    addInputWidget(_csv);
    addInputWidget(_udp);
    _csv->addPort(new QGpioCsvReader(_csv));
    _udp->addPort(new QGpioUdpReader(_udp));
}

void QRobotCommandManager::setupMainWindow(QMainWindow *m)
{
    m->menuBar()->addAction(getPopupAction());
}

void QRobotCommandManager::connect(QRobotConnectionManager *c)
{

    QObject::connect(this,&QRobotCommandManager::commands,c,&QRobotConnectionManager::packetsSend);}

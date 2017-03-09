#include "qrobotportmanager.h"

QRobotPortManager::QRobotPortManager(QObject *parent) :
    QObject(parent),
    _gpio(new QGPIOPortDialog(0)),
    _menu(new QMenu("Interfaces"))
{
    addPort(_gpio);
}

void QRobotPortManager::connect(QRobotConnectionManager *m)
{
    QObject::connect(_gpio,SIGNAL(gpioPacket(mavlink_gpio_t)),m,SLOT(gpioMsgSend(mavlink_gpio_t)));
}

QMenu *QRobotPortManager::menu()
{
    return _menu;
}

void QRobotPortManager::addPort(QExternalPortDialog *p)
{
    _menu->addAction(p->getPopupAction());
}

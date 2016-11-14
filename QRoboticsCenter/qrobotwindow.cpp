#include "qrobotwindow.h"

QRobotWindow::QRobotWindow(QWidget *parent) :
    _gpio(new QGPIOWidget())
{
    addView(_gpio);   
}

QGPIOWidget *QRobotWindow::getGPIOWidget()
{
    return _gpio;
}

void QRobotWindow::connect(QRobotConnectionManager *c)
{
    QObject::connect(this,&QRobotWindow::eventMsgSend,c,&QRobotConnectionManager::eventMsgSend);
    QObject::connect(c,&QRobotConnectionManager::gpioMsgReceived,_gpio,&QGPIOWidget::setInput);
    QObject::connect(c,SIGNAL(printReceived(QString)),this->statusBar(),SLOT(showMessage(QString)));
}

void QRobotWindow::setupGPIOWidget()
{
    QObject::connect(_gpio,&QGPIOWidget::eventButtonPressed,this,&QRobotWindow::eventButtonPressed);
}

void QRobotWindow::sendEvent(int id)
{
    mavlink_event_t event;
    event.type = id;
    emit eventMsgSend(event);
}

void QRobotWindow::eventButtonPressed(int id)
{
    mavlink_event_t event;
    event.type = id + 1000;
    emit eventMsgSend(event);
}

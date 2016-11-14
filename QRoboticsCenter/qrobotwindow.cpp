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
}

void QRobotWindow::setupGPIOWidget()
{
    QObject::connect(_gpio,&QGPIOWidget::eventButtonPressed,this,&QRobotWindow::eventButtonPressed);

    //QObject::connect(_gpio,SIGNAL(eventButtonPressed(int)),this,SLOT(eventButtonPressed(int)));
    //QObject::connect(_gpio,SIGNAL(setOutput(QGPIOWidget::gpio_t)),this,SLOT(setGpioOutput(QGPIOWidget::gpio_t)));

    //add recorder
    /*
    QGPIORecorder* gpiorec = new QGPIORecorder(this);
    QObject::connect(this,SIGNAL(gpioReceived(QGPIOWidget::gpio_t)),gpiorec,SLOT(gpioReceived(QGPIOWidget::gpio_t)));

    addRecorder(gpiorec);
    _gpiowidget->inputLabelsSend();*/

    //add view
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

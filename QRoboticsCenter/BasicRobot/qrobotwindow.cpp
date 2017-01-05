#include "qrobotwindow.h"

QRobotWindow::QRobotWindow(QWidget *parent) :
    _gpio(new QGPIOWidget()),
    _threading(new QThreadingDialog(parent))
{
    addView(_gpio);
    // Setup threading
    QObject::connect(_gpio,&QGPIOWidget::eventButtonPressed,this,&QRobotWindow::eventButtonPressed);
    QMenu* analyze = menuBar()->addMenu("Analyze");
    analyze->addAction(_threading->getPopupAction());
}

QGPIOWidget *QRobotWindow::getGPIOWidget()
{
    return _gpio;
}

QThreadingDialog *QRobotWindow::getThreadingDialog()
{
    return _threading;
}

void QRobotWindow::connect(QRobotConnectionManager *c)
{
    QObject::connect(this,&QRobotWindow::eventMsgSend,c,&QRobotConnectionManager::eventMsgSend);
    QObject::connect(c,&QRobotConnectionManager::gpioMsgReceived,_gpio,&QGPIOWidget::setInput);
    QObject::connect(c,SIGNAL(printReceived(QString)),this->statusBar(),SLOT(showMessage(QString)));
    QObject::connect(c,&QRobotConnectionManager::threadinfoMsgReceived,_threading,&QThreadingDialog::threadInfoMsgReceived);
}

void QRobotWindow::sendEvent(int id)
{
    mavlink_event_t event;
    event.type = id;
    emit eventMsgSend(event);
}

void QRobotWindow::eventButtonPressed(int id)
{
    sendEvent(id + 1000);
}

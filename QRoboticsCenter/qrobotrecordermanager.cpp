#include "qrobotrecordermanager.h"

QRobotRecorderManager::QRobotRecorderManager(QGPIOWidget *gpio, QObject *parent) :
    QObject(parent),
    _gpio(new QGPIORecorder(gpio,this)),
    _widget(new QRecorderWidget(0)),
    _menu(new QMenu("Recorders",0)),
    _quick_record(new QAction("Quick record",this))
{
    setupGpioRecorder();
    setupQuickRecord();
}

void QRobotRecorderManager::setupMainWindow(QMainWindow *m)
{
    m->addAction(_quick_record);
    m->menuBar()->addMenu(_menu);
    m->statusBar()->addPermanentWidget(_widget);
}

void QRobotRecorderManager::connect(QRobotConnectionManager *c)
{
    QObject::connect(this,&QRobotRecorderManager::eventMsgSend,c,&QRobotConnectionManager::eventMsgSend);
    QObject::connect(c,&QRobotConnectionManager::gpioReceived,_gpio,&QGPIORecorder::gpioReceived);
}

QRecorderWidget *QRobotRecorderManager::getRecorderWidget()
{
    return _widget;
}

QGPIORecorder *QRobotRecorderManager::getGPIORecorder()
{
    return _gpio;
}

QMenu *QRobotRecorderManager::getMenu()
{
    return _menu;
}

QAction *QRobotRecorderManager::getQuickRecord()
{
    return _quick_record;
}

int QRobotRecorderManager::addRecorder(QAbstractRecorder *recorder)
{
    //_recorders.append(recorder);
    _menu->addAction(recorder->recorder());
    QObject::connect(recorder,SIGNAL(started()),_widget,SLOT(start()));
    QObject::connect(recorder,SIGNAL(stopped()),_widget,SLOT(stop()));
}

void QRobotRecorderManager::sendEvent(int id)
{
    mavlink_event_t event;
    event.type = id;
    emit eventMsgSend(event);
}

void QRobotRecorderManager::setupGpioRecorder()
{
    QObject::connect(_gpio,&QGPIORecorder::started,this,&QRobotRecorderManager::requestGpioRecording);
    addRecorder(_gpio);
}

void QRobotRecorderManager::setupQuickRecord()
{
    _quick_record->setCheckable(true);
    _quick_record->setChecked(false);
    _quick_record->setShortcut(Qt::CTRL + Qt::Key_R);
    connect(_quick_record,&QAction::toggled,this,&QRobotRecorderManager::quickRecord);
}

void QRobotRecorderManager::requestStartRecording(int id)
{
    sendEvent(id); //set right message
    sendEvent(LOG_START); // start logging
}

void QRobotRecorderManager::requestStopRecording()
{
    sendEvent(LOG_STOP); //stop logging
}

void QRobotRecorderManager::requestGpioRecording()
{
    requestStartRecording(LOG_GPIO);
}

void QRobotRecorderManager::quickRecord(bool checked)
{
    _gpio->recorder()->setChecked(checked);
}

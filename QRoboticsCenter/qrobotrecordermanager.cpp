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
    //QObject::connect(recorder,SIGNAL(started()),this,SLOT(requestStartRecording()));
    QObject::connect(recorder,SIGNAL(stopped()),_widget,SLOT(stop()));
    //QObject::connect(recorder,SIGNAL(stopped()),this,SLOT(requestStopLogging()));
}

void QRobotRecorderManager::sendEvent(int id)
{
    mavlink_event_t event;
    event.type = id;
    emit eventMsgSend(event);
}

void QRobotRecorderManager::setupGpioRecorder()
{
    //QObject::connect(this,SIGNAL(gpioReceived(QGPIOWidget::gpio_t)),_gpio,SLOT(gpioReceived(QGPIOWidget::gpio_t)));
    QObject::connect(_gpio,&QGPIORecorder::started,this,&QRobotRecorderManager::requestGpioRecording);
    //QObject::connect(_gpiowidget,SIGNAL(inputLabelsSet(QStringList)),_gpio,SLOT(setLabels(QStringList)));
    addRecorder(_gpio);

    //FIX
    //_gpiowidget->inputLabelsSend();
}

void QRobotRecorderManager::setupQuickRecord()
{
    _quick_record->setCheckable(true);
    _quick_record->setChecked(false);
    _quick_record->setShortcut(Qt::CTRL + Qt::Key_R);
    connect(_quick_record,&QAction::toggled,this,&QRobotRecorderManager::quickRecord);
}

void QRobotRecorderManager::receiveMessage(mavlink_message_t msg)
{
    if(msg.msgid == MAVLINK_MSG_ID_GPIO){
        mavlink_gpio_t gpio;
        mavlink_msg_gpio_decode(&msg, &gpio);

        // put info on the socket
        /*QGPIOWidget::gpio_t gpio_;
        memcpy(gpio_.floats,gpio.gpio_float,32); //copy 8*4=32 bytes
        memcpy(gpio_.ints,gpio.gpio_int,16); //copy 4*4=16 bytes
        gpio_.time = gpio.time;*/
        _gpio->gpioReceived(gpio);
        //writeToSocket(gpio_);
    }
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

void QRobotRecorderManager::quickRecord(bool checked)
{
    _gpio->recorder()->setChecked(checked);
}

void QRobotRecorderManager::requestGpioRecording()
{
    requestStartRecording(LOG_GPIO);
}

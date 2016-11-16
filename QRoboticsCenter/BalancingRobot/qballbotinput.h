#ifndef QBALLBOTINPUT_H
#define QBALLBOTINPUT_H

#include <QObject>
#include <qcontrollerdeviceinterface.h>
#include <qbalancingconnectionmanager.h>
#include <mavlink.h>

class QBallbotInput : public QObject
{
    Q_OBJECT
public:
    explicit QBallbotInput(QObject *parent = 0);

    void connect(QBalancingConnectionManager *c);
    void setControllerDevice(QControllerDeviceInterface *controller);
    void removeControllerDevice();

private:
    QControllerDeviceInterface *_controller;
    int _timer;

    void timerEvent(QTimerEvent *);

signals:
    void velocityCmdMsgSend(mavlink_velocity_cmd_t velocity_cmd);

public slots:
};

#endif // QBALLBOTINPUT_H

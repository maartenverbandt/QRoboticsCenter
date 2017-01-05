#ifndef QBALLBOT_H
#define QBALLBOT_H

#include <qbalancingrobot.h>
#include <ballbotconfigdialog.h>
#include <qexcitationdialog.h>
#include <qballbotinput.h>

class QBallbot : public QBalancingRobot
{
public:
    QBallbot(int id, QObject *parent = 0);
    void setup();
    void setControllerDevice(QControllerDeviceInterface *d);
    void removeControllerDevice();

    QString getType();
    QIcon getIcon();

private:
    BallbotConfigDialog* _config;
    QExcitationDialog* _excitation;
    QBallbotInput* _input;

public slots:

    //TODO: move partition messages to config dialog itself.
    void partitionMsgReceived(mavlink_partition_t partition);
    void sendConfig(QByteArray data);
    void requestSendConfig();
    void requestSaveConfig();

};

#endif // QBALLBOT_H

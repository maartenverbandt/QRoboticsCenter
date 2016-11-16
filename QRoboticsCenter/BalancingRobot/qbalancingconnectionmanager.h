#ifndef QBALANCINGCONNECTIONMANAGER_H
#define QBALANCINGCONNECTIONMANAGER_H

#include <qrobotconnectionmanager.h>

class QBalancingConnectionManager : public QRobotConnectionManager
{
    Q_OBJECT

public:
    QBalancingConnectionManager(QObject *parent = 0);

signals:
    void poseMsgReceived(mavlink_pose_t pose);
    void attitudeMsgReceived(mavlink_attitude_t attitude);
    void velocityMsgReceived(mavlink_velocity_t velocity);
    void positionMsgReceived(mavlink_position_t position);

public slots:
    virtual void receiveMessage(mavlink_message_t msg);

    void attitudeCmdMsgSend(mavlink_attitude_cmd_t attitude_cmd);
    void velocityCmdMsgSend(mavlink_velocity_cmd_t velocity_cmd);
    void positionCmdMsgSend(mavlink_position_cmd_t position_cmd);

    void signalSweptsineMsgSend(mavlink_signal_sweptsine_t signal_sweptsine);
    void signalMultisineMsgSend(mavlink_signal_multisine_t signal_multisine);
    void signalSteppedsineMsgSend(mavlink_signal_steppedsine_t signal_steppedsine);

};

#endif // QBALANCINGCONNECTIONMANAGER_H

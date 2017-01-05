#ifndef QBALANCINGWINDOW_H
#define QBALANCINGWINDOW_H

#include <qrobotwindow.h>
#include <qbalancingconnectionmanager.h>
#include <qbalancingwidget.h>

class QBalancingWindow : public QRobotWindow
{
    Q_OBJECT

public:
    QBalancingWindow(QWidget *parent = 0);
    void connect(QBalancingConnectionManager* c);

private:
    QBalancingWidget* _balancing;

    void requestIdleMode();
    void requestAttitudeMode();
    void requestVelocityMode();
    void requestPositionMode();

    typedef enum event_t{
            MODE_IDLE = 200,
            MODE_ATTITUDE = 201,
            MODE_VELOCITY = 202,
            MODE_POSITION = 203,
    } event_t;

public slots:
    void poseMsgReceived(mavlink_pose_t pose);
    void attitudeMsgReceived(mavlink_attitude_t attitude);
    void velocityMsgReceived(mavlink_velocity_t velocity);
    void positionMsgReceived(mavlink_position_t position);

    void velocityCmdReceived(mavlink_velocity_cmd_t command);

    void setControlMode(int mode);

};

#endif // QBALANCINGWINDOW_H

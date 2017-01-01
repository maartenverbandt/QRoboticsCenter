#include "qbalancingwindow.h"

QBalancingWindow::QBalancingWindow(QWidget *parent) :
    QRobotWindow(parent),
    _balancing(new QBalancingWidget(this))
{
    addView(_balancing);
    QObject::connect(_balancing,&QBalancingWidget::controlModeChanged,this,&QBalancingWindow::setControlMode);
}

void QBalancingWindow::connect(QBalancingConnectionManager *c)
{
    QRobotWindow::connect(c);
    QObject::connect(c,&QBalancingConnectionManager::poseMsgReceived,this,&QBalancingWindow::poseMsgReceived);
    QObject::connect(c,&QBalancingConnectionManager::attitudeMsgReceived,this,&QBalancingWindow::attitudeMsgReceived);
    QObject::connect(c,&QBalancingConnectionManager::velocityMsgReceived,this,&QBalancingWindow::velocityMsgReceived);
    QObject::connect(c,&QBalancingConnectionManager::positionMsgReceived,this,&QBalancingWindow::positionMsgReceived);
}

void QBalancingWindow::poseMsgReceived(mavlink_pose_t pose)
{
    _balancing->updateAttitude(QVector3D(pose.roll,pose.pitch,pose.yaw)*0.0001);
    _balancing->updatePosition(QVector3D(pose.x,pose.y,pose.z));
}

void QBalancingWindow::attitudeMsgReceived(mavlink_attitude_t attitude)
{
    _balancing->updateAttitude(QVector3D(attitude.roll,attitude.pitch,attitude.yaw)*0.0001);
}

void QBalancingWindow::velocityMsgReceived(mavlink_velocity_t velocity)
{
    //do nothing?
}

void QBalancingWindow::positionMsgReceived(mavlink_position_t position)
{
    _balancing->updatePosition(QVector3D(position.x,position.y,position.z)*0.001);
}

void QBalancingWindow::velocityCmdReceived(mavlink_velocity_cmd_t command)
{
    _balancing->updateSpeedCommand(QVector2D(command.vx,command.vy));
}

void QBalancingWindow::setControlMode(int mode)
{
    switch(mode){
    case 0: requestIdleMode(); break;
    case 1: requestAttitudeMode(); break;
    case 2: requestVelocityMode(); break;
    case 3: requestPositionMode(); break;
    }
}

void QBalancingWindow::requestIdleMode()
{
    sendEvent(QBalancingWindow::MODE_IDLE);
}

void QBalancingWindow::requestAttitudeMode()
{
    sendEvent(QBalancingWindow::MODE_ATTITUDE);
}

void QBalancingWindow::requestVelocityMode()
{
    sendEvent(QBalancingWindow::MODE_VELOCITY);
}

void QBalancingWindow::requestPositionMode()
{
    sendEvent(QBalancingWindow::MODE_POSITION);
}

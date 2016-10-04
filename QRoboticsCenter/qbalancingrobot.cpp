#include "qbalancingrobot.h"

QBalancingRobot::QBalancingRobot(unsigned int id, QString type, QIcon icon, QWidget *parent) :
    QRobot(id,type,icon,parent), _position(0.0,0.0,0.0), _attitude(0.0,0.0,0.0)
{
    setupBalancingWidget();
}

QVector3D QBalancingRobot::position()
{
    return _position;
}

QVector3D QBalancingRobot::attitude()
{
    return _attitude;
}

void QBalancingRobot::setupBalancingWidget()
{
    QBalancingWidget* widget = new QBalancingWidget(this);
    QObject::connect(this,SIGNAL(attitudeChanged(QVector3D)),widget,SLOT(updateAttitude(QVector3D)));
    QObject::connect(this,SIGNAL(positionChanged(QVector3D)),widget,SLOT(updatePosition(QVector3D)));
    QObject::connect(widget,SIGNAL(controlModeChanged(int)),this,SLOT(setControlMode(int)));

    addView(widget);
}

void QBalancingRobot::handlePartition(const char id, const QByteArray &partition, const int index)
{
    QRobot::handlePartition(id, partition, index);
}

void QBalancingRobot::setPosition(QVector3D position)
{
    _position = position;
    emit positionChanged(_position);
}

void QBalancingRobot::setAttitude(QVector3D attitude)
{
    _attitude = attitude;
    emit attitudeChanged(_attitude);
}

void QBalancingRobot::setControlMode(int mode)
{
    sendEvent(QRobot::MODE_INDEX + mode);
}

void QBalancingRobot::receiveMessage(mavlink_message_t msg)
{
    switch(msg.msgid){
    case MAVLINK_MSG_ID_POSE:{
        mavlink_pose_t pose;
        mavlink_msg_pose_decode(&msg,&pose);
        setAttitude(QVector3D(pose.roll,pose.pitch,pose.yaw));
        setPosition(QVector3D(pose.x,pose.y,pose.z));
        break;}

    case MAVLINK_MSG_ID_ATTITUDE:{
        mavlink_attitude_t attitude;
        mavlink_msg_attitude_decode(&msg,&attitude);
        setAttitude(QVector3D(attitude.roll,attitude.pitch,attitude.roll));
        break;}

    case MAVLINK_MSG_ID_POSITION:{
        mavlink_position_t position;
        mavlink_msg_position_decode(&msg,&position);
        setPosition(QVector3D(position.x,position.y,position.z));
        break;}

    default:
        QRobot::receiveMessage(msg);
    }
}



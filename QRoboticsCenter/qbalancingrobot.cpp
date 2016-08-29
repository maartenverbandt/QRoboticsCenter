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
    addView(widget);
}

void QBalancingRobot::handlePartition(const char id, const QByteArray &partition, const int index)
{
    QRobot::handlePartition(id, partition, index);
}

void QBalancingRobot::setPosition(QVector3D position)
{
    _position = position;
}

void QBalancingRobot::setAttitude(QVector3D attitude)
{
    _attitude = attitude;
}

void QBalancingRobot::receiveMessage(mavlink_message_t msg)
{
    switch(msg.msgid){
    case MAVLINK_MSG_ID_AHRS_ANGLE:{
        mavlink_ahrs_angle_t ahrs_angle;
        setAttitude(QVector3D(ahrs_angle.roll,ahrs_angle.pitch,ahrs_angle.yaw));
        break;}

    default:
        QRobot::receiveMessage(msg);
    }
}



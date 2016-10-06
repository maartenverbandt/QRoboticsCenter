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

    // setup recorders
    _attitude_recorder = new QAttitudeRecorder(this);
    QObject::connect(this,SIGNAL(attitudeMessageReceived(mavlink_attitude_t)),_attitude_recorder,SLOT(attitudeReceived(mavlink_attitude_t)));
    QObject::connect(_attitude_recorder,SIGNAL(started()),this,SLOT(requestAttitudeLogging()));
    addRecorder(_attitude_recorder);
    _position_recorder = new QPositionRecorder(this);
    QObject::connect(this,SIGNAL(positionMessageReceived(mavlink_position_t)),_position_recorder,SLOT(positionReceived(mavlink_position_t)));
    QObject::connect(_position_recorder,SIGNAL(started()),this,SLOT(requestPositionLogging()));
    addRecorder(_position_recorder);
}

void QBalancingRobot::handlePartition(const char id, const QByteArray &partition, const int index)
{
    QRobot::handlePartition(id, partition, index);
}

void QBalancingRobot::quickRecordToggled(bool b)
{
    _position_recorder->recorder()->setChecked(b);
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
    switch(mode){
    case 0: requestIdleMode(); break;
    case 1: requestAttitudeMode(); break;
    case 2: requestVelocityMode(); break;
    case 3: requestPositionMode(); break;
    }
}

void QBalancingRobot::requestIdleMode()
{
    sendEvent(QBalancingRobot::MODE_IDLE);
}

void QBalancingRobot::requestAttitudeMode()
{
    sendEvent(QBalancingRobot::MODE_ATTITUDE);
}

void QBalancingRobot::requestVelocityMode()
{
    sendEvent(QBalancingRobot::MODE_VELOCITY);
}

void QBalancingRobot::requestPositionMode()
{
    sendEvent(QBalancingRobot::MODE_POSITION);
}

void QBalancingRobot::requestAttitudeLogging()
{
    sendEvent(QBalancingRobot::LOG_ATTITUDE);
}

void QBalancingRobot::requestPositionLogging()
{
    sendEvent(QBalancingRobot::LOG_POSITION);
}

void QBalancingRobot::receiveMessage(mavlink_message_t msg)
{
    switch(msg.msgid){
    case MAVLINK_MSG_ID_POSE:{
        mavlink_pose_t pose;
        mavlink_msg_pose_decode(&msg,&pose);
        setAttitude(QVector3D(pose.roll,pose.pitch,pose.yaw)*0.0001);
        setPosition(QVector3D(pose.x,pose.y,pose.z));
        break;}

    case MAVLINK_MSG_ID_ATTITUDE:{
        mavlink_attitude_t attitude;
        mavlink_msg_attitude_decode(&msg,&attitude);
        setAttitude(QVector3D(attitude.roll,attitude.pitch,attitude.yaw)*0.0001);
        emit attitudeMessageReceived(attitude);
        break;}

    case MAVLINK_MSG_ID_POSITION:{
        mavlink_position_t position;
        mavlink_msg_position_decode(&msg,&position);
        setPosition(QVector3D(position.x,position.y,position.z)*0.001);
        emit positionMessageReceived(position);
        break;}

    default:
        QRobot::receiveMessage(msg);
    }
}



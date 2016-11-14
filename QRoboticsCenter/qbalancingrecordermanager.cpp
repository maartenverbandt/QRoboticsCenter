#include "qbalancingrecordermanager.h"

QBalancingRecorderManager::QBalancingRecorderManager(QGPIOWidget *gpio, QObject *parent) :
    QRobotRecorderManager(gpio,parent)
{
    setupAttitudeRecorder();
    setupVelocityRecorder();
    setupPositionRecorder();
}

void QBalancingRecorderManager::connect(QBalancingConnectionManager *c)
{
    this->QRobotRecorderManager::connect(c);
    QObject::connect(c,&QBalancingConnectionManager::attitudeMsgReceived,_attitude,&QAttitudeRecorder::attitudeReceived);
    QObject::connect(c,&QBalancingConnectionManager::velocityMsgReceived,_velocity,&QVelocityRecorder::velocityReceived);
    QObject::connect(c,&QBalancingConnectionManager::positionMsgReceived,_position,&QPositionRecorder::positionReceived);
}

void QBalancingRecorderManager::setupAttitudeRecorder()
{
    _attitude = new QAttitudeRecorder(this);
    QObject::connect(_attitude,&QAttitudeRecorder::started,this,&QBalancingRecorderManager::requestAttitudeRecording);
    QObject::connect(_attitude,&QAttitudeRecorder::stopped,this,&QBalancingRecorderManager::requestStopRecording);
    addRecorder(_attitude);
}

void QBalancingRecorderManager::setupVelocityRecorder()
{
    _velocity = new QVelocityRecorder(this);
    QObject::connect(_velocity,&QVelocityRecorder::started,this,&QBalancingRecorderManager::requestVelocityRecording);
    QObject::connect(_velocity,&QVelocityRecorder::stopped,this,&QBalancingRecorderManager::requestStopRecording);
    addRecorder(_velocity);
}

void QBalancingRecorderManager::setupPositionRecorder()
{
    _position = new QPositionRecorder(this);
    QObject::connect(_position,&QPositionRecorder::started,this,&QBalancingRecorderManager::requestPositionRecording);
    QObject::connect(_position,&QPositionRecorder::stopped,this,&QBalancingRecorderManager::requestStopRecording);
    addRecorder(_position);
}

void QBalancingRecorderManager::requestAttitudeRecording()
{

    requestStartRecording(QBalancingRecorderManager::LOG_ATTITUDE);
}

void QBalancingRecorderManager::requestVelocityRecording()
{
    requestStartRecording(QBalancingRecorderManager::LOG_VELOCITY);
}

void QBalancingRecorderManager::requestPositionRecording()
{
    requestStartRecording(QBalancingRecorderManager::LOG_POSITION);
}

void QBalancingRecorderManager::quickRecord(bool checked)
{
    _velocity->recorder()->setChecked(checked);
}

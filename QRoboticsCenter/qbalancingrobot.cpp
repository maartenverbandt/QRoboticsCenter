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
    _velocity_recorder = new QVelocityRecorder(this);
    QObject::connect(this,SIGNAL(velocityMessageReceived(mavlink_velocity_t)),_velocity_recorder,SLOT(velocityReceived(mavlink_velocity_t)));
    QObject::connect(_velocity_recorder,SIGNAL(started()),this,SLOT(requestVelocityLogging()));
    addRecorder(_velocity_recorder);
    _position_recorder = new QPositionRecorder(this);
    QObject::connect(this,SIGNAL(positionMessageReceived(mavlink_position_t)),_position_recorder,SLOT(positionReceived(mavlink_position_t)));
    QObject::connect(_position_recorder,SIGNAL(started()),this,SLOT(requestPositionLogging()));
    addRecorder(_position_recorder);

    // setup ports
    /*QExternalPortDialog* ports = new QExternalPortDialog("Attitude port",this);
    QAttitudeFilePort* fileport = new QAttitudeFilePort(ports);
    QObject::connect(fileport,SIGNAL(attitudeCommand(mavlink_attitude_cmd_t)),this,SLOT(requestAttitudeCommand(mavlink_attitude_cmd_t)));
    ports->addPort(fileport,"File");
    addRobotMenuAction(ports->getPopupAction());*/

    // setup excitation
    QExcitationDialog* excitation = new QExcitationDialog(this);
    QObject::connect(excitation,SIGNAL(requestSweptsine(uint,double,double,double,double)),this,SLOT(requestSweptsine(uint,double,double,double,double)));
    QObject::connect(excitation,SIGNAL(requestMultisine(uint,int,double)),this,SLOT(requestMultisine(uint,int,double)));
    QObject::connect(excitation,SIGNAL(requestSteppedsine(uint,double,double,int,double)),this,SLOT(requestSteppedsine(uint,double,double,int,double)));
    QObject::connect(excitation,SIGNAL(requestStopExcitation()),this,SLOT(requestStopExcitation()));
    addRobotMenuAction(excitation->getPopupAction());
}

void QBalancingRobot::handlePartition(const char id, const QByteArray &partition, const int index)
{
    QRobot::handlePartition(id, partition, index);
}

void QBalancingRobot::moveRequested(QControllerDeviceInterface::robot_move_cmd_t move_cmd)
{
    mavlink_velocity_cmd_t cmd;
    cmd.vx = -move_cmd.y*1500.0;
    cmd.vy = -move_cmd.x*1500.0;
    cmd.vz = -move_cmd.z*1000.0;
    requestVelocityCommand(cmd);
    qDebug() << "Balancing robot move requested." << QVector3D(move_cmd.x,move_cmd.y,move_cmd.z);
}

void QBalancingRobot::quickRecordToggled(bool b)
{
    _velocity_recorder->recorder()->setChecked(b);
}

void QBalancingRobot::setupController(QControllerDeviceInterface *controller)
{
    QRobot::setupController(controller);
    QObject::connect(controller,SIGNAL(moveCmdChanged(QControllerDeviceInterface::robot_move_cmd_t)),
                     this,SLOT(moveRequested(QControllerDeviceInterface::robot_move_cmd_t)));
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

void QBalancingRobot::requestVelocityLogging()
{
    sendEvent(QBalancingRobot::LOG_VELOCITY);
}

void QBalancingRobot::requestPositionLogging()
{
    sendEvent(QBalancingRobot::LOG_POSITION);
}

void QBalancingRobot::requestAttitudeCommand(mavlink_attitude_cmd_t attitude_cmd)
{
    mavlink_message_t msg;
    mavlink_msg_attitude_cmd_encode(0,0,&msg,&attitude_cmd);
    sendMessage(msg);
}

void QBalancingRobot::requestVelocityCommand(mavlink_velocity_cmd_t velocity_cmd)
{
    mavlink_message_t msg;
    mavlink_msg_velocity_cmd_encode(0,0,&msg,&velocity_cmd);
    sendMessage(msg);
}

void QBalancingRobot::requestPositionCommand(mavlink_position_cmd_t position_cmd)
{
    mavlink_message_t msg;
    mavlink_msg_position_cmd_encode(0,0,&msg,&position_cmd);
    sendMessage(msg);
}

void QBalancingRobot::requestSweptsine(unsigned int channels, double fmin, double fmax, double period, double amplitude)
{
    mavlink_message_t msg;
    mavlink_msg_signal_sweptsine_pack(0,0,&msg,channels,fmin,fmax,period,amplitude);
    sendMessage(msg);
}

void QBalancingRobot::requestMultisine(unsigned int channels, int id, double amplitude)
{
    mavlink_message_t msg;
    mavlink_msg_signal_multisine_pack(0,0,&msg,channels,id,amplitude);
    sendMessage(msg);
}

void QBalancingRobot::requestSteppedsine(unsigned int channels, double fmin, double fmax, int period, double amplitude)
{
    mavlink_message_t msg;
    mavlink_msg_signal_steppedsine_pack(0,0,&msg,channels,fmin,fmax,period,1.124,amplitude);
    sendMessage(msg);
}

void QBalancingRobot::requestStopExcitation()
{
    sendEvent(QBalancingRobot::STOP_EXCITATION);
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

    case MAVLINK_MSG_ID_VELOCITY:{
        mavlink_velocity_t velocity;
        mavlink_msg_velocity_decode(&msg,&velocity);
        emit velocityMessageReceived(velocity);
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



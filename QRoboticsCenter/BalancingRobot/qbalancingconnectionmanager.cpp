#include "qbalancingconnectionmanager.h"

QBalancingConnectionManager::QBalancingConnectionManager(QObject *parent) :
    QRobotConnectionManager(parent)
{

}

void QBalancingConnectionManager::receiveMessage(mavlink_message_t msg)
{
    switch(msg.msgid){
    case MAVLINK_MSG_ID_POSE:{
        mavlink_pose_t pose;
        mavlink_msg_pose_decode(&msg,&pose);
        emit poseMsgReceived(pose);
        break;}

    case MAVLINK_MSG_ID_ATTITUDE:{
        mavlink_attitude_t attitude;
        mavlink_msg_attitude_decode(&msg,&attitude);
        emit attitudeMsgReceived(attitude);
        break;}

    case MAVLINK_MSG_ID_VELOCITY:{
        mavlink_velocity_t velocity;
        mavlink_msg_velocity_decode(&msg,&velocity);
        emit velocityMsgReceived(velocity);
        break;}

    case MAVLINK_MSG_ID_POSITION:{
        mavlink_position_t position;
        mavlink_msg_position_decode(&msg,&position);
        emit positionMsgReceived(position);
        break;}

    default:
        QRobotConnectionManager::receiveMessage(msg);
    }
}

void QBalancingConnectionManager::packetSend(QVariant packet)
{
    int t = packet.userType();
    if(t == qMetaTypeId<mavlink_attitude_cmd_t>()){
        attitudeCmdMsgSend(packet.value<mavlink_attitude_cmd_t>());
    } else if (t == qMetaTypeId<mavlink_velocity_cmd_t>()){
        velocityCmdMsgSend(packet.value<mavlink_velocity_cmd_t>());
    } else if (t == qMetaTypeId<mavlink_position_cmd_t>()){
        positionCmdMsgSend(packet.value<mavlink_position_cmd_t>());
    } else if (t == qMetaTypeId<mavlink_signal_sweptsine_t>()) {
        signalSweptsineMsgSend(packet.value<mavlink_signal_sweptsine_t>());
    } else if (t == qMetaTypeId<mavlink_signal_multisine_t>()){
        signalMultisineMsgSend(packet.value<mavlink_signal_multisine_t>());
    } else if (t == qMetaTypeId<mavlink_signal_steppedsine_t>()){
        signalSteppedsineMsgSend(packet.value<mavlink_signal_steppedsine_t>());
    } else {
        QRobotConnectionManager::packetSend(packet);
    }
}

void QBalancingConnectionManager::attitudeCmdMsgSend(mavlink_attitude_cmd_t attitude_cmd)
{
    mavlink_message_t msg;
    mavlink_msg_attitude_cmd_encode(0,0,&msg,&attitude_cmd);
    sendMessage(msg);
}

void QBalancingConnectionManager::velocityCmdMsgSend(mavlink_velocity_cmd_t velocity_cmd)
{
    mavlink_message_t msg;
    mavlink_msg_velocity_cmd_encode(0,0,&msg,&velocity_cmd);
    sendMessage(msg);
}

void QBalancingConnectionManager::positionCmdMsgSend(mavlink_position_cmd_t position_cmd)
{
    mavlink_message_t msg;
    mavlink_msg_position_cmd_encode(0,0,&msg,&position_cmd);
    sendMessage(msg);
}

void QBalancingConnectionManager::signalSweptsineMsgSend(mavlink_signal_sweptsine_t signal_sweptsine)
{
    mavlink_message_t msg;
    mavlink_msg_signal_sweptsine_encode(0,0,&msg,&signal_sweptsine);
    sendMessage(msg);
}

void QBalancingConnectionManager::signalMultisineMsgSend(mavlink_signal_multisine_t signal_multisine)
{
    mavlink_message_t msg;
    mavlink_msg_signal_multisine_encode(0,0,&msg,&signal_multisine);
    sendMessage(msg);
}

void QBalancingConnectionManager::signalSteppedsineMsgSend(mavlink_signal_steppedsine_t signal_steppedsine)
{
    mavlink_message_t msg;
    mavlink_msg_signal_steppedsine_encode(0,0,&msg,&signal_steppedsine);
    sendMessage(msg);
}




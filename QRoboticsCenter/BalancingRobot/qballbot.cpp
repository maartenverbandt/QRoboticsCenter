#include "qballbot.h"

QBallbot::QBallbot(int id, QObject *parent) :
    QBalancingRobot(id,parent),
    _config(new BallbotConfigDialog(0)),
    _excitation(new QExcitationDialog(0))
{
    //do nothing
}

void QBallbot::setup()
{
    // Default balancing robot setup
    QBalancingRobot::setup();

    //Connect config //TODO: should be more standard in the future..
    QObject::connect(getConnectionManager(),&QBalancingConnectionManager::partitionMsgReceived,this,&QBallbot::partitionMsgReceived);
    QObject::connect(_config,&BallbotConfigDialog::readRobotSettings,this,&QBallbot::requestSendConfig);
    QObject::connect(_config,&BallbotConfigDialog::storeRobotSettings,this,&QBallbot::requestSaveConfig);
    QObject::connect(_config,&BallbotConfigDialog::writeRobotSettings,this,&QBallbot::sendConfig);

    //connect
    _excitation->connect(getConnectionManager());

    //add tools menu.. // move tools t
    QMenu* tools = getWindow()->menuBar()->addMenu("Tools");
    tools->addAction(_config->getPopupAction());
    tools->addAction(_excitation->getPopupAction());
}

QString QBallbot::getType()
{
    return "Ballbot";
}

QIcon QBallbot::getIcon()
{
    return QIcon(":/icons/ballbot.png");
}

// TODO: move method to config dialog itself
void QBallbot::partitionMsgReceived(mavlink_partition_t partition)
{
    if(partition.ID == 'C'){
        _config->fromByteArray(QByteArray((char*)(partition.value),partition.size),partition.index);
    } else {
        qDebug() << "partition" << partition.ID << "not handled.";
    }
}

// TODO: move...
void QBallbot::sendConfig(QByteArray data)
{
    mavlink_partition_t partition;
    partition.ID = 'C';

    int count = 0;
    int chunk = 32;
    int index = 0;

    qDebug() << "Sending partition with" << data.size() << "bytes";
    qDebug() << data;

    for(count = data.size();count >= 0;count-=32){
        if(count < 32)
            chunk = data.size()-index;

        partition.size = chunk;
        partition.index = index;
        partition.togo = count/32;
        memcpy(partition.value,(uint8_t*)(data.data()+index),chunk);

        //mavlink_msg_partition_encode(0,0,&msg,&partition);
        //getConnectionManager()->sendMessage(msg);
        getConnectionManager()->partitionMsgSend(partition);
        index += 32;
        qDebug() << "Chunk size: " << chunk;
    }
}

// TODO: move method to config dialog itself
void QBallbot::requestSendConfig()
{
    mavlink_event_t event;
    event.type = 100;
    //mavlink_message_t msg;
    //mavlink_msg_event_encode(0,0,&msg,&event);
    //getConnectionManager()->sendMessage(msg);
    getConnectionManager()->eventMsgSend(event);
}

// TODO: move method to config dialog itself
void QBallbot::requestSaveConfig()
{
    mavlink_event_t event;
    event.type = 101;
    //mavlink_message_t msg;
    //mavlink_msg_event_encode(0,0,&msg,&event);
    //getConnectionManager()->sendMessage(msg);
    getConnectionManager()->eventMsgSend(event);
}

#include "qballbot.h"

QBallbot::QBallbot(unsigned int id, QWidget *parent):
    QBalancingRobot(id, "Ballbot", QIcon(":/icons/ballbot.png"), parent),
    _config(new BallbotConfigDialog(0))
{
    setupBallbotWidget();
}

void QBallbot::handlePartition(const char id, const QByteArray &partition, const int index)
{
    switch(id){
    case 'C':{
        _config->fromByteArray(partition,index);
        break;}
    case 'D':{
        qDebug() << "Data partition not handled";
        break;}
    }
}

void QBallbot::setupBallbotWidget()
{
    addRobotMenuAction(_config->getPopupAction());
    QObject::connect(_config,SIGNAL(readRobotSettings()),this,SLOT(requestSendConfig()));
    QObject::connect(_config,SIGNAL(writeRobotSettings(QByteArray)),this,SLOT(writeRobotSettings(QByteArray)));
    QObject::connect(_config,SIGNAL(storeRobotSettings()),this,SLOT(requestSaveConfig()));
    requestSendConfig(); //request current info
}

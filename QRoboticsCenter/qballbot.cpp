#include "qballbot.h"

QBallbot::QBallbot(unsigned int id, QWidget *parent):
    QBalancingRobot(id, "Ballbot", QIcon(), parent),
    _config(new BallbotConfigDialog(0))
{
    setupBallbotWidget();
}

void QBallbot::handlePartition(const char id, const QByteArray &partition, const int index)
{
    switch(id){
    case 'C':{
        _config->fromByteArray(partition,index);
        qDebug() << "Config partition handled!";
        break;}
    case 'D':{
        qDebug() << "Data partition not handled";
        break;}
    }
}

void QBallbot::setupBallbotWidget()
{
    addRobotMenuAction(_config->getPopupAction());
}

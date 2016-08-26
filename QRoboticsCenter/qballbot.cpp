#include "qballbot.h"

QBallbot::QBallbot(unsigned int id, QWidget *parent):
    QBalancingRobot(id, "Ballbot", QIcon(), parent),
    _config(new BallbotConfigDialog(0))
{
    setupBallbotWidget();
}

void QBallbot::setupBallbotWidget()
{
    addRobotMenuAction(_config->getPopupAction());
}

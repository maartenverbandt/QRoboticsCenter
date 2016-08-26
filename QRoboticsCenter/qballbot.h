#ifndef QBALLBOT_H
#define QBALLBOT_H

#include <qbalancingrobot.h>
#include <ballbotconfigdialog.h>

class QBallbot : public QBalancingRobot
{
    Q_OBJECT

public:
    QBallbot(unsigned int id, QWidget *parent = 0);

private:
    BallbotConfigDialog *_config;

    void setupBallbotWidget();

};

#endif // QBALLBOT_H

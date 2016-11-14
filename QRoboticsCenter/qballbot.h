#ifndef QBALLBOT_H
#define QBALLBOT_H

#include <qbalancingrobot.h>

class QBallbot : public QBalancingRobot
{
public:
    QBallbot(int id, QObject *parent = 0);

    QString getType();
    QIcon getIcon();
};

#endif // QBALLBOT_H

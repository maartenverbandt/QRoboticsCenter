#ifndef QSEGBOT_H
#define QSEGBOT_H

#include <qbalancingrobot.h>

class QSegbot : public QBalancingRobot
{
public:
    QSegbot(unsigned int id, QWidget *parent = 0);
};

#endif // QSEGBOT_H

#ifndef QBALLBOT_H
#define QBALLBOT_H

#include <qbalancingrobot.h>
#include <ballbotconfigdialog.h>

class QBallbot : public QBalancingRobot
{
    Q_OBJECT

public:
    QBallbot(unsigned int id, QWidget *parent = 0);

protected:
    virtual void handlePartition(const char id, const QByteArray &partition, const int index);

private:
    BallbotConfigDialog *_config;

    void setupBallbotWidget();

};

#endif // QBALLBOT_H

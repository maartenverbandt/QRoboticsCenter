#ifndef QBALANCINGROBOT_H
#define QBALANCINGROBOT_H

#include <QVector3D>
#include <qrobot.h>
#include <qbalancingwidget.h>

class QBalancingRobot : public QRobot
{
public:
    QBalancingRobot(unsigned int id, QString type, QIcon icon, QWidget *parent = 0);

    QVector3D position();
    QVector3D attitude();

    void setupBalancingWidget();

private:
    QVector3D _position;
    QVector3D _attitude;

public slots:
    void setPosition(QVector3D position);
    void setAttitude(QVector3D attitude);

    virtual void receiveMessage(mavlink_message_t msg);

};

#endif // QBALANCINGROBOT_H

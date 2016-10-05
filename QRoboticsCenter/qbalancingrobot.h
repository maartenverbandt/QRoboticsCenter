#ifndef QBALANCINGROBOT_H
#define QBALANCINGROBOT_H

#include <QVector3D>
#include <qrobot.h>
#include <qbalancingwidget.h>
#include <qattituderecorder.h>
#include <qpositionrecorder.h>

class QBalancingRobot : public QRobot
{
    Q_OBJECT

public:
    QBalancingRobot(unsigned int id, QString type, QIcon icon, QWidget *parent = 0);

    QVector3D position();
    QVector3D attitude();

    void setupBalancingWidget();

protected:
    virtual void handlePartition(const char id, const QByteArray &partition, const int index);

private:
    QVector3D _position;
    QVector3D _attitude;

signals:
    void positionChanged(QVector3D position);
    void attitudeChanged(QVector3D attitude);
    void positionMessageReceived(mavlink_position_t position);
    void attitudeMessageReceived(mavlink_attitude_t attitude);

public slots:
    void setPosition(QVector3D position);
    void setAttitude(QVector3D attitude);
    void setControlMode(int mode);

    virtual void receiveMessage(mavlink_message_t msg);

};

Q_DECLARE_METATYPE(mavlink_position_t)
Q_DECLARE_METATYPE(mavlink_attitude_t)

#endif // QBALANCINGROBOT_H

#ifndef QBALANCINGROBOT_H
#define QBALANCINGROBOT_H

#include <QVector3D>
#include <qrobot.h>
#include <qbalancingwidget.h>
#include <qattituderecorder.h>
#include <qpositionrecorder.h>
#include <qexternalportdialog.h>
#include <qattitudefileport.h>

class QBalancingRobot : public QRobot
{
    Q_OBJECT

public:
    typedef enum event_t{
        MODE_IDLE = 200,
        MODE_ATTITUDE = 201,
        MODE_VELOCITY = 202,
        MODE_POSITION = 203,
        LOG_GPIO = 302,
        LOG_ATTITUDE = 303,
        LOG_VELOCITY = 304,
        LOG_POSITION = 305
    } event_t;

    QBalancingRobot(unsigned int id, QString type, QIcon icon, QWidget *parent = 0);

    QVector3D position();
    QVector3D attitude();

    void setupBalancingWidget();

protected:
    virtual void handlePartition(const char id, const QByteArray &partition, const int index);

private:
    QVector3D _position;
    QVector3D _attitude;

    QAbstractRecorder* _attitude_recorder;
    QAbstractRecorder* _position_recorder;

signals:
    void positionChanged(QVector3D position);
    void attitudeChanged(QVector3D attitude);
    void positionMessageReceived(mavlink_position_t position);
    void attitudeMessageReceived(mavlink_attitude_t attitude);

protected slots:
    void quickRecordToggled(bool b);

public slots:
    void setPosition(QVector3D position);
    void setAttitude(QVector3D attitude);
    void setControlMode(int mode);

    void requestIdleMode();
    void requestAttitudeMode();
    void requestVelocityMode();
    void requestPositionMode();
    void requestAttitudeLogging();
    void requestPositionLogging();

    virtual void receiveMessage(mavlink_message_t msg);

};

Q_DECLARE_METATYPE(mavlink_position_t)
Q_DECLARE_METATYPE(mavlink_attitude_t)

#endif // QBALANCINGROBOT_H

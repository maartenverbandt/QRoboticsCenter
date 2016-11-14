#ifndef QBALANCINGRECORDERMANAGER_H
#define QBALANCINGRECORDERMANAGER_H

#include <qrobotrecordermanager.h>
#include <qattituderecorder.h>
#include <qvelocityrecorder.h>
#include <qpositionrecorder.h>
#include <qbalancingconnectionmanager.h>

//#include <qbalancingrobot_old.h>

class QBalancingRecorderManager : public QRobotRecorderManager
{
    Q_OBJECT

public:
    QBalancingRecorderManager(QGPIOWidget *gpio, QObject *parent = 0);
    void connect(QBalancingConnectionManager* c);

protected:
    typedef enum event_t{
        LOG_ATTITUDE = 303,
        LOG_VELOCITY = 304,
        LOG_POSITION = 305
    } event_t;

private:
    QAttitudeRecorder* _attitude;
    QVelocityRecorder* _velocity;
    QPositionRecorder* _position;

    void setupAttitudeRecorder();
    void setupVelocityRecorder();
    void setupPositionRecorder();

    void sendEvent(int id);

signals:
    void eventMsgSend(mavlink_event_t event);

private slots:
    void requestAttitudeRecording();
    void requestVelocityRecording();
    void requestPositionRecording();

    void quickRecord(bool checked);

};

Q_DECLARE_METATYPE(mavlink_position_t)
Q_DECLARE_METATYPE(mavlink_velocity_t)
Q_DECLARE_METATYPE(mavlink_attitude_t)

#endif // QBALANCINGRECORDERMANAGER_H

#ifndef QBALANCINGROBOT_H
#define QBALANCINGROBOT_H

#include <qabstractrobot.h>
#include <qbalancingwindow.h>
#include <qbalancingconnectionmanager.h>
#include <qbalancingrecordermanager.h>

class QBalancingRobot : public QAbstractRobot
{
public:

    /*typedef enum event_t{
            MODE_IDLE = 200,
            MODE_ATTITUDE = 201,
            MODE_VELOCITY = 202,
            MODE_POSITION = 203,
            LOG_GPIO = 302,
            LOG_ATTITUDE = 303,
            LOG_VELOCITY = 304,
            LOG_POSITION = 305,
            STOP_EXCITATION = 310
        } event_t;*/

    QBalancingRobot(int id, QObject* parent = 0);

    virtual QString getType() = 0;
    virtual QIcon getIcon() = 0;

    QBalancingWindow *getWindow();
    QBalancingConnectionManager *getConnectionManager();
    QBalancingRecorderManager *getRecorderManager();

private:
    QBalancingWindow *_window;
    QBalancingConnectionManager *_connection_manager;
    QBalancingRecorderManager* _recorder_manager;
};

#endif // QBALANCINGROBOT_H

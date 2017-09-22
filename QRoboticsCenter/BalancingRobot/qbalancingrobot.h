#ifndef QBALANCINGROBOT_H
#define QBALANCINGROBOT_H

#include <qabstractrobot.h>
#include <qbalancingwindow.h>
#include <qbalancingconnectionmanager.h>
#include <qbalancingrecordermanager.h>
#include <qbalancingcommandmanager.h>
#include <qbalancingmeasurementmanager.h>

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
    virtual void setup();

    virtual QString getType() = 0;
    virtual QIcon getIcon() = 0;

    QBalancingWindow *getWindow();
    QBalancingConnectionManager *getConnectionManager();
    QBalancingRecorderManager *getRecorderManager();
    QBalancingCommandManager *getCommandManager();
    QRobotMeasurementManager *getMeasurementManager();

    virtual void saveState();
    virtual void restoreState();

private:
    QBalancingConnectionManager *_connection_manager;
    QBalancingWindow *_window;
    QBalancingRecorderManager* _recorder_manager;
    QBalancingCommandManager* _command_manager;
    QRobotMeasurementManager* _measurement_manager;

};

#endif // QBALANCINGROBOT_H

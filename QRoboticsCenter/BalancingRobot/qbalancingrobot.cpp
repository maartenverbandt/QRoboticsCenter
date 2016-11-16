#include "qbalancingrobot.h"

QBalancingRobot::QBalancingRobot(int id, QObject *parent) :
    QAbstractRobot(id, parent),
    _connection_manager(new QBalancingConnectionManager(this)),
    _window(new QBalancingWindow(0)),
    _recorder_manager(new QBalancingRecorderManager(_window->getGPIOWidget(), this))
{
    //do nothing (yet..)
}

void QBalancingRobot::setup()
{
    QAbstractRobot::setup();
    //setup signal-slot connections
    _window->connect(_connection_manager);
    _recorder_manager->connect(_connection_manager);
    //setup mainwindow
    _connection_manager->setupMainWindow(_window);
    _recorder_manager->setupMainWindow(_window);
}

QBalancingWindow *QBalancingRobot::getWindow()
{
    return _window;
}

QBalancingConnectionManager *QBalancingRobot::getConnectionManager()
{
    return _connection_manager;
}

QBalancingRecorderManager *QBalancingRobot::getRecorderManager()
{
    return _recorder_manager;
}

#include "qbasicrobot.h"

QBasicRobot::QBasicRobot(int id, QObject *parent) :
    QAbstractRobot(id, parent),
    _connection_manager(new QRobotConnectionManager(this)),
    _window(new QRobotWindow(0)),
    _recorder_manager(new QRobotRecorderManager(_window->getGPIOWidget(),this))
{
    //setup only in real robots
}

void QBasicRobot::setup()
{
    //Standard setup
    QAbstractRobot::setup();
    //setup signal-slot connections
    _window->connect(_connection_manager);
    _recorder_manager->connect(_connection_manager);
    //setup mainwindow
    _connection_manager->setupMainWindow(_window);
    _recorder_manager->setupMainWindow(_window);
}

QRobotWindow *QBasicRobot::getWindow()
{
    return _window;
}

QRobotConnectionManager *QBasicRobot::getConnectionManager()
{
    return _connection_manager;
}

QRobotRecorderManager *QBasicRobot::getRecorderManager()
{
    return _recorder_manager;
}

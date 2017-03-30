#include "qbasicrobot.h"

QBasicRobot::QBasicRobot(int id, QObject *parent) :
    QAbstractRobot(id, parent),
    _connection_manager(new QRobotConnectionManager(this)),
    _window(new QRobotWindow(0)),
    _recorder_manager(new QRobotRecorderManager(_window->getGPIOWidget(),this)),
    _command_manager(new QRobotCommandManager(parent)),
    _measurement_manager(new QRobotMeasurementManager(parent))
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
    _command_manager->connect(_connection_manager);
    _measurement_manager->connect(_connection_manager);
    //setup mainwindow
    _connection_manager->setupMainWindow(_window);
    _recorder_manager->setupMainWindow(_window);
    _command_manager->setupMainWindow(_window);
    _measurement_manager->setupMainWindow(_window);
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

QRobotCommandManager *QBasicRobot::getCommandManager()
{
    return _command_manager;
}

QRobotMeasurementManager *QBasicRobot::getMeasurementManager()
{
    return _measurement_manager;
}

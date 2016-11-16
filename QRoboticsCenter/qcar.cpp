#include "qcar.h"

QCar::QCar(int id, QObject *parent) :
    QAbstractRobot(id, parent),
    _connection_manager(new QRobotConnectionManager(this)),
    _window(new QRobotWindow(0)),
    _recorder_manager(new QRobotRecorderManager(_window->getGPIOWidget(),this))
{
    setup();
}

void QCar::setup()
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

QString QCar::getType()
{
    return "car";
}

QIcon QCar::getIcon()
{
    return QIcon(":/icons/car.png");
}

QRobotWindow *QCar::getWindow()
{
    return _window;
}

QRobotConnectionManager *QCar::getConnectionManager()
{
    return _connection_manager;
}

QRobotRecorderManager *QCar::getRecorderManager()
{
    return _recorder_manager;
}

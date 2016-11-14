#include "qcar.h"

QCar::QCar(int id, QObject *parent) :
    QAbstractRobot(id, parent)
{
    _connection_manager = new QRobotConnectionManager(this);
    _window = new QRobotWindow(0);
    _window->connect(_connection_manager);
    _recorder_manager = new QRobotRecorderManager(_window->getGPIOWidget(),this);
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

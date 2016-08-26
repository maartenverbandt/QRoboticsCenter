#include "qrobotcoordinator.h"

QRobotCoordinator::QRobotCoordinator(QWidget *parent) :
    QWidget(parent), _layout(new QVBoxLayout()), _robot_mapper(new QSignalMapper(this))
{
    this->setLayout(_layout);
    QObject::connect(_robot_mapper,SIGNAL(mapped(int)),this,SLOT(showRobotWidget(int)));
}

QRobot *QRobotCoordinator::addRobot(unsigned int id, unsigned int type)
{
    //Create new robot
    QRobot* robot;
    switch(type){
    case(QRobot::BALLBOT):
        robot = new QBallbot(id,0);
        break;
    case(QRobot::SEGBOT):
        robot = new QSegbot(id,0);
        break;
    default:
        robot = new QRobot(id,0);
        break;
    }
    _robots.append(robot);

    //Add button to the mainwindow
    QPushButton* button = new QPushButton(this);
    button->setText(robot->getType() + " " + QString::number(id));
    _layout->addWidget(button);

    QObject::connect(button,SIGNAL(clicked()),_robot_mapper,SLOT(map()));
    _robot_mapper->setMapping(button, _buttons.length());
    _buttons.append(button);

    return robot;
}

QRobot *QRobotCoordinator::addRobot(QMavlinkConnection *connection)
{
    QRobot* robot = this->addRobot(connection->getRobotID(), connection->getRobotType());
    robot->addConnection(connection);

    return robot;
}

void QRobotCoordinator::closeEvent(QCloseEvent *e)
{
    QListIterator<QRobot*> robot(_robots);
    while (robot.hasNext())
        robot.next()->close();
}

void QRobotCoordinator::mavlinkConnectionFound(QMavlinkConnection *connection)
{
    QRobot* robot = addRobot(connection->getRobotID(),connection->getRobotType());
    robot->addConnection(connection);
}

void QRobotCoordinator::showRobotWidget(int index)
{
    _robots[index]->show();
}

/*void QRobotCoordinator::paintEvent(QPaintEvent *)
{

}*/

#include "qrobotcoordinator.h"

QRobotCoordinator::QRobotCoordinator() :
    QMainWindow(),
    _layout(new QVBoxLayout()),
    _robot_mapper(new QSignalMapper(this)),
    _rescan(new QAction("Scan",this)),
    _about(new QAction("About",this)),
{
    // setup central widget
    QWidget* central_widget = new QWidget(this);
    central_widget->setLayout(_layout);
    this->setCentralWidget(central_widget);
    QObject::connect(_robot_mapper,SIGNAL(mapped(int)),this,SLOT(showRobotWidget(int)));

    _rescan->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    addAction(_rescan);

    QObject::connect(_about,SIGNAL(triggered(bool)),this,SLOT(showAboutDialog()));
    addAction(_about);

    QMenu *help = menuBar()->addMenu("Help");
    help->addAction(_about);

    setMinimumWidth(250);
}

QRobot *QRobotCoordinator::addRobot(unsigned int id, unsigned int type)
{
    //Create new robot
    QRobot* robot;
    switch(type){
    case(QRobot::BALLBOT):
        robot = new QBallbot(id,this);
        break;
    case(QRobot::SEGBOT):
        robot = new QSegbot(id,this);
        break;
    case(QRobot::CAR):
        robot = new QRobot(id,"car",QIcon(":/icons/car.png"),this);
        break;
    default:
        robot = new QRobot(id,this);
        break;
    }
    _robots.append(robot);

    //Add button to the mainwindow
    QPushButton* button = new QRobotButton(robot, this);
    _layout->addWidget(button);

    QObject::connect(button,SIGNAL(clicked()),_robot_mapper,SLOT(map()));
    _robot_mapper->setMapping(button, _buttons.length());
    _buttons.append(button);

    return robot;
}

QRobot *QRobotCoordinator::addRobot(QMavlinkConnection *connection)
{
    QRobot* robot = findRobot(connection->getRobotID(), connection->getRobotType());
    if(robot == NULL){
        robot = this->addRobot(connection->getRobotID(), connection->getRobotType());
    }
    robot->addConnection(connection);

    return robot;
}

QRobot *QRobotCoordinator::findRobot(unsigned int id, unsigned int type)
{
    QListIterator<QRobot*> i(_robots);
    while(i.hasNext()){
        qDebug() << i.peekNext()->id() << id;
        if(i.next()->id() == id){
            return i.peekPrevious();
        }
    }

    return NULL;
}

void QRobotCoordinator::closeEvent(QCloseEvent *e)
{
    QListIterator<QRobot*> robot(_robots);
    while (robot.hasNext())
        robot.next()->close();
}


void QRobotCoordinator::showAboutDialog()
{
    QAboutDialog *d = new QAboutDialog(this);
    d->setApplicationTitle("QRoboticsCenter");
    d->setVersion("0.1.0");
    d->setIcon(":/icons/car.png");
}

void QRobotCoordinator::mavlinkConnectionFound(QMavlinkConnection *connection)
{
    addRobot(connection);
}

void QRobotCoordinator::showRobotWidget(int index)
{
    _robots[index]->show();
}

QAction* QRobotCoordinator::getRescanAction()
{
    return _rescan;
}

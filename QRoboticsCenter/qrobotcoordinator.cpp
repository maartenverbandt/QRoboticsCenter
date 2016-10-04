#include "qrobotcoordinator.h"

QRobotCoordinator::QRobotCoordinator() :
    QMainWindow(),
    _layout(new QVBoxLayout()),
    _robot_mapper(new QSignalMapper(this)),
    _rescan(new QAction("Scan",this)),
    _scan_usb(new QAction("usb",this)),
    _scan_bluetooth(new QAction("bluetooth",this)),
    _about(new QAction("About",this)),
    _connection_coordinator(new QConnectionCoordinator(this))
{
    // setup central widget
    QWidget* central_widget = new QWidget(this);
    central_widget->setLayout(_layout);
    this->setCentralWidget(central_widget);

    QObject::connect(_connection_coordinator, SIGNAL(mavlinkConnectionFound(QMavlinkConnection*)), this, SLOT(mavlinkConnectionFound(QMavlinkConnection*)));
    QObject::connect(_rescan,SIGNAL(triggered()),this,SLOT(scan()));

    QObject::connect(_robot_mapper,SIGNAL(mapped(int)),this,SLOT(showRobotWidget(int)));

    QMenu *scan = menuBar()->addMenu("Scan");
    _rescan->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    scan->addAction(_rescan);
    scan->addSeparator();
    _scan_usb->setCheckable(true);
    _scan_bluetooth->setCheckable(true);
    scan->addAction(_scan_usb);
    scan->addAction(_scan_bluetooth);

    QObject::connect(_about,SIGNAL(triggered(bool)),this,SLOT(showAboutDialog()));
    addAction(_about);

    QMenu *help = menuBar()->addMenu("Help");
    help->addAction(_about);

    loadSettings();

    setMinimumWidth(250);
}

QRobotCoordinator::~QRobotCoordinator()
{
    saveSettings();
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

void QRobotCoordinator::saveSettings()
{
    QSettings settings("RobSoft", "QRoboticsCenter");

    // set window group
    settings.beginGroup("QRobotCoordinator");

    // save window settings
    settings.setValue("pos", pos());

    //save scan settings
    settings.setValue("scan_usb", _scan_usb->isChecked());
    settings.setValue("scan_bluetooth", _scan_bluetooth->isChecked());

    settings.endGroup();
}

void QRobotCoordinator::loadSettings()
{
    QSettings settings("RobSoft", "QRoboticsCenter");

    // set window group
    settings.beginGroup("QRobotCoordinator");

    // restore window settings
    move(settings.value("pos", QPoint(200, 200)).toPoint());

    //save scan settings
    _scan_usb->setChecked(settings.value("scan_usb",true).toBool());
    _scan_bluetooth->setChecked(settings.value("scan_bluetooth",false).toBool());

    settings.endGroup();
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

void QRobotCoordinator::scan()
{
    if(_scan_usb->isChecked())
        _connection_coordinator->scanUSB();
    if(_scan_bluetooth->isChecked())
        _connection_coordinator->scanBT();
}

QAction* QRobotCoordinator::getRescanAction()
{
    return _rescan;
}

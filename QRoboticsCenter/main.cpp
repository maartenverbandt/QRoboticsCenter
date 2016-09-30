#include <QApplication>
#include <qconnectioncoordinator.h>
#include <qrobotcoordinator.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QConnectionCoordinator c;
    QRobotCoordinator w;
    QObject::connect(&c, SIGNAL(mavlinkConnectionFound(QMavlinkConnection*)), &w, SLOT(mavlinkConnectionFound(QMavlinkConnection*)));
    QObject::connect(w.getRescanAction(),SIGNAL(triggered()),&c,SLOT(query()));

    w.show();
    //w.addRobot(100,10);
    //w.addRobot(101,11);
    //w.addRobot(102,20);

    c.query();

    //QRobot *r = new QBallbot(102,0);
    //r->show();

    return a.exec();
}

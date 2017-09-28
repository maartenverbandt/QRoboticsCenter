#include <QApplication>
#include <qrobotcoordinator.h>

//#define DEBUG

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("QRoboticsCenter");
    a.setOrganizationName("RobSoft");
    a.setApplicationVersion("4.2.5");
    a.setApplicationDisplayName("QRoboticsCenter");
    a.setWindowIcon(QIcon(":/icons/QRoboticsCenterLogo_blue.png"));

    QRobotCoordinator w;

    w.show();
    w.scan();

#ifdef DEBUG
    w.addRobot(1,1);
    w.addRobot(2,2);
    w.addRobot(10,QRobotCoordinator::CAR);
    w.addRobot(23,QRobotCoordinator::BALLBOT);
#endif

    //QExternalPortDialog* d = new QExternalPortDialog();
    //QFilePort* w2 = new QFilePort();
    //d->addPort(w2,"File");
    //d->show();

    return a.exec();
}

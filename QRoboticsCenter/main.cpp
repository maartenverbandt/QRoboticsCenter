#include <QApplication>
#include <qrobotcoordinator.h>
#include <qexternalportdialog.h>
#include <qfileport.h>

//#define DEBUG

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRobotCoordinator w;

    w.show();
    w.scan();

#ifdef DEBUG
    w.addRobot(10,QRobot::CAR);
    w.addRobot(23,QRobot::BALLBOT);    
#endif

    //QExternalPortDialog* d = new QExternalPortDialog();
    //QFilePort* w2 = new QFilePort();
    //d->addPort(w2,"File");
    //d->show();

    return a.exec();
}

#include <QApplication>
#include <qrobotcoordinator.h>

#define DEBUG

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRobotCoordinator w;

    w.show();
    w.scan();

#ifdef DEBUG
    w.addRobot(23,QRobot::BALLBOT);
#endif

    return a.exec();
}

#include <QApplication>
#include <qrobotcoordinator.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRobotCoordinator w;

    w.show();
    w.scan();

    return a.exec();
}

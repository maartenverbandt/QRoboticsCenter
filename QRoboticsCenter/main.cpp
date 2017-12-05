#include <QtGui>
#include <QApplication>

#include <qroboticscentermainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("QRoboticsCenter");
    a.setOrganizationName("RobSoft");
    a.setApplicationVersion("5.0.0 - alpha");
    a.setApplicationDisplayName("QRoboticsCenter");
    a.setWindowIcon(QIcon(":/icons/QRoboticsCenterLogo_blue.png"));

    QRoboticsCenterMainwindow mainwindow;
    mainwindow.show();

    return a.exec();
}

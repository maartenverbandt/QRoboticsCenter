#ifndef QCAR_H
#define QCAR_H

#include <qabstractrobot.h>

class QCar : public QAbstractRobot
{
    Q_OBJECT

public:
    QCar(int id, QObject* parent = 0);
    void setup();

    QString getType();
    QIcon getIcon();

    QRobotWindow *getWindow();
    QRobotConnectionManager *getConnectionManager();
    QRobotRecorderManager *getRecorderManager();

private:
    QRobotConnectionManager* _connection_manager;
    QRobotWindow *_window;
    QRobotRecorderManager* _recorder_manager;

};

#endif // QCAR_H

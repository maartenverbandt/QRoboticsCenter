#ifndef QBASICROBOT_H
#define QBASICROBOT_H

#include <qabstractrobot.h>

class QBasicRobot : public QAbstractRobot
{
    Q_OBJECT

public:
    QBasicRobot(int id, QObject* parent = 0);
    void setup();

    virtual QString getType() = 0;
    virtual QIcon getIcon() = 0;

    QRobotWindow *getWindow();
    QRobotConnectionManager *getConnectionManager();
    QRobotRecorderManager *getRecorderManager();
    virtual QRobotCommandManager *getCommandManager();

private:
    QRobotConnectionManager* _connection_manager;
    QRobotWindow *_window;
    QRobotRecorderManager* _recorder_manager;
    QRobotCommandManager* _command_manager;

};

#endif // QBASICROBOT_H

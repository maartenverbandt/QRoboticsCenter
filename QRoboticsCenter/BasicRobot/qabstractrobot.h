#ifndef QABSTRACTROBOT_H
#define QABSTRACTROBOT_H

#include <QObject>
#include <qrobotwindow.h>
#include <qrobotconnectionmanager.h>
#include <qrobotrecordermanager.h>
#include <qrobotlog.h>
#include <qcontrollerdeviceinterface.h>

class QAbstractRobot : public QObject
{
    Q_OBJECT

public:
    explicit QAbstractRobot(int id, QObject *parent = 0);
    virtual void setup();

    virtual QString getType() = 0;
    virtual QIcon getIcon() = 0;

    virtual QRobotWindow *getWindow() = 0;
    virtual QRobotConnectionManager* getConnectionManager() = 0;
    virtual QRobotRecorderManager* getRecorderManager() = 0;
    virtual void setControllerDevice(QControllerDeviceInterface* c);
    virtual void removeControllerDevice();

    int id();
    QString getName();
    QRobotLog *getLog();

    virtual void saveState();
    virtual void restoreState();

private:
    const int _id;
    QRobotLog* _log;

};

#endif // QABSTRACTROBOT_H

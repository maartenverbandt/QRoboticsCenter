#ifndef QABSTRACTROBOT_H
#define QABSTRACTROBOT_H

#include <QObject>
#include <qrobotwindow.h>
#include <qrobotconnectionmanager.h>
#include <qrobotrecordermanager.h>


class QAbstractRobot : public QObject
{
    Q_OBJECT

public:
    explicit QAbstractRobot(int id, QObject *parent = 0);

    virtual QString getType() = 0;
    virtual QIcon getIcon() = 0;

    virtual QRobotWindow *getWindow() = 0;
    virtual QRobotConnectionManager* getConnectionManager() = 0;
    virtual QRobotRecorderManager* getRecorderManager() = 0;

    int id();
    QString getName();

private:
    const int _id;

signals:

public slots:
};

#endif // QABSTRACTROBOT_H

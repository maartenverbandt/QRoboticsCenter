#ifndef QROBOTCOORDINATOR_H
#define QROBOTCOORDINATOR_H

#include <QObject>
#include <QLayout>
#include <qrobot.h>
#include <qballbot.h>
#include <qsegbot.h>
#include <qmavlinkconnection.h>

class QRobotCoordinator : public QWidget
{
    Q_OBJECT
public:
    explicit QRobotCoordinator(QWidget *parent = 0);
    QRobot* addRobot(unsigned int id, unsigned int type);
    QRobot* addRobot(QMavlinkConnection* connection);

private:
    QLayout* _layout;
    QList<QRobot*> _robots;
    QList<QPushButton*> _buttons;
    QSignalMapper* _robot_mapper;

signals:

public slots:
    void mavlinkConnectionFound(QMavlinkConnection *connection);
    void showRobotWidget(int index);

};

#endif // QROBOTCOORDINATOR_H

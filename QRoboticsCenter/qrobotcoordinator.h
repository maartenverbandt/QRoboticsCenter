#ifndef QROBOTCOORDINATOR_H
#define QROBOTCOORDINATOR_H

#include <QObject>
#include <QMainWindow>
#include <QLayout>
#include <qrobot.h>
#include <qrobotbutton.h>
#include <qballbot.h>
#include <qsegbot.h>
#include <qmavlinkconnection.h>
#include <qaboutdialog.h>

class QRobotCoordinator : public QMainWindow
{
    Q_OBJECT
public:
    explicit QRobotCoordinator(QWidget *parent = 0);

    QRobot* addRobot(unsigned int id, unsigned int type);
    QRobot* addRobot(QMavlinkConnection* connection);
    QRobot* findRobot(unsigned int id, unsigned int type);

    QAction* getRescanAction();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    QLayout* _layout;
    QList<QRobot*> _robots;
    QList<QPushButton*> _buttons;
    QSignalMapper* _robot_mapper;

    QAction* _rescan;
    QAction* _about;

signals:

private slots:
    void showAboutDialog();

public slots:
    void mavlinkConnectionFound(QMavlinkConnection *connection);
    void showRobotWidget(int index);

};

#endif // QROBOTCOORDINATOR_H

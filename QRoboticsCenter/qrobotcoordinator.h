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
#include <qtrustmaster.h>

class QRobotCoordinator : public QMainWindow
{
    Q_OBJECT
public:
    explicit QRobotCoordinator();
    ~QRobotCoordinator();

    QRobot* addRobot(unsigned int id, unsigned int type);
    QRobot* addRobot(QMavlinkConnection* connection);
    QRobot* findRobot(unsigned int id, unsigned int type);

    QAction* getRescanAction();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    QLayout* _layout;
    QList<QRobot*> _robots;
    int _current_robot;
    QList<QPushButton*> _buttons;
    QSignalMapper* _robot_mapper;

    QAction* _rescan;
    QAction* _scan_usb;
    QAction* _scan_bluetooth;
    QAction* _about;

    QConnectionCoordinator* _connection_coordinator;
    QControllerDeviceInterface* _controller_device;
    void connectController();
    void disconnectController();

    void saveSettings();
    void loadSettings();

signals:

private slots:
    void showAboutDialog();

public slots:
    void mavlinkConnectionFound(QMavlinkConnection *connection);
    void showRobotWidget(int index);
    void showNextRobotWidget();
    void showPrevRobotWidget();
    void scan();

};

#endif // QROBOTCOORDINATOR_H

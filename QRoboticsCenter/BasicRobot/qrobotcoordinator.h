#ifndef QROBOTCOORDINATOR_H
#define QROBOTCOORDINATOR_H

#include <QObject>
#include <QMainWindow>
#include <QLayout>
#include <qrobotbutton.h>
#include <qunknownrobot.h>
#include <qcar.h>
#include <qballbot.h>
#include <qtiltingtable.h>
#include <qmavlinkconnection.h>
#include <qaboutdialog.h>
//#include <qtrustmaster.h>

class QRobotCoordinator : public QMainWindow
{
    Q_OBJECT
public:
    explicit QRobotCoordinator();
    ~QRobotCoordinator();

    QAbstractRobot* addRobot(unsigned int id, unsigned int type);
    QAbstractRobot* addRobot(QMavlinkConnection* connection);
    QAbstractRobot* findRobot(unsigned int id, unsigned int type);

    QAction* getRescanAction();

    typedef enum type_t{
        BALLBOT = 10,
        SEGBOT = 11,
        TILTINGTABLE = 12,
        CAR = 20
    } type_t;

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    QLayout* _layout;
    QList<QAbstractRobot*> _robots;
    int _current_robot;
    QList<QPushButton*> _buttons;
    QSignalMapper* _robot_mapper;

    QAction* _rescan;
    QAction* _scan_usb;
    QAction* _scan_bluetooth;
    QAction* _about;

    QConnectionCoordinator* _connection_coordinator;
    //QControllerDeviceInterface* _controller_device;
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

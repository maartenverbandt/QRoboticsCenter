#ifndef QROBOTCOMMANDMANAGER_H
#define QROBOTCOMMANDMANAGER_H

#include <qexternalportdialog.h>
#include <qgpiocsvreader.h>
#include <qtudpreader.h>
#include <qrobotconnectionmanager.h>
#include <qgamepadinputwidget.h>

class QRobotCommandManager : public QExternalPortDialog
{
    Q_OBJECT

public:
    explicit QRobotCommandManager(QObject *parent = 0);
    virtual void setupMainWindow(QMainWindow *m);
    virtual void connect(QRobotConnectionManager* c);

    QInputWidget *getCsvInputWidget();
    QInputWidget *getUdpInputWidget();
    QGamepadInputWidget *getGamepadInputWidget();

protected:
    QInputWidget *_csv;
    QInputWidget *_udp;
    QGamepadInputWidget *_gamepad;

};

#endif // QROBOTCOMMANDMANAGER_H

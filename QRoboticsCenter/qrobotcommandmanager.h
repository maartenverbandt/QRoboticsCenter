#ifndef QROBOTCOMMANDMANAGER_H
#define QROBOTCOMMANDMANAGER_H

#include <qexternalportdialog.h>
#include <qgpiocsvreader.h>
#include <qtudpreader.h>
#include <qrobotconnectionmanager.h>

class QRobotCommandManager : public QExternalPortDialog
{
    Q_OBJECT

public:
    explicit QRobotCommandManager(QObject *parent = 0);
    virtual void setupMainWindow(QMainWindow *m);
    virtual void connect(QRobotConnectionManager* c);

    QInputWidget *getCsvInputWidget();
    QInputWidget *getUdpInputWidget();

protected:
    QInputWidget *_csv;
    QInputWidget *_udp;

};

#endif // QROBOTCOMMANDMANAGER_H

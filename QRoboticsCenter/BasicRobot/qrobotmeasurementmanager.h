#ifndef QROBOTMEASUREMENTMANAGER_H
#define QROBOTMEASUREMENTMANAGER_H

#include <qoutputdialog.h>
#include <qtudpsender.h>
#include <qrobotconnectionmanager.h>
#include <qoutputwidget.h>

class QRobotMeasurementManager : public QOutputDialog
{
    Q_OBJECT

public:
    explicit QRobotMeasurementManager(QObject *parent = 0);
    virtual void setupMainWindow(QMainWindow *m);
    virtual void connect(QRobotConnectionManager* c);

    QOutputWidget *getUdpOutputWidget();

protected:
    QOutputWidget *_udp;

};

#endif // QROBOTMEASUREMENTMANAGER_H

#ifndef QROBOTMEASUREMENTMANAGER_H
#define QROBOTMEASUREMENTMANAGER_H

#include <qoutputwidget.h>
#include <qmeasurementportdialog.h>
#include <qtudpwriter.h>
#include <qrobotconnectionmanager.h>

class QRobotMeasurementManager : public QMeasurementPortDialog
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

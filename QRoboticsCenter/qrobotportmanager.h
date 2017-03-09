#ifndef QROBOTPORTMANAGER_H
#define QROBOTPORTMANAGER_H

#include <QObject>
#include <QMenu>
#include "qgpioportdialog.h"
#include "qrobotconnectionmanager.h"

class QRobotPortManager : public QObject
{
    Q_OBJECT
public:
    explicit QRobotPortManager(QObject *parent = 0);

    virtual void connect(QRobotConnectionManager *m);
    QMenu *menu();

protected:
    void addPort(QExternalPortDialog* p);

private:
    QGPIOPortDialog *_gpio;

    QMenu *_menu;

};

#endif // QROBOTPORTMANAGER_H

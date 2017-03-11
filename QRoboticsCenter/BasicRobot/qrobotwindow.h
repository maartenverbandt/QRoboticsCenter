#ifndef QROBOTWINDOW_H
#define QROBOTWINDOW_H

#include <QStatusBar>
#include <qstackedwindow.h>
#include <qgpiowidget.h>
#include <qthreadingdialog.h>
#include <qrobotconnectionmanager.h>

class QRobotWindow : public QStackedWindow
{
    Q_OBJECT

public:
    explicit QRobotWindow(QWidget *parent = 0);
    void connect(QRobotConnectionManager* c);

    QGPIOWidget *getGPIOWidget();
    QThreadingDialog *getThreadingDialog();

    virtual void saveState(QString group);
    virtual void restoreState(QString group);

protected:
    void sendEvent(int id);

private:
    QGPIOWidget *_gpio;
    QThreadingDialog *_threading;

    void setupGPIOWidget();

signals:
    void eventMsgSend(mavlink_event_t event);

private slots:
    void eventButtonPressed(int id);

};

#endif // QROBOTWINDOW_H

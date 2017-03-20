#ifndef QROBOTRECORDERMANAGER_H
#define QROBOTRECORDERMANAGER_H

#include <QObject>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <qabstractrecorder.h>
#include <qgpiorecorder.h>
#include <qrecorderwidget.h>
#include <qrobotconnectionmanager.h>
#include <mavlink.h>

class QRobotRecorderManager : public QObject
{
    Q_OBJECT

public:
    explicit QRobotRecorderManager(QGPIOWidget *gpio, QObject *parent = 0);
    virtual void setupMainWindow(QMainWindow *m);
    void connect(QRobotConnectionManager* c);

    QRecorderWidget* getRecorderWidget();
    QGPIORecorder* getGPIORecorder();
    QMenu *getMenu();
    QAction *getQuickRecord();

protected:
    int addRecorder(QAbstractRecorder* recorder);

    typedef enum event_t{
        LOG_START = 300,
        LOG_STOP = 301,
        LOG_GPIO = 302
    } event_t;
    void sendEvent(int id);

private:
    QGPIORecorder* _gpio;
    QRecorderWidget* _widget;

    QMenu* _menu;
    QAction* _quick_record;

    void setupGpioRecorder();
    void setupQuickRecord();


signals:
    void eventMsgSend(mavlink_event_t event);

protected slots:
    void requestStartRecording(int id);
    void requestStopRecording();

private slots:
    void requestGpioRecording();
    virtual void quickRecord(bool checked);

};

#endif // QROBOTRECORDERMANAGER_H

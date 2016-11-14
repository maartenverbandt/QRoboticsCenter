#ifndef QROBOTRECORDERMANAGER_H
#define QROBOTRECORDERMANAGER_H

#include <QObject>
#include <QMenu>
#include <qabstractrecorder.h>
#include <qgpiorecorder.h>
#include <qrecorderwidget.h>
#include <mavlink.h>

class QRobotRecorderManager : public QObject
{
    Q_OBJECT

public:
    explicit QRobotRecorderManager(QGPIOWidget *gpio, QObject *parent = 0);

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

public slots:
    virtual void receiveMessage(mavlink_message_t msg);

protected slots:
    void requestStartRecording(int id);
    void requestStopRecording();

private slots:
    virtual void quickRecord(bool checked);

    void requestGpioRecording();

};

#endif // QROBOTRECORDERMANAGER_H

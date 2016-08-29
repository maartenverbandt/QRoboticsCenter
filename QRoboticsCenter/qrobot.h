#ifndef QROBOT_H
#define QROBOT_H

#include "qrecorderwidget.h"

#include <QWidget>
#include <QMainWindow>
#include <qmavlinkconnection.h>
#include <qgpiowidget.h>
#include <qprintstitcher.h>
#include <qabstractrecorder.h>
#include <qgpiorecorder.h>
#include <qthreadingwidget.h>

class QRobot : public QMainWindow
{
    Q_OBJECT
public:
    explicit QRobot(unsigned int id, QWidget *parent = 0);
    explicit QRobot(unsigned int id, QString type, QIcon icon, QWidget *parent = 0);

    typedef enum type_t{
        BALLBOT = 10,
        SEGBOT = 11,
        CAR = 20
    } type_t;

    typedef enum event_t{
        SEND_CONFIG = 100,
        SAVE_CONFIG = 101
    } event_t;

    unsigned int id();
    QString getType();
    QIcon getIcon();

    void addConnection(QMavlinkConnection* connection);
    QStackedWidget* getStack();
    int stackUp();
    int stackDown();

    QList<QAbstractRecorder*> recorders;

protected:
    const unsigned int  _id;
    const QString       _type;
    const QIcon         _icon;

    void sendMessage(const mavlink_message_t &msg);
    void sendEvent(QRobot::event_t event);

    int addView(QWidget* w);
    void setView(int index);

    void setupMainWindow();
    void setupGPIOWidget();

    void addRecorder(QAbstractRecorder* recorder);
    void addRobotMenuAction(QAction* open);

    void closeEvent(QCloseEvent *event);

private:
    QList<QMavlinkConnection*> _connections;

    QList<QAbstractRecorder*> _recorders;

    QMenu* _robot_menu;
    QMenu* _connections_menu;
    QMenu* _recorder_menu;
    QAction* _quickrecord_action;

    QStackedWidget* _stack;
    QGPIOWidget* _gpiowidget;

    QRecorderWidget* _recorder;
    QThreadingWidget* _threading;

    QPrintStitcher* _stitcher;

signals:
    void gpioReceived(QVector<float> doubles, QVector<int> ints, double time);
    //void threadReceived()
    void printReceived(QString text);

private slots:
    void eventButtonPressed(int b);
    void gpioSet(QVector<float> doubles, QVector<int> ints);
    void setStatusBarMessage(QString text);

protected slots:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void quickRecordToggled(bool b);

public slots:
    virtual void receiveMessage(mavlink_message_t msg);
    virtual void saveSettings();

};

#endif // QROBOT_H

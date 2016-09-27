#ifndef QROBOT_H
#define QROBOT_H

#include "qrecorderwidget.h"

#include <QWidget>
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <qmavlinkconnection.h>
#include <qgpiowidget.h>
#include <qprintstitcher.h>
#include <qabstractrecorder.h>
#include <qgpiorecorder.h>
#include <qthreadingwidget.h>
#include <qgpioinputdialog.h>

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
        SAVE_CONFIG = 101,
        MODE_INDEX = 200
    } event_t;

    unsigned int id();
    QString getType();
    QString getName();
    QIcon getIcon();

    void addConnection(QMavlinkConnection* connection);
    QStackedWidget* getStack();

    QList<QAbstractRecorder*> recorders;

    bool serverConnected();

protected:
    const unsigned int  _id;
    const QString       _type;
    const QIcon         _icon;

    void sendMessage(const mavlink_message_t &msg);
    void sendEvent(int event);
    void sendPartition(const char id, QByteArray data, int index = 0);

    virtual void handlePartition(const char id, const QByteArray &partition, const int index);

    int addView(QWidget* w);
    void setView(int index);

    void setupMainWindow();
    void setupGPIOWidget();
    void setupRobotLog();

    void addRecorder(QAbstractRecorder* recorder);
    void addRobotMenuAction(QAction* open);

    void closeEvent(QCloseEvent *event);

private:
    QList<QMavlinkConnection*> _connections;

    QList<QAbstractRecorder*> _recorders;

    QMenu* _robot_menu;
    QMenu* _connections_menu;
    QMenu* _tools_menu;
    QMenu* _recorder_menu;
    QAction* _quickrecord_action;

    QStackedWidget* _stack;
    QAction* _stackup_action;
    QAction* _stackdown_action;

    QGPIOWidget* _gpiowidget;

    QRecorderWidget* _recorder;
    QThreadingWidget* _threading;
    QGPIOInputDialog* _gpioinput;

    QPrintStitcher* _stitcher;
    QFile* _robot_log;

    QTcpServer* _server;
    QTcpSocket* _socket;

signals:
    void gpioReceived(QGPIOWidget::gpio_t gpio);
    //void threadReceived()
    void printReceived(QString text);

private slots:
    void eventButtonPressed(int b);
    void setGpioOutput(QGPIOWidget::gpio_t gpio);
    void setStatusBarMessage(QString text);

    void stackUp();
    void stackDown();

protected slots:
    virtual void quickRecordToggled(bool b);

public slots:
    virtual void receiveMessage(mavlink_message_t msg);

    void sendRobotSettings(); //request config from robot
    void writeRobotSettings(QByteArray data); //write new config file
    void saveRobotSettings(); //save config file to eeprom

    virtual void saveSettings();

    void restartServer();
    void handleNewConnection();
    void readFromSocket();
    void writeToSocket(QGPIOWidget::gpio_t gpio);

};

#endif // QROBOT_H

#ifndef QROBOTCONNECTIONMANAGER_H
#define QROBOTCONNECTIONMANAGER_H

#include <QObject>
#include <QMenu>
#include <QMenuBar>
#include <mavlink.h>
#include <qprintstitcher.h>
#include <qmavlinkconnection.h>

#include <qstackedwindow.h>
#include <qgpiowidget.h> //should be removed later on.. //FIX
#include <qthreadingwidget.h> //should be removed later on..

class QRobotConnectionManager : public QObject
{
    Q_OBJECT

public:
    explicit QRobotConnectionManager(QObject *parent = 0);
    virtual void setupMainWindow(QStackedWindow *m);

    void addConnection(QMavlinkConnection* connection);
    QAction *suspendAllAction();

protected:
    //virtual void handlePartition(const char id, const QByteArray &partition, const int index);
    void sendMessage(const mavlink_message_t &msg);

private:
    QList<QMavlinkConnection*> _connections;
    QMenu* _menu;

    QPrintStitcher* _stitcher;

    QAction _activate_all;

signals:
    //void gpioReceived(QGPIOWidget::gpio_t gpio); //obsolete in future

    // msg received signals
    void packetReceived(QVariant packet);
    void printReceived(QString text); //special print stiched
    void gpioMsgReceived(mavlink_gpio_t gpio);
    void threadinfoMsgReceived(mavlink_thread_info_t thread);
    void partitionMsgReceived(mavlink_partition_t partition);

/*private slots:
    void eventButtonPressed(int b);
    void setGpioOutput(QGPIOWidget::gpio_t gpio);
    void setStatusBarMessage(QString text);*/

public slots:
    virtual void receiveMessage(mavlink_message_t msg);
    virtual void packetSend(QVariant packet);

    void packetsSend(QList<QVariant> packets);
    void gpioMsgSend(mavlink_gpio_t gpio);
    void eventMsgSend(mavlink_event_t event);
    void partitionMsgSend(mavlink_partition_t partition);
    //void sendPartition(const char id, QByteArray data, int index = 0);
    void toggleActivateAll();
};

//Q_DECLARE_METATYPE(mavlink_gpio_t)
//Q_DECLARE_METATYPE(mavlink_thread_info_t)
//Q_DECLARE_METATYPE(mavlink_partition_t)

#endif // QROBOTCONNECTIONMANAGER_H

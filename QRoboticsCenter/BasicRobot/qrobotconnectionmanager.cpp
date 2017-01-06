#include "qrobotconnectionmanager.h"

QRobotConnectionManager::QRobotConnectionManager(QObject *parent) :
    QObject(parent),
    _menu(new QMenu("Connections")),
    _stitcher(new QPrintStitcher(this))
{

}

void QRobotConnectionManager::setupMainWindow(QMainWindow *m)
{
    m->menuBar()->addMenu(_menu);
}

void QRobotConnectionManager::addConnection(QMavlinkConnection *connection)
{
    _connections.append(connection);
    QObject::connect(connection,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),this,SLOT(receiveMessage(mavlink_message_t)));

    QMenu* menu = connection->constructMenu();
    _menu->addMenu(menu);
}

void QRobotConnectionManager::sendMessage(const mavlink_message_t &msg)
{
    if(!_connections.isEmpty())
        _connections[0]->mavlinkMsgSend(msg);
    else
        qDebug() << "Error when sending message: no connections in the list.";
}

void QRobotConnectionManager::receiveMessage(mavlink_message_t msg)
{
    switch(msg.msgid){
        case MAVLINK_MSG_ID_GPIO:{
            mavlink_gpio_t gpio;
            mavlink_msg_gpio_decode(&msg, &gpio);

            emit gpioMsgReceived(gpio);
        break; }

        case MAVLINK_MSG_ID_PRINT:{
            mavlink_print_t print;
            mavlink_msg_print_decode(&msg, &print);

            if(_stitcher->stitch(QString(print.text),32)){
                emit printReceived(_stitcher->getLine());
            }
        break; }

        case MAVLINK_MSG_ID_THREAD_INFO:{
            mavlink_thread_info_t thread_info;
            mavlink_msg_thread_info_decode(&msg,&thread_info);

            /*thread_t thread;
            thread.id = thread_info.ID;
            thread.time = thread_info.time;
            thread.priority = thread_info.priority;
            thread.average_duration = thread_info.total_duration/thread_info.number_of_executions;
            thread.average_latency = thread_info.total_latency/thread_info.number_of_executions;
            thread.duration = thread_info.duration;
            thread.latency = thread_info.latency;
            thread.executions = thread_info.number_of_executions;*/

            //FIX
            //_threading->updateThreadInfo(thread);
            emit threadinfoMsgReceived(thread_info);
        break; }

        case MAVLINK_MSG_ID_PARTITION:{
            mavlink_partition_t partition;
            mavlink_msg_partition_decode(&msg,&partition);

            //handlePartition(partition.ID, QByteArray((char*)partition.value,partition.size), partition.index);
            emit partitionMsgReceived(partition);
        break; }
    }
}

void QRobotConnectionManager::gpioMsgSend(mavlink_gpio_t gpio)
{
    mavlink_message_t msg;
    mavlink_msg_gpio_encode(0,0,&msg,&gpio);
    sendMessage(msg);
}

void QRobotConnectionManager::eventMsgSend(mavlink_event_t event)
{
    mavlink_message_t msg;
    mavlink_msg_event_encode(0,0,&msg,&event);
    sendMessage(msg);
}

void QRobotConnectionManager::partitionMsgSend(mavlink_partition_t partition)
{
    mavlink_message_t msg;
    mavlink_msg_partition_encode(0,0,&msg,&partition);
    sendMessage(msg);
}

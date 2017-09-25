#include "qrobotconnectionmanager.h"

QRobotConnectionManager::QRobotConnectionManager(QObject *parent) :
    QObject(parent),
    _menu(new QMenu("Connections")),
    _stitcher(new QPrintStitcher(this)),
    _activate_all("suspend_all",this)
{
    _activate_all.setCheckable(true);
    _activate_all.setChecked(true);
    _activate_all.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    QObject::connect(&_activate_all,&QAction::toggled,this,&QRobotConnectionManager::toggleActivateAll);
}

void QRobotConnectionManager::setupMainWindow(QStackedWindow *m)
{
    m->menuBar()->addMenu(_menu);
    m->addAction(&_activate_all);
    QObject::connect(&_activate_all,&QAction::toggled,m,&QStackedWindow::setStackEnabled);
}

void QRobotConnectionManager::addConnection(QMavlinkConnection *connection)
{
    _connections.append(connection);
    QObject::connect(connection,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),this,SLOT(receiveMessage(mavlink_message_t)));

    QMenu* menu = connection->constructMenu();
    _menu->addMenu(menu);
}

QAction *QRobotConnectionManager::suspendAllAction()
{
    return &_activate_all;
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

            QVariant packet;
            packet.setValue<mavlink_gpio_t>(gpio);
            emit packetReceived(packet);
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

void QRobotConnectionManager::packetSend(QVariant packet)
{
    int t = packet.userType();
    if(t == qMetaTypeId<mavlink_gpio_t>()){
        gpioMsgSend(packet.value<mavlink_gpio_t>());
    } else if (t == qMetaTypeId<mavlink_event_t>()){
        eventMsgSend(packet.value<mavlink_event_t>());
    } else if (t == qMetaTypeId<mavlink_partition_t>()){
        partitionMsgSend(packet.value<mavlink_partition_t>());
    } /*else{
        qDebug() << "Unable to handle variant packet";
    }*/
}

void QRobotConnectionManager::packetsSend(QList<QVariant> packets)
{
    QListIterator<QVariant> i(packets);
    while(i.hasNext()){
        packetSend(i.next());
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

void QRobotConnectionManager::toggleActivateAll()
{
    QListIterator<QMavlinkConnection*> i(_connections);
    while(i.hasNext())
        i.next()->getActivateAction()->toggle();
}

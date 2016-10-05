#include "qrobot.h"

QRobot::QRobot(unsigned int id, QWidget *parent) :
    QMainWindow(parent),
    _id(id),
    _type("Unknown"),
    _icon(QIcon()),
    _server(new QTcpServer(this)),
    _socket(NULL)
{
    setupMainWindow();
    setCentralWidget(_stack);
    setupGPIOWidget();
    setupRobotLog();

    QObject::connect(_server,SIGNAL(newConnection()),this,SLOT(handleNewConnection()));
    restartServer();
}

QRobot::QRobot(unsigned int id, QString type, QIcon icon, QWidget *parent) :
    QMainWindow(parent),
    _id(id),
    _type(type),
    _icon(icon),
    _server(new QTcpServer(this)),
    _socket(NULL)
{
    setupMainWindow();
    setCentralWidget(_stack);
    setupGPIOWidget();
    setupRobotLog();

    QObject::connect(_server,SIGNAL(newConnection()),this,SLOT(handleNewConnection()));
    restartServer();
}

unsigned int QRobot::id()
{
    return _id;
}

QString QRobot::getType()
{
    return _type;
}

QString QRobot::getName()
{
    return _type + QString::number(_id);
}

QIcon QRobot::getIcon()
{
    return _icon;
}

void QRobot::addConnection(QMavlinkConnection *connection)
{
    _connections.append(connection);
    QObject::connect(connection,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),this,SLOT(receiveMessage(mavlink_message_t)));

    QMenu* menu = connection->constructMenu();
    _connections_menu->addMenu(menu);
}

bool QRobot::serverConnected()
{
    return (_socket != NULL);
}

void QRobot::stackUp()
{
    int new_index = _stack->currentIndex()+1;
    if(new_index>_stack->count())
        new_index = 0;
    _stack->setCurrentIndex(new_index);
}

void QRobot::stackDown()
{
    int new_index = _stack->currentIndex()-1;
    if(new_index < 0)
        new_index = _stack->count();
    _stack->setCurrentIndex(new_index);
}

void QRobot::sendMessage(const mavlink_message_t &msg)
{
    if(!_connections.isEmpty())
        _connections[0]->mavlinkMsgSend(msg);
    else
        qDebug() << "Error when sending message: no connections in the list.";
}

void QRobot::sendEvent(int event)
{
    mavlink_message_t msg;
    mavlink_msg_event_pack(0,0,&msg,event);
    sendMessage(msg);
}

void QRobot::sendPartition(const char id, QByteArray data, int index)
{
    mavlink_message_t msg;
    mavlink_partition_t partition;
    partition.ID = id;

    int count = 0;
    int chunk = 32;

    qDebug() << "Sending partition with" << data.size() << "bytes";
    qDebug() << data;

    for(count = data.size();count >= 0;count-=32){
        if(count < 32)
            chunk = data.size()-index;

        partition.size = chunk;
        partition.index = index;
        memcpy(partition.value,(uint8_t*)(data.data()+index),chunk);

        mavlink_msg_partition_encode(0,0,&msg,&partition);
        sendMessage(msg);
        index += 32;
        qDebug() << "Chunk size: " << chunk;
    }
}

void QRobot::handlePartition(const char id, const QByteArray &partition, const int index)
{
    qDebug() << "QRobot is not handling the partition";
}

void QRobot::receiveMessage(mavlink_message_t msg)
{
    switch(msg.msgid){
        case MAVLINK_MSG_ID_GPIO:{
            mavlink_gpio_t gpio;
            mavlink_msg_gpio_decode(&msg, &gpio);

            // put info on the socket
            QGPIOWidget::gpio_t gpio_;
            memcpy(gpio_.floats,gpio.gpio_float,32); //copy 8*4=32 bytes
            memcpy(gpio_.ints,gpio.gpio_int,16); //copy 4*4=16 bytes
            gpio_.time = gpio.time;
            writeToSocket(gpio_);

            // emit the message for whatever widget using it
            emit gpioReceived(gpio_);
        break; }

        case MAVLINK_MSG_ID_PRINT:{
            mavlink_print_t print;
            mavlink_msg_print_decode(&msg, &print);

            if(_stitcher->stitch(QString(print.text),32)){
                setStatusBarMessage(_stitcher->getLine());
                _robot_log->write(_stitcher->getLine().toLatin1());
                _robot_log->flush(); //force a quick update
                printReceived(_stitcher->getLine());
            }
        break; }

        case MAVLINK_MSG_ID_THREAD_INFO:{
            mavlink_thread_info_t thread_info;
            mavlink_msg_thread_info_decode(&msg,&thread_info);

            thread_t thread;
            thread.id = thread_info.ID;
            thread.time = thread_info.time;
            thread.priority = thread_info.priority;
            thread.average_duration = thread_info.total_duration/thread_info.number_of_executions;
            thread.average_latency = thread_info.total_latency/thread_info.number_of_executions;
            thread.duration = thread_info.duration;
            thread.latency = thread_info.latency;
            thread.executions = thread_info.number_of_executions;

            _threading->updateThreadInfo(thread);
        break; }

        case MAVLINK_MSG_ID_PARTITION:{
            mavlink_partition_t partition;
            mavlink_msg_partition_decode(&msg,&partition);

            handlePartition(partition.ID, QByteArray((char*)partition.value,partition.size), partition.index);
        break; }
    }
}

void QRobot::sendRobotSettings()
{
    sendEvent(QRobot::SEND_CONFIG);
}


void QRobot::requestStartLogging()
{
    sendEvent(QRobot::LOG_START);
}

void QRobot::requestStopLogging()
{
    sendEvent(QRobot::LOG_STOP);
}

void QRobot::writeRobotSettings(QByteArray data)
{
    sendPartition('C',data);
    qDebug() << "sending partition data.";
}

void QRobot::saveRobotSettings()
{
    sendEvent(QRobot::SAVE_CONFIG);
}

void QRobot::saveSettings()
{
    _gpiowidget->saveSettings();
}

int QRobot::addView(QWidget* w)
{
    //make action and menu
    int index = _stack->addWidget(w);
    setView(index);
    return index;
}

void QRobot::setView(int index)
{
    _stack->setCurrentIndex(index);
}

void QRobot::eventButtonPressed(int b)
{
    mavlink_message_t msg;
    mavlink_msg_event_pack(0,0,&msg,1000+b);

    emit sendMessage(msg);
}

void QRobot::setGpioOutput(QGPIOWidget::gpio_t gpio)
{
    mavlink_message_t msg;
    mavlink_msg_gpio_pack(0,0,&msg,gpio.time,gpio.floats,gpio.ints);

    emit sendMessage(msg);
}

void QRobot::setupMainWindow()
{
    //initialization of the members
    _robot_menu = new QMenu("Settings",this);
    _connections_menu = new QMenu("Connections",this);
    _tools_menu = new QMenu("Tools",this);
    _recorder_menu = new QMenu("Recorders",this);
    _stack = new QStackedWidget(this);
    _recorder = new QRecorderWidget(this);

    _quickrecord_action = new QAction("Quick record",this);
    _quickrecord_action->setCheckable(true);
    _quickrecord_action->setChecked(false);
    _quickrecord_action->setShortcut(Qt::CTRL + Qt::Key_R);
    QObject::connect(_quickrecord_action,SIGNAL(toggled(bool)),this,SLOT(quickRecordToggled(bool)));
    addAction(_quickrecord_action);

    _stackup_action = new QAction("next",this);
    _stackup_action->setShortcut(Qt::CTRL + Qt::Key_Right);
    QObject::connect(_stackup_action,SIGNAL(triggered(bool)),this,SLOT(stackUp()));
    addAction(_stackup_action);

    _stackdown_action = new QAction("next",this);
    _stackdown_action->setShortcut(Qt::CTRL + Qt::Key_Left);
    QObject::connect(_stackdown_action,SIGNAL(triggered(bool)),this,SLOT(stackDown()));
    addAction(_stackdown_action);

    _stitcher = new QPrintStitcher(this);
    _threading = new QThreadingWidget(0);

    _gpioinput = new QGPIOInputDialog(0);
    QObject::connect(_gpioinput,SIGNAL(setGpioOutput(QGPIOWidget::gpio_t)),this,SLOT(setGpioOutput(QGPIOWidget::gpio_t)));

    //setup the statusbar
    statusBar()->addPermanentWidget(_recorder);

    //setup the settings
    menuBar()->addMenu(_robot_menu);

    //setup the connections
    menuBar()->addMenu(_connections_menu);

    //setup the tools
    menuBar()->addMenu(_tools_menu);
    _tools_menu->addAction(_threading->getPopupAction());
    _tools_menu->addAction(_gpioinput->getPopupAction());
    _tools_menu->addMenu(_recorder_menu);
}

void QRobot::setStatusBarMessage(QString text)
{
    statusBar()->showMessage(text,2000);
}

void QRobot::quickRecordToggled(bool b)
{
    _recorders[0]->recorder()->setChecked(b);
}

void QRobot::setupGPIOWidget()
{
    _gpiowidget = new QGPIOWidget(this);

    QObject::connect(this,SIGNAL(gpioReceived(QGPIOWidget::gpio_t)),_gpiowidget,SLOT(setInput(QGPIOWidget::gpio_t)));
    QObject::connect(_gpiowidget,SIGNAL(eventButtonPressed(int)),this,SLOT(eventButtonPressed(int)));
    QObject::connect(_gpiowidget,SIGNAL(setOutput(QGPIOWidget::gpio_t)),this,SLOT(setGpioOutput(QGPIOWidget::gpio_t)));

    //add recorder
    QGPIORecorder* gpiorec = new QGPIORecorder(this);
    QObject::connect(this,SIGNAL(gpioReceived(QGPIOWidget::gpio_t)),gpiorec,SLOT(gpioReceived(QGPIOWidget::gpio_t)));
    QObject::connect(_gpiowidget,SIGNAL(inputLabelsSet(QStringList)),gpiorec,SLOT(setLabels(QStringList)));
    addRecorder(gpiorec);
    _gpiowidget->inputLabelsSend();

    //add view
    addView(_gpiowidget);
}

void QRobot::setupRobotLog()
{
    _robot_log = new QFile(QDir::tempPath() + QDir::separator() + getName() + ".txt",this);
    if(!_robot_log->open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Error opening robot log file";
}

void QRobot::addRecorder(QAbstractRecorder *recorder)
{
    _recorders.append(recorder);
    _recorder_menu->addAction(recorder->recorder());
    QObject::connect(recorder,SIGNAL(started()),_recorder,SLOT(start()));
    QObject::connect(recorder,SIGNAL(started()),this,SLOT(requestStartLogging()));
    QObject::connect(recorder,SIGNAL(stopped()),_recorder,SLOT(stop()));
    QObject::connect(recorder,SIGNAL(stopped()),this,SLOT(requestStopLogging()));
}

void QRobot::addRobotMenuAction(QAction *open)
{
    _robot_menu->addAction(open);
}

void QRobot::closeEvent(QCloseEvent *event)
{
    _threading->close();
    saveSettings();
    event->accept();
}

void QRobot::restartServer()
{
    if(_server->isListening())
        _server->close();

    _server->listen(QHostAddress::LocalHost);
    qDebug() << "Started tcp server for" << getName() << ".";
    qDebug() << "The magic number is" << _server->serverPort();
}

void QRobot::handleNewConnection()
{
    if(_socket == NULL){
        _socket = _server->nextPendingConnection();
        _socket->open(QIODevice::ReadWrite);
        QObject::connect(_socket,SIGNAL(readyRead()),this,SLOT(readFromSocket()));
    } else {
        qDebug() << "Server is already connected.";
    }
}

void QRobot::readFromSocket()
{
    if(serverConnected()){
        while(_socket->bytesAvailable() >= sizeof(QGPIOWidget::gpio_t)){
            QByteArray data = _socket->read(sizeof(QGPIOWidget::gpio_t));
            QGPIOWidget::gpio_t packet = *(QGPIOWidget::gpio_t*)data.data();

            setGpioOutput(packet);
            qDebug() << "New socket data: gpio data written to robot.";
        }
    }
}

void QRobot::writeToSocket(QGPIOWidget::gpio_t gpio)
{
    if(serverConnected()){
        QByteArray data((char*)(&gpio),sizeof(QGPIOWidget::gpio_t));
        _socket->write(data);

        qDebug() << "New incoming gpio data: gpio data written to socket";
    }
}

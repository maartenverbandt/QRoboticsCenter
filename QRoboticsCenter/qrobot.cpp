#include "qrobot.h"

QRobot::QRobot(unsigned int id, QWidget *parent) :
    QMainWindow(parent),
    _id(id),
    _type("Unknown"),
    _icon(QIcon())
{
    setupMainWindow();
    setCentralWidget(_stack);
    setupGPIOWidget();
}

QRobot::QRobot(unsigned int id, QString type, QIcon icon, QWidget *parent) :
    QMainWindow(parent),
    _id(id),
    _type(type),
    _icon(icon)
{
    setupMainWindow();
    setCentralWidget(_stack);
    setupGPIOWidget();
}

unsigned int QRobot::id()
{
    return _id;
}

QString QRobot::getType()
{
    return _type;
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

int QRobot::stackUp()
{
    int new_index = _stack->currentIndex()+1;
    if(new_index>_stack->count())
        new_index = 0;
    _stack->setCurrentIndex(new_index);

    return new_index;
}

int QRobot::stackDown()
{
    int new_index = _stack->currentIndex()-1;
    if(new_index < 0)
        new_index = _stack->count();
    _stack->setCurrentIndex(new_index);

    return new_index;
}

void QRobot::sendMessage(const mavlink_message_t &msg)
{
    if(!_connections.isEmpty())
        _connections[0]->mavlinkMsgSend(msg);
    else
        qDebug() << "Error when sending message: no connections in the list.";
}

void QRobot::sendEvent(QRobot::event_t event)
{
    mavlink_message_t msg;
    mavlink_msg_event_pack(0,0,&msg,event);
    sendMessage(msg);
}

void QRobot::receiveMessage(mavlink_message_t msg)
{
    switch(msg.msgid){
        case MAVLINK_MSG_ID_GPIO:{
            mavlink_gpio_t gpio;
            mavlink_msg_gpio_decode(&msg, &gpio);

            QVector<float> doubles; doubles.fill(0,8);
            QVector<int> ints; ints.fill(0,4);
            for(unsigned int k=0;k<8;k++){ doubles[k] = gpio.gpio_float[k]; }
            for(unsigned int k=0;k<4;k++){ ints[k] = gpio.gpio_int[k]; }

            emit gpioReceived(doubles,ints,gpio.time);
        break; }

        case MAVLINK_MSG_ID_PRINT:{
            mavlink_print_t print;
            mavlink_msg_print_decode(&msg, &print);

            if(_stitcher->stitch(QString(print.text),32)){
                setStatusBarMessage(_stitcher->getLine());
                printReceived(_stitcher->getLine());
            }
        break; }

        case MAVLINK_MSG_ID_PARTITION:{
            mavlink_partition_t partition;
            mavlink_msg_partition_decode(&msg,&partition);


        break; }
    }
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

void QRobot::gpioSet(QVector<float> doubles, QVector<int> ints)
{
    mavlink_message_t msg;
    mavlink_msg_gpio_pack(0,0,&msg,0,0,doubles.data(),ints.data());

    emit sendMessage(msg);
}

void QRobot::setupMainWindow()
{
    //initialization of the members
    _robot_menu = new QMenu("Settings",this);
    _connections_menu = new QMenu("Connections",this);
    _recorder_menu = new QMenu("Record",this);
    _stack = new QStackedWidget(this);
    _recorder = new QRecorderWidget(this);
    _stitcher = new QPrintStitcher(this);
    _threading = new QThreadingWidget(0);

    //setup the statusbar
    statusBar()->addPermanentWidget(_recorder);

    //setup the settings
    menuBar()->addMenu(_robot_menu);
    _robot_menu->addAction(_threading->getPopupAction());

    //setup the connections
    menuBar()->addMenu(_connections_menu);

    //setup the recorder
    menuBar()->addMenu(_recorder_menu);
    //Add thread analyzer
}

void QRobot::setStatusBarMessage(QString text)
{
    statusBar()->showMessage(text,2000);
}

void QRobot::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:{
        stackUp();
        break; }
    case Qt::Key_Right:{
        stackDown();
        break; }
    }
}

void QRobot::setupGPIOWidget()
{
    QGPIOWidget* widget = new QGPIOWidget(this);

    QObject::connect(this,SIGNAL(gpioReceived(QVector<float>,QVector<int>,double)),widget,SLOT(setGPIO(QVector<float>,QVector<int>)));
    QObject::connect(this,SIGNAL(printReceived(QString)),widget,SLOT(setPrint(QString)));
    QObject::connect(widget,SIGNAL(eventButtonPressed(int)),this,SLOT(eventButtonPressed(int)));
    QObject::connect(widget,SIGNAL(gpioSet(QVector<float>,QVector<int>)),this,SLOT(gpioSet(QVector<float>,QVector<int>)));

    //add recorder
    QGPIORecorder* gpiorec = new QGPIORecorder(this);
    QObject::connect(this,SIGNAL(gpioReceived(QVector<float>,QVector<int>,double)),gpiorec,SLOT(gpioReceived(QVector<float>,QVector<int>,double)));
    QObject::connect(widget,SIGNAL(inputLabelsSet(QStringList)),gpiorec,SLOT(setLabels(QStringList)));
    QObject::connect(gpiorec,SIGNAL(started()),_recorder,SLOT(start()));
    QObject::connect(gpiorec,SIGNAL(stopped()),_recorder,SLOT(stop()));
    addRecorder(gpiorec);

    //add view
    addView(widget);
}

void QRobot::addRecorder(QAbstractRecorder *recorder)
{
    _recorders.append(recorder);
    _recorder_menu->addAction(recorder->recorder());
}

void QRobot::addRobotMenuAction(QAction *open)
{
    _robot_menu->addAction(open);
}

void QRobot::closeEvent(QCloseEvent *event)
{
    _threading->close();
}

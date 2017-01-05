#include "qbalancingwidget.h"
#include "ui_qbalancingwidget.h"

QBalancingWidget::QBalancingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QBalancingWidget),
    _controls(new QButtonGroup(this)),
    _control_mode(0),
    _jumping(false)
{
    ui->setupUi(this);

    _controls->addButton(ui->idle_pushButton,0);
    _controls->addButton(ui->attitude_pushButton,1);
    _controls->addButton(ui->velocity_pushButton,2);
    _controls->addButton(ui->position_pushButton,3);

    QListIterator<QAbstractButton*> i(_controls->buttons());
    while(i.hasNext())
        i.next()->setCheckable(true);

    _controls->button(_control_mode)->setChecked(true);
    QObject::connect(_controls,SIGNAL(buttonClicked(int)),this,SLOT(handleControlsClicked(int)));

    // Setup balance widget
    ui->balance_widget->setRange(10);
    ui->balance_widget->addCircle(5);
    ui->balance_widget->addCircle(10);
    ui->balance_widget->setSize(20);

    // Setup map widget
    ui->map_widget->setRange(5000.0);
    ui->map_widget->getRobot()->getMarker()->setSize(200);
    ui->map_widget->getRobot()->getSpeed()->setSize(0.2);
}

QBalancingWidget::~QBalancingWidget()
{
    delete ui;
}

QFrame *QBalancingWidget::controlsFrame()
{
    return ui->controls_frame;
}

QFrame *QBalancingWidget::widgetsFrame()
{
    return ui->widgets_frame;
}

void QBalancingWidget::updatePosition(QVector3D position)
{
    ui->map_widget->getRobot()->setPosition(position.toVector2D());
}

void QBalancingWidget::updateAttitude(QVector3D attitude)
{
    ui->balance_widget->addPoint(QPointF(qRadiansToDegrees(attitude.x()),-qRadiansToDegrees(attitude.y())));
    ui->map_widget->getRobot()->setOrientation(attitude.z());
}

void QBalancingWidget::updateSpeedCommand(QVector2D command)
{
    ui->map_widget->getRobot()->setVelocity(command);
}

void QBalancingWidget::handleControlsClicked(int id)
{
    if((abs(id-_control_mode)==1) || (_jumping)){
        _control_mode = id;
        emit controlModeChanged(_control_mode);
    } else if(abs(id-_control_mode)!=0){
        _controls->button(_control_mode)->setChecked(true);
        qDebug() << "Cannot set the requested mode: jumping is not allowed.";
    }
}

#include "qbalancingwidget.h"
#include "ui_qbalancingwidget.h"

QBalancingWidget::QBalancingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QBalancingWidget),
    _controls(new QButtonGroup(this)),
    _control_mode(0),
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

    ui->balance_widget->setRange(10);
    ui->balance_widget->addCircle(5);
    ui->balance_widget->addCircle(10);
    ui->balance_widget->setSize(20);
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
    ui->map_widget->setPosition(position.toVector2D());
}

void QBalancingWidget::updateAttitude(QVector3D attitude)
{
    ui->balance_widget->addPoint(QPointF(qRadiansToDegrees(attitude.x()),qRadiansToDegrees(attitude.y())));
    ui->map_widget->setOrientation(attitude.z());
}

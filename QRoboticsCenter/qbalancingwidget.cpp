#include "qbalancingwidget.h"
#include "ui_qbalancingwidget.h"

QBalancingWidget::QBalancingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QBalancingWidget)
{
    ui->setupUi(this);

    ui->attitude_widget->xAxis->setVisible(false);
    ui->attitude_widget->yAxis->setVisible(false);
    ui->attitude_widget->xAxis->setRange(-10,10);
    ui->attitude_widget->yAxis->setRange(-10,10);
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

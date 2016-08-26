#ifndef QBALANCINGWIDGET_H
#define QBALANCINGWIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class QBalancingWidget;
}

class QBalancingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QBalancingWidget(QWidget *parent = 0);
    ~QBalancingWidget();

    QFrame* controlsFrame();
    QFrame* widgetsFrame();

private:
    Ui::QBalancingWidget *ui;
};

#endif // QBALANCINGWIDGET_H

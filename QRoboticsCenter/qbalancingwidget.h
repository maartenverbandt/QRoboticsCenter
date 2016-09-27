#ifndef QBALANCINGWIDGET_H
#define QBALANCINGWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QButtonGroup>
#include <QVector2D>
#include <QVector3D>
#include <QtMath>

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
    QButtonGroup *_controls;
    int _control_mode;

public slots:
    virtual void updatePosition(QVector3D position);
    virtual void updateAttitude(QVector3D attitude);

};

#endif // QBALANCINGWIDGET_H

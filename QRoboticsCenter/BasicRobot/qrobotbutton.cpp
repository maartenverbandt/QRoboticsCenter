#include "qrobotbutton.h"



QRobotButton::QRobotButton(QAbstractRobot *robot, QWidget *parent) :
    QPushButton(robot->getIcon(),robot->getType(),parent)
{
    _id = robot->id();
    setMinimumHeight(_icon_size);
}

void QRobotButton::paintEvent(QPaintEvent *)
{
    //make painter and button style object
    QStylePainter painter(this);
    QStyleOptionButton opt;
    initStyleOption(&opt);

    //draw button in right state
    opt.state = isDown() ? QStyle::State_Sunken : QStyle::State_Raised;
    if (isDefault())
        opt.features |= QStyleOptionButton::DefaultButton;
    painter.drawPrimitive(QStyle::PE_PanelButtonCommand, opt);

    //add margins to drawing area
    opt.rect -= QMargins(6,0,6,0);
    painter.drawItemPixmap(opt.rect, Qt::AlignLeft|Qt::AlignVCenter, icon().pixmap(QSize(_icon_size,_icon_size)));
    painter.drawItemText(opt.rect, Qt::AlignCenter, palette(), 1, text());
    painter.drawItemText(opt.rect, Qt::AlignRight|Qt::AlignVCenter, palette(), 1, QString::number(_id));
}



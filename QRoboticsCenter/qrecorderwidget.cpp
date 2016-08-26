#include "qrecorderwidget.h"

QRecorderWidget::QRecorderWidget(QWidget *parent) : QLabel(parent)
{
    setNum(0);
    setFrameShadow(Sunken);
    setFrameShape(StyledPanel);
    setMinimumSize(80,14);
    setAlignment(Qt::AlignCenter);
    setStyleSheet("QLabel { background-color : Forestgreen; color : black;  border-radius : 4px; border-style: outset; border-width: 1px; border-color: gray;}");
}

void QRecorderWidget::timerEvent(QTimerEvent *)
{
    setNum(text().toDouble() + 1.0);
}

void QRecorderWidget::start()
{
    setStyleSheet("QLabel { background-color : red; color : black; border-radius : 4px; border-style: outset; border-width: 1px; border-color: gray;}");
    timerid = startTimer(1000);
    setNum(0.0);
}

void QRecorderWidget::stop()
{
    setStyleSheet("QLabel { background-color : Forestgreen; color : black;  border-radius : 4px; border-style: outset; border-width: 1px; border-color: gray;}");
    killTimer(timerid);
}

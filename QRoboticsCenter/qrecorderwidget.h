#ifndef QRECORDERWIDGET_H
#define QRECORDERWIDGET_H

#include <QObject>
#include <QLabel>

class QRecorderWidget : public QLabel
{
    Q_OBJECT
public:
    explicit QRecorderWidget(QWidget *parent = 0);

private:
    int timerid;
    void timerEvent(QTimerEvent *);

public slots:
    void start();
    void stop();
};

#endif // QRECORDERWIDGET_H

#ifndef QGPIORECORDER_H
#define QGPIORECORDER_H

#include <qabstractrecorder.h>
#include <qgpiowidget.h>

class QGPIORecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QGPIORecorder(QObject* parent = 0);

private:
    QFile* _log;
    QStringList _labels;

    QString createHeader();

public slots:
    void gpioReceived(QGPIOWidget::gpio_t gpio);
    void setLabels(QStringList);
    void startRecording();
    void stopRecording();

};

#endif // QGPIORECORDER_H

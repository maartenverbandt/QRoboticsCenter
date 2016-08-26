#ifndef QGPIORECORDER_H
#define QGPIORECORDER_H

#include <qabstractrecorder.h>

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
    void gpioReceived(QVector<float>, QVector<int>, double);
    void setLabels(QStringList);
    void startRecording();
    void stopRecording();

};

#endif // QGPIORECORDER_H

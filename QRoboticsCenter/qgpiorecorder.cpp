#include "qgpiorecorder.h"
#include <qdebug.h>

QGPIORecorder::QGPIORecorder(QObject *parent) : QAbstractRecorder(parent), _log(NULL)
{
    _recorder.setText("GPIO");
    _labels.reserve(12);
}

QString QGPIORecorder::createHeader()
{
    QString header;
    header = "QGPIORecord\n";
    header += QDateTime::currentDateTime().toString("dd/MM/yy, HH'h'mm") + "\n";
    header += "1.0\n";
    header += "\n";
    header += "time\t" + _labels.join('\t') + "\n";

    return header;
}

void QGPIORecorder::gpioReceived(QVector<float> doubles, QVector<int> ints, double time)
{
    if(isRecording()){
        int k;
        QString line = QString::number(time);

        for(k=0;k<8;k++){
           line +=  "\t" + QString::number(doubles[k]);
        }

        for(k=0;k<4;k++){
           line +=  "\t" + QString::number(ints[k]);
        }

        line += QString("\n");

        _log->write(line.toLocal8Bit());
    }
}

void QGPIORecorder::setLabels(QStringList labels)
{
    _labels = labels;
}

void QGPIORecorder::startRecording()
{
    QAbstractRecorder::startRecording(); //emit signals

    _log = openDateFile("log_gpio");
    _log->open(QIODevice::ReadWrite);

    //make header
    _log->write(createHeader().toLocal8Bit());
}

void QGPIORecorder::stopRecording()
{
    QAbstractRecorder::stopRecording(); //emit signals

    _log->close();
}

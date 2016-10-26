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
    header = "<QGPIORecord>\n";

    // Time
    QDateTime now = QDateTime::currentDateTime();
    header += "\t<time>\n";
    header += "\t\t<year>" + now.toString("yyyy") + "</year>\n";
    header += "\t\t<month>" + now.toString("MM") + "</month>\n";
    header += "\t\t<day>" + now.toString("dd") + "</day>\n";
    header += "\t\t<hour>" + now.toString("HH") + "</hour>\n";
    header += "\t\t<minute>" + now.toString("mm") + "</minute>\n";
    header += "\t</time>\n";

    // Version
    header += "\t<version>2.0</version>\n";

    // Comment
    header += "\t<comment></comment>\n";
    header += "\n";

    // Labels
    header += "\t<labels>\n";
    header += "\t\t<value>time</value>\n";
    for(int k=0;k<_labels.length();k++){
        header += "\t\t<value>" + _labels[k] + "</value>\n";
    }
    header += "\t</labels>\n";

    // Data
    header += "\t<data>\n";

    return header;
}

QString QGPIORecorder::createFooter()
{
    QString footer;
    footer += "\t</data>\n";
    footer += "</QGPIORecord>";

    return footer;
}

void QGPIORecorder::gpioReceived(QGPIOWidget::gpio_t gpio)
{
    if(isRecording()){
        int k;

        QString line = "\t\t<row>";
        line += QString::number(gpio.time);

        for(k=0;k<8;k++){
            line +=  "\t" + QString::number(gpio.floats[k]);
        }

        for(k=0;k<4;k++){
           line +=  "\t" + QString::number(gpio.ints[k]);
        }

        line += "</row>\n";

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

    //make footer
    _log->write(createFooter().toLocal8Bit());
    _log->close();
}

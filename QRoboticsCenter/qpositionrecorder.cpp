#include "qpositionrecorder.h"

QPositionRecorder::QPositionRecorder(QObject *parent) : QAbstractRecorder(parent), _log(NULL)
{
    _recorder.setText("Position");
}

QString QPositionRecorder::createHeader()
{
    QString header;
    header = "QPositionRecord\n";
    header += QDateTime::currentDateTime().toString("dd/MM/yy, HH'h'mm") + "\n";
    header += "1.0\n";
    header += "\n";
    header += "time ;x ;y ;z ;xcmd ;ycmd; zcmd; xact; yact; zact;\n";

    return header;
}

void QPositionRecorder::positionReceived(mavlink_position_t position)
{
    if(isRecording()){
        QString line = QString::number(position.time);
        line += "\t" + QString::number(position.x);
        line += "\t" + QString::number(position.y);
        line += "\t" + QString::number(position.z);
        line += "\t" + QString::number(position.x_cmd);
        line += "\t" + QString::number(position.y_cmd);
        line += "\t" + QString::number(position.z_cmd);
        line += "\t" + QString::number(position.x_act);
        line += "\t" + QString::number(position.y_act);
        line += "\t" + QString::number(position.z_act);
        line += QString("\n");

        _log->write(line.toLocal8Bit());
    }
}

void QPositionRecorder::startRecording()
{
    QAbstractRecorder::startRecording(); //emit signals

    _log = openDateFile("log_position");
    _log->open(QIODevice::ReadWrite);

    //make header
    _log->write(createHeader().toLocal8Bit());
}

void QPositionRecorder::stopRecording()
{
    QAbstractRecorder::stopRecording(); //emit signals

    _log->close();
}

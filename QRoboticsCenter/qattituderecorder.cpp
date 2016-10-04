#include "qattituderecorder.h"

QAttitudeRecorder::QAttitudeRecorder(QObject *parent) : QAbstractRecorder(parent), _log(NULL)
{
    _recorder.setText("Attitude");
}

QString QAttitudeRecorder::createHeader()
{
    QString header;
    header = "QAttitudeRecord\n";
    header += QDateTime::currentDateTime().toString("dd/MM/yy, HH'h'mm") + "\n";
    header += "1.0\n";
    header += "\n";
    header += "time ;roll ;pitch ;yaw ;rollcmd ;pitchcmd; yawcmd; rollact; pitchact; yawact;\n";

    return header;
}

void QAttitudeRecorder::attitudeReceived(mavlink_attitude_t attitude)
{
    if(isRecording()){
        QString line = QString::number(attitude.time);
        line += "\t" + QString::number(attitude.roll);
        line += "\t" + QString::number(attitude.pitch);
        line += "\t" + QString::number(attitude.yaw);
        line += "\t" + QString::number(attitude.roll_cmd);
        line += "\t" + QString::number(attitude.pitch_cmd);
        line += "\t" + QString::number(attitude.yaw_cmd);
        line += "\t" + QString::number(attitude.roll_act);
        line += "\t" + QString::number(attitude.pitch_act);
        line += "\t" + QString::number(attitude.yaw_act);
        line += QString("\n");

        _log->write(line.toLocal8Bit());
    }
}

void QAttitudeRecorder::startRecording()
{
    QAbstractRecorder::startRecording(); //emit signals

    _log = openDateFile("log_attitude");
    _log->open(QIODevice::ReadWrite);

    //make header
    _log->write(createHeader().toLocal8Bit());
}

void QAttitudeRecorder::stopRecording()
{
    QAbstractRecorder::stopRecording(); //emit signals

    _log->close();
}

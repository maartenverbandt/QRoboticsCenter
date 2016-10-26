#include "qattituderecorder.h"

QAttitudeRecorder::QAttitudeRecorder(QObject *parent) : QAbstractRecorder(parent), _log(NULL)
{
    _recorder.setText("Attitude");
}

QString QAttitudeRecorder::createHeader()
{
    QString header;
    header = "<QAttitudeRecord>\n";

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

    // Excitation
    header += "\t<excitation>\n";
    header += "\t\t<type>unknown</type>\n";
    header += "\t\t<fmin>0</fmin>\n";
    header += "\t\t<fmax>inf</fmax>\n";
    header += "\t\t<period>inf</period>\n";
    header += "\t</excitation>\n";

    // Labels
    header += "\t<labels>\n";
    header += "\t\t<value>time</value>\n";
    header += "\t\t<value>roll</value>\n";
    header += "\t\t<value>pitch</value>\n";
    header += "\t\t<value>yaw</value>\n";
    header += "\t\t<value>rollcmd</value>\n";
    header += "\t\t<value>pitchcmd</value>\n";
    header += "\t\t<value>yawcmd</value>\n";
    header += "\t\t<value>rollact</value>\n";
    header += "\t\t<value>pitchact</value>\n";
    header += "\t\t<value>yawact</value>\n";
    header += "\t</labels>\n";

    // Data
    header += "\t<data>\n";

    return header;
}

QString QAttitudeRecorder::createFooter()
{
    QString footer;
    footer += "\t</data>\n";
    footer += "</QAttitudeRecord>";

    return footer;
}

void QAttitudeRecorder::attitudeReceived(mavlink_attitude_t attitude)
{
    if(isRecording()){
        QString line = "\t\t<row>";
        line += QString::number(attitude.time);
        line += "\t" + QString::number(attitude.roll);
        line += "\t" + QString::number(attitude.pitch);
        line += "\t" + QString::number(attitude.yaw);
        line += "\t" + QString::number(attitude.roll_cmd);
        line += "\t" + QString::number(attitude.pitch_cmd);
        line += "\t" + QString::number(attitude.yaw_cmd);
        line += "\t" + QString::number(attitude.roll_act);
        line += "\t" + QString::number(attitude.pitch_act);
        line += "\t" + QString::number(attitude.yaw_act);
        line += "</row>\n";

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

    //make footer
    _log->write(createFooter().toLocal8Bit());
    _log->close();
}

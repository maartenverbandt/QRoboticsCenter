#include "qvelocityrecorder.h"

QVelocityRecorder::QVelocityRecorder(QObject *parent) : QAbstractRecorder(parent), _log(NULL)
{
    _recorder.setText("Velocity");
}

QString QVelocityRecorder::createHeader()
{
    QString header;
    header = "<QVelocityRecord>\n";

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
    header += "\t<comment>none</comment>\n";
    header += "\n";

    // Excitation
    header += "\t<excitation>\n";
    header += "\t\t<type>unknown</type>\n";
    header += "\t\t<fmin>0</fmin>\n";
    header += "\t\t<fmax>inf</fmax>\n";
    header += "\t\t<fs>0</fs>\n";
    header += "\t\t<period>inf</period>\n";
    header += "\t</excitation>\n";

    // Labels
    header += "\t<labels>\n";
    header += "\t\t<value>time</value>\n";
    header += "\t\t<value>vx</value>\n";
    header += "\t\t<value>vy</value>\n";
    header += "\t\t<value>vz</value>\n";
    header += "\t\t<value>vxcmd</value>\n";
    header += "\t\t<value>vycmd</value>\n";
    header += "\t\t<value>vzcmd</value>\n";
    header += "\t\t<value>vxact</value>\n";
    header += "\t\t<value>vyact</value>\n";
    header += "\t\t<value>vzact</value>\n";
    header += "\t</labels>\n";

    // Data
    header += "\t<data>\n";

    return header;
}

QString QVelocityRecorder::createFooter()
{
    QString footer;
    footer += "\t</data>\n";
    footer += "</QVelocityRecord>";

    return footer;
}

void QVelocityRecorder::velocityReceived(mavlink_velocity_t velocity)
{
    if(isRecording()){
        QString line = "\t\t<row>";
        line += QString::number(velocity.time);
        line += "\t" + QString::number(velocity.vx);
        line += "\t" + QString::number(velocity.vy);
        line += "\t" + QString::number(velocity.vz);
        line += "\t" + QString::number(velocity.vx_cmd);
        line += "\t" + QString::number(velocity.vy_cmd);
        line += "\t" + QString::number(velocity.vz_cmd);
        line += "\t" + QString::number(velocity.vx_act);
        line += "\t" + QString::number(velocity.vy_act);
        line += "\t" + QString::number(velocity.vz_act);
        line += "</row>\n";

        _log->write(line.toLocal8Bit());
    }
}

void QVelocityRecorder::startRecording()
{
    QAbstractRecorder::startRecording(); //emit signals

    _log = openDateFile("log_velocity");
    _log->open(QIODevice::ReadWrite);

    //make header
    _log->write(createHeader().toLocal8Bit());
}

void QVelocityRecorder::stopRecording()
{
    QAbstractRecorder::stopRecording(); //emit signals

    //make footer
    _log->write(createFooter().toLocal8Bit());
    _log->close();
}

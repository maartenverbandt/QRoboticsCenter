#include "qpositionrecorder.h"

QPositionRecorder::QPositionRecorder(QObject *parent) : QAbstractRecorder(parent), _log(NULL)
{
    _recorder.setText("Position");
}

QString QPositionRecorder::createHeader()
{
    QString header;
    header = "<QPositionRecord>\n";

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
    header += "\t\t<value>x</value>\n";
    header += "\t\t<value>y</value>\n";
    header += "\t\t<value>z</value>\n";
    header += "\t\t<value>xcmd</value>\n";
    header += "\t\t<value>ycmd</value>\n";
    header += "\t\t<value>zcmd</value>\n";
    header += "\t\t<value>xact</value>\n";
    header += "\t\t<value>yact</value>\n";
    header += "\t\t<value>zact</value>\n";
    header += "\t</labels>\n";

    // Data
    header += "\t<data>\n";

    return header;
}

QString QPositionRecorder::createFooter()
{
    QString footer;
    footer += "\t</data>\n";
    footer += "</QPositionRecord>";

    return footer;
}

void QPositionRecorder::positionReceived(mavlink_position_t position)
{
    if(isRecording()){
        QString line = "\t\t<row>";
        line += QString::number(position.time);
        line += "\t" + QString::number(position.x);
        line += "\t" + QString::number(position.y);
        line += "\t" + QString::number(position.z);
        line += "\t" + QString::number(position.x_cmd);
        line += "\t" + QString::number(position.y_cmd);
        line += "\t" + QString::number(position.z_cmd);
        line += "\t" + QString::number(position.x_act);
        line += "\t" + QString::number(position.y_act);
        line += "\t" + QString::number(position.z_act);
        line += "</row>\n";

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

    //make footer
    _log->write(createFooter().toLocal8Bit());
    _log->close();
}

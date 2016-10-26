#include "qabstractrecorder.h"

QAbstractRecorder::QAbstractRecorder(QObject *parent) : QObject(parent), _recorder(this)
{
    _recorder.setCheckable(true);
    _recorder.setChecked(false);

    QObject::connect(&_recorder,SIGNAL(toggled(bool)),this,SLOT(handleToggled(bool)));
}

bool QAbstractRecorder::isRecording()
{
    return _recorder.isChecked();
}

QAction* QAbstractRecorder::recorder()
{
    return &_recorder;
}

QFile *QAbstractRecorder::openDateFile(QString prefix)
{
    QDir().mkdir("logs");
    QFile *log = new QFile("logs/" + prefix + "_" + QDateTime::currentDateTime().toString("MM_dd_HH_mm") + ".xml");

    return log;
}

void QAbstractRecorder::startRecording()
{
    emit started();
}

void QAbstractRecorder::stopRecording()
{
    emit stopped();
}

void QAbstractRecorder::handleToggled(bool checked)
{
    if(checked){
        startRecording();
    } else {
        stopRecording();
    }
}



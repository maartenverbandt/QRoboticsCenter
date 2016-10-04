#ifndef QATTITUDERECORDER_H
#define QATTITUDERECORDER_H

#include <qabstractrecorder.h>
#include <mavlink.h>

class QAttitudeRecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QAttitudeRecorder(QObject* parent = 0);

private:
    QFile* _log;
    QString createHeader();

public slots:
    void attitudeReceived(mavlink_attitude_t attitude);
    void startRecording();
    void stopRecording();

};

#endif // QATTITUDERECORDER_H

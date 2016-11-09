#ifndef QVELOCITYRECORDER_H
#define QVELOCITYRECORDER_H

#include <qabstractrecorder.h>
#include <mavlink.h>

class QVelocityRecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QVelocityRecorder(QObject* parent = 0);

private:
    QFile* _log;
    QString createHeader();
    QString createFooter();

public slots:
    void velocityReceived(mavlink_velocity_t velocity);
    void startRecording();
    void stopRecording();

};

#endif // QVELOCITYRECORDER_H

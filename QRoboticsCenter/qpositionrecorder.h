#ifndef QPOSITIONRECORDER_H
#define QPOSITIONRECORDER_H

#include <qabstractrecorder.h>
#include <mavlink.h>

class QPositionRecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QPositionRecorder(QObject* parent = 0);

private:
    QFile* _log;
    QString createHeader();

public slots:
    void positionReceived(mavlink_position_t position);
    void startRecording();
    void stopRecording();

};

#endif // QPOSITIONRECORDER_H

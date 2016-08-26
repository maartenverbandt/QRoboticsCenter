#ifndef QABSTRACTRECORDER_H
#define QABSTRACTRECORDER_H

#include <QObject>
#include <QAction>
#include <QFile>
#include <QDir>
#include <QDateTime>

class QAbstractRecorder : public QObject
{
    Q_OBJECT
public:
    explicit QAbstractRecorder(QObject *parent = 0);

    bool isRecording();
    QAction* recorder();

protected:
    QAction _recorder;
    QFile *openDateFile(QString prefix);

signals:
    void started();
    void stopped();

public slots:
    virtual void startRecording();
    virtual void stopRecording();

private slots:
    void handleToggled(bool checked);

};

#endif // QABSTRACTRECORDER_H

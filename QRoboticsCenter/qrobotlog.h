#ifndef QROBOTLOG_H
#define QROBOTLOG_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QDebug>

class QRobotLog : public QObject
{
    Q_OBJECT

public:
    explicit QRobotLog(QObject *parent = 0);
    void open(QString robot);

private:
    QFile* _robot_log;

public slots:
    void write(QString line);

};

#endif // QROBOTLOG_H

#ifndef QABSTRACTEXTERNALPORT_H
#define QABSTRACTEXTERNALPORT_H

#include <QObject>

class QAbstractExternalPort : public QObject
{
    Q_OBJECT
public:
    explicit QAbstractExternalPort(QObject *parent = 0);

signals:

public slots:
};

#endif // QABSTRACTEXTERNALPORT_H
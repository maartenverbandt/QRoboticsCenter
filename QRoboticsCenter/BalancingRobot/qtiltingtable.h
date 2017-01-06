#ifndef QTILTINGTABLE_H
#define QTILTINGTABLE_H

#include <qbalancingrobot.h>

class QTiltingTable : public QBalancingRobot
{
public:
    QTiltingTable(int id, QObject *parent = 0);
    void setup();

    QString getType();
    QIcon getIcon();
};

#endif // QTILTINGTABLE_H

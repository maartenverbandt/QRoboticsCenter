#ifndef QUNKNOWNROBOT_H
#define QUNKNOWNROBOT_H

#include <qbasicrobot.h>

class QUnknownRobot : public QBasicRobot
{
    Q_OBJECT

public:
    QUnknownRobot(int id, QObject* parent = 0);

    QString getType();
    QIcon getIcon();
};

#endif // QUNKNOWNROBOT_H

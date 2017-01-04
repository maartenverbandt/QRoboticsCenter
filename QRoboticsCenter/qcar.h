#ifndef QCAR_H
#define QCAR_H

#include <qbasicrobot.h>

class QCar : public QBasicRobot
{
    Q_OBJECT

public:
    QCar(int id, QObject* parent = 0);

    QString getType();
    QIcon getIcon();
};

#endif // QCAR_H

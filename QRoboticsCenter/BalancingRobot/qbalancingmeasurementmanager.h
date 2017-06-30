#ifndef QBALANCINGMEASUREMENTMANAGER_H
#define QBALANCINGMEASUREMENTMANAGER_H

#include <qrobotmeasurementmanager.h>

class QBalancingMeasurementManager : public QRobotMeasurementManager
{
    Q_OBJECT

public:
    explicit QBalancingMeasurementManager(QObject *parent = 0);

};

#endif // QBALANCINGMEASUREMENTMANAGER_H

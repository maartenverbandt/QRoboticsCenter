#include "qtiltingtable.h"

QTiltingTable::QTiltingTable(int id, QObject *parent) :
    QBalancingRobot(id,parent)
{
    //do nothing
}

void QTiltingTable::setup()
{
    // Default balancing robot setup
    QBalancingRobot::setup();
    QBalancingWidget* w = getWindow()->getBalancingView();

    // Setup jumping
    w->setJumping();

    // Setup map widget
    w->map()->setRange(100.0);
    w->map()->getRobot()->getMarker()->setSize(5.0);
    w->map()->getRobot()->getMarker()->setSize(0.0);
}

QString QTiltingTable::getType()
{
    return "TiltingTable";
}

QIcon QTiltingTable::getIcon()
{
    return QIcon(":/icons/tiltingtable.png");
}

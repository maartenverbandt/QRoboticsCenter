#ifndef QBALANCINGCOMMANDMANAGER_H
#define QBALANCINGCOMMANDMANAGER_H

#include <qrobotcommandmanager.h>
#include <qpositioncmdcsvreader.h>
#include <qvelocitygamepadcommand.h>

class QBalancingCommandManager : public QRobotCommandManager
{
    Q_OBJECT

public:
    explicit QBalancingCommandManager(QObject *parent = 0);
    virtual void connect(QRobotConnectionManager* c);

};

#endif // QBALANCINGCOMMANDMANAGER_H

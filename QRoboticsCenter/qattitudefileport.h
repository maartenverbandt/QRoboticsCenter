#ifndef QATTITUDEFILEPORT_H
#define QATTITUDEFILEPORT_H

#include <qfileport.h>
#include <mavlink.h>

class QAttitudeFilePort : public QFilePort
{
public:
    QAttitudeFilePort();

private:
    void sendData();

signals:
    void attitudeCommand(mavlink_attitude_cmd_t);

};

Q_DECLARE_METATYPE(mavlink_attitude_cmd_t)

#endif // QATTITUDEFILEPORT_H

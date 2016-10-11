#ifndef QATTITUDEFILEPORT_H
#define QATTITUDEFILEPORT_H

#include <qfileport.h>
#include <mavlink.h>

class QAttitudeFilePort : public QFilePort
{
    Q_OBJECT

public:
    explicit QAttitudeFilePort(QWidget *parent = 0);

private:
    void sendData();

signals:
    void attitudeCommand(mavlink_attitude_cmd_t cmd);

};

Q_DECLARE_METATYPE(mavlink_attitude_cmd_t)

#endif // QATTITUDEFILEPORT_H

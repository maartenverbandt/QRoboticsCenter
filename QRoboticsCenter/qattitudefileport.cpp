#include "qattitudefileport.h"

QAttitudeFilePort::QAttitudeFilePort()
{

}

void QAttitudeFilePort::sendData()
{
    QStringList line = readLine();
    if(line.length()!=6) {
        abort("Attitude command expects exactly 6 columns.");
    } else {
        mavlink_attitude_cmd_t attitude_cmd;
        attitude_cmd.roll = line[0].toUInt();
        attitude_cmd.pitch = line[1].toUInt();
        attitude_cmd.yaw = line[2].toUInt();
        attitude_cmd.rollFF = line[3].toUInt();
        attitude_cmd.pitchFF = line[4].toUInt();
        attitude_cmd.yawFF = line[5].toUInt();

        emit attitudeCommand(attitude_cmd);
    }
}

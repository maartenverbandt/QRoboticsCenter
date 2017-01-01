#ifndef BALLBOTCONFIGDIALOG_H
#define BALLBOTCONFIGDIALOG_H

#include <qrobotconfigdialog.h>
#include <QTreeWidget>

typedef struct __attribute__((__packed__)) ballbot_config_t{
    // robot statistics
    quint32 ballbot_runtime; 
    quint16 ballbot_dropcount;
    // robot parameters
    quint8  robot_id;
    // control setpoints
    float roll_offset;
    float pitch_offset;
    // controller configuration
    quint8 default_attitude_controller;
    quint8 default_velocity_controller;
    quint8 default_position_controller;
    quint8 default_yaw_velocity_controller;
    quint8 default_yaw_controller;
    // controller settings
    float attitude_gain_adjust;
    float velocity_gain_adjust;
    float position_gain_adjust;
    float yaw_velocity_gain_adjust;
    float yaw_gain_adjust;
    // maximum ratings
    float maximum_velocity;
    float maximum_yaw_velocity;
    // conversion
    float encoder_to_millimeter;
} ballbot_config_t;

class BallbotConfigDialog : public QRobotConfigDialog
{
    Q_OBJECT

public:
    BallbotConfigDialog(QWidget *parent = 0);
    ~BallbotConfigDialog();

    QByteArray getByteArray();
    void fromByteArray(const QByteArray &data, const int index = 0);

private:
    void load(ballbot_config_t config);

    ballbot_config_t _config;
};

#endif // BALLBOTCONFIGDIALOG_H

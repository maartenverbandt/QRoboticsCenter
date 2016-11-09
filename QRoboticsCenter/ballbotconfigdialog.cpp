#include "ballbotconfigdialog.h"

BallbotConfigDialog::BallbotConfigDialog(QWidget *parent) : QRobotConfigDialog("ballbot",parent)
{
    addGroup("Info")->setExpanded(true);
    addParameter("ID",&_config.robot_id,"Info");
    addGroup("Stats")->setExpanded(true);
    addParameter("ballbot runtime",&_config.ballbot_runtime,"Stats");
    addParameter("ballbot dropcount",&_config.ballbot_dropcount,"Stats");
    addGroup("IMU")->setExpanded(true);
    addParameter("roll offset",&_config.roll_offset,"IMU");
    addParameter("pitch offset",&_config.pitch_offset,"IMU");
    addGroup("Controllers")->setExpanded(true);
    addParameter("attitude controller",&_config.default_attitude_controller,"Controllers");
    addParameter("velocity controller",&_config.default_velocity_controller,"Controllers");
    addParameter("position controller",&_config.default_position_controller,"Controllers");
    addParameter("yaw velocity controller",&_config.default_yaw_velocity_controller,"Controllers");
    addParameter("yaw controller",&_config.default_yaw_controller,"Controllers");
    addParameter("attitude gain adjustment",&_config.attitude_gain_adjust,"Controllers");
    addParameter("velocity gain adjustment",&_config.velocity_gain_adjust,"Controllers");
    addParameter("position gain adjustment",&_config.position_gain_adjust,"Controllers");
    addParameter("yaw velocity gain adjustment",&_config.yaw_velocity_gain_adjust,"Controllers");
    addParameter("yaw gain adjustment",&_config.yaw_gain_adjust,"Controllers");
}

BallbotConfigDialog::~BallbotConfigDialog()
{

}

QByteArray BallbotConfigDialog::getByteArray()
{
    updateParameters(); //update the parameters from the widget first!
    QByteArray data((char*)(&_config), sizeof(_config));

    return data;
}

void BallbotConfigDialog::fromByteArray(const QByteArray &data, const int index)
{
    memcpy((char*)(&_config)+index,data.data(),data.size());
    updateWidgets(); //update the widgets after new parameters have been read
}

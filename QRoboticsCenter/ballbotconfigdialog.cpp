#include "ballbotconfigdialog.h"

BallbotConfigDialog::BallbotConfigDialog(QWidget *parent) : QRobotConfigDialog("ballbot",parent)
{
    addGroup("Stats");
    addParameter("ballbot runtime",&_config.ballbot_runtime,"Stats");
    addParameter("ballbot dropcount",&_config.ballbot_dropcount,"Stats");
    addGroup("IMU");
    addParameter("roll offset",&_config.roll_offset,"IMU");
    addParameter("pitch offset",&_config.pitch_offset,"IMU");
    addGroup("Controllers");
    addParameter("attitude controller",&_config.default_attitude_controller,"Controllers");
    addParameter("yaw controller",&_config.default_yaw_controller,"Controllers");
    addParameter("position controller",&_config.default_position_controller,"Controllers");

    setExpanded(true);
}

BallbotConfigDialog::~BallbotConfigDialog()
{

}

QByteArray BallbotConfigDialog::getByteArray()
{
    QByteArray data((char*)(&_config), sizeof(_config));
    qDebug() << *((int*)data.data());

    return data;
}

void BallbotConfigDialog::fromByteArray(const QByteArray &data)
{
    _config = *reinterpret_cast<const ballbot_config_t*>(data.data());
}

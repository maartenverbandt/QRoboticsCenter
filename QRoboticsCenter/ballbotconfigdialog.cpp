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
    addParameter("yaw controller",&_config.default_yaw_controller,"Controllers");
    addParameter("position controller",&_config.default_position_controller,"Controllers");
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

void BallbotConfigDialog::fromByteArray(const QByteArray &data, const int index)
{
    //_config = *reinterpret_cast<const ballbot_config_t*>(data.data());
    memcpy((char*)(&_config)+index,data.data(),data.size());
}

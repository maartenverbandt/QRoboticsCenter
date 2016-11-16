#include "qballbotinput.h"

QBallbotInput::QBallbotInput(QObject *parent) :
    QObject(parent),
    _controller(NULL)
{

}

void QBallbotInput::connect(QBalancingConnectionManager *c)
{
    QObject::connect(this,&QBallbotInput::velocityCmdMsgSend,c,&QBalancingConnectionManager::velocityCmdMsgSend);
}

void QBallbotInput::setControllerDevice(QControllerDeviceInterface *controller)
{
    _controller = controller;
    _timer = startTimer(100);
}

void QBallbotInput::removeControllerDevice()
{
    _controller = NULL;
    killTimer(_timer);
}

void QBallbotInput::timerEvent(QTimerEvent *)
{
    QControllerDeviceInterface::controller_state_t state = _controller->getState();
    mavlink_velocity_cmd_t velocity_cmd;
    if(state.buttonL2){
        velocity_cmd.vx = -state.axisRightX*1500.0;
        velocity_cmd.vy = -state.axisRightY*1500.0;
        velocity_cmd.vz = -state.axisLeftX*2000.0;
    } else {
        velocity_cmd.vx = 0.0;
        velocity_cmd.vy = 0.0;
        velocity_cmd.vz = 0.0;
    }
    emit velocityCmdMsgSend(velocity_cmd);
}


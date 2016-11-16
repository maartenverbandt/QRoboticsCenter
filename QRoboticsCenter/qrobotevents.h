#ifndef QROBOTEVENTS_H
#define QROBOTEVENTS_H

namespace QRoboticsCenter{
    typedef enum event_t{
        MODE_IDLE = 200,
        MODE_ATTITUDE = 201,
        MODE_VELOCITY = 202,
        MODE_POSITION = 203,
        LOG_GPIO = 302,
        LOG_ATTITUDE = 303,
        LOG_VELOCITY = 304,
        LOG_POSITION = 305,
        STOP_EXCITATION = 310,
        BUTTON = 1000
    } event_t;
}

#endif // QROBOTEVENTS_H

// MESSAGE BALLBOT_STATE PACKING

#define MAVLINK_MSG_ID_BALLBOT_STATE 70

typedef struct __mavlink_ballbot_state_t
{
 float X_est; ///< Estimated X position
 float Y_est; ///< Estimated Y position
 float dX_est; ///< Estimated X velocity
 float dY_est; ///< Estimated Y velocity
 float roll_est; ///< Estimated roll
 float pitch_est; ///< Estimated pitch
 float yaw_est; ///< Estimated yaw
 float droll_est; ///< Estimated droll
 float dpitch_est; ///< Estimated dpitch
 float dyaw_est; ///< Estimated dyaw
} mavlink_ballbot_state_t;

#define MAVLINK_MSG_ID_BALLBOT_STATE_LEN 40
#define MAVLINK_MSG_ID_70_LEN 40

#define MAVLINK_MSG_ID_BALLBOT_STATE_CRC 188
#define MAVLINK_MSG_ID_70_CRC 188



#define MAVLINK_MESSAGE_INFO_BALLBOT_STATE { \
	"BALLBOT_STATE", \
	10, \
	{  { "X_est", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ballbot_state_t, X_est) }, \
         { "Y_est", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ballbot_state_t, Y_est) }, \
         { "dX_est", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ballbot_state_t, dX_est) }, \
         { "dY_est", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ballbot_state_t, dY_est) }, \
         { "roll_est", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ballbot_state_t, roll_est) }, \
         { "pitch_est", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ballbot_state_t, pitch_est) }, \
         { "yaw_est", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ballbot_state_t, yaw_est) }, \
         { "droll_est", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ballbot_state_t, droll_est) }, \
         { "dpitch_est", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ballbot_state_t, dpitch_est) }, \
         { "dyaw_est", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_ballbot_state_t, dyaw_est) }, \
         } \
}


/**
 * @brief Pack a ballbot_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param X_est Estimated X position
 * @param Y_est Estimated Y position
 * @param dX_est Estimated X velocity
 * @param dY_est Estimated Y velocity
 * @param roll_est Estimated roll
 * @param pitch_est Estimated pitch
 * @param yaw_est Estimated yaw
 * @param droll_est Estimated droll
 * @param dpitch_est Estimated dpitch
 * @param dyaw_est Estimated dyaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float X_est, float Y_est, float dX_est, float dY_est, float roll_est, float pitch_est, float yaw_est, float droll_est, float dpitch_est, float dyaw_est)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_STATE_LEN];
	_mav_put_float(buf, 0, X_est);
	_mav_put_float(buf, 4, Y_est);
	_mav_put_float(buf, 8, dX_est);
	_mav_put_float(buf, 12, dY_est);
	_mav_put_float(buf, 16, roll_est);
	_mav_put_float(buf, 20, pitch_est);
	_mav_put_float(buf, 24, yaw_est);
	_mav_put_float(buf, 28, droll_est);
	_mav_put_float(buf, 32, dpitch_est);
	_mav_put_float(buf, 36, dyaw_est);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#else
	mavlink_ballbot_state_t packet;
	packet.X_est = X_est;
	packet.Y_est = Y_est;
	packet.dX_est = dX_est;
	packet.dY_est = dY_est;
	packet.roll_est = roll_est;
	packet.pitch_est = pitch_est;
	packet.yaw_est = yaw_est;
	packet.droll_est = droll_est;
	packet.dpitch_est = dpitch_est;
	packet.dyaw_est = dyaw_est;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_STATE_LEN, MAVLINK_MSG_ID_BALLBOT_STATE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif
}

/**
 * @brief Pack a ballbot_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param X_est Estimated X position
 * @param Y_est Estimated Y position
 * @param dX_est Estimated X velocity
 * @param dY_est Estimated Y velocity
 * @param roll_est Estimated roll
 * @param pitch_est Estimated pitch
 * @param yaw_est Estimated yaw
 * @param droll_est Estimated droll
 * @param dpitch_est Estimated dpitch
 * @param dyaw_est Estimated dyaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float X_est,float Y_est,float dX_est,float dY_est,float roll_est,float pitch_est,float yaw_est,float droll_est,float dpitch_est,float dyaw_est)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_STATE_LEN];
	_mav_put_float(buf, 0, X_est);
	_mav_put_float(buf, 4, Y_est);
	_mav_put_float(buf, 8, dX_est);
	_mav_put_float(buf, 12, dY_est);
	_mav_put_float(buf, 16, roll_est);
	_mav_put_float(buf, 20, pitch_est);
	_mav_put_float(buf, 24, yaw_est);
	_mav_put_float(buf, 28, droll_est);
	_mav_put_float(buf, 32, dpitch_est);
	_mav_put_float(buf, 36, dyaw_est);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#else
	mavlink_ballbot_state_t packet;
	packet.X_est = X_est;
	packet.Y_est = Y_est;
	packet.dX_est = dX_est;
	packet.dY_est = dY_est;
	packet.roll_est = roll_est;
	packet.pitch_est = pitch_est;
	packet.yaw_est = yaw_est;
	packet.droll_est = droll_est;
	packet.dpitch_est = dpitch_est;
	packet.dyaw_est = dyaw_est;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_STATE_LEN, MAVLINK_MSG_ID_BALLBOT_STATE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif
}

/**
 * @brief Encode a ballbot_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ballbot_state_t* ballbot_state)
{
	return mavlink_msg_ballbot_state_pack(system_id, component_id, msg, ballbot_state->X_est, ballbot_state->Y_est, ballbot_state->dX_est, ballbot_state->dY_est, ballbot_state->roll_est, ballbot_state->pitch_est, ballbot_state->yaw_est, ballbot_state->droll_est, ballbot_state->dpitch_est, ballbot_state->dyaw_est);
}

/**
 * @brief Encode a ballbot_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ballbot_state_t* ballbot_state)
{
	return mavlink_msg_ballbot_state_pack_chan(system_id, component_id, chan, msg, ballbot_state->X_est, ballbot_state->Y_est, ballbot_state->dX_est, ballbot_state->dY_est, ballbot_state->roll_est, ballbot_state->pitch_est, ballbot_state->yaw_est, ballbot_state->droll_est, ballbot_state->dpitch_est, ballbot_state->dyaw_est);
}

/**
 * @brief Send a ballbot_state message
 * @param chan MAVLink channel to send the message
 *
 * @param X_est Estimated X position
 * @param Y_est Estimated Y position
 * @param dX_est Estimated X velocity
 * @param dY_est Estimated Y velocity
 * @param roll_est Estimated roll
 * @param pitch_est Estimated pitch
 * @param yaw_est Estimated yaw
 * @param droll_est Estimated droll
 * @param dpitch_est Estimated dpitch
 * @param dyaw_est Estimated dyaw
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ballbot_state_send(mavlink_channel_t chan, float X_est, float Y_est, float dX_est, float dY_est, float roll_est, float pitch_est, float yaw_est, float droll_est, float dpitch_est, float dyaw_est)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_STATE_LEN];
	_mav_put_float(buf, 0, X_est);
	_mav_put_float(buf, 4, Y_est);
	_mav_put_float(buf, 8, dX_est);
	_mav_put_float(buf, 12, dY_est);
	_mav_put_float(buf, 16, roll_est);
	_mav_put_float(buf, 20, pitch_est);
	_mav_put_float(buf, 24, yaw_est);
	_mav_put_float(buf, 28, droll_est);
	_mav_put_float(buf, 32, dpitch_est);
	_mav_put_float(buf, 36, dyaw_est);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, buf, MAVLINK_MSG_ID_BALLBOT_STATE_LEN, MAVLINK_MSG_ID_BALLBOT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, buf, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif
#else
	mavlink_ballbot_state_t packet;
	packet.X_est = X_est;
	packet.Y_est = Y_est;
	packet.dX_est = dX_est;
	packet.dY_est = dY_est;
	packet.roll_est = roll_est;
	packet.pitch_est = pitch_est;
	packet.yaw_est = yaw_est;
	packet.droll_est = droll_est;
	packet.dpitch_est = dpitch_est;
	packet.dyaw_est = dyaw_est;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_STATE_LEN, MAVLINK_MSG_ID_BALLBOT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_BALLBOT_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ballbot_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float X_est, float Y_est, float dX_est, float dY_est, float roll_est, float pitch_est, float yaw_est, float droll_est, float dpitch_est, float dyaw_est)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, X_est);
	_mav_put_float(buf, 4, Y_est);
	_mav_put_float(buf, 8, dX_est);
	_mav_put_float(buf, 12, dY_est);
	_mav_put_float(buf, 16, roll_est);
	_mav_put_float(buf, 20, pitch_est);
	_mav_put_float(buf, 24, yaw_est);
	_mav_put_float(buf, 28, droll_est);
	_mav_put_float(buf, 32, dpitch_est);
	_mav_put_float(buf, 36, dyaw_est);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, buf, MAVLINK_MSG_ID_BALLBOT_STATE_LEN, MAVLINK_MSG_ID_BALLBOT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, buf, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif
#else
	mavlink_ballbot_state_t *packet = (mavlink_ballbot_state_t *)msgbuf;
	packet->X_est = X_est;
	packet->Y_est = Y_est;
	packet->dX_est = dX_est;
	packet->dY_est = dY_est;
	packet->roll_est = roll_est;
	packet->pitch_est = pitch_est;
	packet->yaw_est = yaw_est;
	packet->droll_est = droll_est;
	packet->dpitch_est = dpitch_est;
	packet->dyaw_est = dyaw_est;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_STATE_LEN, MAVLINK_MSG_ID_BALLBOT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_STATE, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE BALLBOT_STATE UNPACKING


/**
 * @brief Get field X_est from ballbot_state message
 *
 * @return Estimated X position
 */
static inline float mavlink_msg_ballbot_state_get_X_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field Y_est from ballbot_state message
 *
 * @return Estimated Y position
 */
static inline float mavlink_msg_ballbot_state_get_Y_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field dX_est from ballbot_state message
 *
 * @return Estimated X velocity
 */
static inline float mavlink_msg_ballbot_state_get_dX_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field dY_est from ballbot_state message
 *
 * @return Estimated Y velocity
 */
static inline float mavlink_msg_ballbot_state_get_dY_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field roll_est from ballbot_state message
 *
 * @return Estimated roll
 */
static inline float mavlink_msg_ballbot_state_get_roll_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitch_est from ballbot_state message
 *
 * @return Estimated pitch
 */
static inline float mavlink_msg_ballbot_state_get_pitch_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field yaw_est from ballbot_state message
 *
 * @return Estimated yaw
 */
static inline float mavlink_msg_ballbot_state_get_yaw_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field droll_est from ballbot_state message
 *
 * @return Estimated droll
 */
static inline float mavlink_msg_ballbot_state_get_droll_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field dpitch_est from ballbot_state message
 *
 * @return Estimated dpitch
 */
static inline float mavlink_msg_ballbot_state_get_dpitch_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field dyaw_est from ballbot_state message
 *
 * @return Estimated dyaw
 */
static inline float mavlink_msg_ballbot_state_get_dyaw_est(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a ballbot_state message into a struct
 *
 * @param msg The message to decode
 * @param ballbot_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_ballbot_state_decode(const mavlink_message_t* msg, mavlink_ballbot_state_t* ballbot_state)
{
#if MAVLINK_NEED_BYTE_SWAP
	ballbot_state->X_est = mavlink_msg_ballbot_state_get_X_est(msg);
	ballbot_state->Y_est = mavlink_msg_ballbot_state_get_Y_est(msg);
	ballbot_state->dX_est = mavlink_msg_ballbot_state_get_dX_est(msg);
	ballbot_state->dY_est = mavlink_msg_ballbot_state_get_dY_est(msg);
	ballbot_state->roll_est = mavlink_msg_ballbot_state_get_roll_est(msg);
	ballbot_state->pitch_est = mavlink_msg_ballbot_state_get_pitch_est(msg);
	ballbot_state->yaw_est = mavlink_msg_ballbot_state_get_yaw_est(msg);
	ballbot_state->droll_est = mavlink_msg_ballbot_state_get_droll_est(msg);
	ballbot_state->dpitch_est = mavlink_msg_ballbot_state_get_dpitch_est(msg);
	ballbot_state->dyaw_est = mavlink_msg_ballbot_state_get_dyaw_est(msg);
#else
	memcpy(ballbot_state, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_BALLBOT_STATE_LEN);
#endif
}

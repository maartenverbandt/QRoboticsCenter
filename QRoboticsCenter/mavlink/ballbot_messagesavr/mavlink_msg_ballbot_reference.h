// MESSAGE BALLBOT_REFERENCE PACKING

#define MAVLINK_MSG_ID_BALLBOT_REFERENCE 72

typedef struct __mavlink_ballbot_reference_t
{
 float pos_x; ///< Desired/actual x-position (position mode)/roll (attitude mode)
 float pos_y; ///< Desired/actual y-position (position mode)/pitch (attitude mode)
 float yaw; ///< Desired/actual yaw angle (position and attitude mode)
 uint32_t dt; ///< Time of trajectory.
 uint8_t mode; ///< Compatibility with reference trajectory command.
} mavlink_ballbot_reference_t;

#define MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN 17
#define MAVLINK_MSG_ID_72_LEN 17

#define MAVLINK_MSG_ID_BALLBOT_REFERENCE_CRC 169
#define MAVLINK_MSG_ID_72_CRC 169



#define MAVLINK_MESSAGE_INFO_BALLBOT_REFERENCE { \
	"BALLBOT_REFERENCE", \
	5, \
	{  { "pos_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ballbot_reference_t, pos_x) }, \
         { "pos_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ballbot_reference_t, pos_y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ballbot_reference_t, yaw) }, \
         { "dt", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_ballbot_reference_t, dt) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_ballbot_reference_t, mode) }, \
         } \
}


/**
 * @brief Pack a ballbot_reference message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pos_x Desired/actual x-position (position mode)/roll (attitude mode)
 * @param pos_y Desired/actual y-position (position mode)/pitch (attitude mode)
 * @param yaw Desired/actual yaw angle (position and attitude mode)
 * @param dt Time of trajectory.
 * @param mode Compatibility with reference trajectory command.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_reference_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float pos_x, float pos_y, float yaw, uint32_t dt, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN];
	_mav_put_float(buf, 0, pos_x);
	_mav_put_float(buf, 4, pos_y);
	_mav_put_float(buf, 8, yaw);
	_mav_put_uint32_t(buf, 12, dt);
	_mav_put_uint8_t(buf, 16, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#else
	mavlink_ballbot_reference_t packet;
	packet.pos_x = pos_x;
	packet.pos_y = pos_y;
	packet.yaw = yaw;
	packet.dt = dt;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_REFERENCE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN, MAVLINK_MSG_ID_BALLBOT_REFERENCE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif
}

/**
 * @brief Pack a ballbot_reference message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pos_x Desired/actual x-position (position mode)/roll (attitude mode)
 * @param pos_y Desired/actual y-position (position mode)/pitch (attitude mode)
 * @param yaw Desired/actual yaw angle (position and attitude mode)
 * @param dt Time of trajectory.
 * @param mode Compatibility with reference trajectory command.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_reference_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float pos_x,float pos_y,float yaw,uint32_t dt,uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN];
	_mav_put_float(buf, 0, pos_x);
	_mav_put_float(buf, 4, pos_y);
	_mav_put_float(buf, 8, yaw);
	_mav_put_uint32_t(buf, 12, dt);
	_mav_put_uint8_t(buf, 16, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#else
	mavlink_ballbot_reference_t packet;
	packet.pos_x = pos_x;
	packet.pos_y = pos_y;
	packet.yaw = yaw;
	packet.dt = dt;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_REFERENCE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN, MAVLINK_MSG_ID_BALLBOT_REFERENCE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif
}

/**
 * @brief Encode a ballbot_reference struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_reference C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_reference_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ballbot_reference_t* ballbot_reference)
{
	return mavlink_msg_ballbot_reference_pack(system_id, component_id, msg, ballbot_reference->pos_x, ballbot_reference->pos_y, ballbot_reference->yaw, ballbot_reference->dt, ballbot_reference->mode);
}

/**
 * @brief Encode a ballbot_reference struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_reference C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_reference_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ballbot_reference_t* ballbot_reference)
{
	return mavlink_msg_ballbot_reference_pack_chan(system_id, component_id, chan, msg, ballbot_reference->pos_x, ballbot_reference->pos_y, ballbot_reference->yaw, ballbot_reference->dt, ballbot_reference->mode);
}

/**
 * @brief Send a ballbot_reference message
 * @param chan MAVLink channel to send the message
 *
 * @param pos_x Desired/actual x-position (position mode)/roll (attitude mode)
 * @param pos_y Desired/actual y-position (position mode)/pitch (attitude mode)
 * @param yaw Desired/actual yaw angle (position and attitude mode)
 * @param dt Time of trajectory.
 * @param mode Compatibility with reference trajectory command.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ballbot_reference_send(mavlink_channel_t chan, float pos_x, float pos_y, float yaw, uint32_t dt, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN];
	_mav_put_float(buf, 0, pos_x);
	_mav_put_float(buf, 4, pos_y);
	_mav_put_float(buf, 8, yaw);
	_mav_put_uint32_t(buf, 12, dt);
	_mav_put_uint8_t(buf, 16, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, buf, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN, MAVLINK_MSG_ID_BALLBOT_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, buf, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif
#else
	mavlink_ballbot_reference_t packet;
	packet.pos_x = pos_x;
	packet.pos_y = pos_y;
	packet.yaw = yaw;
	packet.dt = dt;
	packet.mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN, MAVLINK_MSG_ID_BALLBOT_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ballbot_reference_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float pos_x, float pos_y, float yaw, uint32_t dt, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, pos_x);
	_mav_put_float(buf, 4, pos_y);
	_mav_put_float(buf, 8, yaw);
	_mav_put_uint32_t(buf, 12, dt);
	_mav_put_uint8_t(buf, 16, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, buf, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN, MAVLINK_MSG_ID_BALLBOT_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, buf, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif
#else
	mavlink_ballbot_reference_t *packet = (mavlink_ballbot_reference_t *)msgbuf;
	packet->pos_x = pos_x;
	packet->pos_y = pos_y;
	packet->yaw = yaw;
	packet->dt = dt;
	packet->mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN, MAVLINK_MSG_ID_BALLBOT_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_REFERENCE, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE BALLBOT_REFERENCE UNPACKING


/**
 * @brief Get field pos_x from ballbot_reference message
 *
 * @return Desired/actual x-position (position mode)/roll (attitude mode)
 */
static inline float mavlink_msg_ballbot_reference_get_pos_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field pos_y from ballbot_reference message
 *
 * @return Desired/actual y-position (position mode)/pitch (attitude mode)
 */
static inline float mavlink_msg_ballbot_reference_get_pos_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field yaw from ballbot_reference message
 *
 * @return Desired/actual yaw angle (position and attitude mode)
 */
static inline float mavlink_msg_ballbot_reference_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field dt from ballbot_reference message
 *
 * @return Time of trajectory.
 */
static inline uint32_t mavlink_msg_ballbot_reference_get_dt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field mode from ballbot_reference message
 *
 * @return Compatibility with reference trajectory command.
 */
static inline uint8_t mavlink_msg_ballbot_reference_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Decode a ballbot_reference message into a struct
 *
 * @param msg The message to decode
 * @param ballbot_reference C-struct to decode the message contents into
 */
static inline void mavlink_msg_ballbot_reference_decode(const mavlink_message_t* msg, mavlink_ballbot_reference_t* ballbot_reference)
{
#if MAVLINK_NEED_BYTE_SWAP
	ballbot_reference->pos_x = mavlink_msg_ballbot_reference_get_pos_x(msg);
	ballbot_reference->pos_y = mavlink_msg_ballbot_reference_get_pos_y(msg);
	ballbot_reference->yaw = mavlink_msg_ballbot_reference_get_yaw(msg);
	ballbot_reference->dt = mavlink_msg_ballbot_reference_get_dt(msg);
	ballbot_reference->mode = mavlink_msg_ballbot_reference_get_mode(msg);
#else
	memcpy(ballbot_reference, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_BALLBOT_REFERENCE_LEN);
#endif
}

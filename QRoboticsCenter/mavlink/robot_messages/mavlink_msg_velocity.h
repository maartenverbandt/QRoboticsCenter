// MESSAGE VELOCITY PACKING

#define MAVLINK_MSG_ID_VELOCITY 52

typedef struct __mavlink_velocity_t
{
 uint32_t time; ///< time [us]
 int16_t vx; ///< x velocity [mrad-sugg.].
 int16_t vy; ///< y velocity [mrad-sugg.]
 int16_t vz; ///< z velocity [mrad-sugg.]
 int16_t vx_actuation; ///< x velocity actuator [mrad-sugg.].
 int16_t vy_actuation; ///< y velocity actuator [mrad-sugg.].
 int16_t vz_actuation; ///< z velocity actuator [mrad-sugg.].
} mavlink_velocity_t;

#define MAVLINK_MSG_ID_VELOCITY_LEN 16
#define MAVLINK_MSG_ID_52_LEN 16

#define MAVLINK_MSG_ID_VELOCITY_CRC 117
#define MAVLINK_MSG_ID_52_CRC 117



#define MAVLINK_MESSAGE_INFO_VELOCITY { \
	"VELOCITY", \
	7, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_velocity_t, time) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_velocity_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_velocity_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_velocity_t, vz) }, \
         { "vx_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_velocity_t, vx_actuation) }, \
         { "vy_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_velocity_t, vy_actuation) }, \
         { "vz_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_velocity_t, vz_actuation) }, \
         } \
}


/**
 * @brief Pack a velocity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time time [us]
 * @param vx x velocity [mrad-sugg.].
 * @param vy y velocity [mrad-sugg.]
 * @param vz z velocity [mrad-sugg.]
 * @param vx_actuation x velocity actuator [mrad-sugg.].
 * @param vy_actuation y velocity actuator [mrad-sugg.].
 * @param vz_actuation z velocity actuator [mrad-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, int16_t vx, int16_t vy, int16_t vz, int16_t vx_actuation, int16_t vy_actuation, int16_t vz_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_actuation);
	_mav_put_int16_t(buf, 12, vy_actuation);
	_mav_put_int16_t(buf, 14, vz_actuation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#else
	mavlink_velocity_t packet;
	packet.time = time;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vx_actuation = vx_actuation;
	packet.vy_actuation = vy_actuation;
	packet.vz_actuation = vz_actuation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
}

/**
 * @brief Pack a velocity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time time [us]
 * @param vx x velocity [mrad-sugg.].
 * @param vy y velocity [mrad-sugg.]
 * @param vz z velocity [mrad-sugg.]
 * @param vx_actuation x velocity actuator [mrad-sugg.].
 * @param vy_actuation y velocity actuator [mrad-sugg.].
 * @param vz_actuation z velocity actuator [mrad-sugg.].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,int16_t vx,int16_t vy,int16_t vz,int16_t vx_actuation,int16_t vy_actuation,int16_t vz_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_actuation);
	_mav_put_int16_t(buf, 12, vy_actuation);
	_mav_put_int16_t(buf, 14, vz_actuation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#else
	mavlink_velocity_t packet;
	packet.time = time;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vx_actuation = vx_actuation;
	packet.vy_actuation = vy_actuation;
	packet.vz_actuation = vz_actuation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
}

/**
 * @brief Encode a velocity struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_velocity_t* velocity)
{
	return mavlink_msg_velocity_pack(system_id, component_id, msg, velocity->time, velocity->vx, velocity->vy, velocity->vz, velocity->vx_actuation, velocity->vy_actuation, velocity->vz_actuation);
}

/**
 * @brief Encode a velocity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_velocity_t* velocity)
{
	return mavlink_msg_velocity_pack_chan(system_id, component_id, chan, msg, velocity->time, velocity->vx, velocity->vy, velocity->vz, velocity->vx_actuation, velocity->vy_actuation, velocity->vz_actuation);
}

/**
 * @brief Send a velocity message
 * @param chan MAVLink channel to send the message
 *
 * @param time time [us]
 * @param vx x velocity [mrad-sugg.].
 * @param vy y velocity [mrad-sugg.]
 * @param vz z velocity [mrad-sugg.]
 * @param vx_actuation x velocity actuator [mrad-sugg.].
 * @param vy_actuation y velocity actuator [mrad-sugg.].
 * @param vz_actuation z velocity actuator [mrad-sugg.].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_velocity_send(mavlink_channel_t chan, uint32_t time, int16_t vx, int16_t vy, int16_t vz, int16_t vx_actuation, int16_t vy_actuation, int16_t vz_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_actuation);
	_mav_put_int16_t(buf, 12, vy_actuation);
	_mav_put_int16_t(buf, 14, vz_actuation);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#else
	mavlink_velocity_t packet;
	packet.time = time;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.vx_actuation = vx_actuation;
	packet.vy_actuation = vy_actuation;
	packet.vz_actuation = vz_actuation;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_VELOCITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_velocity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, int16_t vx, int16_t vy, int16_t vz, int16_t vx_actuation, int16_t vy_actuation, int16_t vz_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, vx);
	_mav_put_int16_t(buf, 6, vy);
	_mav_put_int16_t(buf, 8, vz);
	_mav_put_int16_t(buf, 10, vx_actuation);
	_mav_put_int16_t(buf, 12, vy_actuation);
	_mav_put_int16_t(buf, 14, vz_actuation);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, buf, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#else
	mavlink_velocity_t *packet = (mavlink_velocity_t *)msgbuf;
	packet->time = time;
	packet->vx = vx;
	packet->vy = vy;
	packet->vz = vz;
	packet->vx_actuation = vx_actuation;
	packet->vy_actuation = vy_actuation;
	packet->vz_actuation = vz_actuation;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_LEN, MAVLINK_MSG_ID_VELOCITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE VELOCITY UNPACKING


/**
 * @brief Get field time from velocity message
 *
 * @return time [us]
 */
static inline uint32_t mavlink_msg_velocity_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field vx from velocity message
 *
 * @return x velocity [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vx(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field vy from velocity message
 *
 * @return y velocity [mrad-sugg.]
 */
static inline int16_t mavlink_msg_velocity_get_vy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field vz from velocity message
 *
 * @return z velocity [mrad-sugg.]
 */
static inline int16_t mavlink_msg_velocity_get_vz(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field vx_actuation from velocity message
 *
 * @return x velocity actuator [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vx_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field vy_actuation from velocity message
 *
 * @return y velocity actuator [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vy_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field vz_actuation from velocity message
 *
 * @return z velocity actuator [mrad-sugg.].
 */
static inline int16_t mavlink_msg_velocity_get_vz_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Decode a velocity message into a struct
 *
 * @param msg The message to decode
 * @param velocity C-struct to decode the message contents into
 */
static inline void mavlink_msg_velocity_decode(const mavlink_message_t* msg, mavlink_velocity_t* velocity)
{
#if MAVLINK_NEED_BYTE_SWAP
	velocity->time = mavlink_msg_velocity_get_time(msg);
	velocity->vx = mavlink_msg_velocity_get_vx(msg);
	velocity->vy = mavlink_msg_velocity_get_vy(msg);
	velocity->vz = mavlink_msg_velocity_get_vz(msg);
	velocity->vx_actuation = mavlink_msg_velocity_get_vx_actuation(msg);
	velocity->vy_actuation = mavlink_msg_velocity_get_vy_actuation(msg);
	velocity->vz_actuation = mavlink_msg_velocity_get_vz_actuation(msg);
#else
	memcpy(velocity, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VELOCITY_LEN);
#endif
}

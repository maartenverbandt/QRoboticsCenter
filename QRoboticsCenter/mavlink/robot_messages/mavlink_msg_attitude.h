// MESSAGE ATTITUDE PACKING

#define MAVLINK_MSG_ID_ATTITUDE 51

typedef struct __mavlink_attitude_t
{
 uint32_t time; ///< time [us]
 int16_t roll; ///< roll [mrad-sugg.].
 int16_t pitch; ///< pitch [mrad-sugg.]
 int16_t yaw; ///< yaw [mrad-sugg.]
 int16_t roll_actuation; ///< roll actuator [mV].
 int16_t pitch_actuation; ///< pitch actuator [mV]
 int16_t yaw_actuation; ///< yaw actuator [mV]
} mavlink_attitude_t;

#define MAVLINK_MSG_ID_ATTITUDE_LEN 16
#define MAVLINK_MSG_ID_51_LEN 16

#define MAVLINK_MSG_ID_ATTITUDE_CRC 235
#define MAVLINK_MSG_ID_51_CRC 235



#define MAVLINK_MESSAGE_INFO_ATTITUDE { \
	"ATTITUDE", \
	7, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_attitude_t, time) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_attitude_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_attitude_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_attitude_t, yaw) }, \
         { "roll_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_attitude_t, roll_actuation) }, \
         { "pitch_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_attitude_t, pitch_actuation) }, \
         { "yaw_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_attitude_t, yaw_actuation) }, \
         } \
}


/**
 * @brief Pack a attitude message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time time [us]
 * @param roll roll [mrad-sugg.].
 * @param pitch pitch [mrad-sugg.]
 * @param yaw yaw [mrad-sugg.]
 * @param roll_actuation roll actuator [mV].
 * @param pitch_actuation pitch actuator [mV]
 * @param yaw_actuation yaw actuator [mV]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, int16_t roll, int16_t pitch, int16_t yaw, int16_t roll_actuation, int16_t pitch_actuation, int16_t yaw_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ATTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, roll);
	_mav_put_int16_t(buf, 6, pitch);
	_mav_put_int16_t(buf, 8, yaw);
	_mav_put_int16_t(buf, 10, roll_actuation);
	_mav_put_int16_t(buf, 12, pitch_actuation);
	_mav_put_int16_t(buf, 14, yaw_actuation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_LEN);
#else
	mavlink_attitude_t packet;
	packet.time = time;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_actuation = roll_actuation;
	packet.pitch_actuation = pitch_actuation;
	packet.yaw_actuation = yaw_actuation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ATTITUDE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATTITUDE_LEN, MAVLINK_MSG_ID_ATTITUDE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif
}

/**
 * @brief Pack a attitude message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time time [us]
 * @param roll roll [mrad-sugg.].
 * @param pitch pitch [mrad-sugg.]
 * @param yaw yaw [mrad-sugg.]
 * @param roll_actuation roll actuator [mV].
 * @param pitch_actuation pitch actuator [mV]
 * @param yaw_actuation yaw actuator [mV]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,int16_t roll,int16_t pitch,int16_t yaw,int16_t roll_actuation,int16_t pitch_actuation,int16_t yaw_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ATTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, roll);
	_mav_put_int16_t(buf, 6, pitch);
	_mav_put_int16_t(buf, 8, yaw);
	_mav_put_int16_t(buf, 10, roll_actuation);
	_mav_put_int16_t(buf, 12, pitch_actuation);
	_mav_put_int16_t(buf, 14, yaw_actuation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_LEN);
#else
	mavlink_attitude_t packet;
	packet.time = time;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_actuation = roll_actuation;
	packet.pitch_actuation = pitch_actuation;
	packet.yaw_actuation = yaw_actuation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ATTITUDE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATTITUDE_LEN, MAVLINK_MSG_ID_ATTITUDE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif
}

/**
 * @brief Encode a attitude struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param attitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_attitude_t* attitude)
{
	return mavlink_msg_attitude_pack(system_id, component_id, msg, attitude->time, attitude->roll, attitude->pitch, attitude->yaw, attitude->roll_actuation, attitude->pitch_actuation, attitude->yaw_actuation);
}

/**
 * @brief Encode a attitude struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param attitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_attitude_t* attitude)
{
	return mavlink_msg_attitude_pack_chan(system_id, component_id, chan, msg, attitude->time, attitude->roll, attitude->pitch, attitude->yaw, attitude->roll_actuation, attitude->pitch_actuation, attitude->yaw_actuation);
}

/**
 * @brief Send a attitude message
 * @param chan MAVLink channel to send the message
 *
 * @param time time [us]
 * @param roll roll [mrad-sugg.].
 * @param pitch pitch [mrad-sugg.]
 * @param yaw yaw [mrad-sugg.]
 * @param roll_actuation roll actuator [mV].
 * @param pitch_actuation pitch actuator [mV]
 * @param yaw_actuation yaw actuator [mV]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_attitude_send(mavlink_channel_t chan, uint32_t time, int16_t roll, int16_t pitch, int16_t yaw, int16_t roll_actuation, int16_t pitch_actuation, int16_t yaw_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ATTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, roll);
	_mav_put_int16_t(buf, 6, pitch);
	_mav_put_int16_t(buf, 8, yaw);
	_mav_put_int16_t(buf, 10, roll_actuation);
	_mav_put_int16_t(buf, 12, pitch_actuation);
	_mav_put_int16_t(buf, 14, yaw_actuation);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, buf, MAVLINK_MSG_ID_ATTITUDE_LEN, MAVLINK_MSG_ID_ATTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, buf, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif
#else
	mavlink_attitude_t packet;
	packet.time = time;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_actuation = roll_actuation;
	packet.pitch_actuation = pitch_actuation;
	packet.yaw_actuation = yaw_actuation;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, (const char *)&packet, MAVLINK_MSG_ID_ATTITUDE_LEN, MAVLINK_MSG_ID_ATTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, (const char *)&packet, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_ATTITUDE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_attitude_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, int16_t roll, int16_t pitch, int16_t yaw, int16_t roll_actuation, int16_t pitch_actuation, int16_t yaw_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, roll);
	_mav_put_int16_t(buf, 6, pitch);
	_mav_put_int16_t(buf, 8, yaw);
	_mav_put_int16_t(buf, 10, roll_actuation);
	_mav_put_int16_t(buf, 12, pitch_actuation);
	_mav_put_int16_t(buf, 14, yaw_actuation);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, buf, MAVLINK_MSG_ID_ATTITUDE_LEN, MAVLINK_MSG_ID_ATTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, buf, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif
#else
	mavlink_attitude_t *packet = (mavlink_attitude_t *)msgbuf;
	packet->time = time;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->roll_actuation = roll_actuation;
	packet->pitch_actuation = pitch_actuation;
	packet->yaw_actuation = yaw_actuation;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, (const char *)packet, MAVLINK_MSG_ID_ATTITUDE_LEN, MAVLINK_MSG_ID_ATTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE, (const char *)packet, MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE ATTITUDE UNPACKING


/**
 * @brief Get field time from attitude message
 *
 * @return time [us]
 */
static inline uint32_t mavlink_msg_attitude_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field roll from attitude message
 *
 * @return roll [mrad-sugg.].
 */
static inline int16_t mavlink_msg_attitude_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field pitch from attitude message
 *
 * @return pitch [mrad-sugg.]
 */
static inline int16_t mavlink_msg_attitude_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field yaw from attitude message
 *
 * @return yaw [mrad-sugg.]
 */
static inline int16_t mavlink_msg_attitude_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field roll_actuation from attitude message
 *
 * @return roll actuator [mV].
 */
static inline int16_t mavlink_msg_attitude_get_roll_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field pitch_actuation from attitude message
 *
 * @return pitch actuator [mV]
 */
static inline int16_t mavlink_msg_attitude_get_pitch_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field yaw_actuation from attitude message
 *
 * @return yaw actuator [mV]
 */
static inline int16_t mavlink_msg_attitude_get_yaw_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Decode a attitude message into a struct
 *
 * @param msg The message to decode
 * @param attitude C-struct to decode the message contents into
 */
static inline void mavlink_msg_attitude_decode(const mavlink_message_t* msg, mavlink_attitude_t* attitude)
{
#if MAVLINK_NEED_BYTE_SWAP
	attitude->time = mavlink_msg_attitude_get_time(msg);
	attitude->roll = mavlink_msg_attitude_get_roll(msg);
	attitude->pitch = mavlink_msg_attitude_get_pitch(msg);
	attitude->yaw = mavlink_msg_attitude_get_yaw(msg);
	attitude->roll_actuation = mavlink_msg_attitude_get_roll_actuation(msg);
	attitude->pitch_actuation = mavlink_msg_attitude_get_pitch_actuation(msg);
	attitude->yaw_actuation = mavlink_msg_attitude_get_yaw_actuation(msg);
#else
	memcpy(attitude, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_ATTITUDE_LEN);
#endif
}

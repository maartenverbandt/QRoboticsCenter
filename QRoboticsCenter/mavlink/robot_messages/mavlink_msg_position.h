// MESSAGE POSITION PACKING

#define MAVLINK_MSG_ID_POSITION 53

typedef struct __mavlink_position_t
{
 uint32_t time; ///< time [us]
 int16_t x; ///< x [mm-sugg.].
 int16_t y; ///< y [mm-sugg.].
 int16_t z; ///< z [mm-sugg.].
 int16_t x_actuation; ///< x actuator [mrad].
 int16_t y_actuation; ///< y actuator [mrad]
 int16_t z_actuation; ///< z actuator [mrad]
} mavlink_position_t;

#define MAVLINK_MSG_ID_POSITION_LEN 16
#define MAVLINK_MSG_ID_53_LEN 16

#define MAVLINK_MSG_ID_POSITION_CRC 43
#define MAVLINK_MSG_ID_53_CRC 43



#define MAVLINK_MESSAGE_INFO_POSITION { \
	"POSITION", \
	7, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_position_t, time) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_position_t, z) }, \
         { "x_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_position_t, x_actuation) }, \
         { "y_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_position_t, y_actuation) }, \
         { "z_actuation", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_position_t, z_actuation) }, \
         } \
}


/**
 * @brief Pack a position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time time [us]
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param x_actuation x actuator [mrad].
 * @param y_actuation y actuator [mrad]
 * @param z_actuation z actuator [mrad]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, int16_t x, int16_t y, int16_t z, int16_t x_actuation, int16_t y_actuation, int16_t z_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, x);
	_mav_put_int16_t(buf, 6, y);
	_mav_put_int16_t(buf, 8, z);
	_mav_put_int16_t(buf, 10, x_actuation);
	_mav_put_int16_t(buf, 12, y_actuation);
	_mav_put_int16_t(buf, 14, z_actuation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_LEN);
#else
	mavlink_position_t packet;
	packet.time = time;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.x_actuation = x_actuation;
	packet.y_actuation = y_actuation;
	packet.z_actuation = z_actuation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_LEN);
#endif
}

/**
 * @brief Pack a position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time time [us]
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param x_actuation x actuator [mrad].
 * @param y_actuation y actuator [mrad]
 * @param z_actuation z actuator [mrad]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,int16_t x,int16_t y,int16_t z,int16_t x_actuation,int16_t y_actuation,int16_t z_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, x);
	_mav_put_int16_t(buf, 6, y);
	_mav_put_int16_t(buf, 8, z);
	_mav_put_int16_t(buf, 10, x_actuation);
	_mav_put_int16_t(buf, 12, y_actuation);
	_mav_put_int16_t(buf, 14, z_actuation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_LEN);
#else
	mavlink_position_t packet;
	packet.time = time;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.x_actuation = x_actuation;
	packet.y_actuation = y_actuation;
	packet.z_actuation = z_actuation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_LEN);
#endif
}

/**
 * @brief Encode a position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_t* position)
{
	return mavlink_msg_position_pack(system_id, component_id, msg, position->time, position->x, position->y, position->z, position->x_actuation, position->y_actuation, position->z_actuation);
}

/**
 * @brief Encode a position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_position_t* position)
{
	return mavlink_msg_position_pack_chan(system_id, component_id, chan, msg, position->time, position->x, position->y, position->z, position->x_actuation, position->y_actuation, position->z_actuation);
}

/**
 * @brief Send a position message
 * @param chan MAVLink channel to send the message
 *
 * @param time time [us]
 * @param x x [mm-sugg.].
 * @param y y [mm-sugg.].
 * @param z z [mm-sugg.].
 * @param x_actuation x actuator [mrad].
 * @param y_actuation y actuator [mrad]
 * @param z_actuation z actuator [mrad]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_send(mavlink_channel_t chan, uint32_t time, int16_t x, int16_t y, int16_t z, int16_t x_actuation, int16_t y_actuation, int16_t z_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, x);
	_mav_put_int16_t(buf, 6, y);
	_mav_put_int16_t(buf, 8, z);
	_mav_put_int16_t(buf, 10, x_actuation);
	_mav_put_int16_t(buf, 12, y_actuation);
	_mav_put_int16_t(buf, 14, z_actuation);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#else
	mavlink_position_t packet;
	packet.time = time;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.x_actuation = x_actuation;
	packet.y_actuation = y_actuation;
	packet.z_actuation = z_actuation;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)&packet, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)&packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, int16_t x, int16_t y, int16_t z, int16_t x_actuation, int16_t y_actuation, int16_t z_actuation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, x);
	_mav_put_int16_t(buf, 6, y);
	_mav_put_int16_t(buf, 8, z);
	_mav_put_int16_t(buf, 10, x_actuation);
	_mav_put_int16_t(buf, 12, y_actuation);
	_mav_put_int16_t(buf, 14, z_actuation);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#else
	mavlink_position_t *packet = (mavlink_position_t *)msgbuf;
	packet->time = time;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->x_actuation = x_actuation;
	packet->y_actuation = y_actuation;
	packet->z_actuation = z_actuation;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)packet, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE POSITION UNPACKING


/**
 * @brief Get field time from position message
 *
 * @return time [us]
 */
static inline uint32_t mavlink_msg_position_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field x from position message
 *
 * @return x [mm-sugg.].
 */
static inline int16_t mavlink_msg_position_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field y from position message
 *
 * @return y [mm-sugg.].
 */
static inline int16_t mavlink_msg_position_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field z from position message
 *
 * @return z [mm-sugg.].
 */
static inline int16_t mavlink_msg_position_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field x_actuation from position message
 *
 * @return x actuator [mrad].
 */
static inline int16_t mavlink_msg_position_get_x_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field y_actuation from position message
 *
 * @return y actuator [mrad]
 */
static inline int16_t mavlink_msg_position_get_y_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field z_actuation from position message
 *
 * @return z actuator [mrad]
 */
static inline int16_t mavlink_msg_position_get_z_actuation(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Decode a position message into a struct
 *
 * @param msg The message to decode
 * @param position C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_decode(const mavlink_message_t* msg, mavlink_position_t* position)
{
#if MAVLINK_NEED_BYTE_SWAP
	position->time = mavlink_msg_position_get_time(msg);
	position->x = mavlink_msg_position_get_x(msg);
	position->y = mavlink_msg_position_get_y(msg);
	position->z = mavlink_msg_position_get_z(msg);
	position->x_actuation = mavlink_msg_position_get_x_actuation(msg);
	position->y_actuation = mavlink_msg_position_get_y_actuation(msg);
	position->z_actuation = mavlink_msg_position_get_z_actuation(msg);
#else
	memcpy(position, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_POSITION_LEN);
#endif
}

// MESSAGE BALLBOT_CONTROL PACKING

#define MAVLINK_MSG_ID_BALLBOT_CONTROL 71

typedef struct __mavlink_ballbot_control_t
{
 float var1_1; ///< Variable (1,1)
 float var1_2; ///< Variable (1,2)
 float var1_3; ///< Variable (1,3)
 float var2_1; ///< Variable (2,1)
 float var2_2; ///< Variable (2,2)
 float var2_3; ///< Variable (2,3)
 float var3_1; ///< Variable (3,1)
 float var3_2; ///< Variable (3,2)
 float var3_3; ///< Variable (3,3)
 uint8_t control_mode; ///< Ballbot control mode. Can be motor, ground, attitude, position,...
 uint8_t control_law; ///< Controllaw to implement
} mavlink_ballbot_control_t;

#define MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN 38
#define MAVLINK_MSG_ID_71_LEN 38

#define MAVLINK_MSG_ID_BALLBOT_CONTROL_CRC 167
#define MAVLINK_MSG_ID_71_CRC 167



#define MAVLINK_MESSAGE_INFO_BALLBOT_CONTROL { \
	"BALLBOT_CONTROL", \
	11, \
	{  { "var1_1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ballbot_control_t, var1_1) }, \
         { "var1_2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ballbot_control_t, var1_2) }, \
         { "var1_3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ballbot_control_t, var1_3) }, \
         { "var2_1", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ballbot_control_t, var2_1) }, \
         { "var2_2", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ballbot_control_t, var2_2) }, \
         { "var2_3", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ballbot_control_t, var2_3) }, \
         { "var3_1", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ballbot_control_t, var3_1) }, \
         { "var3_2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ballbot_control_t, var3_2) }, \
         { "var3_3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ballbot_control_t, var3_3) }, \
         { "control_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_ballbot_control_t, control_mode) }, \
         { "control_law", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_ballbot_control_t, control_law) }, \
         } \
}


/**
 * @brief Pack a ballbot_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param control_mode Ballbot control mode. Can be motor, ground, attitude, position,...
 * @param control_law Controllaw to implement
 * @param var1_1 Variable (1,1)
 * @param var1_2 Variable (1,2)
 * @param var1_3 Variable (1,3)
 * @param var2_1 Variable (2,1)
 * @param var2_2 Variable (2,2)
 * @param var2_3 Variable (2,3)
 * @param var3_1 Variable (3,1)
 * @param var3_2 Variable (3,2)
 * @param var3_3 Variable (3,3)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t control_mode, uint8_t control_law, float var1_1, float var1_2, float var1_3, float var2_1, float var2_2, float var2_3, float var3_1, float var3_2, float var3_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN];
	_mav_put_float(buf, 0, var1_1);
	_mav_put_float(buf, 4, var1_2);
	_mav_put_float(buf, 8, var1_3);
	_mav_put_float(buf, 12, var2_1);
	_mav_put_float(buf, 16, var2_2);
	_mav_put_float(buf, 20, var2_3);
	_mav_put_float(buf, 24, var3_1);
	_mav_put_float(buf, 28, var3_2);
	_mav_put_float(buf, 32, var3_3);
	_mav_put_uint8_t(buf, 36, control_mode);
	_mav_put_uint8_t(buf, 37, control_law);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#else
	mavlink_ballbot_control_t packet;
	packet.var1_1 = var1_1;
	packet.var1_2 = var1_2;
	packet.var1_3 = var1_3;
	packet.var2_1 = var2_1;
	packet.var2_2 = var2_2;
	packet.var2_3 = var2_3;
	packet.var3_1 = var3_1;
	packet.var3_2 = var3_2;
	packet.var3_3 = var3_3;
	packet.control_mode = control_mode;
	packet.control_law = control_law;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN, MAVLINK_MSG_ID_BALLBOT_CONTROL_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif
}

/**
 * @brief Pack a ballbot_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_mode Ballbot control mode. Can be motor, ground, attitude, position,...
 * @param control_law Controllaw to implement
 * @param var1_1 Variable (1,1)
 * @param var1_2 Variable (1,2)
 * @param var1_3 Variable (1,3)
 * @param var2_1 Variable (2,1)
 * @param var2_2 Variable (2,2)
 * @param var2_3 Variable (2,3)
 * @param var3_1 Variable (3,1)
 * @param var3_2 Variable (3,2)
 * @param var3_3 Variable (3,3)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t control_mode,uint8_t control_law,float var1_1,float var1_2,float var1_3,float var2_1,float var2_2,float var2_3,float var3_1,float var3_2,float var3_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN];
	_mav_put_float(buf, 0, var1_1);
	_mav_put_float(buf, 4, var1_2);
	_mav_put_float(buf, 8, var1_3);
	_mav_put_float(buf, 12, var2_1);
	_mav_put_float(buf, 16, var2_2);
	_mav_put_float(buf, 20, var2_3);
	_mav_put_float(buf, 24, var3_1);
	_mav_put_float(buf, 28, var3_2);
	_mav_put_float(buf, 32, var3_3);
	_mav_put_uint8_t(buf, 36, control_mode);
	_mav_put_uint8_t(buf, 37, control_law);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#else
	mavlink_ballbot_control_t packet;
	packet.var1_1 = var1_1;
	packet.var1_2 = var1_2;
	packet.var1_3 = var1_3;
	packet.var2_1 = var2_1;
	packet.var2_2 = var2_2;
	packet.var2_3 = var2_3;
	packet.var3_1 = var3_1;
	packet.var3_2 = var3_2;
	packet.var3_3 = var3_3;
	packet.control_mode = control_mode;
	packet.control_law = control_law;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN, MAVLINK_MSG_ID_BALLBOT_CONTROL_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif
}

/**
 * @brief Encode a ballbot_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ballbot_control_t* ballbot_control)
{
	return mavlink_msg_ballbot_control_pack(system_id, component_id, msg, ballbot_control->control_mode, ballbot_control->control_law, ballbot_control->var1_1, ballbot_control->var1_2, ballbot_control->var1_3, ballbot_control->var2_1, ballbot_control->var2_2, ballbot_control->var2_3, ballbot_control->var3_1, ballbot_control->var3_2, ballbot_control->var3_3);
}

/**
 * @brief Encode a ballbot_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ballbot_control_t* ballbot_control)
{
	return mavlink_msg_ballbot_control_pack_chan(system_id, component_id, chan, msg, ballbot_control->control_mode, ballbot_control->control_law, ballbot_control->var1_1, ballbot_control->var1_2, ballbot_control->var1_3, ballbot_control->var2_1, ballbot_control->var2_2, ballbot_control->var2_3, ballbot_control->var3_1, ballbot_control->var3_2, ballbot_control->var3_3);
}

/**
 * @brief Send a ballbot_control message
 * @param chan MAVLink channel to send the message
 *
 * @param control_mode Ballbot control mode. Can be motor, ground, attitude, position,...
 * @param control_law Controllaw to implement
 * @param var1_1 Variable (1,1)
 * @param var1_2 Variable (1,2)
 * @param var1_3 Variable (1,3)
 * @param var2_1 Variable (2,1)
 * @param var2_2 Variable (2,2)
 * @param var2_3 Variable (2,3)
 * @param var3_1 Variable (3,1)
 * @param var3_2 Variable (3,2)
 * @param var3_3 Variable (3,3)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ballbot_control_send(mavlink_channel_t chan, uint8_t control_mode, uint8_t control_law, float var1_1, float var1_2, float var1_3, float var2_1, float var2_2, float var2_3, float var3_1, float var3_2, float var3_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN];
	_mav_put_float(buf, 0, var1_1);
	_mav_put_float(buf, 4, var1_2);
	_mav_put_float(buf, 8, var1_3);
	_mav_put_float(buf, 12, var2_1);
	_mav_put_float(buf, 16, var2_2);
	_mav_put_float(buf, 20, var2_3);
	_mav_put_float(buf, 24, var3_1);
	_mav_put_float(buf, 28, var3_2);
	_mav_put_float(buf, 32, var3_3);
	_mav_put_uint8_t(buf, 36, control_mode);
	_mav_put_uint8_t(buf, 37, control_law);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, buf, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN, MAVLINK_MSG_ID_BALLBOT_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, buf, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif
#else
	mavlink_ballbot_control_t packet;
	packet.var1_1 = var1_1;
	packet.var1_2 = var1_2;
	packet.var1_3 = var1_3;
	packet.var2_1 = var2_1;
	packet.var2_2 = var2_2;
	packet.var2_3 = var2_3;
	packet.var3_1 = var3_1;
	packet.var3_2 = var3_2;
	packet.var3_3 = var3_3;
	packet.control_mode = control_mode;
	packet.control_law = control_law;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN, MAVLINK_MSG_ID_BALLBOT_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ballbot_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t control_mode, uint8_t control_law, float var1_1, float var1_2, float var1_3, float var2_1, float var2_2, float var2_3, float var3_1, float var3_2, float var3_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, var1_1);
	_mav_put_float(buf, 4, var1_2);
	_mav_put_float(buf, 8, var1_3);
	_mav_put_float(buf, 12, var2_1);
	_mav_put_float(buf, 16, var2_2);
	_mav_put_float(buf, 20, var2_3);
	_mav_put_float(buf, 24, var3_1);
	_mav_put_float(buf, 28, var3_2);
	_mav_put_float(buf, 32, var3_3);
	_mav_put_uint8_t(buf, 36, control_mode);
	_mav_put_uint8_t(buf, 37, control_law);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, buf, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN, MAVLINK_MSG_ID_BALLBOT_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, buf, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif
#else
	mavlink_ballbot_control_t *packet = (mavlink_ballbot_control_t *)msgbuf;
	packet->var1_1 = var1_1;
	packet->var1_2 = var1_2;
	packet->var1_3 = var1_3;
	packet->var2_1 = var2_1;
	packet->var2_2 = var2_2;
	packet->var2_3 = var2_3;
	packet->var3_1 = var3_1;
	packet->var3_2 = var3_2;
	packet->var3_3 = var3_3;
	packet->control_mode = control_mode;
	packet->control_law = control_law;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN, MAVLINK_MSG_ID_BALLBOT_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_CONTROL, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE BALLBOT_CONTROL UNPACKING


/**
 * @brief Get field control_mode from ballbot_control message
 *
 * @return Ballbot control mode. Can be motor, ground, attitude, position,...
 */
static inline uint8_t mavlink_msg_ballbot_control_get_control_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field control_law from ballbot_control message
 *
 * @return Controllaw to implement
 */
static inline uint8_t mavlink_msg_ballbot_control_get_control_law(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field var1_1 from ballbot_control message
 *
 * @return Variable (1,1)
 */
static inline float mavlink_msg_ballbot_control_get_var1_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field var1_2 from ballbot_control message
 *
 * @return Variable (1,2)
 */
static inline float mavlink_msg_ballbot_control_get_var1_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field var1_3 from ballbot_control message
 *
 * @return Variable (1,3)
 */
static inline float mavlink_msg_ballbot_control_get_var1_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field var2_1 from ballbot_control message
 *
 * @return Variable (2,1)
 */
static inline float mavlink_msg_ballbot_control_get_var2_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field var2_2 from ballbot_control message
 *
 * @return Variable (2,2)
 */
static inline float mavlink_msg_ballbot_control_get_var2_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field var2_3 from ballbot_control message
 *
 * @return Variable (2,3)
 */
static inline float mavlink_msg_ballbot_control_get_var2_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field var3_1 from ballbot_control message
 *
 * @return Variable (3,1)
 */
static inline float mavlink_msg_ballbot_control_get_var3_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field var3_2 from ballbot_control message
 *
 * @return Variable (3,2)
 */
static inline float mavlink_msg_ballbot_control_get_var3_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field var3_3 from ballbot_control message
 *
 * @return Variable (3,3)
 */
static inline float mavlink_msg_ballbot_control_get_var3_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a ballbot_control message into a struct
 *
 * @param msg The message to decode
 * @param ballbot_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_ballbot_control_decode(const mavlink_message_t* msg, mavlink_ballbot_control_t* ballbot_control)
{
#if MAVLINK_NEED_BYTE_SWAP
	ballbot_control->var1_1 = mavlink_msg_ballbot_control_get_var1_1(msg);
	ballbot_control->var1_2 = mavlink_msg_ballbot_control_get_var1_2(msg);
	ballbot_control->var1_3 = mavlink_msg_ballbot_control_get_var1_3(msg);
	ballbot_control->var2_1 = mavlink_msg_ballbot_control_get_var2_1(msg);
	ballbot_control->var2_2 = mavlink_msg_ballbot_control_get_var2_2(msg);
	ballbot_control->var2_3 = mavlink_msg_ballbot_control_get_var2_3(msg);
	ballbot_control->var3_1 = mavlink_msg_ballbot_control_get_var3_1(msg);
	ballbot_control->var3_2 = mavlink_msg_ballbot_control_get_var3_2(msg);
	ballbot_control->var3_3 = mavlink_msg_ballbot_control_get_var3_3(msg);
	ballbot_control->control_mode = mavlink_msg_ballbot_control_get_control_mode(msg);
	ballbot_control->control_law = mavlink_msg_ballbot_control_get_control_law(msg);
#else
	memcpy(ballbot_control, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_BALLBOT_CONTROL_LEN);
#endif
}

// MESSAGE MOTOR_CONTROL PACKING

#define MAVLINK_MSG_ID_MOTOR_CONTROL 51

typedef struct __mavlink_motor_control_t
{
 float var1; ///< 1st extra variable.
 float var2; ///< 2nd extra variable.
 float var3; ///< 3rd extra variable.
 float var4; ///< 4th extra variable.
 float var5; ///< 5th extra variable.
 float var6; ///< 6th extra variable.
 float var7; ///< 7th extra variable.
 float var8; ///< 8th extra variable.
 float var9; ///< 9th extra variable.
 uint8_t mode; ///< Current control mode of motor.
} mavlink_motor_control_t;

#define MAVLINK_MSG_ID_MOTOR_CONTROL_LEN 37
#define MAVLINK_MSG_ID_51_LEN 37

#define MAVLINK_MSG_ID_MOTOR_CONTROL_CRC 237
#define MAVLINK_MSG_ID_51_CRC 237



#define MAVLINK_MESSAGE_INFO_MOTOR_CONTROL { \
	"MOTOR_CONTROL", \
	10, \
	{  { "var1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_motor_control_t, var1) }, \
         { "var2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_motor_control_t, var2) }, \
         { "var3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_motor_control_t, var3) }, \
         { "var4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_motor_control_t, var4) }, \
         { "var5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motor_control_t, var5) }, \
         { "var6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_motor_control_t, var6) }, \
         { "var7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_motor_control_t, var7) }, \
         { "var8", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_motor_control_t, var8) }, \
         { "var9", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_motor_control_t, var9) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_motor_control_t, mode) }, \
         } \
}


/**
 * @brief Pack a motor_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode Current control mode of motor.
 * @param var1 1st extra variable.
 * @param var2 2nd extra variable.
 * @param var3 3rd extra variable.
 * @param var4 4th extra variable.
 * @param var5 5th extra variable.
 * @param var6 6th extra variable.
 * @param var7 7th extra variable.
 * @param var8 8th extra variable.
 * @param var9 9th extra variable.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode, float var1, float var2, float var3, float var4, float var5, float var6, float var7, float var8, float var9)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_CONTROL_LEN];
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_float(buf, 16, var5);
	_mav_put_float(buf, 20, var6);
	_mav_put_float(buf, 24, var7);
	_mav_put_float(buf, 28, var8);
	_mav_put_float(buf, 32, var9);
	_mav_put_uint8_t(buf, 36, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#else
	mavlink_motor_control_t packet;
	packet.var1 = var1;
	packet.var2 = var2;
	packet.var3 = var3;
	packet.var4 = var4;
	packet.var5 = var5;
	packet.var6 = var6;
	packet.var7 = var7;
	packet.var8 = var8;
	packet.var9 = var9;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN, MAVLINK_MSG_ID_MOTOR_CONTROL_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif
}

/**
 * @brief Pack a motor_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode Current control mode of motor.
 * @param var1 1st extra variable.
 * @param var2 2nd extra variable.
 * @param var3 3rd extra variable.
 * @param var4 4th extra variable.
 * @param var5 5th extra variable.
 * @param var6 6th extra variable.
 * @param var7 7th extra variable.
 * @param var8 8th extra variable.
 * @param var9 9th extra variable.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode,float var1,float var2,float var3,float var4,float var5,float var6,float var7,float var8,float var9)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_CONTROL_LEN];
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_float(buf, 16, var5);
	_mav_put_float(buf, 20, var6);
	_mav_put_float(buf, 24, var7);
	_mav_put_float(buf, 28, var8);
	_mav_put_float(buf, 32, var9);
	_mav_put_uint8_t(buf, 36, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#else
	mavlink_motor_control_t packet;
	packet.var1 = var1;
	packet.var2 = var2;
	packet.var3 = var3;
	packet.var4 = var4;
	packet.var5 = var5;
	packet.var6 = var6;
	packet.var7 = var7;
	packet.var8 = var8;
	packet.var9 = var9;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN, MAVLINK_MSG_ID_MOTOR_CONTROL_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif
}

/**
 * @brief Encode a motor_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_control_t* motor_control)
{
	return mavlink_msg_motor_control_pack(system_id, component_id, msg, motor_control->mode, motor_control->var1, motor_control->var2, motor_control->var3, motor_control->var4, motor_control->var5, motor_control->var6, motor_control->var7, motor_control->var8, motor_control->var9);
}

/**
 * @brief Encode a motor_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_control_t* motor_control)
{
	return mavlink_msg_motor_control_pack_chan(system_id, component_id, chan, msg, motor_control->mode, motor_control->var1, motor_control->var2, motor_control->var3, motor_control->var4, motor_control->var5, motor_control->var6, motor_control->var7, motor_control->var8, motor_control->var9);
}

/**
 * @brief Send a motor_control message
 * @param chan MAVLink channel to send the message
 *
 * @param mode Current control mode of motor.
 * @param var1 1st extra variable.
 * @param var2 2nd extra variable.
 * @param var3 3rd extra variable.
 * @param var4 4th extra variable.
 * @param var5 5th extra variable.
 * @param var6 6th extra variable.
 * @param var7 7th extra variable.
 * @param var8 8th extra variable.
 * @param var9 9th extra variable.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_control_send(mavlink_channel_t chan, uint8_t mode, float var1, float var2, float var3, float var4, float var5, float var6, float var7, float var8, float var9)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_CONTROL_LEN];
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_float(buf, 16, var5);
	_mav_put_float(buf, 20, var6);
	_mav_put_float(buf, 24, var7);
	_mav_put_float(buf, 28, var8);
	_mav_put_float(buf, 32, var9);
	_mav_put_uint8_t(buf, 36, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, buf, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN, MAVLINK_MSG_ID_MOTOR_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, buf, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif
#else
	mavlink_motor_control_t packet;
	packet.var1 = var1;
	packet.var2 = var2;
	packet.var3 = var3;
	packet.var4 = var4;
	packet.var5 = var5;
	packet.var6 = var6;
	packet.var7 = var7;
	packet.var8 = var8;
	packet.var9 = var9;
	packet.mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN, MAVLINK_MSG_ID_MOTOR_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_MOTOR_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, float var1, float var2, float var3, float var4, float var5, float var6, float var7, float var8, float var9)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_float(buf, 16, var5);
	_mav_put_float(buf, 20, var6);
	_mav_put_float(buf, 24, var7);
	_mav_put_float(buf, 28, var8);
	_mav_put_float(buf, 32, var9);
	_mav_put_uint8_t(buf, 36, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, buf, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN, MAVLINK_MSG_ID_MOTOR_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, buf, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif
#else
	mavlink_motor_control_t *packet = (mavlink_motor_control_t *)msgbuf;
	packet->var1 = var1;
	packet->var2 = var2;
	packet->var3 = var3;
	packet->var4 = var4;
	packet->var5 = var5;
	packet->var6 = var6;
	packet->var7 = var7;
	packet->var8 = var8;
	packet->var9 = var9;
	packet->mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, (const char *)packet, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN, MAVLINK_MSG_ID_MOTOR_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONTROL, (const char *)packet, MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE MOTOR_CONTROL UNPACKING


/**
 * @brief Get field mode from motor_control message
 *
 * @return Current control mode of motor.
 */
static inline uint8_t mavlink_msg_motor_control_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field var1 from motor_control message
 *
 * @return 1st extra variable.
 */
static inline float mavlink_msg_motor_control_get_var1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field var2 from motor_control message
 *
 * @return 2nd extra variable.
 */
static inline float mavlink_msg_motor_control_get_var2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field var3 from motor_control message
 *
 * @return 3rd extra variable.
 */
static inline float mavlink_msg_motor_control_get_var3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field var4 from motor_control message
 *
 * @return 4th extra variable.
 */
static inline float mavlink_msg_motor_control_get_var4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field var5 from motor_control message
 *
 * @return 5th extra variable.
 */
static inline float mavlink_msg_motor_control_get_var5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field var6 from motor_control message
 *
 * @return 6th extra variable.
 */
static inline float mavlink_msg_motor_control_get_var6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field var7 from motor_control message
 *
 * @return 7th extra variable.
 */
static inline float mavlink_msg_motor_control_get_var7(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field var8 from motor_control message
 *
 * @return 8th extra variable.
 */
static inline float mavlink_msg_motor_control_get_var8(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field var9 from motor_control message
 *
 * @return 9th extra variable.
 */
static inline float mavlink_msg_motor_control_get_var9(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a motor_control message into a struct
 *
 * @param msg The message to decode
 * @param motor_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_control_decode(const mavlink_message_t* msg, mavlink_motor_control_t* motor_control)
{
#if MAVLINK_NEED_BYTE_SWAP
	motor_control->var1 = mavlink_msg_motor_control_get_var1(msg);
	motor_control->var2 = mavlink_msg_motor_control_get_var2(msg);
	motor_control->var3 = mavlink_msg_motor_control_get_var3(msg);
	motor_control->var4 = mavlink_msg_motor_control_get_var4(msg);
	motor_control->var5 = mavlink_msg_motor_control_get_var5(msg);
	motor_control->var6 = mavlink_msg_motor_control_get_var6(msg);
	motor_control->var7 = mavlink_msg_motor_control_get_var7(msg);
	motor_control->var8 = mavlink_msg_motor_control_get_var8(msg);
	motor_control->var9 = mavlink_msg_motor_control_get_var9(msg);
	motor_control->mode = mavlink_msg_motor_control_get_mode(msg);
#else
	memcpy(motor_control, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_MOTOR_CONTROL_LEN);
#endif
}

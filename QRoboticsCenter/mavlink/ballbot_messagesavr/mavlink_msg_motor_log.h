// MESSAGE MOTOR_LOG PACKING

#define MAVLINK_MSG_ID_MOTOR_LOG 100

typedef struct __mavlink_motor_log_t
{
 uint32_t time; ///< Time at which measurement was sampled [ms].
 int32_t position; ///< Encoder position at the sampled instance [-].
 int16_t voltage; ///< Voltage on the motor terminals at sampled instance [mV].
 int16_t current; ///< Current through the motor at sampled instance [mA].
} mavlink_motor_log_t;

#define MAVLINK_MSG_ID_MOTOR_LOG_LEN 12
#define MAVLINK_MSG_ID_100_LEN 12

#define MAVLINK_MSG_ID_MOTOR_LOG_CRC 8
#define MAVLINK_MSG_ID_100_CRC 8



#define MAVLINK_MESSAGE_INFO_MOTOR_LOG { \
	"MOTOR_LOG", \
	4, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_motor_log_t, time) }, \
         { "position", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_motor_log_t, position) }, \
         { "voltage", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_motor_log_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_motor_log_t, current) }, \
         } \
}


/**
 * @brief Pack a motor_log message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time Time at which measurement was sampled [ms].
 * @param voltage Voltage on the motor terminals at sampled instance [mV].
 * @param current Current through the motor at sampled instance [mA].
 * @param position Encoder position at the sampled instance [-].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_log_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, int16_t voltage, int16_t current, int32_t position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_LOG_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, position);
	_mav_put_int16_t(buf, 8, voltage);
	_mav_put_int16_t(buf, 10, current);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#else
	mavlink_motor_log_t packet;
	packet.time = time;
	packet.position = position;
	packet.voltage = voltage;
	packet.current = current;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_LOG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_LOG_LEN, MAVLINK_MSG_ID_MOTOR_LOG_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif
}

/**
 * @brief Pack a motor_log message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time Time at which measurement was sampled [ms].
 * @param voltage Voltage on the motor terminals at sampled instance [mV].
 * @param current Current through the motor at sampled instance [mA].
 * @param position Encoder position at the sampled instance [-].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_log_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,int16_t voltage,int16_t current,int32_t position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_LOG_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, position);
	_mav_put_int16_t(buf, 8, voltage);
	_mav_put_int16_t(buf, 10, current);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#else
	mavlink_motor_log_t packet;
	packet.time = time;
	packet.position = position;
	packet.voltage = voltage;
	packet.current = current;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_LOG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_LOG_LEN, MAVLINK_MSG_ID_MOTOR_LOG_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif
}

/**
 * @brief Encode a motor_log struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_log C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_log_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_log_t* motor_log)
{
	return mavlink_msg_motor_log_pack(system_id, component_id, msg, motor_log->time, motor_log->voltage, motor_log->current, motor_log->position);
}

/**
 * @brief Encode a motor_log struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_log C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_log_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_log_t* motor_log)
{
	return mavlink_msg_motor_log_pack_chan(system_id, component_id, chan, msg, motor_log->time, motor_log->voltage, motor_log->current, motor_log->position);
}

/**
 * @brief Send a motor_log message
 * @param chan MAVLink channel to send the message
 *
 * @param time Time at which measurement was sampled [ms].
 * @param voltage Voltage on the motor terminals at sampled instance [mV].
 * @param current Current through the motor at sampled instance [mA].
 * @param position Encoder position at the sampled instance [-].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_log_send(mavlink_channel_t chan, uint32_t time, int16_t voltage, int16_t current, int32_t position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_LOG_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, position);
	_mav_put_int16_t(buf, 8, voltage);
	_mav_put_int16_t(buf, 10, current);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, buf, MAVLINK_MSG_ID_MOTOR_LOG_LEN, MAVLINK_MSG_ID_MOTOR_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, buf, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif
#else
	mavlink_motor_log_t packet;
	packet.time = time;
	packet.position = position;
	packet.voltage = voltage;
	packet.current = current;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_LOG_LEN, MAVLINK_MSG_ID_MOTOR_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_MOTOR_LOG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_log_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, int16_t voltage, int16_t current, int32_t position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_int32_t(buf, 4, position);
	_mav_put_int16_t(buf, 8, voltage);
	_mav_put_int16_t(buf, 10, current);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, buf, MAVLINK_MSG_ID_MOTOR_LOG_LEN, MAVLINK_MSG_ID_MOTOR_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, buf, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif
#else
	mavlink_motor_log_t *packet = (mavlink_motor_log_t *)msgbuf;
	packet->time = time;
	packet->position = position;
	packet->voltage = voltage;
	packet->current = current;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, (const char *)packet, MAVLINK_MSG_ID_MOTOR_LOG_LEN, MAVLINK_MSG_ID_MOTOR_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_LOG, (const char *)packet, MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE MOTOR_LOG UNPACKING


/**
 * @brief Get field time from motor_log message
 *
 * @return Time at which measurement was sampled [ms].
 */
static inline uint32_t mavlink_msg_motor_log_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field voltage from motor_log message
 *
 * @return Voltage on the motor terminals at sampled instance [mV].
 */
static inline int16_t mavlink_msg_motor_log_get_voltage(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field current from motor_log message
 *
 * @return Current through the motor at sampled instance [mA].
 */
static inline int16_t mavlink_msg_motor_log_get_current(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field position from motor_log message
 *
 * @return Encoder position at the sampled instance [-].
 */
static inline int32_t mavlink_msg_motor_log_get_position(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Decode a motor_log message into a struct
 *
 * @param msg The message to decode
 * @param motor_log C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_log_decode(const mavlink_message_t* msg, mavlink_motor_log_t* motor_log)
{
#if MAVLINK_NEED_BYTE_SWAP
	motor_log->time = mavlink_msg_motor_log_get_time(msg);
	motor_log->position = mavlink_msg_motor_log_get_position(msg);
	motor_log->voltage = mavlink_msg_motor_log_get_voltage(msg);
	motor_log->current = mavlink_msg_motor_log_get_current(msg);
#else
	memcpy(motor_log, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_MOTOR_LOG_LEN);
#endif
}

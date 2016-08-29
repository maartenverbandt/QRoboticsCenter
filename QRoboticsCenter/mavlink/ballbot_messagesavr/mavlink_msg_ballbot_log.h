// MESSAGE BALLBOT_LOG PACKING

#define MAVLINK_MSG_ID_BALLBOT_LOG 101

typedef struct __mavlink_ballbot_log_t
{
 uint32_t time; ///< TimeStamp
 float roll; ///< Ballbot roll angle [rad]
 float pitch; ///< Ballbot pitch angle [rad]
 float yaw; ///< Ballbot yaw angle [rad]
 float rollcmd; ///< Excitation in the 0 direction (along motor 0 or x)
 float pitchcmd; ///< Excitation in the 1 direction (along motor 1 or y)
 float yawcmd; ///< Excitation in the 2 direction (along motor 2 or z)
 int32_t Encmot0; ///< Motor 0 encoder [-]
 int32_t Encmot1; ///< Motor 1 encoder [-]
 int32_t Encmot2; ///< Motor 2 encoder [-]
 int16_t Vmot0; ///< Motor 0 voltage [mV]
 int16_t Vmot1; ///< Motor 1 voltage [mV]
 int16_t Vmot2; ///< Motor 2 voltage [mV]
 int16_t Imot0; ///< Motor 0 current [mA]
 int16_t Imot1; ///< Motor 1 current [mA]
 int16_t Imot2; ///< Motor 2 current [mA]
} mavlink_ballbot_log_t;

#define MAVLINK_MSG_ID_BALLBOT_LOG_LEN 52
#define MAVLINK_MSG_ID_101_LEN 52

#define MAVLINK_MSG_ID_BALLBOT_LOG_CRC 174
#define MAVLINK_MSG_ID_101_CRC 174



#define MAVLINK_MESSAGE_INFO_BALLBOT_LOG { \
	"BALLBOT_LOG", \
	16, \
	{  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ballbot_log_t, time) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ballbot_log_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ballbot_log_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ballbot_log_t, yaw) }, \
         { "rollcmd", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ballbot_log_t, rollcmd) }, \
         { "pitchcmd", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ballbot_log_t, pitchcmd) }, \
         { "yawcmd", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ballbot_log_t, yawcmd) }, \
         { "Encmot0", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_ballbot_log_t, Encmot0) }, \
         { "Encmot1", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_ballbot_log_t, Encmot1) }, \
         { "Encmot2", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_ballbot_log_t, Encmot2) }, \
         { "Vmot0", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_ballbot_log_t, Vmot0) }, \
         { "Vmot1", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_ballbot_log_t, Vmot1) }, \
         { "Vmot2", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_ballbot_log_t, Vmot2) }, \
         { "Imot0", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_ballbot_log_t, Imot0) }, \
         { "Imot1", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_ballbot_log_t, Imot1) }, \
         { "Imot2", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_ballbot_log_t, Imot2) }, \
         } \
}


/**
 * @brief Pack a ballbot_log message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time TimeStamp
 * @param Vmot0 Motor 0 voltage [mV]
 * @param Vmot1 Motor 1 voltage [mV]
 * @param Vmot2 Motor 2 voltage [mV]
 * @param Imot0 Motor 0 current [mA]
 * @param Imot1 Motor 1 current [mA]
 * @param Imot2 Motor 2 current [mA]
 * @param roll Ballbot roll angle [rad]
 * @param pitch Ballbot pitch angle [rad]
 * @param yaw Ballbot yaw angle [rad]
 * @param rollcmd Excitation in the 0 direction (along motor 0 or x)
 * @param pitchcmd Excitation in the 1 direction (along motor 1 or y)
 * @param yawcmd Excitation in the 2 direction (along motor 2 or z)
 * @param Encmot0 Motor 0 encoder [-]
 * @param Encmot1 Motor 1 encoder [-]
 * @param Encmot2 Motor 2 encoder [-]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_log_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, int16_t Vmot0, int16_t Vmot1, int16_t Vmot2, int16_t Imot0, int16_t Imot1, int16_t Imot2, float roll, float pitch, float yaw, float rollcmd, float pitchcmd, float yawcmd, int32_t Encmot0, int32_t Encmot1, int32_t Encmot2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_LOG_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float(buf, 4, roll);
	_mav_put_float(buf, 8, pitch);
	_mav_put_float(buf, 12, yaw);
	_mav_put_float(buf, 16, rollcmd);
	_mav_put_float(buf, 20, pitchcmd);
	_mav_put_float(buf, 24, yawcmd);
	_mav_put_int32_t(buf, 28, Encmot0);
	_mav_put_int32_t(buf, 32, Encmot1);
	_mav_put_int32_t(buf, 36, Encmot2);
	_mav_put_int16_t(buf, 40, Vmot0);
	_mav_put_int16_t(buf, 42, Vmot1);
	_mav_put_int16_t(buf, 44, Vmot2);
	_mav_put_int16_t(buf, 46, Imot0);
	_mav_put_int16_t(buf, 48, Imot1);
	_mav_put_int16_t(buf, 50, Imot2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#else
	mavlink_ballbot_log_t packet;
	packet.time = time;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollcmd = rollcmd;
	packet.pitchcmd = pitchcmd;
	packet.yawcmd = yawcmd;
	packet.Encmot0 = Encmot0;
	packet.Encmot1 = Encmot1;
	packet.Encmot2 = Encmot2;
	packet.Vmot0 = Vmot0;
	packet.Vmot1 = Vmot1;
	packet.Vmot2 = Vmot2;
	packet.Imot0 = Imot0;
	packet.Imot1 = Imot1;
	packet.Imot2 = Imot2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_LOG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_LOG_LEN, MAVLINK_MSG_ID_BALLBOT_LOG_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif
}

/**
 * @brief Pack a ballbot_log message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time TimeStamp
 * @param Vmot0 Motor 0 voltage [mV]
 * @param Vmot1 Motor 1 voltage [mV]
 * @param Vmot2 Motor 2 voltage [mV]
 * @param Imot0 Motor 0 current [mA]
 * @param Imot1 Motor 1 current [mA]
 * @param Imot2 Motor 2 current [mA]
 * @param roll Ballbot roll angle [rad]
 * @param pitch Ballbot pitch angle [rad]
 * @param yaw Ballbot yaw angle [rad]
 * @param rollcmd Excitation in the 0 direction (along motor 0 or x)
 * @param pitchcmd Excitation in the 1 direction (along motor 1 or y)
 * @param yawcmd Excitation in the 2 direction (along motor 2 or z)
 * @param Encmot0 Motor 0 encoder [-]
 * @param Encmot1 Motor 1 encoder [-]
 * @param Encmot2 Motor 2 encoder [-]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ballbot_log_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,int16_t Vmot0,int16_t Vmot1,int16_t Vmot2,int16_t Imot0,int16_t Imot1,int16_t Imot2,float roll,float pitch,float yaw,float rollcmd,float pitchcmd,float yawcmd,int32_t Encmot0,int32_t Encmot1,int32_t Encmot2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_LOG_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float(buf, 4, roll);
	_mav_put_float(buf, 8, pitch);
	_mav_put_float(buf, 12, yaw);
	_mav_put_float(buf, 16, rollcmd);
	_mav_put_float(buf, 20, pitchcmd);
	_mav_put_float(buf, 24, yawcmd);
	_mav_put_int32_t(buf, 28, Encmot0);
	_mav_put_int32_t(buf, 32, Encmot1);
	_mav_put_int32_t(buf, 36, Encmot2);
	_mav_put_int16_t(buf, 40, Vmot0);
	_mav_put_int16_t(buf, 42, Vmot1);
	_mav_put_int16_t(buf, 44, Vmot2);
	_mav_put_int16_t(buf, 46, Imot0);
	_mav_put_int16_t(buf, 48, Imot1);
	_mav_put_int16_t(buf, 50, Imot2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#else
	mavlink_ballbot_log_t packet;
	packet.time = time;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollcmd = rollcmd;
	packet.pitchcmd = pitchcmd;
	packet.yawcmd = yawcmd;
	packet.Encmot0 = Encmot0;
	packet.Encmot1 = Encmot1;
	packet.Encmot2 = Encmot2;
	packet.Vmot0 = Vmot0;
	packet.Vmot1 = Vmot1;
	packet.Vmot2 = Vmot2;
	packet.Imot0 = Imot0;
	packet.Imot1 = Imot1;
	packet.Imot2 = Imot2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BALLBOT_LOG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_LOG_LEN, MAVLINK_MSG_ID_BALLBOT_LOG_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif
}

/**
 * @brief Encode a ballbot_log struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_log C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_log_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ballbot_log_t* ballbot_log)
{
	return mavlink_msg_ballbot_log_pack(system_id, component_id, msg, ballbot_log->time, ballbot_log->Vmot0, ballbot_log->Vmot1, ballbot_log->Vmot2, ballbot_log->Imot0, ballbot_log->Imot1, ballbot_log->Imot2, ballbot_log->roll, ballbot_log->pitch, ballbot_log->yaw, ballbot_log->rollcmd, ballbot_log->pitchcmd, ballbot_log->yawcmd, ballbot_log->Encmot0, ballbot_log->Encmot1, ballbot_log->Encmot2);
}

/**
 * @brief Encode a ballbot_log struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ballbot_log C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ballbot_log_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ballbot_log_t* ballbot_log)
{
	return mavlink_msg_ballbot_log_pack_chan(system_id, component_id, chan, msg, ballbot_log->time, ballbot_log->Vmot0, ballbot_log->Vmot1, ballbot_log->Vmot2, ballbot_log->Imot0, ballbot_log->Imot1, ballbot_log->Imot2, ballbot_log->roll, ballbot_log->pitch, ballbot_log->yaw, ballbot_log->rollcmd, ballbot_log->pitchcmd, ballbot_log->yawcmd, ballbot_log->Encmot0, ballbot_log->Encmot1, ballbot_log->Encmot2);
}

/**
 * @brief Send a ballbot_log message
 * @param chan MAVLink channel to send the message
 *
 * @param time TimeStamp
 * @param Vmot0 Motor 0 voltage [mV]
 * @param Vmot1 Motor 1 voltage [mV]
 * @param Vmot2 Motor 2 voltage [mV]
 * @param Imot0 Motor 0 current [mA]
 * @param Imot1 Motor 1 current [mA]
 * @param Imot2 Motor 2 current [mA]
 * @param roll Ballbot roll angle [rad]
 * @param pitch Ballbot pitch angle [rad]
 * @param yaw Ballbot yaw angle [rad]
 * @param rollcmd Excitation in the 0 direction (along motor 0 or x)
 * @param pitchcmd Excitation in the 1 direction (along motor 1 or y)
 * @param yawcmd Excitation in the 2 direction (along motor 2 or z)
 * @param Encmot0 Motor 0 encoder [-]
 * @param Encmot1 Motor 1 encoder [-]
 * @param Encmot2 Motor 2 encoder [-]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ballbot_log_send(mavlink_channel_t chan, uint32_t time, int16_t Vmot0, int16_t Vmot1, int16_t Vmot2, int16_t Imot0, int16_t Imot1, int16_t Imot2, float roll, float pitch, float yaw, float rollcmd, float pitchcmd, float yawcmd, int32_t Encmot0, int32_t Encmot1, int32_t Encmot2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BALLBOT_LOG_LEN];
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float(buf, 4, roll);
	_mav_put_float(buf, 8, pitch);
	_mav_put_float(buf, 12, yaw);
	_mav_put_float(buf, 16, rollcmd);
	_mav_put_float(buf, 20, pitchcmd);
	_mav_put_float(buf, 24, yawcmd);
	_mav_put_int32_t(buf, 28, Encmot0);
	_mav_put_int32_t(buf, 32, Encmot1);
	_mav_put_int32_t(buf, 36, Encmot2);
	_mav_put_int16_t(buf, 40, Vmot0);
	_mav_put_int16_t(buf, 42, Vmot1);
	_mav_put_int16_t(buf, 44, Vmot2);
	_mav_put_int16_t(buf, 46, Imot0);
	_mav_put_int16_t(buf, 48, Imot1);
	_mav_put_int16_t(buf, 50, Imot2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, buf, MAVLINK_MSG_ID_BALLBOT_LOG_LEN, MAVLINK_MSG_ID_BALLBOT_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, buf, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif
#else
	mavlink_ballbot_log_t packet;
	packet.time = time;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollcmd = rollcmd;
	packet.pitchcmd = pitchcmd;
	packet.yawcmd = yawcmd;
	packet.Encmot0 = Encmot0;
	packet.Encmot1 = Encmot1;
	packet.Encmot2 = Encmot2;
	packet.Vmot0 = Vmot0;
	packet.Vmot1 = Vmot1;
	packet.Vmot2 = Vmot2;
	packet.Imot0 = Imot0;
	packet.Imot1 = Imot1;
	packet.Imot2 = Imot2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_LOG_LEN, MAVLINK_MSG_ID_BALLBOT_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, (const char *)&packet, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_BALLBOT_LOG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ballbot_log_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, int16_t Vmot0, int16_t Vmot1, int16_t Vmot2, int16_t Imot0, int16_t Imot1, int16_t Imot2, float roll, float pitch, float yaw, float rollcmd, float pitchcmd, float yawcmd, int32_t Encmot0, int32_t Encmot1, int32_t Encmot2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time);
	_mav_put_float(buf, 4, roll);
	_mav_put_float(buf, 8, pitch);
	_mav_put_float(buf, 12, yaw);
	_mav_put_float(buf, 16, rollcmd);
	_mav_put_float(buf, 20, pitchcmd);
	_mav_put_float(buf, 24, yawcmd);
	_mav_put_int32_t(buf, 28, Encmot0);
	_mav_put_int32_t(buf, 32, Encmot1);
	_mav_put_int32_t(buf, 36, Encmot2);
	_mav_put_int16_t(buf, 40, Vmot0);
	_mav_put_int16_t(buf, 42, Vmot1);
	_mav_put_int16_t(buf, 44, Vmot2);
	_mav_put_int16_t(buf, 46, Imot0);
	_mav_put_int16_t(buf, 48, Imot1);
	_mav_put_int16_t(buf, 50, Imot2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, buf, MAVLINK_MSG_ID_BALLBOT_LOG_LEN, MAVLINK_MSG_ID_BALLBOT_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, buf, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif
#else
	mavlink_ballbot_log_t *packet = (mavlink_ballbot_log_t *)msgbuf;
	packet->time = time;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->rollcmd = rollcmd;
	packet->pitchcmd = pitchcmd;
	packet->yawcmd = yawcmd;
	packet->Encmot0 = Encmot0;
	packet->Encmot1 = Encmot1;
	packet->Encmot2 = Encmot2;
	packet->Vmot0 = Vmot0;
	packet->Vmot1 = Vmot1;
	packet->Vmot2 = Vmot2;
	packet->Imot0 = Imot0;
	packet->Imot1 = Imot1;
	packet->Imot2 = Imot2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_LOG_LEN, MAVLINK_MSG_ID_BALLBOT_LOG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BALLBOT_LOG, (const char *)packet, MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE BALLBOT_LOG UNPACKING


/**
 * @brief Get field time from ballbot_log message
 *
 * @return TimeStamp
 */
static inline uint32_t mavlink_msg_ballbot_log_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field Vmot0 from ballbot_log message
 *
 * @return Motor 0 voltage [mV]
 */
static inline int16_t mavlink_msg_ballbot_log_get_Vmot0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field Vmot1 from ballbot_log message
 *
 * @return Motor 1 voltage [mV]
 */
static inline int16_t mavlink_msg_ballbot_log_get_Vmot1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  42);
}

/**
 * @brief Get field Vmot2 from ballbot_log message
 *
 * @return Motor 2 voltage [mV]
 */
static inline int16_t mavlink_msg_ballbot_log_get_Vmot2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  44);
}

/**
 * @brief Get field Imot0 from ballbot_log message
 *
 * @return Motor 0 current [mA]
 */
static inline int16_t mavlink_msg_ballbot_log_get_Imot0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  46);
}

/**
 * @brief Get field Imot1 from ballbot_log message
 *
 * @return Motor 1 current [mA]
 */
static inline int16_t mavlink_msg_ballbot_log_get_Imot1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  48);
}

/**
 * @brief Get field Imot2 from ballbot_log message
 *
 * @return Motor 2 current [mA]
 */
static inline int16_t mavlink_msg_ballbot_log_get_Imot2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  50);
}

/**
 * @brief Get field roll from ballbot_log message
 *
 * @return Ballbot roll angle [rad]
 */
static inline float mavlink_msg_ballbot_log_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pitch from ballbot_log message
 *
 * @return Ballbot pitch angle [rad]
 */
static inline float mavlink_msg_ballbot_log_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yaw from ballbot_log message
 *
 * @return Ballbot yaw angle [rad]
 */
static inline float mavlink_msg_ballbot_log_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field rollcmd from ballbot_log message
 *
 * @return Excitation in the 0 direction (along motor 0 or x)
 */
static inline float mavlink_msg_ballbot_log_get_rollcmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitchcmd from ballbot_log message
 *
 * @return Excitation in the 1 direction (along motor 1 or y)
 */
static inline float mavlink_msg_ballbot_log_get_pitchcmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field yawcmd from ballbot_log message
 *
 * @return Excitation in the 2 direction (along motor 2 or z)
 */
static inline float mavlink_msg_ballbot_log_get_yawcmd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field Encmot0 from ballbot_log message
 *
 * @return Motor 0 encoder [-]
 */
static inline int32_t mavlink_msg_ballbot_log_get_Encmot0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field Encmot1 from ballbot_log message
 *
 * @return Motor 1 encoder [-]
 */
static inline int32_t mavlink_msg_ballbot_log_get_Encmot1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field Encmot2 from ballbot_log message
 *
 * @return Motor 2 encoder [-]
 */
static inline int32_t mavlink_msg_ballbot_log_get_Encmot2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Decode a ballbot_log message into a struct
 *
 * @param msg The message to decode
 * @param ballbot_log C-struct to decode the message contents into
 */
static inline void mavlink_msg_ballbot_log_decode(const mavlink_message_t* msg, mavlink_ballbot_log_t* ballbot_log)
{
#if MAVLINK_NEED_BYTE_SWAP
	ballbot_log->time = mavlink_msg_ballbot_log_get_time(msg);
	ballbot_log->roll = mavlink_msg_ballbot_log_get_roll(msg);
	ballbot_log->pitch = mavlink_msg_ballbot_log_get_pitch(msg);
	ballbot_log->yaw = mavlink_msg_ballbot_log_get_yaw(msg);
	ballbot_log->rollcmd = mavlink_msg_ballbot_log_get_rollcmd(msg);
	ballbot_log->pitchcmd = mavlink_msg_ballbot_log_get_pitchcmd(msg);
	ballbot_log->yawcmd = mavlink_msg_ballbot_log_get_yawcmd(msg);
	ballbot_log->Encmot0 = mavlink_msg_ballbot_log_get_Encmot0(msg);
	ballbot_log->Encmot1 = mavlink_msg_ballbot_log_get_Encmot1(msg);
	ballbot_log->Encmot2 = mavlink_msg_ballbot_log_get_Encmot2(msg);
	ballbot_log->Vmot0 = mavlink_msg_ballbot_log_get_Vmot0(msg);
	ballbot_log->Vmot1 = mavlink_msg_ballbot_log_get_Vmot1(msg);
	ballbot_log->Vmot2 = mavlink_msg_ballbot_log_get_Vmot2(msg);
	ballbot_log->Imot0 = mavlink_msg_ballbot_log_get_Imot0(msg);
	ballbot_log->Imot1 = mavlink_msg_ballbot_log_get_Imot1(msg);
	ballbot_log->Imot2 = mavlink_msg_ballbot_log_get_Imot2(msg);
#else
	memcpy(ballbot_log, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_BALLBOT_LOG_LEN);
#endif
}

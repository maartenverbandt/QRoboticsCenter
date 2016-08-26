// MESSAGE AHRS_ANGLE PACKING

#define MAVLINK_MSG_ID_AHRS_ANGLE 64

typedef struct __mavlink_ahrs_angle_t
{
 float roll; ///< Roll angle.
 float pitch; ///< Pitch angle.
 float yaw; ///< Yaw angle.
 float Droll; ///< Roll angle derivative.
 float Dpitch; ///< Pitch angle derivative.
 float Dyaw; ///< Yaw angle derivative.
} mavlink_ahrs_angle_t;

#define MAVLINK_MSG_ID_AHRS_ANGLE_LEN 24
#define MAVLINK_MSG_ID_64_LEN 24

#define MAVLINK_MSG_ID_AHRS_ANGLE_CRC 0
#define MAVLINK_MSG_ID_64_CRC 0



#define MAVLINK_MESSAGE_INFO_AHRS_ANGLE { \
	"AHRS_ANGLE", \
	6, \
	{  { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ahrs_angle_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ahrs_angle_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ahrs_angle_t, yaw) }, \
         { "Droll", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ahrs_angle_t, Droll) }, \
         { "Dpitch", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ahrs_angle_t, Dpitch) }, \
         { "Dyaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ahrs_angle_t, Dyaw) }, \
         } \
}


/**
 * @brief Pack a ahrs_angle message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param roll Roll angle.
 * @param pitch Pitch angle.
 * @param yaw Yaw angle.
 * @param Droll Roll angle derivative.
 * @param Dpitch Pitch angle derivative.
 * @param Dyaw Yaw angle derivative.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs_angle_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float roll, float pitch, float yaw, float Droll, float Dpitch, float Dyaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS_ANGLE_LEN];
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, Droll);
	_mav_put_float(buf, 16, Dpitch);
	_mav_put_float(buf, 20, Dyaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#else
	mavlink_ahrs_angle_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.Droll = Droll;
	packet.Dpitch = Dpitch;
	packet.Dyaw = Dyaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AHRS_ANGLE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AHRS_ANGLE_LEN, MAVLINK_MSG_ID_AHRS_ANGLE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif
}

/**
 * @brief Pack a ahrs_angle message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param roll Roll angle.
 * @param pitch Pitch angle.
 * @param yaw Yaw angle.
 * @param Droll Roll angle derivative.
 * @param Dpitch Pitch angle derivative.
 * @param Dyaw Yaw angle derivative.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs_angle_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float roll,float pitch,float yaw,float Droll,float Dpitch,float Dyaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS_ANGLE_LEN];
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, Droll);
	_mav_put_float(buf, 16, Dpitch);
	_mav_put_float(buf, 20, Dyaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#else
	mavlink_ahrs_angle_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.Droll = Droll;
	packet.Dpitch = Dpitch;
	packet.Dyaw = Dyaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AHRS_ANGLE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AHRS_ANGLE_LEN, MAVLINK_MSG_ID_AHRS_ANGLE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif
}

/**
 * @brief Encode a ahrs_angle struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ahrs_angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs_angle_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ahrs_angle_t* ahrs_angle)
{
	return mavlink_msg_ahrs_angle_pack(system_id, component_id, msg, ahrs_angle->roll, ahrs_angle->pitch, ahrs_angle->yaw, ahrs_angle->Droll, ahrs_angle->Dpitch, ahrs_angle->Dyaw);
}

/**
 * @brief Encode a ahrs_angle struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ahrs_angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs_angle_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ahrs_angle_t* ahrs_angle)
{
	return mavlink_msg_ahrs_angle_pack_chan(system_id, component_id, chan, msg, ahrs_angle->roll, ahrs_angle->pitch, ahrs_angle->yaw, ahrs_angle->Droll, ahrs_angle->Dpitch, ahrs_angle->Dyaw);
}

/**
 * @brief Send a ahrs_angle message
 * @param chan MAVLink channel to send the message
 *
 * @param roll Roll angle.
 * @param pitch Pitch angle.
 * @param yaw Yaw angle.
 * @param Droll Roll angle derivative.
 * @param Dpitch Pitch angle derivative.
 * @param Dyaw Yaw angle derivative.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ahrs_angle_send(mavlink_channel_t chan, float roll, float pitch, float yaw, float Droll, float Dpitch, float Dyaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS_ANGLE_LEN];
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, Droll);
	_mav_put_float(buf, 16, Dpitch);
	_mav_put_float(buf, 20, Dyaw);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, buf, MAVLINK_MSG_ID_AHRS_ANGLE_LEN, MAVLINK_MSG_ID_AHRS_ANGLE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, buf, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif
#else
	mavlink_ahrs_angle_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.Droll = Droll;
	packet.Dpitch = Dpitch;
	packet.Dyaw = Dyaw;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, (const char *)&packet, MAVLINK_MSG_ID_AHRS_ANGLE_LEN, MAVLINK_MSG_ID_AHRS_ANGLE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, (const char *)&packet, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_AHRS_ANGLE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ahrs_angle_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float roll, float pitch, float yaw, float Droll, float Dpitch, float Dyaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, Droll);
	_mav_put_float(buf, 16, Dpitch);
	_mav_put_float(buf, 20, Dyaw);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, buf, MAVLINK_MSG_ID_AHRS_ANGLE_LEN, MAVLINK_MSG_ID_AHRS_ANGLE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, buf, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif
#else
	mavlink_ahrs_angle_t *packet = (mavlink_ahrs_angle_t *)msgbuf;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->Droll = Droll;
	packet->Dpitch = Dpitch;
	packet->Dyaw = Dyaw;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, (const char *)packet, MAVLINK_MSG_ID_AHRS_ANGLE_LEN, MAVLINK_MSG_ID_AHRS_ANGLE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS_ANGLE, (const char *)packet, MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE AHRS_ANGLE UNPACKING


/**
 * @brief Get field roll from ahrs_angle message
 *
 * @return Roll angle.
 */
static inline float mavlink_msg_ahrs_angle_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field pitch from ahrs_angle message
 *
 * @return Pitch angle.
 */
static inline float mavlink_msg_ahrs_angle_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field yaw from ahrs_angle message
 *
 * @return Yaw angle.
 */
static inline float mavlink_msg_ahrs_angle_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field Droll from ahrs_angle message
 *
 * @return Roll angle derivative.
 */
static inline float mavlink_msg_ahrs_angle_get_Droll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field Dpitch from ahrs_angle message
 *
 * @return Pitch angle derivative.
 */
static inline float mavlink_msg_ahrs_angle_get_Dpitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field Dyaw from ahrs_angle message
 *
 * @return Yaw angle derivative.
 */
static inline float mavlink_msg_ahrs_angle_get_Dyaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a ahrs_angle message into a struct
 *
 * @param msg The message to decode
 * @param ahrs_angle C-struct to decode the message contents into
 */
static inline void mavlink_msg_ahrs_angle_decode(const mavlink_message_t* msg, mavlink_ahrs_angle_t* ahrs_angle)
{
#if MAVLINK_NEED_BYTE_SWAP
	ahrs_angle->roll = mavlink_msg_ahrs_angle_get_roll(msg);
	ahrs_angle->pitch = mavlink_msg_ahrs_angle_get_pitch(msg);
	ahrs_angle->yaw = mavlink_msg_ahrs_angle_get_yaw(msg);
	ahrs_angle->Droll = mavlink_msg_ahrs_angle_get_Droll(msg);
	ahrs_angle->Dpitch = mavlink_msg_ahrs_angle_get_Dpitch(msg);
	ahrs_angle->Dyaw = mavlink_msg_ahrs_angle_get_Dyaw(msg);
#else
	memcpy(ahrs_angle, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AHRS_ANGLE_LEN);
#endif
}

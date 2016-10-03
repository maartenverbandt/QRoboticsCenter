// MESSAGE EXCITATION PACKING

#define MAVLINK_MSG_ID_EXCITATION 73

typedef struct __mavlink_excitation_t
{
 float var1; ///< Variable for settings.
 float var2; ///< Variable for settings.
 float var3; ///< Variable for settings.
 float var4; ///< Variable for settings.
 uint16_t channels; ///< Contains the channels which will be excited.
 uint8_t type; ///< Type of the excitation signal.
} mavlink_excitation_t;

#define MAVLINK_MSG_ID_EXCITATION_LEN 19
#define MAVLINK_MSG_ID_73_LEN 19

#define MAVLINK_MSG_ID_EXCITATION_CRC 84
#define MAVLINK_MSG_ID_73_CRC 84



#define MAVLINK_MESSAGE_INFO_EXCITATION { \
	"EXCITATION", \
	6, \
	{  { "var1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_excitation_t, var1) }, \
         { "var2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_excitation_t, var2) }, \
         { "var3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_excitation_t, var3) }, \
         { "var4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_excitation_t, var4) }, \
         { "channels", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_excitation_t, channels) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_excitation_t, type) }, \
         } \
}


/**
 * @brief Pack a excitation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type Type of the excitation signal.
 * @param channels Contains the channels which will be excited.
 * @param var1 Variable for settings.
 * @param var2 Variable for settings.
 * @param var3 Variable for settings.
 * @param var4 Variable for settings.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_excitation_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t type, uint16_t channels, float var1, float var2, float var3, float var4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EXCITATION_LEN];
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXCITATION_LEN);
#else
	mavlink_excitation_t packet;
	packet.var1 = var1;
	packet.var2 = var2;
	packet.var3 = var3;
	packet.var4 = var4;
	packet.channels = channels;
	packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EXCITATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXCITATION_LEN, MAVLINK_MSG_ID_EXCITATION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif
}

/**
 * @brief Pack a excitation message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type Type of the excitation signal.
 * @param channels Contains the channels which will be excited.
 * @param var1 Variable for settings.
 * @param var2 Variable for settings.
 * @param var3 Variable for settings.
 * @param var4 Variable for settings.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_excitation_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t type,uint16_t channels,float var1,float var2,float var3,float var4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EXCITATION_LEN];
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXCITATION_LEN);
#else
	mavlink_excitation_t packet;
	packet.var1 = var1;
	packet.var2 = var2;
	packet.var3 = var3;
	packet.var4 = var4;
	packet.channels = channels;
	packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EXCITATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXCITATION_LEN, MAVLINK_MSG_ID_EXCITATION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif
}

/**
 * @brief Encode a excitation struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param excitation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_excitation_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_excitation_t* excitation)
{
	return mavlink_msg_excitation_pack(system_id, component_id, msg, excitation->type, excitation->channels, excitation->var1, excitation->var2, excitation->var3, excitation->var4);
}

/**
 * @brief Encode a excitation struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param excitation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_excitation_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_excitation_t* excitation)
{
	return mavlink_msg_excitation_pack_chan(system_id, component_id, chan, msg, excitation->type, excitation->channels, excitation->var1, excitation->var2, excitation->var3, excitation->var4);
}

/**
 * @brief Send a excitation message
 * @param chan MAVLink channel to send the message
 *
 * @param type Type of the excitation signal.
 * @param channels Contains the channels which will be excited.
 * @param var1 Variable for settings.
 * @param var2 Variable for settings.
 * @param var3 Variable for settings.
 * @param var4 Variable for settings.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_excitation_send(mavlink_channel_t chan, uint8_t type, uint16_t channels, float var1, float var2, float var3, float var4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EXCITATION_LEN];
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, buf, MAVLINK_MSG_ID_EXCITATION_LEN, MAVLINK_MSG_ID_EXCITATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, buf, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif
#else
	mavlink_excitation_t packet;
	packet.var1 = var1;
	packet.var2 = var2;
	packet.var3 = var3;
	packet.var4 = var4;
	packet.channels = channels;
	packet.type = type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, (const char *)&packet, MAVLINK_MSG_ID_EXCITATION_LEN, MAVLINK_MSG_ID_EXCITATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, (const char *)&packet, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_EXCITATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_excitation_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint16_t channels, float var1, float var2, float var3, float var4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, var1);
	_mav_put_float(buf, 4, var2);
	_mav_put_float(buf, 8, var3);
	_mav_put_float(buf, 12, var4);
	_mav_put_uint16_t(buf, 16, channels);
	_mav_put_uint8_t(buf, 18, type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, buf, MAVLINK_MSG_ID_EXCITATION_LEN, MAVLINK_MSG_ID_EXCITATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, buf, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif
#else
	mavlink_excitation_t *packet = (mavlink_excitation_t *)msgbuf;
	packet->var1 = var1;
	packet->var2 = var2;
	packet->var3 = var3;
	packet->var4 = var4;
	packet->channels = channels;
	packet->type = type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, (const char *)packet, MAVLINK_MSG_ID_EXCITATION_LEN, MAVLINK_MSG_ID_EXCITATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXCITATION, (const char *)packet, MAVLINK_MSG_ID_EXCITATION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE EXCITATION UNPACKING


/**
 * @brief Get field type from excitation message
 *
 * @return Type of the excitation signal.
 */
static inline uint8_t mavlink_msg_excitation_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field channels from excitation message
 *
 * @return Contains the channels which will be excited.
 */
static inline uint16_t mavlink_msg_excitation_get_channels(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field var1 from excitation message
 *
 * @return Variable for settings.
 */
static inline float mavlink_msg_excitation_get_var1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field var2 from excitation message
 *
 * @return Variable for settings.
 */
static inline float mavlink_msg_excitation_get_var2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field var3 from excitation message
 *
 * @return Variable for settings.
 */
static inline float mavlink_msg_excitation_get_var3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field var4 from excitation message
 *
 * @return Variable for settings.
 */
static inline float mavlink_msg_excitation_get_var4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a excitation message into a struct
 *
 * @param msg The message to decode
 * @param excitation C-struct to decode the message contents into
 */
static inline void mavlink_msg_excitation_decode(const mavlink_message_t* msg, mavlink_excitation_t* excitation)
{
#if MAVLINK_NEED_BYTE_SWAP
	excitation->var1 = mavlink_msg_excitation_get_var1(msg);
	excitation->var2 = mavlink_msg_excitation_get_var2(msg);
	excitation->var3 = mavlink_msg_excitation_get_var3(msg);
	excitation->var4 = mavlink_msg_excitation_get_var4(msg);
	excitation->channels = mavlink_msg_excitation_get_channels(msg);
	excitation->type = mavlink_msg_excitation_get_type(msg);
#else
	memcpy(excitation, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_EXCITATION_LEN);
#endif
}

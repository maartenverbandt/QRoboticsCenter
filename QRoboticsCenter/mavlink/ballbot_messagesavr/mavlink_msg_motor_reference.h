// MESSAGE MOTOR_REFERENCE PACKING

#define MAVLINK_MSG_ID_MOTOR_REFERENCE 52

typedef struct __mavlink_motor_reference_t
{
 int32_t ref; ///< Reference for the selected controller.
 uint16_t dt; ///< Timestep for the smoothed trajectory.
 uint8_t mode; ///< Mode for the reference change. Can be used to invoke a smoothed trajectory
} mavlink_motor_reference_t;

#define MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN 7
#define MAVLINK_MSG_ID_52_LEN 7

#define MAVLINK_MSG_ID_MOTOR_REFERENCE_CRC 45
#define MAVLINK_MSG_ID_52_CRC 45



#define MAVLINK_MESSAGE_INFO_MOTOR_REFERENCE { \
	"MOTOR_REFERENCE", \
	3, \
	{  { "ref", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_motor_reference_t, ref) }, \
         { "dt", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_motor_reference_t, dt) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_motor_reference_t, mode) }, \
         } \
}


/**
 * @brief Pack a motor_reference message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode Mode for the reference change. Can be used to invoke a smoothed trajectory
 * @param ref Reference for the selected controller.
 * @param dt Timestep for the smoothed trajectory.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_reference_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode, int32_t ref, uint16_t dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN];
	_mav_put_int32_t(buf, 0, ref);
	_mav_put_uint16_t(buf, 4, dt);
	_mav_put_uint8_t(buf, 6, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#else
	mavlink_motor_reference_t packet;
	packet.ref = ref;
	packet.dt = dt;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_REFERENCE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN, MAVLINK_MSG_ID_MOTOR_REFERENCE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif
}

/**
 * @brief Pack a motor_reference message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode Mode for the reference change. Can be used to invoke a smoothed trajectory
 * @param ref Reference for the selected controller.
 * @param dt Timestep for the smoothed trajectory.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_reference_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode,int32_t ref,uint16_t dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN];
	_mav_put_int32_t(buf, 0, ref);
	_mav_put_uint16_t(buf, 4, dt);
	_mav_put_uint8_t(buf, 6, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#else
	mavlink_motor_reference_t packet;
	packet.ref = ref;
	packet.dt = dt;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_REFERENCE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN, MAVLINK_MSG_ID_MOTOR_REFERENCE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif
}

/**
 * @brief Encode a motor_reference struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_reference C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_reference_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_reference_t* motor_reference)
{
	return mavlink_msg_motor_reference_pack(system_id, component_id, msg, motor_reference->mode, motor_reference->ref, motor_reference->dt);
}

/**
 * @brief Encode a motor_reference struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_reference C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_reference_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_reference_t* motor_reference)
{
	return mavlink_msg_motor_reference_pack_chan(system_id, component_id, chan, msg, motor_reference->mode, motor_reference->ref, motor_reference->dt);
}

/**
 * @brief Send a motor_reference message
 * @param chan MAVLink channel to send the message
 *
 * @param mode Mode for the reference change. Can be used to invoke a smoothed trajectory
 * @param ref Reference for the selected controller.
 * @param dt Timestep for the smoothed trajectory.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_reference_send(mavlink_channel_t chan, uint8_t mode, int32_t ref, uint16_t dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN];
	_mav_put_int32_t(buf, 0, ref);
	_mav_put_uint16_t(buf, 4, dt);
	_mav_put_uint8_t(buf, 6, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, buf, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN, MAVLINK_MSG_ID_MOTOR_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, buf, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif
#else
	mavlink_motor_reference_t packet;
	packet.ref = ref;
	packet.dt = dt;
	packet.mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN, MAVLINK_MSG_ID_MOTOR_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_reference_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, int32_t ref, uint16_t dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, ref);
	_mav_put_uint16_t(buf, 4, dt);
	_mav_put_uint8_t(buf, 6, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, buf, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN, MAVLINK_MSG_ID_MOTOR_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, buf, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif
#else
	mavlink_motor_reference_t *packet = (mavlink_motor_reference_t *)msgbuf;
	packet->ref = ref;
	packet->dt = dt;
	packet->mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, (const char *)packet, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN, MAVLINK_MSG_ID_MOTOR_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_REFERENCE, (const char *)packet, MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE MOTOR_REFERENCE UNPACKING


/**
 * @brief Get field mode from motor_reference message
 *
 * @return Mode for the reference change. Can be used to invoke a smoothed trajectory
 */
static inline uint8_t mavlink_msg_motor_reference_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field ref from motor_reference message
 *
 * @return Reference for the selected controller.
 */
static inline int32_t mavlink_msg_motor_reference_get_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field dt from motor_reference message
 *
 * @return Timestep for the smoothed trajectory.
 */
static inline uint16_t mavlink_msg_motor_reference_get_dt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a motor_reference message into a struct
 *
 * @param msg The message to decode
 * @param motor_reference C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_reference_decode(const mavlink_message_t* msg, mavlink_motor_reference_t* motor_reference)
{
#if MAVLINK_NEED_BYTE_SWAP
	motor_reference->ref = mavlink_msg_motor_reference_get_ref(msg);
	motor_reference->dt = mavlink_msg_motor_reference_get_dt(msg);
	motor_reference->mode = mavlink_msg_motor_reference_get_mode(msg);
#else
	memcpy(motor_reference, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_MOTOR_REFERENCE_LEN);
#endif
}

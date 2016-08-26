// MESSAGE MOTOR_STATE PACKING

#define MAVLINK_MSG_ID_MOTOR_STATE 50

typedef struct __mavlink_motor_state_t
{
 uint32_t t; ///< time [us].
 int32_t X; ///< position [ticks].
 int32_t V; ///< velocity [ticks/s].
 int32_t A; ///< acceleration [ticks/s^2].
 int32_t r; ///< reference.
 int16_t I; ///< Current [mA].
 int16_t VFF; ///< Feedforward voltage [mV].
 int16_t VFB; ///< Feedback voltage [mV].
} mavlink_motor_state_t;

#define MAVLINK_MSG_ID_MOTOR_STATE_LEN 26
#define MAVLINK_MSG_ID_50_LEN 26

#define MAVLINK_MSG_ID_MOTOR_STATE_CRC 3
#define MAVLINK_MSG_ID_50_CRC 3



#define MAVLINK_MESSAGE_INFO_MOTOR_STATE { \
	"MOTOR_STATE", \
	8, \
	{  { "t", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_motor_state_t, t) }, \
         { "X", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_motor_state_t, X) }, \
         { "V", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_motor_state_t, V) }, \
         { "A", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_motor_state_t, A) }, \
         { "r", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_motor_state_t, r) }, \
         { "I", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_motor_state_t, I) }, \
         { "VFF", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_motor_state_t, VFF) }, \
         { "VFB", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_motor_state_t, VFB) }, \
         } \
}


/**
 * @brief Pack a motor_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param t time [us].
 * @param I Current [mA].
 * @param VFF Feedforward voltage [mV].
 * @param VFB Feedback voltage [mV].
 * @param X position [ticks].
 * @param V velocity [ticks/s].
 * @param A acceleration [ticks/s^2].
 * @param r reference.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t t, int16_t I, int16_t VFF, int16_t VFB, int32_t X, int32_t V, int32_t A, int32_t r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_STATE_LEN];
	_mav_put_uint32_t(buf, 0, t);
	_mav_put_int32_t(buf, 4, X);
	_mav_put_int32_t(buf, 8, V);
	_mav_put_int32_t(buf, 12, A);
	_mav_put_int32_t(buf, 16, r);
	_mav_put_int16_t(buf, 20, I);
	_mav_put_int16_t(buf, 22, VFF);
	_mav_put_int16_t(buf, 24, VFB);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#else
	mavlink_motor_state_t packet;
	packet.t = t;
	packet.X = X;
	packet.V = V;
	packet.A = A;
	packet.r = r;
	packet.I = I;
	packet.VFF = VFF;
	packet.VFB = VFB;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOTOR_STATE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif
}

/**
 * @brief Pack a motor_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param t time [us].
 * @param I Current [mA].
 * @param VFF Feedforward voltage [mV].
 * @param VFB Feedback voltage [mV].
 * @param X position [ticks].
 * @param V velocity [ticks/s].
 * @param A acceleration [ticks/s^2].
 * @param r reference.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t t,int16_t I,int16_t VFF,int16_t VFB,int32_t X,int32_t V,int32_t A,int32_t r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_STATE_LEN];
	_mav_put_uint32_t(buf, 0, t);
	_mav_put_int32_t(buf, 4, X);
	_mav_put_int32_t(buf, 8, V);
	_mav_put_int32_t(buf, 12, A);
	_mav_put_int32_t(buf, 16, r);
	_mav_put_int16_t(buf, 20, I);
	_mav_put_int16_t(buf, 22, VFF);
	_mav_put_int16_t(buf, 24, VFB);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#else
	mavlink_motor_state_t packet;
	packet.t = t;
	packet.X = X;
	packet.V = V;
	packet.A = A;
	packet.r = r;
	packet.I = I;
	packet.VFF = VFF;
	packet.VFB = VFB;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOTOR_STATE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif
}

/**
 * @brief Encode a motor_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_state_t* motor_state)
{
	return mavlink_msg_motor_state_pack(system_id, component_id, msg, motor_state->t, motor_state->I, motor_state->VFF, motor_state->VFB, motor_state->X, motor_state->V, motor_state->A, motor_state->r);
}

/**
 * @brief Encode a motor_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_state_t* motor_state)
{
	return mavlink_msg_motor_state_pack_chan(system_id, component_id, chan, msg, motor_state->t, motor_state->I, motor_state->VFF, motor_state->VFB, motor_state->X, motor_state->V, motor_state->A, motor_state->r);
}

/**
 * @brief Send a motor_state message
 * @param chan MAVLink channel to send the message
 *
 * @param t time [us].
 * @param I Current [mA].
 * @param VFF Feedforward voltage [mV].
 * @param VFB Feedback voltage [mV].
 * @param X position [ticks].
 * @param V velocity [ticks/s].
 * @param A acceleration [ticks/s^2].
 * @param r reference.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_state_send(mavlink_channel_t chan, uint32_t t, int16_t I, int16_t VFF, int16_t VFB, int32_t X, int32_t V, int32_t A, int32_t r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTOR_STATE_LEN];
	_mav_put_uint32_t(buf, 0, t);
	_mav_put_int32_t(buf, 4, X);
	_mav_put_int32_t(buf, 8, V);
	_mav_put_int32_t(buf, 12, A);
	_mav_put_int32_t(buf, 16, r);
	_mav_put_int16_t(buf, 20, I);
	_mav_put_int16_t(buf, 22, VFF);
	_mav_put_int16_t(buf, 24, VFB);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, buf, MAVLINK_MSG_ID_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOTOR_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, buf, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif
#else
	mavlink_motor_state_t packet;
	packet.t = t;
	packet.X = X;
	packet.V = V;
	packet.A = A;
	packet.r = r;
	packet.I = I;
	packet.VFF = VFF;
	packet.VFB = VFB;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOTOR_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_MOTOR_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t t, int16_t I, int16_t VFF, int16_t VFB, int32_t X, int32_t V, int32_t A, int32_t r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, t);
	_mav_put_int32_t(buf, 4, X);
	_mav_put_int32_t(buf, 8, V);
	_mav_put_int32_t(buf, 12, A);
	_mav_put_int32_t(buf, 16, r);
	_mav_put_int16_t(buf, 20, I);
	_mav_put_int16_t(buf, 22, VFF);
	_mav_put_int16_t(buf, 24, VFB);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, buf, MAVLINK_MSG_ID_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOTOR_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, buf, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif
#else
	mavlink_motor_state_t *packet = (mavlink_motor_state_t *)msgbuf;
	packet->t = t;
	packet->X = X;
	packet->V = V;
	packet->A = A;
	packet->r = r;
	packet->I = I;
	packet->VFF = VFF;
	packet->VFB = VFB;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, (const char *)packet, MAVLINK_MSG_ID_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOTOR_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATE, (const char *)packet, MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE MOTOR_STATE UNPACKING


/**
 * @brief Get field t from motor_state message
 *
 * @return time [us].
 */
static inline uint32_t mavlink_msg_motor_state_get_t(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field I from motor_state message
 *
 * @return Current [mA].
 */
static inline int16_t mavlink_msg_motor_state_get_I(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field VFF from motor_state message
 *
 * @return Feedforward voltage [mV].
 */
static inline int16_t mavlink_msg_motor_state_get_VFF(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field VFB from motor_state message
 *
 * @return Feedback voltage [mV].
 */
static inline int16_t mavlink_msg_motor_state_get_VFB(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field X from motor_state message
 *
 * @return position [ticks].
 */
static inline int32_t mavlink_msg_motor_state_get_X(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field V from motor_state message
 *
 * @return velocity [ticks/s].
 */
static inline int32_t mavlink_msg_motor_state_get_V(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field A from motor_state message
 *
 * @return acceleration [ticks/s^2].
 */
static inline int32_t mavlink_msg_motor_state_get_A(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field r from motor_state message
 *
 * @return reference.
 */
static inline int32_t mavlink_msg_motor_state_get_r(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Decode a motor_state message into a struct
 *
 * @param msg The message to decode
 * @param motor_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_state_decode(const mavlink_message_t* msg, mavlink_motor_state_t* motor_state)
{
#if MAVLINK_NEED_BYTE_SWAP
	motor_state->t = mavlink_msg_motor_state_get_t(msg);
	motor_state->X = mavlink_msg_motor_state_get_X(msg);
	motor_state->V = mavlink_msg_motor_state_get_V(msg);
	motor_state->A = mavlink_msg_motor_state_get_A(msg);
	motor_state->r = mavlink_msg_motor_state_get_r(msg);
	motor_state->I = mavlink_msg_motor_state_get_I(msg);
	motor_state->VFF = mavlink_msg_motor_state_get_VFF(msg);
	motor_state->VFB = mavlink_msg_motor_state_get_VFB(msg);
#else
	memcpy(motor_state, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_MOTOR_STATE_LEN);
#endif
}

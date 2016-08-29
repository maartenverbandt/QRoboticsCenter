// MESSAGE IMU_CAL_PARAM PACKING

#define MAVLINK_MSG_ID_IMU_CAL_PARAM 63

typedef struct __mavlink_imu_cal_param_t
{
 float scale_x; ///< scaling in x-direction.
 float scale_y; ///< scaling in y-direction.
 float scale_z; ///< scaling in z-direction.
 int16_t offs_x; ///< offset in x-direction.
 int16_t offs_y; ///< offset in y-direction.
 int16_t offs_z; ///< offset in z-direction.
 uint8_t mode; ///< mode of calibration: ACC=1; GYRO=2; MAGN=3
} mavlink_imu_cal_param_t;

#define MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN 19
#define MAVLINK_MSG_ID_63_LEN 19

#define MAVLINK_MSG_ID_IMU_CAL_PARAM_CRC 195
#define MAVLINK_MSG_ID_63_CRC 195



#define MAVLINK_MESSAGE_INFO_IMU_CAL_PARAM { \
	"IMU_CAL_PARAM", \
	7, \
	{  { "scale_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_imu_cal_param_t, scale_x) }, \
         { "scale_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_imu_cal_param_t, scale_y) }, \
         { "scale_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_imu_cal_param_t, scale_z) }, \
         { "offs_x", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_cal_param_t, offs_x) }, \
         { "offs_y", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_imu_cal_param_t, offs_y) }, \
         { "offs_z", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_imu_cal_param_t, offs_z) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_imu_cal_param_t, mode) }, \
         } \
}


/**
 * @brief Pack a imu_cal_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode mode of calibration: ACC=1; GYRO=2; MAGN=3
 * @param offs_x offset in x-direction.
 * @param offs_y offset in y-direction.
 * @param offs_z offset in z-direction.
 * @param scale_x scaling in x-direction.
 * @param scale_y scaling in y-direction.
 * @param scale_z scaling in z-direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_cal_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode, int16_t offs_x, int16_t offs_y, int16_t offs_z, float scale_x, float scale_y, float scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN];
	_mav_put_float(buf, 0, scale_x);
	_mav_put_float(buf, 4, scale_y);
	_mav_put_float(buf, 8, scale_z);
	_mav_put_int16_t(buf, 12, offs_x);
	_mav_put_int16_t(buf, 14, offs_y);
	_mav_put_int16_t(buf, 16, offs_z);
	_mav_put_uint8_t(buf, 18, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#else
	mavlink_imu_cal_param_t packet;
	packet.scale_x = scale_x;
	packet.scale_y = scale_y;
	packet.scale_z = scale_z;
	packet.offs_x = offs_x;
	packet.offs_y = offs_y;
	packet.offs_z = offs_z;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_CAL_PARAM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN, MAVLINK_MSG_ID_IMU_CAL_PARAM_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif
}

/**
 * @brief Pack a imu_cal_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode mode of calibration: ACC=1; GYRO=2; MAGN=3
 * @param offs_x offset in x-direction.
 * @param offs_y offset in y-direction.
 * @param offs_z offset in z-direction.
 * @param scale_x scaling in x-direction.
 * @param scale_y scaling in y-direction.
 * @param scale_z scaling in z-direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_cal_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode,int16_t offs_x,int16_t offs_y,int16_t offs_z,float scale_x,float scale_y,float scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN];
	_mav_put_float(buf, 0, scale_x);
	_mav_put_float(buf, 4, scale_y);
	_mav_put_float(buf, 8, scale_z);
	_mav_put_int16_t(buf, 12, offs_x);
	_mav_put_int16_t(buf, 14, offs_y);
	_mav_put_int16_t(buf, 16, offs_z);
	_mav_put_uint8_t(buf, 18, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#else
	mavlink_imu_cal_param_t packet;
	packet.scale_x = scale_x;
	packet.scale_y = scale_y;
	packet.scale_z = scale_z;
	packet.offs_x = offs_x;
	packet.offs_y = offs_y;
	packet.offs_z = offs_z;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_CAL_PARAM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN, MAVLINK_MSG_ID_IMU_CAL_PARAM_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif
}

/**
 * @brief Encode a imu_cal_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param imu_cal_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_cal_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_imu_cal_param_t* imu_cal_param)
{
	return mavlink_msg_imu_cal_param_pack(system_id, component_id, msg, imu_cal_param->mode, imu_cal_param->offs_x, imu_cal_param->offs_y, imu_cal_param->offs_z, imu_cal_param->scale_x, imu_cal_param->scale_y, imu_cal_param->scale_z);
}

/**
 * @brief Encode a imu_cal_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param imu_cal_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_cal_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_imu_cal_param_t* imu_cal_param)
{
	return mavlink_msg_imu_cal_param_pack_chan(system_id, component_id, chan, msg, imu_cal_param->mode, imu_cal_param->offs_x, imu_cal_param->offs_y, imu_cal_param->offs_z, imu_cal_param->scale_x, imu_cal_param->scale_y, imu_cal_param->scale_z);
}

/**
 * @brief Send a imu_cal_param message
 * @param chan MAVLink channel to send the message
 *
 * @param mode mode of calibration: ACC=1; GYRO=2; MAGN=3
 * @param offs_x offset in x-direction.
 * @param offs_y offset in y-direction.
 * @param offs_z offset in z-direction.
 * @param scale_x scaling in x-direction.
 * @param scale_y scaling in y-direction.
 * @param scale_z scaling in z-direction.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_imu_cal_param_send(mavlink_channel_t chan, uint8_t mode, int16_t offs_x, int16_t offs_y, int16_t offs_z, float scale_x, float scale_y, float scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN];
	_mav_put_float(buf, 0, scale_x);
	_mav_put_float(buf, 4, scale_y);
	_mav_put_float(buf, 8, scale_z);
	_mav_put_int16_t(buf, 12, offs_x);
	_mav_put_int16_t(buf, 14, offs_y);
	_mav_put_int16_t(buf, 16, offs_z);
	_mav_put_uint8_t(buf, 18, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, buf, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN, MAVLINK_MSG_ID_IMU_CAL_PARAM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, buf, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif
#else
	mavlink_imu_cal_param_t packet;
	packet.scale_x = scale_x;
	packet.scale_y = scale_y;
	packet.scale_z = scale_z;
	packet.offs_x = offs_x;
	packet.offs_y = offs_y;
	packet.offs_z = offs_z;
	packet.mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, (const char *)&packet, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN, MAVLINK_MSG_ID_IMU_CAL_PARAM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, (const char *)&packet, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_imu_cal_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, int16_t offs_x, int16_t offs_y, int16_t offs_z, float scale_x, float scale_y, float scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, scale_x);
	_mav_put_float(buf, 4, scale_y);
	_mav_put_float(buf, 8, scale_z);
	_mav_put_int16_t(buf, 12, offs_x);
	_mav_put_int16_t(buf, 14, offs_y);
	_mav_put_int16_t(buf, 16, offs_z);
	_mav_put_uint8_t(buf, 18, mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, buf, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN, MAVLINK_MSG_ID_IMU_CAL_PARAM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, buf, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif
#else
	mavlink_imu_cal_param_t *packet = (mavlink_imu_cal_param_t *)msgbuf;
	packet->scale_x = scale_x;
	packet->scale_y = scale_y;
	packet->scale_z = scale_z;
	packet->offs_x = offs_x;
	packet->offs_y = offs_y;
	packet->offs_z = offs_z;
	packet->mode = mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, (const char *)packet, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN, MAVLINK_MSG_ID_IMU_CAL_PARAM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_PARAM, (const char *)packet, MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE IMU_CAL_PARAM UNPACKING


/**
 * @brief Get field mode from imu_cal_param message
 *
 * @return mode of calibration: ACC=1; GYRO=2; MAGN=3
 */
static inline uint8_t mavlink_msg_imu_cal_param_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field offs_x from imu_cal_param message
 *
 * @return offset in x-direction.
 */
static inline int16_t mavlink_msg_imu_cal_param_get_offs_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field offs_y from imu_cal_param message
 *
 * @return offset in y-direction.
 */
static inline int16_t mavlink_msg_imu_cal_param_get_offs_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field offs_z from imu_cal_param message
 *
 * @return offset in z-direction.
 */
static inline int16_t mavlink_msg_imu_cal_param_get_offs_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field scale_x from imu_cal_param message
 *
 * @return scaling in x-direction.
 */
static inline float mavlink_msg_imu_cal_param_get_scale_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field scale_y from imu_cal_param message
 *
 * @return scaling in y-direction.
 */
static inline float mavlink_msg_imu_cal_param_get_scale_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field scale_z from imu_cal_param message
 *
 * @return scaling in z-direction.
 */
static inline float mavlink_msg_imu_cal_param_get_scale_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a imu_cal_param message into a struct
 *
 * @param msg The message to decode
 * @param imu_cal_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_imu_cal_param_decode(const mavlink_message_t* msg, mavlink_imu_cal_param_t* imu_cal_param)
{
#if MAVLINK_NEED_BYTE_SWAP
	imu_cal_param->scale_x = mavlink_msg_imu_cal_param_get_scale_x(msg);
	imu_cal_param->scale_y = mavlink_msg_imu_cal_param_get_scale_y(msg);
	imu_cal_param->scale_z = mavlink_msg_imu_cal_param_get_scale_z(msg);
	imu_cal_param->offs_x = mavlink_msg_imu_cal_param_get_offs_x(msg);
	imu_cal_param->offs_y = mavlink_msg_imu_cal_param_get_offs_y(msg);
	imu_cal_param->offs_z = mavlink_msg_imu_cal_param_get_offs_z(msg);
	imu_cal_param->mode = mavlink_msg_imu_cal_param_get_mode(msg);
#else
	memcpy(imu_cal_param, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_IMU_CAL_PARAM_LEN);
#endif
}

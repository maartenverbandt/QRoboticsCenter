// MESSAGE IMU_RAW_DATA PACKING

#define MAVLINK_MSG_ID_IMU_RAW_DATA 61

typedef struct __mavlink_imu_raw_data_t
{
 int16_t acc_raw_x; ///< raw acceleration measurement in x-direction.
 int16_t acc_raw_y; ///< raw acceleration measurement in y-direction.
 int16_t acc_raw_z; ///< raw acceleration measurement in z-direction.
 int16_t gyro_raw_x; ///< raw gyroscope measurement in x-direction.
 int16_t gyro_raw_y; ///< raw gyroscope measurement in y-direction.
 int16_t gyro_raw_z; ///< raw gyroscope measurement in z-direction.
 int16_t magn_raw_x; ///< raw magnetometer measurement in x-direction.
 int16_t magn_raw_y; ///< raw magnetometer measurement in y-direction.
 int16_t magn_raw_z; ///< raw magnetometer measurement in z-direction.
} mavlink_imu_raw_data_t;

#define MAVLINK_MSG_ID_IMU_RAW_DATA_LEN 18
#define MAVLINK_MSG_ID_61_LEN 18

#define MAVLINK_MSG_ID_IMU_RAW_DATA_CRC 19
#define MAVLINK_MSG_ID_61_CRC 19



#define MAVLINK_MESSAGE_INFO_IMU_RAW_DATA { \
	"IMU_RAW_DATA", \
	9, \
	{  { "acc_raw_x", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_imu_raw_data_t, acc_raw_x) }, \
         { "acc_raw_y", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_imu_raw_data_t, acc_raw_y) }, \
         { "acc_raw_z", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_imu_raw_data_t, acc_raw_z) }, \
         { "gyro_raw_x", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_imu_raw_data_t, gyro_raw_x) }, \
         { "gyro_raw_y", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_imu_raw_data_t, gyro_raw_y) }, \
         { "gyro_raw_z", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_imu_raw_data_t, gyro_raw_z) }, \
         { "magn_raw_x", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_raw_data_t, magn_raw_x) }, \
         { "magn_raw_y", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_imu_raw_data_t, magn_raw_y) }, \
         { "magn_raw_z", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_imu_raw_data_t, magn_raw_z) }, \
         } \
}


/**
 * @brief Pack a imu_raw_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param acc_raw_x raw acceleration measurement in x-direction.
 * @param acc_raw_y raw acceleration measurement in y-direction.
 * @param acc_raw_z raw acceleration measurement in z-direction.
 * @param gyro_raw_x raw gyroscope measurement in x-direction.
 * @param gyro_raw_y raw gyroscope measurement in y-direction.
 * @param gyro_raw_z raw gyroscope measurement in z-direction.
 * @param magn_raw_x raw magnetometer measurement in x-direction.
 * @param magn_raw_y raw magnetometer measurement in y-direction.
 * @param magn_raw_z raw magnetometer measurement in z-direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_raw_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t acc_raw_x, int16_t acc_raw_y, int16_t acc_raw_z, int16_t gyro_raw_x, int16_t gyro_raw_y, int16_t gyro_raw_z, int16_t magn_raw_x, int16_t magn_raw_y, int16_t magn_raw_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_RAW_DATA_LEN];
	_mav_put_int16_t(buf, 0, acc_raw_x);
	_mav_put_int16_t(buf, 2, acc_raw_y);
	_mav_put_int16_t(buf, 4, acc_raw_z);
	_mav_put_int16_t(buf, 6, gyro_raw_x);
	_mav_put_int16_t(buf, 8, gyro_raw_y);
	_mav_put_int16_t(buf, 10, gyro_raw_z);
	_mav_put_int16_t(buf, 12, magn_raw_x);
	_mav_put_int16_t(buf, 14, magn_raw_y);
	_mav_put_int16_t(buf, 16, magn_raw_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#else
	mavlink_imu_raw_data_t packet;
	packet.acc_raw_x = acc_raw_x;
	packet.acc_raw_y = acc_raw_y;
	packet.acc_raw_z = acc_raw_z;
	packet.gyro_raw_x = gyro_raw_x;
	packet.gyro_raw_y = gyro_raw_y;
	packet.gyro_raw_z = gyro_raw_z;
	packet.magn_raw_x = magn_raw_x;
	packet.magn_raw_y = magn_raw_y;
	packet.magn_raw_z = magn_raw_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_RAW_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN, MAVLINK_MSG_ID_IMU_RAW_DATA_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif
}

/**
 * @brief Pack a imu_raw_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param acc_raw_x raw acceleration measurement in x-direction.
 * @param acc_raw_y raw acceleration measurement in y-direction.
 * @param acc_raw_z raw acceleration measurement in z-direction.
 * @param gyro_raw_x raw gyroscope measurement in x-direction.
 * @param gyro_raw_y raw gyroscope measurement in y-direction.
 * @param gyro_raw_z raw gyroscope measurement in z-direction.
 * @param magn_raw_x raw magnetometer measurement in x-direction.
 * @param magn_raw_y raw magnetometer measurement in y-direction.
 * @param magn_raw_z raw magnetometer measurement in z-direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_raw_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t acc_raw_x,int16_t acc_raw_y,int16_t acc_raw_z,int16_t gyro_raw_x,int16_t gyro_raw_y,int16_t gyro_raw_z,int16_t magn_raw_x,int16_t magn_raw_y,int16_t magn_raw_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_RAW_DATA_LEN];
	_mav_put_int16_t(buf, 0, acc_raw_x);
	_mav_put_int16_t(buf, 2, acc_raw_y);
	_mav_put_int16_t(buf, 4, acc_raw_z);
	_mav_put_int16_t(buf, 6, gyro_raw_x);
	_mav_put_int16_t(buf, 8, gyro_raw_y);
	_mav_put_int16_t(buf, 10, gyro_raw_z);
	_mav_put_int16_t(buf, 12, magn_raw_x);
	_mav_put_int16_t(buf, 14, magn_raw_y);
	_mav_put_int16_t(buf, 16, magn_raw_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#else
	mavlink_imu_raw_data_t packet;
	packet.acc_raw_x = acc_raw_x;
	packet.acc_raw_y = acc_raw_y;
	packet.acc_raw_z = acc_raw_z;
	packet.gyro_raw_x = gyro_raw_x;
	packet.gyro_raw_y = gyro_raw_y;
	packet.gyro_raw_z = gyro_raw_z;
	packet.magn_raw_x = magn_raw_x;
	packet.magn_raw_y = magn_raw_y;
	packet.magn_raw_z = magn_raw_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_RAW_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN, MAVLINK_MSG_ID_IMU_RAW_DATA_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif
}

/**
 * @brief Encode a imu_raw_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param imu_raw_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_raw_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_imu_raw_data_t* imu_raw_data)
{
	return mavlink_msg_imu_raw_data_pack(system_id, component_id, msg, imu_raw_data->acc_raw_x, imu_raw_data->acc_raw_y, imu_raw_data->acc_raw_z, imu_raw_data->gyro_raw_x, imu_raw_data->gyro_raw_y, imu_raw_data->gyro_raw_z, imu_raw_data->magn_raw_x, imu_raw_data->magn_raw_y, imu_raw_data->magn_raw_z);
}

/**
 * @brief Encode a imu_raw_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param imu_raw_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_raw_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_imu_raw_data_t* imu_raw_data)
{
	return mavlink_msg_imu_raw_data_pack_chan(system_id, component_id, chan, msg, imu_raw_data->acc_raw_x, imu_raw_data->acc_raw_y, imu_raw_data->acc_raw_z, imu_raw_data->gyro_raw_x, imu_raw_data->gyro_raw_y, imu_raw_data->gyro_raw_z, imu_raw_data->magn_raw_x, imu_raw_data->magn_raw_y, imu_raw_data->magn_raw_z);
}

/**
 * @brief Send a imu_raw_data message
 * @param chan MAVLink channel to send the message
 *
 * @param acc_raw_x raw acceleration measurement in x-direction.
 * @param acc_raw_y raw acceleration measurement in y-direction.
 * @param acc_raw_z raw acceleration measurement in z-direction.
 * @param gyro_raw_x raw gyroscope measurement in x-direction.
 * @param gyro_raw_y raw gyroscope measurement in y-direction.
 * @param gyro_raw_z raw gyroscope measurement in z-direction.
 * @param magn_raw_x raw magnetometer measurement in x-direction.
 * @param magn_raw_y raw magnetometer measurement in y-direction.
 * @param magn_raw_z raw magnetometer measurement in z-direction.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_imu_raw_data_send(mavlink_channel_t chan, int16_t acc_raw_x, int16_t acc_raw_y, int16_t acc_raw_z, int16_t gyro_raw_x, int16_t gyro_raw_y, int16_t gyro_raw_z, int16_t magn_raw_x, int16_t magn_raw_y, int16_t magn_raw_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_RAW_DATA_LEN];
	_mav_put_int16_t(buf, 0, acc_raw_x);
	_mav_put_int16_t(buf, 2, acc_raw_y);
	_mav_put_int16_t(buf, 4, acc_raw_z);
	_mav_put_int16_t(buf, 6, gyro_raw_x);
	_mav_put_int16_t(buf, 8, gyro_raw_y);
	_mav_put_int16_t(buf, 10, gyro_raw_z);
	_mav_put_int16_t(buf, 12, magn_raw_x);
	_mav_put_int16_t(buf, 14, magn_raw_y);
	_mav_put_int16_t(buf, 16, magn_raw_z);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, buf, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN, MAVLINK_MSG_ID_IMU_RAW_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, buf, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif
#else
	mavlink_imu_raw_data_t packet;
	packet.acc_raw_x = acc_raw_x;
	packet.acc_raw_y = acc_raw_y;
	packet.acc_raw_z = acc_raw_z;
	packet.gyro_raw_x = gyro_raw_x;
	packet.gyro_raw_y = gyro_raw_y;
	packet.gyro_raw_z = gyro_raw_z;
	packet.magn_raw_x = magn_raw_x;
	packet.magn_raw_y = magn_raw_y;
	packet.magn_raw_z = magn_raw_z;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, (const char *)&packet, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN, MAVLINK_MSG_ID_IMU_RAW_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, (const char *)&packet, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_IMU_RAW_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_imu_raw_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t acc_raw_x, int16_t acc_raw_y, int16_t acc_raw_z, int16_t gyro_raw_x, int16_t gyro_raw_y, int16_t gyro_raw_z, int16_t magn_raw_x, int16_t magn_raw_y, int16_t magn_raw_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int16_t(buf, 0, acc_raw_x);
	_mav_put_int16_t(buf, 2, acc_raw_y);
	_mav_put_int16_t(buf, 4, acc_raw_z);
	_mav_put_int16_t(buf, 6, gyro_raw_x);
	_mav_put_int16_t(buf, 8, gyro_raw_y);
	_mav_put_int16_t(buf, 10, gyro_raw_z);
	_mav_put_int16_t(buf, 12, magn_raw_x);
	_mav_put_int16_t(buf, 14, magn_raw_y);
	_mav_put_int16_t(buf, 16, magn_raw_z);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, buf, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN, MAVLINK_MSG_ID_IMU_RAW_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, buf, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif
#else
	mavlink_imu_raw_data_t *packet = (mavlink_imu_raw_data_t *)msgbuf;
	packet->acc_raw_x = acc_raw_x;
	packet->acc_raw_y = acc_raw_y;
	packet->acc_raw_z = acc_raw_z;
	packet->gyro_raw_x = gyro_raw_x;
	packet->gyro_raw_y = gyro_raw_y;
	packet->gyro_raw_z = gyro_raw_z;
	packet->magn_raw_x = magn_raw_x;
	packet->magn_raw_y = magn_raw_y;
	packet->magn_raw_z = magn_raw_z;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, (const char *)packet, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN, MAVLINK_MSG_ID_IMU_RAW_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_RAW_DATA, (const char *)packet, MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE IMU_RAW_DATA UNPACKING


/**
 * @brief Get field acc_raw_x from imu_raw_data message
 *
 * @return raw acceleration measurement in x-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_acc_raw_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field acc_raw_y from imu_raw_data message
 *
 * @return raw acceleration measurement in y-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_acc_raw_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field acc_raw_z from imu_raw_data message
 *
 * @return raw acceleration measurement in z-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_acc_raw_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field gyro_raw_x from imu_raw_data message
 *
 * @return raw gyroscope measurement in x-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_gyro_raw_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field gyro_raw_y from imu_raw_data message
 *
 * @return raw gyroscope measurement in y-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_gyro_raw_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field gyro_raw_z from imu_raw_data message
 *
 * @return raw gyroscope measurement in z-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_gyro_raw_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field magn_raw_x from imu_raw_data message
 *
 * @return raw magnetometer measurement in x-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_magn_raw_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field magn_raw_y from imu_raw_data message
 *
 * @return raw magnetometer measurement in y-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_magn_raw_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field magn_raw_z from imu_raw_data message
 *
 * @return raw magnetometer measurement in z-direction.
 */
static inline int16_t mavlink_msg_imu_raw_data_get_magn_raw_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Decode a imu_raw_data message into a struct
 *
 * @param msg The message to decode
 * @param imu_raw_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_imu_raw_data_decode(const mavlink_message_t* msg, mavlink_imu_raw_data_t* imu_raw_data)
{
#if MAVLINK_NEED_BYTE_SWAP
	imu_raw_data->acc_raw_x = mavlink_msg_imu_raw_data_get_acc_raw_x(msg);
	imu_raw_data->acc_raw_y = mavlink_msg_imu_raw_data_get_acc_raw_y(msg);
	imu_raw_data->acc_raw_z = mavlink_msg_imu_raw_data_get_acc_raw_z(msg);
	imu_raw_data->gyro_raw_x = mavlink_msg_imu_raw_data_get_gyro_raw_x(msg);
	imu_raw_data->gyro_raw_y = mavlink_msg_imu_raw_data_get_gyro_raw_y(msg);
	imu_raw_data->gyro_raw_z = mavlink_msg_imu_raw_data_get_gyro_raw_z(msg);
	imu_raw_data->magn_raw_x = mavlink_msg_imu_raw_data_get_magn_raw_x(msg);
	imu_raw_data->magn_raw_y = mavlink_msg_imu_raw_data_get_magn_raw_y(msg);
	imu_raw_data->magn_raw_z = mavlink_msg_imu_raw_data_get_magn_raw_z(msg);
#else
	memcpy(imu_raw_data, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_IMU_RAW_DATA_LEN);
#endif
}

// MESSAGE IMU_CAL_DATA PACKING

#define MAVLINK_MSG_ID_IMU_CAL_DATA 62

typedef struct __mavlink_imu_cal_data_t
{
 float acc_cal_x; ///< Calibrated acceleration measurement in x-direction.
 float acc_cal_y; ///< Calibrated acceleration measurement in y-direction.
 float acc_cal_z; ///< Calibrated acceleration measurement in z-direction.
 float gyro_cal_x; ///< Calibrated gyroscope measurement in x-direction.
 float gyro_cal_y; ///< Calibrated gyroscope measurement in y-direction.
 float gyro_cal_z; ///< Calibrated gyroscope measurement in z-direction.
 float magn_cal_x; ///< Calibrated magnetometer measurement in x-direction.
 float magn_cal_y; ///< Calibrated magnetometer measurement in y-direction.
 float magn_cal_z; ///< Calibrated magnetometer measurement in z-direction.
} mavlink_imu_cal_data_t;

#define MAVLINK_MSG_ID_IMU_CAL_DATA_LEN 36
#define MAVLINK_MSG_ID_62_LEN 36

#define MAVLINK_MSG_ID_IMU_CAL_DATA_CRC 12
#define MAVLINK_MSG_ID_62_CRC 12



#define MAVLINK_MESSAGE_INFO_IMU_CAL_DATA { \
	"IMU_CAL_DATA", \
	9, \
	{  { "acc_cal_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_imu_cal_data_t, acc_cal_x) }, \
         { "acc_cal_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_imu_cal_data_t, acc_cal_y) }, \
         { "acc_cal_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_imu_cal_data_t, acc_cal_z) }, \
         { "gyro_cal_x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_imu_cal_data_t, gyro_cal_x) }, \
         { "gyro_cal_y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_imu_cal_data_t, gyro_cal_y) }, \
         { "gyro_cal_z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_imu_cal_data_t, gyro_cal_z) }, \
         { "magn_cal_x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_imu_cal_data_t, magn_cal_x) }, \
         { "magn_cal_y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_imu_cal_data_t, magn_cal_y) }, \
         { "magn_cal_z", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_imu_cal_data_t, magn_cal_z) }, \
         } \
}


/**
 * @brief Pack a imu_cal_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param acc_cal_x Calibrated acceleration measurement in x-direction.
 * @param acc_cal_y Calibrated acceleration measurement in y-direction.
 * @param acc_cal_z Calibrated acceleration measurement in z-direction.
 * @param gyro_cal_x Calibrated gyroscope measurement in x-direction.
 * @param gyro_cal_y Calibrated gyroscope measurement in y-direction.
 * @param gyro_cal_z Calibrated gyroscope measurement in z-direction.
 * @param magn_cal_x Calibrated magnetometer measurement in x-direction.
 * @param magn_cal_y Calibrated magnetometer measurement in y-direction.
 * @param magn_cal_z Calibrated magnetometer measurement in z-direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_cal_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float acc_cal_x, float acc_cal_y, float acc_cal_z, float gyro_cal_x, float gyro_cal_y, float gyro_cal_z, float magn_cal_x, float magn_cal_y, float magn_cal_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_CAL_DATA_LEN];
	_mav_put_float(buf, 0, acc_cal_x);
	_mav_put_float(buf, 4, acc_cal_y);
	_mav_put_float(buf, 8, acc_cal_z);
	_mav_put_float(buf, 12, gyro_cal_x);
	_mav_put_float(buf, 16, gyro_cal_y);
	_mav_put_float(buf, 20, gyro_cal_z);
	_mav_put_float(buf, 24, magn_cal_x);
	_mav_put_float(buf, 28, magn_cal_y);
	_mav_put_float(buf, 32, magn_cal_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#else
	mavlink_imu_cal_data_t packet;
	packet.acc_cal_x = acc_cal_x;
	packet.acc_cal_y = acc_cal_y;
	packet.acc_cal_z = acc_cal_z;
	packet.gyro_cal_x = gyro_cal_x;
	packet.gyro_cal_y = gyro_cal_y;
	packet.gyro_cal_z = gyro_cal_z;
	packet.magn_cal_x = magn_cal_x;
	packet.magn_cal_y = magn_cal_y;
	packet.magn_cal_z = magn_cal_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_CAL_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN, MAVLINK_MSG_ID_IMU_CAL_DATA_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif
}

/**
 * @brief Pack a imu_cal_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param acc_cal_x Calibrated acceleration measurement in x-direction.
 * @param acc_cal_y Calibrated acceleration measurement in y-direction.
 * @param acc_cal_z Calibrated acceleration measurement in z-direction.
 * @param gyro_cal_x Calibrated gyroscope measurement in x-direction.
 * @param gyro_cal_y Calibrated gyroscope measurement in y-direction.
 * @param gyro_cal_z Calibrated gyroscope measurement in z-direction.
 * @param magn_cal_x Calibrated magnetometer measurement in x-direction.
 * @param magn_cal_y Calibrated magnetometer measurement in y-direction.
 * @param magn_cal_z Calibrated magnetometer measurement in z-direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_cal_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float acc_cal_x,float acc_cal_y,float acc_cal_z,float gyro_cal_x,float gyro_cal_y,float gyro_cal_z,float magn_cal_x,float magn_cal_y,float magn_cal_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_CAL_DATA_LEN];
	_mav_put_float(buf, 0, acc_cal_x);
	_mav_put_float(buf, 4, acc_cal_y);
	_mav_put_float(buf, 8, acc_cal_z);
	_mav_put_float(buf, 12, gyro_cal_x);
	_mav_put_float(buf, 16, gyro_cal_y);
	_mav_put_float(buf, 20, gyro_cal_z);
	_mav_put_float(buf, 24, magn_cal_x);
	_mav_put_float(buf, 28, magn_cal_y);
	_mav_put_float(buf, 32, magn_cal_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#else
	mavlink_imu_cal_data_t packet;
	packet.acc_cal_x = acc_cal_x;
	packet.acc_cal_y = acc_cal_y;
	packet.acc_cal_z = acc_cal_z;
	packet.gyro_cal_x = gyro_cal_x;
	packet.gyro_cal_y = gyro_cal_y;
	packet.gyro_cal_z = gyro_cal_z;
	packet.magn_cal_x = magn_cal_x;
	packet.magn_cal_y = magn_cal_y;
	packet.magn_cal_z = magn_cal_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_CAL_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN, MAVLINK_MSG_ID_IMU_CAL_DATA_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif
}

/**
 * @brief Encode a imu_cal_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param imu_cal_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_cal_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_imu_cal_data_t* imu_cal_data)
{
	return mavlink_msg_imu_cal_data_pack(system_id, component_id, msg, imu_cal_data->acc_cal_x, imu_cal_data->acc_cal_y, imu_cal_data->acc_cal_z, imu_cal_data->gyro_cal_x, imu_cal_data->gyro_cal_y, imu_cal_data->gyro_cal_z, imu_cal_data->magn_cal_x, imu_cal_data->magn_cal_y, imu_cal_data->magn_cal_z);
}

/**
 * @brief Encode a imu_cal_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param imu_cal_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_cal_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_imu_cal_data_t* imu_cal_data)
{
	return mavlink_msg_imu_cal_data_pack_chan(system_id, component_id, chan, msg, imu_cal_data->acc_cal_x, imu_cal_data->acc_cal_y, imu_cal_data->acc_cal_z, imu_cal_data->gyro_cal_x, imu_cal_data->gyro_cal_y, imu_cal_data->gyro_cal_z, imu_cal_data->magn_cal_x, imu_cal_data->magn_cal_y, imu_cal_data->magn_cal_z);
}

/**
 * @brief Send a imu_cal_data message
 * @param chan MAVLink channel to send the message
 *
 * @param acc_cal_x Calibrated acceleration measurement in x-direction.
 * @param acc_cal_y Calibrated acceleration measurement in y-direction.
 * @param acc_cal_z Calibrated acceleration measurement in z-direction.
 * @param gyro_cal_x Calibrated gyroscope measurement in x-direction.
 * @param gyro_cal_y Calibrated gyroscope measurement in y-direction.
 * @param gyro_cal_z Calibrated gyroscope measurement in z-direction.
 * @param magn_cal_x Calibrated magnetometer measurement in x-direction.
 * @param magn_cal_y Calibrated magnetometer measurement in y-direction.
 * @param magn_cal_z Calibrated magnetometer measurement in z-direction.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_imu_cal_data_send(mavlink_channel_t chan, float acc_cal_x, float acc_cal_y, float acc_cal_z, float gyro_cal_x, float gyro_cal_y, float gyro_cal_z, float magn_cal_x, float magn_cal_y, float magn_cal_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IMU_CAL_DATA_LEN];
	_mav_put_float(buf, 0, acc_cal_x);
	_mav_put_float(buf, 4, acc_cal_y);
	_mav_put_float(buf, 8, acc_cal_z);
	_mav_put_float(buf, 12, gyro_cal_x);
	_mav_put_float(buf, 16, gyro_cal_y);
	_mav_put_float(buf, 20, gyro_cal_z);
	_mav_put_float(buf, 24, magn_cal_x);
	_mav_put_float(buf, 28, magn_cal_y);
	_mav_put_float(buf, 32, magn_cal_z);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, buf, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN, MAVLINK_MSG_ID_IMU_CAL_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, buf, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif
#else
	mavlink_imu_cal_data_t packet;
	packet.acc_cal_x = acc_cal_x;
	packet.acc_cal_y = acc_cal_y;
	packet.acc_cal_z = acc_cal_z;
	packet.gyro_cal_x = gyro_cal_x;
	packet.gyro_cal_y = gyro_cal_y;
	packet.gyro_cal_z = gyro_cal_z;
	packet.magn_cal_x = magn_cal_x;
	packet.magn_cal_y = magn_cal_y;
	packet.magn_cal_z = magn_cal_z;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, (const char *)&packet, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN, MAVLINK_MSG_ID_IMU_CAL_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, (const char *)&packet, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_IMU_CAL_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_imu_cal_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float acc_cal_x, float acc_cal_y, float acc_cal_z, float gyro_cal_x, float gyro_cal_y, float gyro_cal_z, float magn_cal_x, float magn_cal_y, float magn_cal_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, acc_cal_x);
	_mav_put_float(buf, 4, acc_cal_y);
	_mav_put_float(buf, 8, acc_cal_z);
	_mav_put_float(buf, 12, gyro_cal_x);
	_mav_put_float(buf, 16, gyro_cal_y);
	_mav_put_float(buf, 20, gyro_cal_z);
	_mav_put_float(buf, 24, magn_cal_x);
	_mav_put_float(buf, 28, magn_cal_y);
	_mav_put_float(buf, 32, magn_cal_z);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, buf, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN, MAVLINK_MSG_ID_IMU_CAL_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, buf, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif
#else
	mavlink_imu_cal_data_t *packet = (mavlink_imu_cal_data_t *)msgbuf;
	packet->acc_cal_x = acc_cal_x;
	packet->acc_cal_y = acc_cal_y;
	packet->acc_cal_z = acc_cal_z;
	packet->gyro_cal_x = gyro_cal_x;
	packet->gyro_cal_y = gyro_cal_y;
	packet->gyro_cal_z = gyro_cal_z;
	packet->magn_cal_x = magn_cal_x;
	packet->magn_cal_y = magn_cal_y;
	packet->magn_cal_z = magn_cal_z;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, (const char *)packet, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN, MAVLINK_MSG_ID_IMU_CAL_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CAL_DATA, (const char *)packet, MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE IMU_CAL_DATA UNPACKING


/**
 * @brief Get field acc_cal_x from imu_cal_data message
 *
 * @return Calibrated acceleration measurement in x-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_acc_cal_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field acc_cal_y from imu_cal_data message
 *
 * @return Calibrated acceleration measurement in y-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_acc_cal_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field acc_cal_z from imu_cal_data message
 *
 * @return Calibrated acceleration measurement in z-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_acc_cal_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field gyro_cal_x from imu_cal_data message
 *
 * @return Calibrated gyroscope measurement in x-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_gyro_cal_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field gyro_cal_y from imu_cal_data message
 *
 * @return Calibrated gyroscope measurement in y-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_gyro_cal_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field gyro_cal_z from imu_cal_data message
 *
 * @return Calibrated gyroscope measurement in z-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_gyro_cal_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field magn_cal_x from imu_cal_data message
 *
 * @return Calibrated magnetometer measurement in x-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_magn_cal_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field magn_cal_y from imu_cal_data message
 *
 * @return Calibrated magnetometer measurement in y-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_magn_cal_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field magn_cal_z from imu_cal_data message
 *
 * @return Calibrated magnetometer measurement in z-direction.
 */
static inline float mavlink_msg_imu_cal_data_get_magn_cal_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a imu_cal_data message into a struct
 *
 * @param msg The message to decode
 * @param imu_cal_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_imu_cal_data_decode(const mavlink_message_t* msg, mavlink_imu_cal_data_t* imu_cal_data)
{
#if MAVLINK_NEED_BYTE_SWAP
	imu_cal_data->acc_cal_x = mavlink_msg_imu_cal_data_get_acc_cal_x(msg);
	imu_cal_data->acc_cal_y = mavlink_msg_imu_cal_data_get_acc_cal_y(msg);
	imu_cal_data->acc_cal_z = mavlink_msg_imu_cal_data_get_acc_cal_z(msg);
	imu_cal_data->gyro_cal_x = mavlink_msg_imu_cal_data_get_gyro_cal_x(msg);
	imu_cal_data->gyro_cal_y = mavlink_msg_imu_cal_data_get_gyro_cal_y(msg);
	imu_cal_data->gyro_cal_z = mavlink_msg_imu_cal_data_get_gyro_cal_z(msg);
	imu_cal_data->magn_cal_x = mavlink_msg_imu_cal_data_get_magn_cal_x(msg);
	imu_cal_data->magn_cal_y = mavlink_msg_imu_cal_data_get_magn_cal_y(msg);
	imu_cal_data->magn_cal_z = mavlink_msg_imu_cal_data_get_magn_cal_z(msg);
#else
	memcpy(imu_cal_data, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_IMU_CAL_DATA_LEN);
#endif
}

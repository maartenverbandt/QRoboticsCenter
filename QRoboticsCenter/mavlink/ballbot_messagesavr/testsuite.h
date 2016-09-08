/** @file
 *	@brief MAVLink comm protocol testsuite generated from ballbot_messagesavr.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef BALLBOT_MESSAGESAVR_TESTSUITE_H
#define BALLBOT_MESSAGESAVR_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_microos_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ballbot_messagesavr(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_microos_messages(system_id, component_id, last_msg);
	mavlink_test_ballbot_messagesavr(system_id, component_id, last_msg);
}
#endif

#include "../microos_messages/testsuite.h"


static void mavlink_test_motor_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_motor_state_t packet_in = {
		963497464,
	}963497672,
	}963497880,
	}963498088,
	}963498296,
	}18275,
	}18379,
	}18483,
	};
	mavlink_motor_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.t = packet_in.t;
        	packet1.X = packet_in.X;
        	packet1.V = packet_in.V;
        	packet1.A = packet_in.A;
        	packet1.r = packet_in.r;
        	packet1.I = packet_in.I;
        	packet1.VFF = packet_in.VFF;
        	packet1.VFB = packet_in.VFB;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_state_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_motor_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_state_pack(system_id, component_id, &msg , packet1.t , packet1.I , packet1.VFF , packet1.VFB , packet1.X , packet1.V , packet1.A , packet1.r );
	mavlink_msg_motor_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.t , packet1.I , packet1.VFF , packet1.VFB , packet1.X , packet1.V , packet1.A , packet1.r );
	mavlink_msg_motor_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_motor_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_state_send(MAVLINK_COMM_1 , packet1.t , packet1.I , packet1.VFF , packet1.VFB , packet1.X , packet1.V , packet1.A , packet1.r );
	mavlink_msg_motor_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_motor_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_motor_control_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}129.0,
	}157.0,
	}185.0,
	}213.0,
	}241.0,
	}113,
	};
	mavlink_motor_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.var1 = packet_in.var1;
        	packet1.var2 = packet_in.var2;
        	packet1.var3 = packet_in.var3;
        	packet1.var4 = packet_in.var4;
        	packet1.var5 = packet_in.var5;
        	packet1.var6 = packet_in.var6;
        	packet1.var7 = packet_in.var7;
        	packet1.var8 = packet_in.var8;
        	packet1.var9 = packet_in.var9;
        	packet1.mode = packet_in.mode;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_motor_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_control_pack(system_id, component_id, &msg , packet1.mode , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 , packet1.var5 , packet1.var6 , packet1.var7 , packet1.var8 , packet1.var9 );
	mavlink_msg_motor_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 , packet1.var5 , packet1.var6 , packet1.var7 , packet1.var8 , packet1.var9 );
	mavlink_msg_motor_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_motor_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_control_send(MAVLINK_COMM_1 , packet1.mode , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 , packet1.var5 , packet1.var6 , packet1.var7 , packet1.var8 , packet1.var9 );
	mavlink_msg_motor_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_motor_reference(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_motor_reference_t packet_in = {
		963497464,
	}17443,
	}151,
	};
	mavlink_motor_reference_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.ref = packet_in.ref;
        	packet1.dt = packet_in.dt;
        	packet1.mode = packet_in.mode;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_reference_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_motor_reference_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_reference_pack(system_id, component_id, &msg , packet1.mode , packet1.ref , packet1.dt );
	mavlink_msg_motor_reference_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_reference_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.ref , packet1.dt );
	mavlink_msg_motor_reference_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_motor_reference_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_reference_send(MAVLINK_COMM_1 , packet1.mode , packet1.ref , packet1.dt );
	mavlink_msg_motor_reference_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_imu_raw_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_imu_raw_data_t packet_in = {
		17235,
	}17339,
	}17443,
	}17547,
	}17651,
	}17755,
	}17859,
	}17963,
	}18067,
	};
	mavlink_imu_raw_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.acc_raw_x = packet_in.acc_raw_x;
        	packet1.acc_raw_y = packet_in.acc_raw_y;
        	packet1.acc_raw_z = packet_in.acc_raw_z;
        	packet1.gyro_raw_x = packet_in.gyro_raw_x;
        	packet1.gyro_raw_y = packet_in.gyro_raw_y;
        	packet1.gyro_raw_z = packet_in.gyro_raw_z;
        	packet1.magn_raw_x = packet_in.magn_raw_x;
        	packet1.magn_raw_y = packet_in.magn_raw_y;
        	packet1.magn_raw_z = packet_in.magn_raw_z;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_raw_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_imu_raw_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_raw_data_pack(system_id, component_id, &msg , packet1.acc_raw_x , packet1.acc_raw_y , packet1.acc_raw_z , packet1.gyro_raw_x , packet1.gyro_raw_y , packet1.gyro_raw_z , packet1.magn_raw_x , packet1.magn_raw_y , packet1.magn_raw_z );
	mavlink_msg_imu_raw_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_raw_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.acc_raw_x , packet1.acc_raw_y , packet1.acc_raw_z , packet1.gyro_raw_x , packet1.gyro_raw_y , packet1.gyro_raw_z , packet1.magn_raw_x , packet1.magn_raw_y , packet1.magn_raw_z );
	mavlink_msg_imu_raw_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_imu_raw_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_raw_data_send(MAVLINK_COMM_1 , packet1.acc_raw_x , packet1.acc_raw_y , packet1.acc_raw_z , packet1.gyro_raw_x , packet1.gyro_raw_y , packet1.gyro_raw_z , packet1.magn_raw_x , packet1.magn_raw_y , packet1.magn_raw_z );
	mavlink_msg_imu_raw_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_imu_cal_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_imu_cal_data_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}129.0,
	}157.0,
	}185.0,
	}213.0,
	}241.0,
	};
	mavlink_imu_cal_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.acc_cal_x = packet_in.acc_cal_x;
        	packet1.acc_cal_y = packet_in.acc_cal_y;
        	packet1.acc_cal_z = packet_in.acc_cal_z;
        	packet1.gyro_cal_x = packet_in.gyro_cal_x;
        	packet1.gyro_cal_y = packet_in.gyro_cal_y;
        	packet1.gyro_cal_z = packet_in.gyro_cal_z;
        	packet1.magn_cal_x = packet_in.magn_cal_x;
        	packet1.magn_cal_y = packet_in.magn_cal_y;
        	packet1.magn_cal_z = packet_in.magn_cal_z;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_imu_cal_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_data_pack(system_id, component_id, &msg , packet1.acc_cal_x , packet1.acc_cal_y , packet1.acc_cal_z , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.magn_cal_x , packet1.magn_cal_y , packet1.magn_cal_z );
	mavlink_msg_imu_cal_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.acc_cal_x , packet1.acc_cal_y , packet1.acc_cal_z , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.magn_cal_x , packet1.magn_cal_y , packet1.magn_cal_z );
	mavlink_msg_imu_cal_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_imu_cal_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_data_send(MAVLINK_COMM_1 , packet1.acc_cal_x , packet1.acc_cal_y , packet1.acc_cal_z , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.magn_cal_x , packet1.magn_cal_y , packet1.magn_cal_z );
	mavlink_msg_imu_cal_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_imu_cal_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_imu_cal_param_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}17859,
	}17963,
	}18067,
	}187,
	};
	mavlink_imu_cal_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.scale_x = packet_in.scale_x;
        	packet1.scale_y = packet_in.scale_y;
        	packet1.scale_z = packet_in.scale_z;
        	packet1.offs_x = packet_in.offs_x;
        	packet1.offs_y = packet_in.offs_y;
        	packet1.offs_z = packet_in.offs_z;
        	packet1.mode = packet_in.mode;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_param_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_imu_cal_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_param_pack(system_id, component_id, &msg , packet1.mode , packet1.offs_x , packet1.offs_y , packet1.offs_z , packet1.scale_x , packet1.scale_y , packet1.scale_z );
	mavlink_msg_imu_cal_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.offs_x , packet1.offs_y , packet1.offs_z , packet1.scale_x , packet1.scale_y , packet1.scale_z );
	mavlink_msg_imu_cal_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_imu_cal_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_imu_cal_param_send(MAVLINK_COMM_1 , packet1.mode , packet1.offs_x , packet1.offs_y , packet1.offs_z , packet1.scale_x , packet1.scale_y , packet1.scale_z );
	mavlink_msg_imu_cal_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ahrs_angle(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ahrs_angle_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}129.0,
	}157.0,
	};
	mavlink_ahrs_angle_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        	packet1.Droll = packet_in.Droll;
        	packet1.Dpitch = packet_in.Dpitch;
        	packet1.Dyaw = packet_in.Dyaw;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_angle_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ahrs_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_angle_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.Droll , packet1.Dpitch , packet1.Dyaw );
	mavlink_msg_ahrs_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_angle_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.Droll , packet1.Dpitch , packet1.Dyaw );
	mavlink_msg_ahrs_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ahrs_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_angle_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw , packet1.Droll , packet1.Dpitch , packet1.Dyaw );
	mavlink_msg_ahrs_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ballbot_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ballbot_state_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}129.0,
	}157.0,
	}185.0,
	}213.0,
	}241.0,
	}269.0,
	};
	mavlink_ballbot_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.X_est = packet_in.X_est;
        	packet1.Y_est = packet_in.Y_est;
        	packet1.dX_est = packet_in.dX_est;
        	packet1.dY_est = packet_in.dY_est;
        	packet1.roll_est = packet_in.roll_est;
        	packet1.pitch_est = packet_in.pitch_est;
        	packet1.yaw_est = packet_in.yaw_est;
        	packet1.droll_est = packet_in.droll_est;
        	packet1.dpitch_est = packet_in.dpitch_est;
        	packet1.dyaw_est = packet_in.dyaw_est;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_state_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ballbot_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_state_pack(system_id, component_id, &msg , packet1.X_est , packet1.Y_est , packet1.dX_est , packet1.dY_est , packet1.roll_est , packet1.pitch_est , packet1.yaw_est , packet1.droll_est , packet1.dpitch_est , packet1.dyaw_est );
	mavlink_msg_ballbot_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.X_est , packet1.Y_est , packet1.dX_est , packet1.dY_est , packet1.roll_est , packet1.pitch_est , packet1.yaw_est , packet1.droll_est , packet1.dpitch_est , packet1.dyaw_est );
	mavlink_msg_ballbot_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ballbot_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_state_send(MAVLINK_COMM_1 , packet1.X_est , packet1.Y_est , packet1.dX_est , packet1.dY_est , packet1.roll_est , packet1.pitch_est , packet1.yaw_est , packet1.droll_est , packet1.dpitch_est , packet1.dyaw_est );
	mavlink_msg_ballbot_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ballbot_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ballbot_control_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}129.0,
	}157.0,
	}185.0,
	}213.0,
	}241.0,
	}113,
	}180,
	};
	mavlink_ballbot_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.var1_1 = packet_in.var1_1;
        	packet1.var1_2 = packet_in.var1_2;
        	packet1.var1_3 = packet_in.var1_3;
        	packet1.var2_1 = packet_in.var2_1;
        	packet1.var2_2 = packet_in.var2_2;
        	packet1.var2_3 = packet_in.var2_3;
        	packet1.var3_1 = packet_in.var3_1;
        	packet1.var3_2 = packet_in.var3_2;
        	packet1.var3_3 = packet_in.var3_3;
        	packet1.control_mode = packet_in.control_mode;
        	packet1.control_law = packet_in.control_law;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ballbot_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_control_pack(system_id, component_id, &msg , packet1.control_mode , packet1.control_law , packet1.var1_1 , packet1.var1_2 , packet1.var1_3 , packet1.var2_1 , packet1.var2_2 , packet1.var2_3 , packet1.var3_1 , packet1.var3_2 , packet1.var3_3 );
	mavlink_msg_ballbot_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.control_mode , packet1.control_law , packet1.var1_1 , packet1.var1_2 , packet1.var1_3 , packet1.var2_1 , packet1.var2_2 , packet1.var2_3 , packet1.var3_1 , packet1.var3_2 , packet1.var3_3 );
	mavlink_msg_ballbot_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ballbot_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_control_send(MAVLINK_COMM_1 , packet1.control_mode , packet1.control_law , packet1.var1_1 , packet1.var1_2 , packet1.var1_3 , packet1.var2_1 , packet1.var2_2 , packet1.var2_3 , packet1.var3_1 , packet1.var3_2 , packet1.var3_3 );
	mavlink_msg_ballbot_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ballbot_reference(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ballbot_reference_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}963498088,
	}53,
	};
	mavlink_ballbot_reference_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.pos_x = packet_in.pos_x;
        	packet1.pos_y = packet_in.pos_y;
        	packet1.yaw = packet_in.yaw;
        	packet1.dt = packet_in.dt;
        	packet1.mode = packet_in.mode;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_reference_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ballbot_reference_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_reference_pack(system_id, component_id, &msg , packet1.pos_x , packet1.pos_y , packet1.yaw , packet1.dt , packet1.mode );
	mavlink_msg_ballbot_reference_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_reference_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pos_x , packet1.pos_y , packet1.yaw , packet1.dt , packet1.mode );
	mavlink_msg_ballbot_reference_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ballbot_reference_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_reference_send(MAVLINK_COMM_1 , packet1.pos_x , packet1.pos_y , packet1.yaw , packet1.dt , packet1.mode );
	mavlink_msg_ballbot_reference_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ballbot_excitation(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ballbot_excitation_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}18067,
	}187,
	};
	mavlink_ballbot_excitation_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.var1 = packet_in.var1;
        	packet1.var2 = packet_in.var2;
        	packet1.var3 = packet_in.var3;
        	packet1.var4 = packet_in.var4;
        	packet1.channels = packet_in.channels;
        	packet1.type = packet_in.type;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_excitation_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ballbot_excitation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_excitation_pack(system_id, component_id, &msg , packet1.type , packet1.channels , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 );
	mavlink_msg_ballbot_excitation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_excitation_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.channels , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 );
	mavlink_msg_ballbot_excitation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ballbot_excitation_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_excitation_send(MAVLINK_COMM_1 , packet1.type , packet1.channels , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 );
	mavlink_msg_ballbot_excitation_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_motor_log(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_motor_log_t packet_in = {
		963497464,
	}963497672,
	}17651,
	}17755,
	};
	mavlink_motor_log_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.position = packet_in.position;
        	packet1.voltage = packet_in.voltage;
        	packet1.current = packet_in.current;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_log_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_motor_log_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_log_pack(system_id, component_id, &msg , packet1.time , packet1.voltage , packet1.current , packet1.position );
	mavlink_msg_motor_log_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_log_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.voltage , packet1.current , packet1.position );
	mavlink_msg_motor_log_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_motor_log_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_log_send(MAVLINK_COMM_1 , packet1.time , packet1.voltage , packet1.current , packet1.position );
	mavlink_msg_motor_log_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ballbot_log(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ballbot_log_t packet_in = {
		963497464,
	}45.0,
	}73.0,
	}101.0,
	}129.0,
	}157.0,
	}185.0,
	}963498920,
	}963499128,
	}963499336,
	}19315,
	}19419,
	}19523,
	}19627,
	}19731,
	}19835,
	};
	mavlink_ballbot_log_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        	packet1.rollcmd = packet_in.rollcmd;
        	packet1.pitchcmd = packet_in.pitchcmd;
        	packet1.yawcmd = packet_in.yawcmd;
        	packet1.Encmot0 = packet_in.Encmot0;
        	packet1.Encmot1 = packet_in.Encmot1;
        	packet1.Encmot2 = packet_in.Encmot2;
        	packet1.Vmot0 = packet_in.Vmot0;
        	packet1.Vmot1 = packet_in.Vmot1;
        	packet1.Vmot2 = packet_in.Vmot2;
        	packet1.Imot0 = packet_in.Imot0;
        	packet1.Imot1 = packet_in.Imot1;
        	packet1.Imot2 = packet_in.Imot2;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_log_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ballbot_log_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_log_pack(system_id, component_id, &msg , packet1.time , packet1.Vmot0 , packet1.Vmot1 , packet1.Vmot2 , packet1.Imot0 , packet1.Imot1 , packet1.Imot2 , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollcmd , packet1.pitchcmd , packet1.yawcmd , packet1.Encmot0 , packet1.Encmot1 , packet1.Encmot2 );
	mavlink_msg_ballbot_log_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_log_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.Vmot0 , packet1.Vmot1 , packet1.Vmot2 , packet1.Imot0 , packet1.Imot1 , packet1.Imot2 , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollcmd , packet1.pitchcmd , packet1.yawcmd , packet1.Encmot0 , packet1.Encmot1 , packet1.Encmot2 );
	mavlink_msg_ballbot_log_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ballbot_log_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ballbot_log_send(MAVLINK_COMM_1 , packet1.time , packet1.Vmot0 , packet1.Vmot1 , packet1.Vmot2 , packet1.Imot0 , packet1.Imot1 , packet1.Imot2 , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollcmd , packet1.pitchcmd , packet1.yawcmd , packet1.Encmot0 , packet1.Encmot1 , packet1.Encmot2 );
	mavlink_msg_ballbot_log_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_channel_io(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_channel_io_t packet_in = {
		963497464,
	}{ 45.0, 46.0, 47.0, 48.0, 49.0, 50.0 },
	}{ 213.0, 214.0, 215.0, 216.0, 217.0, 218.0 },
	}161,
	};
	mavlink_channel_io_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.sync = packet_in.sync;
        
        	mav_array_memcpy(packet1.input, packet_in.input, sizeof(float)*6);
        	mav_array_memcpy(packet1.output, packet_in.output, sizeof(float)*6);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_channel_io_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_pack(system_id, component_id, &msg , packet1.time , packet1.sync , packet1.input , packet1.output );
	mavlink_msg_channel_io_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.sync , packet1.input , packet1.output );
	mavlink_msg_channel_io_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_channel_io_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_send(MAVLINK_COMM_1 , packet1.time , packet1.sync , packet1.input , packet1.output );
	mavlink_msg_channel_io_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_channel_io_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_channel_io_info_t packet_in = {
		5,
	}72,
	}139,
	}206,
	}17,
	};
	mavlink_channel_io_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.type = packet_in.type;
        	packet1.configuration = packet_in.configuration;
        	packet1.excitation = packet_in.excitation;
        	packet1.version = packet_in.version;
        	packet1.subversion = packet_in.subversion;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_channel_io_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_pack(system_id, component_id, &msg , packet1.type , packet1.configuration , packet1.excitation , packet1.version , packet1.subversion );
	mavlink_msg_channel_io_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.configuration , packet1.excitation , packet1.version , packet1.subversion );
	mavlink_msg_channel_io_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_channel_io_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_channel_io_info_send(MAVLINK_COMM_1 , packet1.type , packet1.configuration , packet1.excitation , packet1.version , packet1.subversion );
	mavlink_msg_channel_io_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ballbot_messagesavr(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_motor_state(system_id, component_id, last_msg);
	mavlink_test_motor_control(system_id, component_id, last_msg);
	mavlink_test_motor_reference(system_id, component_id, last_msg);
	mavlink_test_imu_raw_data(system_id, component_id, last_msg);
	mavlink_test_imu_cal_data(system_id, component_id, last_msg);
	mavlink_test_imu_cal_param(system_id, component_id, last_msg);
	mavlink_test_ahrs_angle(system_id, component_id, last_msg);
	mavlink_test_ballbot_state(system_id, component_id, last_msg);
	mavlink_test_ballbot_control(system_id, component_id, last_msg);
	mavlink_test_ballbot_reference(system_id, component_id, last_msg);
	mavlink_test_ballbot_excitation(system_id, component_id, last_msg);
	mavlink_test_motor_log(system_id, component_id, last_msg);
	mavlink_test_ballbot_log(system_id, component_id, last_msg);
	mavlink_test_channel_io(system_id, component_id, last_msg);
	mavlink_test_channel_io_info(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BALLBOT_MESSAGESAVR_TESTSUITE_H

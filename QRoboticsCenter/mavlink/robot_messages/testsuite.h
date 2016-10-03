/** @file
 *	@brief MAVLink comm protocol testsuite generated from robot_messages.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef ROBOT_MESSAGES_TESTSUITE_H
#define ROBOT_MESSAGES_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_microos_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_robot_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_microos_messages(system_id, component_id, last_msg);
	mavlink_test_robot_messages(system_id, component_id, last_msg);
}
#endif

#include "../microos_messages/testsuite.h"


static void mavlink_test_pose(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_pose_t packet_in = {
		963497464,
	}963497672,
	}963497880,
	}17859,
	}17963,
	}18067,
	};
	mavlink_pose_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.x = packet_in.x;
        	packet1.y = packet_in.y;
        	packet1.z = packet_in.z;
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_pack(system_id, component_id, &msg , packet1.x , packet1.y , packet1.z , packet1.roll , packet1.pitch , packet1.yaw );
	mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y , packet1.z , packet1.roll , packet1.pitch , packet1.yaw );
	mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_pose_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pose_send(MAVLINK_COMM_1 , packet1.x , packet1.y , packet1.z , packet1.roll , packet1.pitch , packet1.yaw );
	mavlink_msg_pose_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_attitude(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_attitude_t packet_in = {
		963497464,
	}17443,
	}17547,
	}17651,
	}17755,
	}17859,
	}17963,
	};
	mavlink_attitude_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        	packet1.roll_actuation = packet_in.roll_actuation;
        	packet1.pitch_actuation = packet_in.pitch_actuation;
        	packet1.yaw_actuation = packet_in.yaw_actuation;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_pack(system_id, component_id, &msg , packet1.time , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_actuation , packet1.pitch_actuation , packet1.yaw_actuation );
	mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_actuation , packet1.pitch_actuation , packet1.yaw_actuation );
	mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_attitude_send(MAVLINK_COMM_1 , packet1.time , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_actuation , packet1.pitch_actuation , packet1.yaw_actuation );
	mavlink_msg_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_velocity(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_velocity_t packet_in = {
		963497464,
	}17443,
	}17547,
	}17651,
	}17755,
	}17859,
	}17963,
	};
	mavlink_velocity_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.vx = packet_in.vx;
        	packet1.vy = packet_in.vy;
        	packet1.vz = packet_in.vz;
        	packet1.vx_actuation = packet_in.vx_actuation;
        	packet1.vy_actuation = packet_in.vy_actuation;
        	packet1.vz_actuation = packet_in.vz_actuation;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_pack(system_id, component_id, &msg , packet1.time , packet1.vx , packet1.vy , packet1.vz , packet1.vx_actuation , packet1.vy_actuation , packet1.vz_actuation );
	mavlink_msg_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.vx , packet1.vy , packet1.vz , packet1.vx_actuation , packet1.vy_actuation , packet1.vz_actuation );
	mavlink_msg_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_velocity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_velocity_send(MAVLINK_COMM_1 , packet1.time , packet1.vx , packet1.vy , packet1.vz , packet1.vx_actuation , packet1.vy_actuation , packet1.vz_actuation );
	mavlink_msg_velocity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_position(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_position_t packet_in = {
		963497464,
	}17443,
	}17547,
	}17651,
	}17755,
	}17859,
	}17963,
	};
	mavlink_position_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time = packet_in.time;
        	packet1.x = packet_in.x;
        	packet1.y = packet_in.y;
        	packet1.z = packet_in.z;
        	packet1.x_actuation = packet_in.x_actuation;
        	packet1.y_actuation = packet_in.y_actuation;
        	packet1.z_actuation = packet_in.z_actuation;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_pack(system_id, component_id, &msg , packet1.time , packet1.x , packet1.y , packet1.z , packet1.x_actuation , packet1.y_actuation , packet1.z_actuation );
	mavlink_msg_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.x , packet1.y , packet1.z , packet1.x_actuation , packet1.y_actuation , packet1.z_actuation );
	mavlink_msg_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_position_send(MAVLINK_COMM_1 , packet1.time , packet1.x , packet1.y , packet1.z , packet1.x_actuation , packet1.y_actuation , packet1.z_actuation );
	mavlink_msg_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_radar_cloud(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_radar_cloud_t packet_in = {
		{ 963497464, 963497465, 963497466, 963497467, 963497468, 963497469 },
	}{ 963498712, 963498713, 963498714, 963498715, 963498716, 963498717 },
	};
	mavlink_radar_cloud_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        	mav_array_memcpy(packet1.x, packet_in.x, sizeof(int32_t)*6);
        	mav_array_memcpy(packet1.y, packet_in.y, sizeof(int32_t)*6);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_radar_cloud_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_pack(system_id, component_id, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_cloud_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_cloud_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_radar_cloud_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_cloud_send(MAVLINK_COMM_1 , packet1.x , packet1.y );
	mavlink_msg_radar_cloud_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_radar_line(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_radar_line_t packet_in = {
		{ 963497464, 963497465 },
	}{ 963497880, 963497881 },
	};
	mavlink_radar_line_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        	mav_array_memcpy(packet1.x, packet_in.x, sizeof(int32_t)*2);
        	mav_array_memcpy(packet1.y, packet_in.y, sizeof(int32_t)*2);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_radar_line_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_pack(system_id, component_id, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_line_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y );
	mavlink_msg_radar_line_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_radar_line_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_radar_line_send(MAVLINK_COMM_1 , packet1.x , packet1.y );
	mavlink_msg_radar_line_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_excitation(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_excitation_t packet_in = {
		17.0,
	}45.0,
	}73.0,
	}101.0,
	}18067,
	}187,
	};
	mavlink_excitation_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.var1 = packet_in.var1;
        	packet1.var2 = packet_in.var2;
        	packet1.var3 = packet_in.var3;
        	packet1.var4 = packet_in.var4;
        	packet1.channels = packet_in.channels;
        	packet1.type = packet_in.type;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_excitation_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_excitation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_excitation_pack(system_id, component_id, &msg , packet1.type , packet1.channels , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 );
	mavlink_msg_excitation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_excitation_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.channels , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 );
	mavlink_msg_excitation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_excitation_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_excitation_send(MAVLINK_COMM_1 , packet1.type , packet1.channels , packet1.var1 , packet1.var2 , packet1.var3 , packet1.var4 );
	mavlink_msg_excitation_decode(last_msg, &packet2);
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

static void mavlink_test_robot_messages(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_pose(system_id, component_id, last_msg);
	mavlink_test_attitude(system_id, component_id, last_msg);
	mavlink_test_velocity(system_id, component_id, last_msg);
	mavlink_test_position(system_id, component_id, last_msg);
	mavlink_test_radar_cloud(system_id, component_id, last_msg);
	mavlink_test_radar_line(system_id, component_id, last_msg);
	mavlink_test_excitation(system_id, component_id, last_msg);
	mavlink_test_channel_io(system_id, component_id, last_msg);
	mavlink_test_channel_io_info(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ROBOT_MESSAGES_TESTSUITE_H

import socket
from struct import *

UDP_IP = "127.0.0.1"
UDP_PORT = 5005

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

while True:
	data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
	print "received message:", len(data)
	msg = unpack('Ihhhhhhhhh',data)
	time = msg[0]
	roll = msg[1]
	pitch = msg[2]
	yaw = msg[3]
	roll_cmd = msg[4]
	pitch_cmd = msg[5]
 	yaw_cmd = msg[6]
	roll_act = msg[7]
	pitch_act = msg[8]
	yaw_act = msg[9]
	print time, ", ", roll, ", ", pitch, ", ", yaw

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
	msg = unpack('iiihhh',data)
	pos = msg[0:2]
	ori = msg[3:5]
	print ori

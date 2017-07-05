import socket
from struct import *

UDP_IP = "127.0.0.1"
UDP_PORT = 28000

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

while True:
	data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
	print "received message:", len(data)
	msg = unpack('Iffffffffiiii',data)
	time = msg[0]
	floats = msg[1:9]
	ints = msg[9:]
	print time, ", ", floats[0], ", ", floats[1], ", ", ints[0], ", ", ints[1]

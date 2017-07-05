import socket
import time as tm
from struct import *

UDP_IP = "127.0.0.1"
UDP_PORT = 27500

time = 0
floats = [0]*8
ints = [0]*4

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
while True:
	time = time + 1
	floats[6] = time
	ints[2] = time
	ints[3] = -time
	
	msg = pack('Iffffffffiiii',time,floats[0],floats[1],floats[2],floats[3],floats[4],floats[5],floats[6],floats[7],ints[0],ints[1],ints[2],ints[3]);
	sock.sendto(msg, (UDP_IP, UDP_PORT))
	print "sent message:", len(msg)
	
	tm.sleep(0.025)

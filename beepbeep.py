import winsound
import time
freq = 440

def beepbeep(duration, pause):
	i = 1
	while i:
		winsound.Beep(8*freq, duration)
		time.sleep(pause)
		winsound.Beep(8*freq, duration)
		i=0
		

def myeggs():
	agora = time.time();
	timer = agora+10
	while(1):
		if (not int(agora-timer)) and (buzzCounter<=10):
			print(1)
			agora = time.time()
			timer= agora+5
			buzzCounter = buzzCounter+1
			
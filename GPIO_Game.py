import RPi.GPIO as GPIO
import time
from random import randrange

leds = [32, 36, 38, 40]
buttons = [7, 11, 13, 15]
buzzer = 37

def init ():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BOARD)
    for i in leds:
        GPIO.setup (i, GPIO.OUT,initial=GPIO.LOW)
    for i in buttons:
        GPIO.setup (i, GPIO.IN)
    if (buzzer != 0):
        GPIO.setup (buzzer, GPIO.OUT)
    pass

def make_sound (hezt, duration):
    
    p = GPIO.PWM (buzzer, hezt)
    p.start (100)
    p.ChangeDutyCycle (90)
    p.ChangeFrequency (hezt)
    time.sleep (duration)
    p.stop ()
    pass

def light (which, state): # cause which to blink
    val = GPIO.LOW
    if state == True:
        val = GPIO.HIGH
    GPIO.output (leds[which], val)
    pass

def seq_light (L, duration):
    prev = -1
    for i in L:
        if (prev != -1):
            light (prev, False)
        light (i, True)
        prev = i
        time.sleep (duration)
    if (prev != -1):
        light (prev, False)

def randSeq (L):
    ans = []
    prev = -1
    num = -1
    for i in range (L):
        while prev == num:
            num = randrange (0, 4)
        ans.append (num)
        prev = num

    return ans

def waitInput ():
    
    while True:
        cnt = 0
        for i in buttons:
            val = GPIO.input (i)
            if (val == 1):
                return cnt
            cnt += 1
    pass

def check_loop (L):
    
    for i in L:
        button = waitInput ()
        light (button, 1)
        time.sleep (0.2)
        light (button, 0)
        
        if button != i:
            return False
    return True
    
    
def firework ():
    state = [0, 1]
    for i in range (40):
        light (randrange (0,4), randrange (0,2))
        time.sleep (0.01)
    for i in range (len (leds)):
        light (i, True)
    time.sleep (0.5)
    for i in range (len (leds)):
        light (i, False)
    time.sleep (1)
    pass
def game ():   
    init ()
    round = 0
    firework ()
    make_sound (560, 0.7)
    
    try:
        while 1:
            round += 1
            print ('ROUND %d' % round)
            
            seq = randSeq (round)
            seq_light (seq, 1)
            result = check_loop (seq)
            
            if (result == False):
                print ('FAILED')
                make_sound (100, 0.7)
                break
            else:
                print ('Pass: GOOD JOB')
                make_sound (560, 0.7)
                time.sleep (0.5)
                
    except KeyboardInterrupt:
        pass
    finally:
        GPIO.cleanup ()
    print ('Game OVER')
        
def main ():
    
    init ()
    try:
        game ()
    except KeyboardInterrupt:
        pass
    GPIO.cleanup ()
    
if __name__ == '__main__':
    main ()
    

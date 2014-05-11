# Frank Zhao 2014
# frankzhao.net

import RPi.GPIO as GPIO
import time

# Set pin numbering convention to BCM
GPIO.setmode(GPIO.BCM)

initialized = False;

def initialize():
    GPIO.setup(11, GPIO.OUT) #a
    GPIO.setup(22, GPIO.OUT) #b
    GPIO.setup(23, GPIO.OUT) #c
    GPIO.setup( 7, GPIO.OUT) #d
    GPIO.setup( 8, GPIO.OUT) #e
    GPIO.setup( 9, GPIO.OUT) #f
    GPIO.setup(10, GPIO.OUT) #g
    GPIO.setup(24, GPIO.OUT) #p, decimal point
    initialized = True;

# setvalue([segments], boolean)        
def setvalue(list, value):
    for segment in list:
        if segment == 'a':
            GPIO.output(11, value) #a
        elif segment == 'b':
            GPIO.output(22, value) #b
        elif segment == 'c':
            GPIO.output(23, value) #c
        elif segment == 'd':
            GPIO.output( 7, value) #d
        elif segment == 'e':
            GPIO.output( 8, value) #e
        elif segment == 'f':
            GPIO.output( 9, value) #f
        elif segment == 'g':
            GPIO.output(10, value) #g
        elif segment == 'p':
            GPIO.output(24, value) #p, decimal point
        else:
            print "Segment not recognised"
            break

def turnon(segments):
    if not initialized:
        initialize()
    setvalue(segments, True)

def turnoff(segments):
    if not initialized:
        initialize()
    setvalue(segments, False)
    
def alloff():
    turnoff("abcdefgp")

def allon():
    turnon("abcdefgp")

def display(n):
    alloff()
    if n == 1:
        turnon("bc")
    elif n == 2:
        turnon("abdeg")
    elif n == 3:
        turnon("abcdg")
    elif n == 4:
        turnon("bcfg")
    elif n == 5:
        turnon("afgcd")
    elif n == 6:
        turnon("afedcg")
    elif n == 7:
        turnon("fabc")
    elif n == 8:
        turnon("abcdefg")
    elif n == 9:
        turnon("abcdgf")
    elif n == 0:
        turnon("abcdef")
    elif n == '.':
        turnon("p")
    elif n == "A":
        turnon("abcefg")
    elif n == "B":
        turnon("fedcg")
    elif n == "C":
        turnon("afed")
    elif n == "D":
        turnon("bcdeg")
    elif n == "E":
        turnon("afedg")
    elif n == "F":
        turnon("afeg")

def cycle():
    n = 0
    while n < 10:
        display(n)
        time.sleep(0.8)
        n += 1
    alloff()

# blink(value, interval)
def blink(value, interval):
    while True:
        display(value)
        time.sleep(interval)
        alloff()
        time.sleep(interval)
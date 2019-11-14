import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)
servopin=11
GPIO.setup(servopin,GPIO.OUT)
pwm=GPIO.PWM(servopin,50)
pwm.start(7.3)
angle=-180
angle=angle+180
for i in range(10):
    time.sleep(0.5)
    m1=0
    M1=180
    m2=20
    M2=90
    desired_angle=((angle-m1)*(float(M2-m2)/float(M1-m1))+m2)
    dc=(desired_angle/18.0)+2.3
    print(desired_angle)
    print(angle-m1)
    print(float(M2-m2)/float(M1-m1))
    print(dc)
    print("===========")
angle=180
for i in range(10):
    time.sleep(0.5)
    dc=3
    m1=0
    M1=180
    m2=90
    M2=160
    desired_angle=((angle-m1)*(float(M2-m2)/float(M1-m1))+m2)
    dc=(desired_angle/18.0)+2.3
    print(desired_angle)
    print(angle-m1)
    print(float(M2-m2)/float(M1-m1))
    print(dc)
    print("===========")


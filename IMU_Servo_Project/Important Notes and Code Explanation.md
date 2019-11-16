This is a Simple Raspberry Pi Project

  Link to Video Demo : https://www.youtube.com/watch?v=BOeqh8H5Dj0&feature=youtu.be

  The aim is to control the rotation of the servo motor according to the Position of the IMU Sensor
    
    first I had to to get the values of rotation of the IMU Sensor and because the Readig are somehow noisy 
    and not smooth , the need arrised to use kalman filter to get smoother more accurate results , 
    in this part i used Kalman-Filter-Python-for-mpu6050-master Library.
    
  Credits to : rocheparadox  
  Library link : https://github.com/rocheparadox/Kalman-Filter-Python-for-mpu6050
    
  The core logic :
    
    first i had to caliberate the servo motor in order to be able to fully control it

  Angles Mapping and Servo Calliberation :

    I assumed this relation: PWM Value =AngleValue/18 +2.3  , it is not random but based on another servo calliberation , but each
    servo differs from the other , after some trial i found that the Angle values of range from 20 to 160 correspond to actual
    0-->180 rotation of the servo , so i made this mathematical mapping to control the servo
    
    angles range from 20 to 160 correspond to actual angles from 0 to 180
    to convert  angle 20 --> dc=3.4  , angle 160 ---> dc= 11.2 , angle 90 ---> 7.3 # note : it is a non linear transformation
    because we add 2.3 to each dc value ( it varies from a servo to another servo)
    Kalman filter Code gives us angle from -180 to 180 
    we want angles from -90 to 0 to take values from 20 to 90  ,we will add 90 to negative angles 
    we will work on angles form -90 to 90 for easier Rotation of the IMU 
    range1=[-90,0],range2=[20,90] , m1=min1,m2=min2,M1=max1,M2=max2  for example transform -90
    DesiredAngle= (Current Angle-m1) *((M2-m2)/(M1-m1))+ m2
    in our case Desired Angle=  -90 -(-90) *(70/90)+ 20 = 90*7/18+20 = 20 which is in the start of (20,90)
    range1=[0,90], range2=[90,160]
    we want angles from  0  to 90 to take values from 90 to 160 for example transform 90
    here we do the same method : Desired = 90-0 *(7/9)+90 = 90*7/18+90 = 160 which is in the end of (90, 160)
    
  Finalizing:
    
    All the heavylifting is over ,  I now just need to check if the angle reading is -ve or =ve then apply my mapping and send the PWM
    signal to the servo to rotate according to the desired angle , we run this logic continously in a while loop .

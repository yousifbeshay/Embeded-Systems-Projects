#include <Arduino.h>
int YellowLed =11;
int GreenLed =9;
int BlueLed =8;
int RedLed =10;
int trig=5;
int echo=3;
int i=0;
double distanceArr[10];
double duration;
double distance;
int YellowLedState;
int GreenLedState;
int BlueLedState;
int RedLedState;
void setup() {
  Serial.begin(9600);
  pinMode(YellowLed,OUTPUT);
  pinMode(GreenLed,OUTPUT);
  pinMode(BlueLed,OUTPUT);
  pinMode(RedLed,OUTPUT);
  pinMode(trig,INPUT);
  pinMode(echo,OUTPUT);
}
void loop() {
digitalWrite(trig, LOW); 
delayMicroseconds(2); 
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration=pulseIn(echo,HIGH);
distanceArr[i]= 0.034*duration/2;
distance+=distanceArr[i];
 i++;

if(i==9)
{
distance=distance/10;
i=0;
YellowLedState=digitalRead(YellowLed);
GreenLedState=digitalRead(GreenLed);
BlueLedState=digitalRead(BlueLed);
RedLedState=digitalRead(RedLedState);
if(distance>=50)
{
  digitalWrite(YellowLed,HIGH);
  digitalWrite(GreenLed,LOW);
  digitalWrite(BlueLed,LOW);
  digitalWrite(RedLed,LOW);
}
if(distance>=100)
{
  digitalWrite(YellowLed,LOW);
  digitalWrite(GreenLed,LOW);
  digitalWrite(BlueLed,HIGH);
  digitalWrite(RedLed,LOW);
}
if(distance>=150)
{
  digitalWrite(YellowLed,LOW);
  digitalWrite(GreenLed,HIGH);
  digitalWrite(BlueLed,LOW);
  digitalWrite(RedLed,LOW);
}
if(distance>=200)
{
  digitalWrite(YellowLed,LOW);
  digitalWrite(GreenLed,LOW);
  digitalWrite(BlueLed,LOW);
  digitalWrite(RedLed,HIGH);
}
Serial.print("Distance= ");
Serial.print(distance);
Serial.println("cm");
Serial.print("Yellow Led State= ");
Serial.println(YellowLedState);
Serial.print("Green Led State =");
Serial.println(GreenLedState);
Serial.print("Blue Led State =");
Serial.println(BlueLedState);
Serial.print("Red Led State =");
Serial.println(RedLedState);
}
}
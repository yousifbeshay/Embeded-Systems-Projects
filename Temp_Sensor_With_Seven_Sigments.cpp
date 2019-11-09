#include <Arduino.h>
int temp;
const double TempFactor=100*5/1024;
int Seven_Sig_Num1;
int Seven_Sig_Num2;
int Seven_Sig_Num_Mapping [10][7] = { { 1,1,1,1,1,1,0 }, // 0
                                      { 0,1,1,0,0,0,0 }, // 1
                                      { 1,1,0,1,1,0,1 }, // 2
                                      { 1,1,1,1,0,0,1 }, // 3
                                      { 0,1,1,0,0,1,1 }, // 4
                                      { 1,0,1,1,0,1,1 }, // 5
                                      { 1,0,1,1,1,1,1 }, // 6
                                      { 1,1,1,0,0,0,0 }, // 7
                                      { 1,1,1,1,1,1,1 }, // 8
                                      { 1,1,1,0,0,1,1 }};// 9
void Display_Seven_Sigment_Num1(int);
void Display_Seven_Sigment_Num2(int);
void setup() 
{
  for(int i=2 ; i<14; i++)
  {
  pinMode(i,OUTPUT);
  }
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,INPUT);
}

void loop() 
{
temp=analogRead(A2);
temp=temp*TempFactor;
Seven_Sig_Num1=temp/10;
Seven_Sig_Num2=temp%10;
Display_Seven_Sigment_Num1(Seven_Sig_Num1);
Display_Seven_Sigment_Num2(Seven_Sig_Num2);
delay(500);
}

void Display_Seven_Sigment_Num1(int num) 
{
  int pin= 2;
  for (int i=0; i < 7; i++) 
  {
   digitalWrite(pin, Seven_Sig_Num_Mapping[num][i]);
   pin++;
  }

}
void Display_Seven_Sigment_Num2(int num)
{
  int pin =9;
  for (int i=0; i < 7; i++) 
  {
    if(pin==14)
    pin=A0;
    if(pin==14)
    pin=A1;
   digitalWrite(pin, Seven_Sig_Num_Mapping[num][i]);
   pin++;
  }
}
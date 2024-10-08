/*
1) examples bolmesinden IMU_zero kodunu acib offset almag lazimdi
2) alinan deyerlerden ivme

*/

#include <Wire.h>
#include <MPU6050.h>

#define sagmaviled 4
#define sagqirmiziled 3
#define sagyashilled 2

#define solmaviled 9
#define solqirmiziled 10
#define solyashilled 11
MPU6050 sensor;

int gyrox, gyroy, gyroz;
int ivmeX, ivmeY, ivmeZ;

void setup() {
Serial.begin(9600);
Wire.begin();
sensor.initialize();

pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
pinMode(2, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

}

void loop() {
sensor.getRotation(&gyrox, &gyroy, &gyroz);
sensor.getAcceleration(&ivmeX, &ivmeY, &ivmeZ);
Serial.print("X ");
Serial.println(ivmeX);
Serial.print("Y ");
Serial.println(ivmeY);
Serial.print("Z ");
Serial.println(ivmeZ);
Serial.println("");
delay(100);

if(ivmeY < -1000 && ivmeY >= -2000){
  digitalWrite(sagmaviled, 1);
}else{
  digitalWrite(sagmaviled, 0);
}
if(ivmeY < -2000 && ivmeY >= -3000){
  digitalWrite(sagqirmiziled, 1);
}else{
  digitalWrite(sagqirmiziled, 0);
}
if(ivmeY < -3000){
  digitalWrite(sagyashilled, 1);
}else{
  digitalWrite(sagyashilled, 0);
}

if(ivmeY > 1000 && ivmeY <=2000){
  digitalWrite(solmaviled, 1);
}else{
  digitalWrite(solmaviled, 0);
}
if(ivmeY > 2000 && ivmeY <= 3000){
  digitalWrite(solqirmiziled, 1);
}else{
  digitalWrite(solqirmiziled, 0);
}
if(ivmeY > 3000){
  digitalWrite(solyashilled, 1);
}else{
  digitalWrite(solyashilled, 0);
}

}

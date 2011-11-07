#include "ubrQuadstep.h"

ubrQuadstep ubrQuadstep;
int irRear = 1;
int irValr = 0;
int irFront = 0;
int irValf = 0;
boolean forward = true;

void setup(){
  ubrQuadstep.motor_pins(3,6,9,11,4,7,10,13,2,5,8,12);
  Serial.begin(9600);
}

void loop(){
  irValr = analogRead(irRear);
  irValf = analogRead(irFront);
  if(forward && irValf > 200){
    ubrQuadstep.motor_go(100);
  }
  else if(!forward && irValr > 200){
    ubrQuadstep.motor_go(-100);
  }
  else{
    ubrQuadstep.motor_go(0);
    if(forward){
      forward = false;
      ubrQuadstep.motor_go(-100);
    }
    else{
      forward = true;
      ubrQuadstep.motor_go(100);
    }
  }
}

#include "ubrQuadstep.h"

ubrQuadstep ubrQuadstep;

void setup(){
  ubrQuadstep.motor_pins(3,6,9,11,4,7,10,13,2,5,8,12);
}

void loop(){
  ubrQuadstep.motor_go(100,100);
  //delay(500);
  
  //ubrQuadstep.motor_go(-100,100);
  //delay(500);
}

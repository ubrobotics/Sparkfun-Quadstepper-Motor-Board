/**
 * @author <a href="mailto:dbaratta@buffalo.edu">Dominic Baratta</a>
 * 2011 UB Robotics (Modifications to library)
 *
 * File originally created by:
 * Aaron Weiss, SparkFun electronics 2011	
 * beerware - do what you wish with this ish
 */

#include "WProgram.h"
#include "ubrQuadstep.h"

#define sbi(var, mask)   ((var) |= (uint8_t)(1 << mask))
#define cbi(var, mask)   ((var) &= (uint8_t)~(1 << mask))

#define STEPMIN	800

ubrQuadstep::ubrQuadstep()
{	
  pinMode(3, OUTPUT);  //PD3 {MOTOR 1}
  pinMode(6, OUTPUT);  //PD6 {MOTOR 2}
  pinMode(9, OUTPUT);  //PB1 {MOTOR 3}
  pinMode(11, OUTPUT); //PB3 {MOTOR 4}
	
  //make sure the step lines are low on startup
  cbi(PORTD, 3); //MOTOR 1
  cbi(PORTD, 6); //MOTOR 2
  cbi(PORTB, 1); //MOTOR 3
  cbi(PORTB, 3); //MOTOR 4
	
  Serial.begin(9600);
}

/******************************************************************************
 * PIN CONNECTIONS															  *
 *****************************************************************************/
void ubrQuadstep::motor_pins(int m1StepNum,
			  int m2StepNum,
			  int m3StepNum,
			  int m4StepNum,
			  int m1EnabNum,
			  int m2EnabNum,
			  int m3EnabNum,
			  int m4EnabNum,
			  int m1DrctNum,
			  int m2DrctNum,
			  int m3DrctNum,
			  int m4DrctNum){
														
	/**************************************************************************
	 * ENABLE & SETUP MOTOR 1                                                 *
	 *************************************************************************/
	 pinMode(m1EnabNum, OUTPUT);
	 pinMode(m1DrctNum, OUTPUT);
	 digitalWrite(m1EnabNum, LOW);
	 digitalWrite(m1DrctNum, HIGH);
	 _motor_enable_1 = m1EnabNum;
	 _motor_dir_1 = m1DrctNum;

	 /*************************************************************************
	 * ENABLE & SETUP MOTOR 2                                                 *
	 *************************************************************************/
	 pinMode(m2EnabNum, OUTPUT);
	 pinMode(m2DrctNum, OUTPUT);
	 digitalWrite(m2EnabNum, LOW);
	 digitalWrite(m2DrctNum, HIGH);
	 _motor_enable_2 = m2EnabNum;
	 _motor_dir_2 = m2DrctNum;
	 
	 /*************************************************************************
	 * ENABLE & SETUP MOTOR 3                                                 *
	 *************************************************************************/
	 pinMode(m3EnabNum, OUTPUT);
	 pinMode(m3DrctNum, OUTPUT);
	 digitalWrite(m3EnabNum, LOW);
	 digitalWrite(m3DrctNum, LOW);
	 _motor_enable_3 = m3EnabNum;
	 _motor_dir_3 = m3DrctNum;
	 
	 /*************************************************************************
	 * ENABLE & SETUP MOTOR 4                                                 *
	 *************************************************************************/
	 pinMode(m4EnabNum, OUTPUT);
	 pinMode(m4DrctNum, OUTPUT);
	 digitalWrite(m4EnabNum, LOW);
	 digitalWrite(m4DrctNum, LOW);
	 _motor_enable_4 = m4EnabNum;
	 _motor_dir_4 = m4DrctNum;
}

/******************************************************************************
 * MOTOR SETTINGS							      *
 *****************************************************************************/
void ubrQuadstep::motor_go(int velocity)
{	
  // This section has pretty much been re-written from what Sparkfun provided
  // It has been modified to run all 4 motors at the same time, though there
  // is no turning function planned as the stepper motors we have don't really
  // have a large range of speed settings due to their gear-boxes.

  bool forward = true;
  if (velocity < 0){
    forward = false;
  }

  // Set the direction pins based on if we should move forward or backwords
  if (forward){
    // Set the motor direction pins to drive the platform forward
    digitalWrite(_motor_dir_1, LOW);
    digitalWrite(_motor_dir_2, LOW);
    digitalWrite(_motor_dir_3, HIGH);
    digitalWrite(_motor_dir_4, HIGH);
  } else {
    // Set the motor direction pins to drive the platform backwords
    digitalWrite(_motor_dir_1, HIGH);
    digitalWrite(_motor_dir_2, HIGH);
    digitalWrite(_motor_dir_3, LOW);
    digitalWrite(_motor_dir_4, LOW);
  }

  
  if(velocity == 0){
	//Do nothing, as we want to stop
  } else {
	  // Drive the motors for 100 steps
	  for(int i = 0; i < 100; i++){
		//low to high transition moves one step
		sbi(PORTD, 3); //MOTOR 1
		sbi(PORTD, 6); //MOTOR 2
		sbi(PORTB, 1); //MOTOR 3
		sbi(PORTB, 3); //MOTOR 4
		delayMicroseconds(1060); //high time
		cbi(PORTD, 3); //MOTOR 1
		cbi(PORTD, 6); //MOTOR 2
		cbi(PORTB, 1); //MOTOR 3
		cbi(PORTB, 3); //MOTOR 4
		delayMicroseconds(1060); // low time    
	  }
  }
  
  // Make sure all the motors have stopped...
  cbi(PORTD, 3); //MOTOR 1
  cbi(PORTD, 6); //MOTOR 2
  cbi(PORTB, 1); //MOTOR 3
  cbi(PORTB, 3); //MOTOR 4
}

/**
 * @author <a href="mailto:dbaratta@buffalo.edu">Dominic Baratta</a>
 * 2011 UB Robotics (Modifications to library)
 *
 * File originally created by:
 * Aaron Weiss, SparkFun electronics 2011	
 * beerware - do what you wish with this ish
 */

#ifndef ubrquadstep_h
#define ubrquadstep_h

#include "WProgram.h"

class ubrQuadstep
{
  public:
  /**
   * Constructor for the UBR Stepper Motor libaray for the PCB's produced by Sparkfun Electronics
   */
  ubrQuadstep();
  
  /**
   * Set's the input / output pins being used by the motor's.
   *
   * @param m1StepNum Motor 1's step input pin
   * @param m2StepNum Motor 2's step input pin
   * @param m3StepNum Motor 3's step input pin
   * @param m4StepNum Motor 4's step input pin
   * @param m1EnabNum Motor 1's enable pin
   * @param m2EnabNum Motor 2's enable pin
   * @param m3EnabNum Motor 3's enable pin
   * @param m4EnabNum Motor 4's enable pin
   * @param m1DrctNum Motor 1's direction pin
   * @param m2DrctNum Motor 2's direction pin
   * @param m3DrctNum Motor 3's direction pin
   * @param m4DrctNum Motor 4's direction pin
   */
  void motor_pins(int m1StepNum,
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
		  int m4DrctNum);
  
  /**
   * Drives the platform at a specified velocity and rotation. The velocity
   * and rotation should be between -100 and +100
   *
   * @param velocity
   * @param rotation
   */
  void motor_go(int velocity);
  
 private:
  void current_control(int step);
  int _torque;
  int step1;
  int step2;
  int step4;
  int step8;
  int step16;
  
  int _motor_enable_1;
  int _motor_dir_1;
  int _motor_ms_11;
  int _motor_ms_12;
  int _motor_ms_13;
  
  int _motor_enable_2;
  int _motor_dir_2;
  int _motor_ms_21;
  int _motor_ms_22;
  int _motor_ms_23;
  
  int _motor_enable_3;
  int _motor_dir_3;
  int _motor_ms_31;
  int _motor_ms_32;
  int _motor_ms_33;
  
  int _motor_enable_4;
  int _motor_dir_4;
  int _motor_ms_41;
  int _motor_ms_42;
  int _motor_ms_43;
};
#endif

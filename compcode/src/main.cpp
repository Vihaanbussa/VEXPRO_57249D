/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightFront           motor         5               
// LeftBack             motor         16              
// RightBack            motor         4               
// RightMiddle          motor         7               
// Catapult             motor         1               
// BumperA              bumper        G               
// LeftFront            motor         11              
// LeftMiddle           motor         15              
// Intake               motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
controller Controller = controller();
int pressedA;



  void setLeftDriveExpo(vex::directionType type, int percentage){
    if(percentage>=0){
      percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2*percentage;
    }
    else{
      percentage = -percentage;
      percentage = 1.2*pow(1.034,percentage) - 1.2 + 0.2*percentage;
      percentage = -percentage;
    }
    LeftBack.spin(type, percentage, vex::velocityUnits::pct);
    LeftMiddle.spin(type, percentage, vex::velocityUnits::pct);
    LeftFront.spin(type, percentage, vex::velocityUnits::pct);
  }

  void setRightDriveExpo(vex::directionType type, int percentage){
    if(percentage>=0){
      percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2*percentage;
    }
    else{
      percentage = -percentage;
      percentage = 1.2*pow(1.034,percentage) - 1.2 + 0.2*percentage;
      percentage = -percentage;
    }
    RightBack.spin(type, percentage, vex::velocityUnits::pct);
    RightMiddle.spin(type, percentage, vex::velocityUnits::pct);
    RightFront.spin(type, percentage, vex::percentUnits::pct);
  }

    void catapult_code() {
    Catapult.setVelocity(80, percent);
    Catapult.setStopping(hold);
    Catapult.spinFor(reverse, 9720.0, degrees, true);
  }

  void newcatacode(){
    Catapult.setVelocity(80, percent);
    Catapult.setStopping(hold);
    if (BumperA.pressing()) {
      Catapult.spin(reverse);

    }
  }

  void catacodedown() {
    Catapult.setVelocity(80, percent);
    Catapult.setStopping(hold);
    Catapult.spinFor(reverse, 3037.5, degrees, true);
  }

  void driveForward(float x) {
    LeftFront.spinFor(forward, x, turns, true);
    RightFront.spinFor(forward, x, turns, true);
    LeftBack.spinFor(forward, x, turns, true);
    RightBack.spinFor(forward, x, turns, true);
    LeftMiddle.spinFor(forward, x, turns, true); 
    RightMiddle.spinFor(forward, x, turns, true);
  }
  void driveReverse(float x) {
    LeftFront.spinFor(reverse, x, turns, true);
    RightFront.spinFor(reverse, x, turns, true);
    LeftBack.spinFor(reverse, x, turns, true);
    RightBack.spinFor(reverse, x, turns, true);
    LeftMiddle.spinFor(reverse, x, turns, true);
    RightMiddle.spinFor(reverse, x, turns, true);
  }
  void turnRight(float x){
    LeftFront.spinFor(forward, x, degrees, true);
    RightFront.spinFor(reverse, x, degrees, true);
    LeftMiddle.spinFor(forward, x, degrees, true);
    RightMiddle.spinFor(reverse, x, degrees, true);
    LeftBack.spinFor(forward, x, degrees, true);
    RightBack.spinFor(reverse, x, degrees, true);
  }
  void turnLeft(float x){
    LeftFront.spinFor(reverse, x, degrees, true);
    RightFront.spinFor(forward, x, degrees, true);
    LeftMiddle.spinFor(reverse, x, degrees, true);
    RightMiddle.spinFor(forward, x, degrees, true);
    LeftBack.spinFor(reverse, x, degrees, true);
    RightBack.spinFor(forward, x, degrees, true);
  }
  
// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  RightFront.stop(brakeType::coast);
  RightMiddle.stop(brakeType::coast);
  RightBack.stop(brakeType::coast);
  LeftFront.stop(brakeType::coast);
  LeftMiddle.stop(brakeType::coast);
  LeftBack.stop(brakeType::coast);
  Intake.setVelocity(80, percent);
  Catapult.setVelocity(100, percent);
  RightFront.setVelocity(80, percent);
  RightMiddle.setVelocity(80, percent);
  RightBack.setVelocity(80, percent);
  LeftFront.setVelocity(80, percent);
  LeftMiddle.setVelocity(80, percent);
  LeftBack.setVelocity(80, percent);

  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  pressedA=0;
  Catapult.spin(reverse);
  if (BumperA.pressing() && pressedA == 0){
    Catapult.stop(hold);
    pressedA++;
  }
  Catapult.spinFor(reverse, 9720.0, degrees, true);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  Intake.setVelocity(80, percent);
  Catapult.setVelocity(100, percent);
  Catapult.setStopping(hold);
  while (1) {
    // Movement
      // If the the boolean Reverse is true, the bot will drive backwards when the joystick is forward, and vice versa
      setRightDriveExpo(directionType::fwd, Controller.Axis3.value()-Controller.Axis4.value()); 
      setLeftDriveExpo(directionType::fwd, Controller.Axis3.value()+Controller.Axis4.value()); 

      // Catapult
      // If the limit switches are being pressed, the motor automatically overrides to zero and stops. These are to ensure that the lift does not
      // extend and skip gears
      
      //if(Controller.ButtonR1.pressing()){
          //Catapult.spin(directionType::rev, 150, velocityUnits::pct);
      //}
      //else if(Controller.ButtonR2.pressing()){
          //Catapult.spin(directionType::fwd, 150, velocityUnits::pct);
      //}
      //else{
        //Catapult.stop();      
      //}

      

      // Intake
      if(Controller.ButtonL2.pressing()){
        Intake.spin(directionType::rev, 350, velocityUnits::pct);
      }
      else if(Controller.ButtonL1.pressing()){
        Intake.spin(directionType::fwd, 350, velocityUnits::pct);
      }
      else{
        Intake.stop();
      }

      //Catapult
      //Controller.ButtonR2.pressed(catapult_code);
      //Controller.ButtonDown.pressed(catacodedown);
      if (!BumperA.pressing()){
        Catapult.spin(reverse);
      }
      else if (BumperA.pressing()) {
        if (Controller.ButtonR2.pressing()) {
          Catapult.spin(reverse);
        }
        else {
        Catapult.stop();
        } 
      }
      else {
        Catapult.stop();
      }
      
      }


      

    
    }

  
    //wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

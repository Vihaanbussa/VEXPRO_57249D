#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RightFront = motor(PORT5, ratio6_1, false);
motor LeftBack = motor(PORT16, ratio6_1, true);
motor RightBack = motor(PORT4, ratio6_1, false);
motor RightMiddle = motor(PORT7, ratio6_1, false);
motor Catapult = motor(PORT1, ratio36_1, false);
bumper BumperA = bumper(Brain.ThreeWirePort.G);
motor LeftFront = motor(PORT11, ratio6_1, true);
motor LeftMiddle = motor(PORT15, ratio6_1, true);
motor Intake = motor(PORT9, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
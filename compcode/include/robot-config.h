using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor RightFront;
extern motor LeftBack;
extern motor RightBack;
extern motor RightMiddle;
extern motor Catapult;
extern bumper BumperA;
extern motor LeftFront;
extern motor LeftMiddle;
extern motor Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
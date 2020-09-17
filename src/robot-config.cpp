#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT9, ratio18_1, false);
motor RightDriveSmart = motor(PORT13, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
motor Motor1 = motor(PORT4, ratio18_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1UpDownButtonsControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;
int angle = 0;
int newangle = 0;
int x = 0;
int y = 0;
double axis = 0;
// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  //Brain.Screen.render(true,false);
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      
      //int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      //int drivetrainRightSideSpeed = Controller1.Axis3.position();
      newangle = angle + (Controller1.Axis1.position()/10);
      Drivetrain.turnFor(newangle - angle, degrees);
      angle = newangle;
      double rad = atan(Controller1.Axis3.position(percent)/Controller1.Axis4.position(percent));
      double dist = sqrt(Controller1.Axis4.position(percent)^2 + Controller1.Axis3.position(percent)^2);
      rad += ((angle*3.14159)/180);
      axis = y;
      x = dist * cos(rad);
      y = dist * sin(rad);
     // check if the value is inside of the deadband range
      //if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
      //  if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
      //    LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
      //    DrivetrainLNeedsToBeStopped_Controller1 = false;
        //}
      //} else {
        // reset the toggle so that the deadband code knows to stop the left motor next time the input is in the deadband range
        //DrivetrainLNeedsToBeStopped_Controller1 = true;
      //}
      // check if the value is inside of the deadband range
      //if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        ///if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          ///RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          ///DrivetrainRNeedsToBeStopped_Controller1 = false;
        //}
      //} else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        //DrivetrainRNeedsToBeStopped_Controller1 = true;
      //}
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      //if (DrivetrainLNeedsToBeStopped_Controller1 || true) {
        LeftDriveSmart.setVelocity(y, percent);
        LeftDriveSmart.spin(forward);
      //}
      // only tell the right drive motor to spin if the values are not in the deadband range
      //if (DrivetrainRNeedsToBeStopped_Controller1 || true) {
        RightDriveSmart.setVelocity(y, percent);
        RightDriveSmart.spin(forward);
      //}
      // check the ButtonUp/ButtonDown status to control Motor1
      Motor1.setVelocity(x, percent);
      Motor1.spin(forward);
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}
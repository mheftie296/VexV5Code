/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\matth                                            */
/*    Created:      Fri Sep 11 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    9, 13           
// Motor1               motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
  Brain.Screen.clearLine(1,color::blue);
  Brain.Screen.clearLine(2,color::black);
  Brain.Screen.setCursor(1,0);
  Brain.Screen.setCursor(2,0);
  Brain.Screen.print(axis);
  Brain.Screen.render();
  }
  

}

#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(1000);

  //stepper.setMinPulseWidth(10);
}

void loop() {
 
 
  stepper.moveTo(8000);
  //stepper.runToPosition(); // Using runToPosition only one motor will move at a time

  //Using this whlie loop both motors will move at the same time
//  while ((stepper.distanceToGo() > 0) &&  (stepper2.distanceToGo() > 0)) {
//    stepper.run();
//    stepper2.run();
//  }

  delay(1000);

  // Move back to zero:
  stepper.moveTo(0);
  stepper.runToPosition();


  delay(1000);
}

#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 3
#define stepPin 2
#define motorInterfaceType 1
#define dirPin2 6
#define stepPin2 5
// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);

void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(1000);
  stepper2.setMaxSpeed(5000);
  stepper2.setAcceleration(1000);
  //fix for voltage
  //stepper.setMinPulseWidth(10);
}

void loop() {
 
 
  stepper.moveTo(8000);
  //stepper.runToPosition(); // Using runToPosition only one motor will move at a time
  stepper2.moveTo(8000);
  //stepper2.runToPosition();

  //Using this whlie loop both motors will move at the same time
  while ((stepper.distanceToGo() > 0) && (stepper2.distanceToGo() > 0)) {
    stepper.run();
    stepper2.run();
  }

  delay(1000);

  // Move back to zero:
  stepper.moveTo(0);
  stepper.runToPosition();

  // Move back to zero:
  stepper2.moveTo(0);
  stepper2.runToPosition();

  delay(1000);
}

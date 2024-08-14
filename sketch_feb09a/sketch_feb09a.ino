//#include <Stepper.h>
//#define STEPS 100
//
//Stepper myStepper(STEPS, 0, 1, 2);
//int pos = 1;
//void setup() {
//  stepper.setSpeed(30);
//
//}
//
//void loop() {
//  stepper.step(pos);
//  pos = pos + 1;
//  delay(10);
//}

void setup() {
  digitalWrite(0, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(6, HIGH);
}

void loop() {
  digitalWrite(1, LOW);
  delay(10);
  digitalWrite(1, HIGH);
  delay(10);
}

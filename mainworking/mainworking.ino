// Define pins for the stepper motor driver
int pulsePin = 2;   // positive pulse pin
int dirPin = 3;     // positive direction pin
int enablePin = 4;  // positive enable pin

int pulsePin2 = 5;  // positive pulse pin
int dirPin2 = 6;    // positive direction pin
int enablePin2 = 7;

// int pulsePin3 = 3;    // positive pulse pin
// int dirPin3= 4;      // positive direction pin
// int enablePin3 = 6;


// Define stepper motor parameters
const int stepsPerRevolution = 200;                         // number of steps per motor revolution
const float rpm = 50.0;                                     // target rotation speed in revolutions per minute
const float stepDelay = 60.0 / (stepsPerRevolution * rpm);  // delay between steps in milliseconds



void one_loop() {
  for (int i = 0; i < 2000; i++) {
    digitalWrite(pulsePin, HIGH);
    delayMicroseconds(50);  // pulse width is 50 microseconds
    digitalWrite(pulsePin, LOW);
    delay(stepDelay);
  }
}
void setup() {
  // Set the pins as outputs
  pinMode(pulsePin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  pinMode(pulsePin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  // pinMode(pulsePin3, OUTPUT);
  // pinMode(dirPin3, OUTPUT);
  // pinMode(enablePin3, OUTPUT);
  // Set the initial pin states
  //  digitalWrite(pulsePin, LOW);
  digitalWrite(dirPin, LOW);
  digitalWrite(enablePin, LOW);  // enable the motor driver

  //  digitalWrite(pulsePin2, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(enablePin2, LOW);  // enable the motor driver

  // digitalWrite(pulsePin3, LOW);
  // digitalWrite(dirPin3, HIGH);
  // digitalWrite(enablePin3, LOW); // enable the motor driver

  one_loop();
  delay(100);
}


void loop() {
  // Step the motor one step

  digitalWrite(pulsePin2, HIGH);
  delayMicroseconds(50);  // pulse width is 50 microseconds
  digitalWrite(pulsePin2, LOW);
  delay(stepDelay);

  digitalWrite(pulsePin, HIGH);
  delayMicroseconds(50);  // pulse width is 50 microseconds
  digitalWrite(pulsePin, LOW);
  delay(stepDelay);
  //  // Reverse the direction of the motor if it has completed one revolution
  //  static int stepCount = 0;
  //  stepCount++;
  //  if (stepCount >= stepsPerRevolution) {
  //    stepCount = 0;
  //    digitalWrite(dirPin, !digitalRead(dirPin)); // toggle the direction pin
}

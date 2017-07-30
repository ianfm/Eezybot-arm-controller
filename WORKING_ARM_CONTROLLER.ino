/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo mastServo;  // create servo object to control a servo
Servo boomServo;
Servo rotorServo;

int mastSigPin = 9;
int boomSigPin = 10;
int rotorSigPin = 11;

int mastPin = A0;  // analog pin used to connect the potentiometer
int boomPin = A2;
int rotorPin = A3;

int mastVal;    // variable to read the value from the analog pin
int boomVal;
int rotorVal;

void setup() {
  mastServo.attach(mastSigPin);  // attaches the servo on pin 9 to the servo object
  boomServo.attach(boomSigPin);
  rotorServo.attach(rotorSigPin);
}

void loop() {
  //mastVal = analogRead(mastPin);            // reads the value of the potentiometer (value between 0 and 1023)
  //boomVal = analogRead(boomPin);

  
  mastVal = map(analogRead(mastPin), 0, 1023, 90, 180);     // scale it to use it with the servo (value between 0 and 180)
  boomVal = map(analogRead(boomPin), 0, 1023, 100, 180);
  rotorVal = map(analogRead(rotorPin), 0, 1023, 0, 180);
  
  mastServo.write(mastVal);                  // sets the servo position according to the scaled value
  boomServo.write(boomVal);
  rotorServo.write(rotorVal);
  
  delay(15);                           // waits for the servo to get there
  
}


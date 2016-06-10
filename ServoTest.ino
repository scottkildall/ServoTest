/* 
  Simple servo tester
  Written by Scott Kildall
  Quick n' Dirty simulator of randomness
*/

#include <Servo.h> 

// Built in Arduino Servo library
Servo servo1;

int delayTime = 25;
int servoValue = 90;      // start in the middle
int randomRange = 4;      // max amount of travel per loop, for each side

#define SERIAL_OUT  (0)     // 0 = no serial output, 1 has serial output

void setup(){
 // Attach a servo to pin #10
  servo1.attach(10);

  if( SERIAL_OUT ) {
    Serial.begin(9600);
    Serial.println("Servo Test");
  }
  
  // set to midpoint
  servo1.write(servoValue);
  delay(1000);

  // seed random number generator
  randomSeed(analogRead(A0));
}


void loop() {
  // some maths to get the right randomnness
  servoValue += random(randomRange * 2 + 1) - randomRange;

  // check for past min or max
  if( servoValue < 0 )
    servoValue = 0;
  else if( servoValue > 180 )
    servoValue = 180;

  // randomize the range
  if( SERIAL_OUT ) {
    Serial.println(servoValue);
  }
  
  servo1.write(servoValue);
  delay(delayTime);
}

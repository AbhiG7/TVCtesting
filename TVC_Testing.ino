#include <Servo.h>

/*
 This code can be used for testing the gear ratio, max gimbal, and max speed by allowing 
 us to input any angle into one or both servos at once
*/

Servo tvc_x;
Servo tvc_y;

// These are the values for centering the TVC before beginning the rest of testing
int xCenter = 0;
int yCenter = 0;

// These are the values that we will be inputting and changing the anlge of the servos with
int activeAngX = xCenter;
int activeAngY = yCenter;

void setup() {
  Serial.begin(9600);
  
  tvc_x.attach(7);
  tvc_y.attach(9);

  tvc_x.write(xCenter);
  tvc_y.write(yCenter);

  // Just tells us where it's starting
  Serial.print("Starting X angle: ");
  Serial.println(activeAngX);
  Serial.print("Starting Y angle: ");
  Serial.println(activeAngY);
}

// Variables needed for the loop to make reading it easier
char axis;
int inputAng;
int center = -1000; // I needed to do this to avoid an issue I kept having with the servo returning to zero every time

// Inputs into the Serial Monitor will be a letter followed by a number, x for x-axis servo, y for y-axis servo, b for both servos, number following will be angle
// Ex. x50 (moves x-axis 50 degrees from center), y-30 (moves y-axis -30 degrees from center), b90 (moves both 90 degrees from center)
void loop() {
  if (Serial.available() > 0) {
    axis = Serial.read();
    inputAng = Serial.parseInt();
    
    if (axis == 'x') {
      if (inputAng == center) {
        activeAngX = xCenter;
      }
      else if (inputAng != 0){
        activeAngX = xCenter + inputAng;
      }
    }
    else if (axis == 'y') {
      if (inputAng == center) {
        activeAngY = yCenter;
      }
      else if (inputAng != 0){
        activeAngY = yCenter + inputAng;
      }
    }
    else if (axis == 'b'){
      if (inputAng == center) {
        activeAngX = xCenter;
        activeAngY = yCenter;
      }
      else if (inputAng != 0){
        activeAngX = xCenter + inputAng;
        activeAngY = yCenter + inputAng;
      }
    }

    tvc_x.write(activeAngX);
    tvc_y.write(activeAngY);

    // Prints the new angle that the motors are at relative to our center
    Serial.print("X angle: ");
    Serial.println(activeAngX);
    Serial.print("Y angle: ");
    Serial.println(activeAngY);
  }
}

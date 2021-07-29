#include <Servo.h>

/*
 * This code is for initially centering the tvc. It allows us to move the servos 
 * 1 degree at a time with WASD and then displays the position it's at.
 */

Servo tvcX;
Servo tvcY;

int input;
int xPos;
int yPos;

void setup() {
  Serial.begin(9600);
  tvcX.attach(9);
  tvcY.attach(10);
  
  xPos = tvcX.read();
  yPos = tvcY.read();
  
  Serial.print("Starting xPos: ");
  Serial.println(xPos);
  Serial.print("Starting yPos: ");
  Serial.println(yPos);
}

// A moves the x-axis servo positive, D is negative, W is y-axis servo positive, S is negative
void loop() {
  if (Serial.available()) {
    input = Serial.read();
    if (input == 'a' && xPos > 0) {
      xPos -= 1;
      tvcX.write(xPos);
      Serial.print("xPos: ");
      Serial.println(xPos);
    }
    else if (input == 'd' && xPos < 180) {
      xPos += 1;
      tvcX.write(xPos);
      Serial.print("xPos: ");
      Serial.println(xPos);
    }
    else if (input == 's' && yPos > 0) {
      yPos -= 1;
      tvcX.write(yPos);
      Serial.print("yPos: ");
      Serial.println(yPos);
    }
    else if (input == 'w' && yPos < 180) {
      yPos = yPos + 1;
      tvcX.write(yPos);
      Serial.print("yPos: ");
      Serial.println(yPos);
    }
    //delay(50);
  }

}

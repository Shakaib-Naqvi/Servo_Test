#include "Servo.h"

void setup(){

  Serial.begin(115200);
  Serial.println("Firmware of Servo moving 0-120 degrees after every 5 seconds");
  
}

void loop() {

  MoveServo(0, 1);
  delay(5000);
  MoveServo(120, 1);
  delay(5000);

}
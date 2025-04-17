#include "Servo.h"
// ----------------------------Servo Pin Changed----------------------------

void setup(){

  Serial.begin(115200);
  Serial.println("Firmware of Servo moving 0-90 degrees after every 2 seconds");
  
}

void loop() {

  MoveServo(0, 1);
  Serial.println("0degrees");
  delay(2000);
  MoveServo(90, 1);
  Serial.println("90degrees");
  delay(2000);

}                  


// ----------------------------Servo Pin Changed----------------------------
#include <ESP32PWM.h>
#include <ESP32Servo.h>
#include <Preferences.h>

Servo myservo;


int pos = 0;

void MoveServo(int degrees, int steps) {

  Preferences preferences;
  preferences.begin("servo", false);
  ESP32PWM::allocateTimer(0);
  myservo.setPeriodHertz(50);
  myservo.attach(2);

  pos = preferences.getInt("position", 0);
  if (pos < 0 || pos > 180) {
    pos = 0;
  }

  if (pos > degrees) {

    for (pos = pos; pos >= degrees; pos -= steps) {
      myservo.write(pos);
      delay(30);
      preferences.putInt("position", pos);
    }
    if (pos < degrees) {
      pos = degrees;
      myservo.write(pos);
      preferences.putInt("position", pos);
    }
  } else {
    for (pos = pos; pos <= degrees; pos += steps) {
      myservo.write(pos);
      delay(30);
      preferences.putInt("position", pos);
    }
    if (pos > degrees) {
      pos = degrees;
      myservo.write(pos);
      preferences.putInt("position", pos);
    }
  }
}
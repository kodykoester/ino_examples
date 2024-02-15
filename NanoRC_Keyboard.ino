#include <ArduinoMotorCarrier.h>

void setup() {
  Serial.begin(115200);
  controller.begin();

  controller.ping();
  delay(50);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    switch (command) {
      case 'W':
        goStraight();
        break;
      case 'A':
        turnLeft();
        break;
      case 'D':
        turnRight();
        break;
      case 'S':
        stopMotors();
        break;
      // Add more commands if needed
    }
  }
}

void goStraight() {
  M1.setDuty(80); // Right Motor
  M2.setDuty(80); // Left Motor
  // Serial.println("Straight");
}

void stopMotors() {
  M1.setDuty(0);
  M2.setDuty(0);
  // Serial.println("Stopped");
}

void turnLeft() {
  M1.setDuty(70);
  M2.setDuty(30);
  // Serial.println("Left");
  delay(750);
}

void turnRight() {
  M1.setDuty(30);
  M2.setDuty(70);
  // Serial.println("Right");
  delay(750);
}

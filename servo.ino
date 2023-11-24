#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int ir_sensor = 6;
int neu = 40;    // variable to store the servo position
int right = 50;
int left = 20;
void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
pinMode(ir_sensor, INPUT);
}

void loop() {
    myservo.write(neu); 
    Serial.println("Neutral");
    delay(2000); 
    myservo.write(left); 
    Serial.println("20deg?");
    delay(2000); 

    myservo.write(right); 
    Serial.println("right 20deg?");

    delay(2000); 
  /*
  for (pos = 0; pos <= 45; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 45; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
}

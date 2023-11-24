#include <NewPing.h>


#define trigPin1 4
#define echoPin1 5
#define trigPin2 6
#define echoPin2 7

NewPing sonar1(trigPin1, echoPin1);
NewPing sonar2(trigPin2, echoPin2);

void setup() {
  Serial.begin(9600);
}

void loop() {

  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();


  Serial.print("Distance Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm\t");

  Serial.print("Distance Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");


  delay(500);
}

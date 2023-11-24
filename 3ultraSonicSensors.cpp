// Define the pins for ultrasonic sensors
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int trigPin3 = 6;
const int echoPin3 = 7;

void setup() {
  Serial.begin(9600);

  // Set the trig pins as OUTPUT and echo pins as INPUT
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  // Function to get distance from ultrasonic sensor
  int distance1 = getDistance(trigPin1, echoPin1);
  int distance2 = getDistance(trigPin2, echoPin2);
  int distance3 = getDistance(trigPin3, echoPin3);

  // Print the distances to the Serial Monitor
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm ");

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.print(" cm ");

  Serial.print("Distance 3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  delay(1000); // Wait for 1 second before taking the next set of readings
}

int getDistance(int trigPin, int echoPin) {
  // Generate a pulse for the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  int distance = duration * 0.034 / 2;

  return distance;
}

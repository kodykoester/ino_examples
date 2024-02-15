#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_ICM20X.h>
Adafruit_ICM20948 icm;
Adafruit_Sensor *icm_temp, *icm_accel, *icm_gyro, *icm_mag;

#define PIN            14   // Change this to the actual pin connected to the NeoPixels
#define NUMPIXELS      8    // Change this to the actual number of NeoPixels in your setup
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int motorA = 12;
int pwmPinA = 3;
int brakePinA = 9;

int motorB = 13;
int pwmPinB = 11;
int brakePinB = 8;

// Ultrasonic sensors
const int trigPin1 = 2;
const int echoPin1 = 10;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int trigPin3 = 6;
const int echoPin3 = 7;

// const int highLimit = 25;
const int theLimit = 15;

int getDistance(int trigPin, int echoPin) {   // Generate a pulse for the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);  // Measure the duration of the echo pulse
  int distance = duration * 0.034 / 2;  // Calculate the distance in centimeters
  return distance;
}

enum vehicleState {
  STOP,
  GO,
  BACK,
  LEFT,
  RIGHT
};
// Function declarations
void stateStop();
void stateGo();
void stateBack();
// Variable to keep track of the current state
vehicleState currentState = STOP;

void setup() {
  pixels.begin();

  pinMode(motorA, OUTPUT);
  pinMode(pwmPinA, OUTPUT); 
  pinMode(brakePinA, OUTPUT);

  pinMode(motorB, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  pinMode(brakePinB, OUTPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  if (!icm.begin_I2C()) {
    Serial.println("Failed to find ICM20948 chip");
  }
}

void loop() {
  int center = getDistance(trigPin1, echoPin1);
  int left = getDistance(trigPin2, echoPin2);
  int right = getDistance(trigPin3, echoPin3);
  sensors_event_t accel, gyro, mag, temp;
  icm.getEvent(&accel, &gyro, &temp, &mag);

  // Convert Celsius to Fahrenheit
  float temperatureF = (temp.temperature * 9 / 5) + 32;

  // Convert Celsius to Fahrenheit
  Serial.print("\t\tTemperature ");
  Serial.print(temperatureF, 1);
  Serial.println(" F");

  // Print accelerometer data
  Serial.print("\t\tAccel X: ");
  Serial.print(accel.acceleration.x);
  Serial.print(" \tY: ");
  Serial.print(accel.acceleration.y);
  Serial.print(" \tZ: ");
  Serial.print(accel.acceleration.z);
  Serial.println(" m/s");










 
  // // Simple case statement to switch between states
  // switch (currentState) {
  //   case STOP:
  //     stateStop();
  //     break;
  //   case GO:
  //     stateGo();
  //     break;
  //   case BACK:
  //     stateBack();
  //     break;
  //   case RIGHT:
  //     stateRight();
  //     break;
  //   case LEFT:
  //     stateLeft();
  //     break;
  //   // Add more cases as needed

  //   default:
  //     // Handle unexpected state
  //     break;
  // }

  // // Update the currentState based on your conditions


  // if (center > theLimit && left > theLimit && right > theLimit) {
  //   currentState = STOP;
  // } else if (center < theLimit && left > theLimit && right > theLimit) {
  //   currentState = BACK;
  // } else if (center > theLimit && left > theLimit && right < theLimit) {
  //   currentState = RIGHT;
  // } else if (center > theLimit && left < theLimit && right > theLimit) {
  //   currentState = LEFT;
  // } else {
  //   currentState = GO;
  // }

  // // Add any other necessary code
}

void stateStop() {
  stopMotors();
  setPixelColor(255, 0, 0); // Red
  delayWithPixels(2000);
}

void stateGo() {
  forwardMotors();
  setPixelColor(0, 255, 0); // Green
  delayWithPixels(2000);
}

void stateBack() {
  backwardMotors();
  setPixelColor(0, 0, 255); // Blue
  delayWithPixels(2000);
}

void stateRight() {
  turnRight();
  setPixelColor(0, 100, 255); // 
  delayWithPixels(2000);
}

void stateLeft() {
  turnLeft();
  setPixelColor(255, 255, 0); // Yellow
  delayWithPixels(2000);
}

void stopMotors() {
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);
}

void forwardMotors() {
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, HIGH);
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);
  analogWrite(pwmPinA, 200);
  analogWrite(pwmPinB, 200);
}

void backwardMotors() {
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);
  analogWrite(pwmPinA, 200);
  analogWrite(pwmPinB, 200);
}

void turnRight() {
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);
  analogWrite(pwmPinA, 70);
  analogWrite(pwmPinB, 200);
  }

void turnLeft() {
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);
  analogWrite(pwmPinA, 200);
  analogWrite(pwmPinB, 70);
}

void setPixelColor(int red, int green, int blue) {
  pixels.fill(pixels.Color(red, green, blue));
  pixels.show();
}

void delayWithPixels(int milliseconds) {
  delay(milliseconds);
  pixels.clear();
  pixels.show();
}

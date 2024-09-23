#include <Arduino_BMI270_BMM150.h> // IMU Sensor Library
#include <Arduino_HS300x.h>        // Humidity & Temperature Sensor Library
#include <Arduino_LPS22HB.h>       // Barometer Sensor Library
#define RED 22     
#define BLUE 24     
#define GREEN 23
#define LED_PWR 25

float temperature = HS300x.readTemperature(FAHRENHEIT);   // Passing in FAHRENHEIT as the unit parameter to ENV.readTemperature(...),
float humidity = HS300x.readHumidity();    // Humidity reading (imperial)
float pressure = BARO.readPressure(); // Barometer reading
float altitude = 44330 * ( 1 - pow(pressure/101.325, 1/5.255) ); // Altitude conversation from barometer to meters
float x, y, z; // Floats coordinates of IMU


void setup() {
pinMode(RED, OUTPUT); // Onboard LED Pins
pinMode(BLUE, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(LED_PWR, OUTPUT);


  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
      Serial.println("Failed to initialize IMU!");
      while (1);
  }
  if (!HS300x.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
  if (!BARO.begin()) {
    Serial.println("Failed to initialize pressure sensor!");
    while (1);
  }

  digitalWrite(LED_PWR, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);

  delay(500);  

}

void loop() {


  if (IMU.accelerationAvailable()) {
  IMU.readAcceleration(x, y, z);
    Serial.print(x);
    Serial.print('\t');
    // Serial.print(y);
    // Serial.print('\t');
    Serial.println(z);
}

  Serial.print(temperature);
  Serial.print(" °F");
  Serial.print(",");
  Serial.print(altitude, 1);
  Serial.println(" m");



  delay(1000); 
}



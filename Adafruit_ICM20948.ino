// Basic demo for accelerometer readings from Adafruit ICM20948

#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_ICM20948 icm;


void setup(void) {
  Serial.begin(115200);
  // Initialize
  if (!icm.begin_I2C()) {
    Serial.println("Failed to find ICM20948 chip");
  }
}

void loop() {
  // Get sensor data
  sensors_event_t accel, gyro, mag, temp;
  icm.getEvent(&accel, &gyro, &temp, &mag);

  // Convert Celsius to Fahrenheit
  float temperatureF = (temp.temperature * 9 / 5) + 32;

  // // Print temperature in Fahrenheit
  // Serial.print("\t\tTemperature ");
  // Serial.print(temperatureF, 1);
  // Serial.println(" F");

  // Print accelerometer data
// Send accelerometer data as a comma-separated string
Serial.print(accel.acceleration.x);
Serial.print(",");
Serial.print(accel.acceleration.y);
Serial.print(",");
Serial.println(accel.acceleration.z);

  // // Print magnetometer data
  // Serial.print("\t\tMag X: ");
  // Serial.print(mag.magnetic.x);
  // Serial.print(" \tY: ");
  // Serial.print(mag.magnetic.y);
  // Serial.print(" \tZ: ");
  // Serial.print(mag.magnetic.z);
  // Serial.println(" uT");

  // // Print gyroscope data
  // Serial.print("\t\tGyro X: ");
  // Serial.print(gyro.gyro.x);
  // Serial.print(" \tY: ");
  // Serial.print(gyro.gyro.y);
  // Serial.print(" \tZ: ");
  // Serial.print(gyro.gyro.z);
  // Serial.println(" radians/s");
  // Serial.println();

  // delay(10);



  //  Serial.print(temp.temperature);
  //
  //  Serial.print(",");
  //
  //  Serial.print(accel.acceleration.x);
  //  Serial.print(","); Serial.print(accel.acceleration.y);
  //  Serial.print(","); Serial.print(accel.acceleration.z);
  //
  //  Serial.print(",");
  //  Serial.print(gyro.gyro.x);
  //  Serial.print(","); Serial.print(gyro.gyro.y);
  //  Serial.print(","); Serial.print(gyro.gyro.z);
  //
  //  Serial.print(",");
  //  Serial.print(mag.magnetic.x);
  //  Serial.print(","); Serial.print(mag.magnetic.y);
  //  Serial.print(","); Serial.print(mag.magnetic.z);

  //  Serial.println();
  //
  //  delayMicroseconds(measurement_delay_us);
}

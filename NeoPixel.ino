#include <Adafruit_NeoPixel.h>


// Define the pin connected to the NeoPixels
#define PIN            14   // Change this to the actual pin connected to the NeoPixels

// Define the total number of NeoPixels in your setup
#define NUMPIXELS      8    // Change this to the actual number of NeoPixels in your setup

// Create an Adafruit_NeoPixel object with the specified number of pixels, pin, and color order
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize the NeoPixel object
  pixels.begin();
}

void loop() {
  // Flash red for 1 second
  pixels.fill(pixels.Color(0, 0, 255));  // Set all pixels to purple
  pixels.show();                          // Display the changes
  delay(1000);                            // Pause for 1 second

  // Clear pixels and pause for 1 second
  pixels.clear();                         // Clear all pixels
  pixels.show();                          // Display the changes (all off)
  delay(1000);                            // Pause for 1 second

   // Flash red for 1 second
  pixels.fill(pixels.Color(255, 0, 0));  // Set all pixels to burgandy
  pixels.show();                          // Display the changes
  delay(1000);  

    // Clear pixels and pause for 1 second
  pixels.clear();                         // Clear all pixels
  pixels.show();                          // Display the changes (all off)
  delay(1000);                            // Pause for 1 second

   // Flash red for 1 second
  pixels.fill(pixels.Color(0, 255, 0));  // Set all pixels to burgandy
  pixels.show();                          // Display the changes
  delay(1000);  

  
}


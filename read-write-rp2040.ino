#if !defined(ARDUINO_ARCH_RP2040)
  #error For RP2040 only
#endif

#if defined(ARDUINO_ARCH_MBED)

  #define PIN_SD_MOSI       PIN_SPI_MOSI
  #define PIN_SD_MISO       PIN_SPI_MISO
  #define PIN_SD_SCK        PIN_SPI_SCK
  #define PIN_SD_SS         PIN_SPI_SS

#else

  #define PIN_SD_MOSI       PIN_SPI0_MOSI
  #define PIN_SD_MISO       PIN_SPI0_MISO
  #define PIN_SD_SCK        PIN_SPI0_SCK
  #define PIN_SD_SS         PIN_SPI0_SS

#endif

#define _RP2040_SD_LOGLEVEL_       4

#include <SPI.h>
#include <RP2040_SD.h>

File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

  while (!Serial);

  delay(1000);

#if defined(ARDUINO_ARCH_MBED)
  Serial.print("Starting SD Card ReadWrite on MBED ");
#else
  Serial.print("Starting SD Card ReadWrite on ");
#endif

  Serial.println(BOARD_NAME);
  Serial.println(RP2040_SD_VERSION);

  Serial.print("Initializing SD card with SS = ");
  Serial.println(PIN_SD_SS);
  Serial.print("SCK = ");
  Serial.println(PIN_SD_SCK);
  Serial.print("MOSI = ");
  Serial.println(PIN_SD_MOSI);
  Serial.print("MISO = ");
  Serial.println(PIN_SD_MISO);

  if (!SD.begin(PIN_SD_SS))
  {
    Serial.println("Initialization failed!");
    return;
  }

  Serial.println("Initialization done.");

#define fileName  "newtest0.txt"
  char writeData[]  = "Testing writing to " fileName;

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(fileName, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile)
  {
    Serial.print("Writing to ");
    Serial.print(fileName);
    Serial.print(" ==> ");
    Serial.println(writeData);

    myFile.println(writeData);

    // close the file:
    myFile.close();
    Serial.println("done.");
  }
  else
  {
    // if the file didn't open, print an error:
    Serial.print("Error opening ");
    Serial.println(fileName);
  }

  // re-open the file for reading:
  myFile = SD.open(fileName, FILE_READ);

  if (myFile)
  {
    Serial.print("Reading from ");
    Serial.println(fileName);
    Serial.println("===============");

    // read from the file until there's nothing else in it:
    while (myFile.available())
    {
      Serial.write(myFile.read());
    }

    // close the file:
    myFile.close();

    Serial.println("===============");
  }
  else
  {
    // if the file didn't open, print an error:
    Serial.print("Error opening ");
    Serial.println(fileName);
  }
}

void loop()
{
  // nothing happens after setup
}

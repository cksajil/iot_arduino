#include <Arduino.h>
#include <Wire.h>
#include <BMP180TwoWire.h>

#define I2C_ADDRESS 0x77

//create an BMP180 object using the I2C interface
BMP180TwoWire bmp180(&Wire, I2C_ADDRESS);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Wire.begin();
  
  if (!bmp180.begin())
  {
    Serial.println("begin() failed. check your BMP180 Interface and I2C Address.");
    while (1);
  }

  bmp180.resetToDefaults();

  bmp180.setSamplingMode(BMP180MI::MODE_UHR);
}

void loop() {


  delay(1000);

  if (!bmp180.measureTemperature())
  {
    Serial.println("could not start temperature measurement, is a measurement already running?");
    return;
  }

  do
  {
    delay(100);
  } while (!bmp180.hasValue());

  Serial.print("Temperature: "); 
  Serial.print(bmp180.getTemperature()); 
  Serial.println(" degC");

 
  if (!bmp180.measurePressure())
  {
    Serial.println("could not start perssure measurement, is a measurement already running?");
    return;
  }

  do
  {
    delay(100);
  } while (!bmp180.hasValue());

  Serial.print("Pressure: "); 
  Serial.print(bmp180.getPressure());
  Serial.println(" Pa");
}

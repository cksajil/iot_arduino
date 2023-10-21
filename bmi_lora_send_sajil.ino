#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include <Arduino.h>
#include <Wire.h>
#include <BMP180TwoWire.h>

#define I2C_ADDRESS 0x77

#ifdef COMPILE_REGRESSION_TEST
# define in_866 1
#else
# warning "You must replace the values marked FILLMEIN with real values from the TTN control panel!"
# define FILLMEIN (#dont edit this, edit the lines that use FILLMEIN)
#endif


BMP180TwoWire bmp180(&Wire, I2C_ADDRESS);



void read_sensors()
{
  
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

  int temparature = bmp180.getTemperature();
  int pressure = bmp180.measurePressure();
  
  Serial.print("Temperature: "); 
  Serial.print(temparature); 
  Serial.println(" degC");

 
  if (!pressure)
  {
    Serial.println("could not start perssure measurement, is a measurement already running?");
    return;
  }

  do
  {
    delay(100);
  } while (!bmp180.hasValue());

  Serial.print("Pressure: "); 
  Serial.print(pressure);
  Serial.println(" Pa");
}
  
}


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
    Serial.println(F("Starting"));

}

void loop() {
    read_sensor();
}

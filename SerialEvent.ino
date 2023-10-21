/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  A good test for this is to try it with a GPS receiver that sends out
  NMEA 0183 sentences.

  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

  created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/SerialEvent
*/

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() 
{
              if (stringComplete) 
                  {
                      Serial.println(inputString);
                      if (inputString=="ON")
                            { 
                              Serial.println("Received on command");
                              digitalWrite(45, HIGH);
                      
                             }
                      else if (inputString =="OFF")
                            { 
                              Serial.println("Received off command");
                              digitalWrite(45, LOW);
                            }

                       else
                       {
                        Serial.println("eRROR! Not a valid input");
                        }
                       stringComplete = false;
                       inputString = "";
                    }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
        if (inChar == '\n') {
      stringComplete = true;
    }else
    
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:

  }
}

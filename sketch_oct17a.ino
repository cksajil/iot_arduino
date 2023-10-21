
String inputString = "";         
bool stringComplete = false;
bool right = true;

void setup() {
 pinMode(47, OUTPUT);
 pinMode(45, OUTPUT);
 pinMode(43, OUTPUT);
 pinMode(41, OUTPUT);
 pinMode(39, OUTPUT);
 pinMode(37, OUTPUT);
 pinMode(35, OUTPUT);
 pinMode(33, OUTPUT);
 Serial.begin(9600);
 inputString.reserve(200);
}


void loop() 

{ 
  if (stringComplete) 
                  {
                      Serial.println(inputString);
                      if (inputString=="LEFT")
                            { 
                              Serial.println("Received LEFT command");  
                              right = false;       
                              stringComplete = false;   
                             }
                      else if (inputString =="RIGHT")
                            { 
                              Serial.println("Received RIGHT command");
                              right = true;
                              stringComplete = false;
                            }
                      else if (inputString == "STOP")
                            {
                              Serial.println("Stopping Process");
                              stringComplete = true;
                            }

                       inputString = "";

    if (right==true)
    {
      for(int i=47; i>=33; i-=2)
    {digitalWrite(i, HIGH); 
    delay(200); 
    }
    for(int i=47; i>=33; i-=2)
    {digitalWrite(i, LOW); 
    }
    }
      
    else
    {
      for(int i=33; i<=47; i+=2)
    {digitalWrite(i, HIGH);
    delay(200);
    } 
    for(int i=47; i>=33; i-=2)
    {digitalWrite(i, LOW); 
    }
    }
    
      
}
}
                     
              
      
   
  
     

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

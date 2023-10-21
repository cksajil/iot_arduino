void setup() {
  Serial.begin(9600);
 pinMode(47, OUTPUT);
 pinMode(45, OUTPUT);
 pinMode(43, OUTPUT);
 pinMode(41, OUTPUT);
 pinMode(39, OUTPUT);
 pinMode(37, OUTPUT);
 pinMode(35, OUTPUT);
 pinMode(33, OUTPUT);

  }

void loop() {
  int light = analogRead(A0);

//  int mapped_level = 5-map(moisture,280,420,0,8);
  
  Serial.println(light);
  delay(1000);

//  switch (mapped_level)
//  {
//    case 0 ... 1:
//    Serial.println("Very dark");
//    break;
//
//    case 2 ... 4:
//    Serial.println("Bright");
//    break;
//
//    case 5 ... 7:
//    Serial.println("Very bright");
//    break;
//
//    default:
//    break;
//    
//    }
//
//
//  for(int i=47; i>=47-2*mapped_level; i-=2)
//    {digitalWrite(i, HIGH); 
//    }
//    for(int i=47; i>=33; i-=2)
//    {digitalWrite(i, LOW); 
//    }
//   delay(200);

}

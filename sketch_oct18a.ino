void setup() {
  Serial.begin(9600);

  }

void loop() {
  int moisture = analogRead(A0);
  Serial.println(moisture);
//  int mapped_level = moisture%10;
//  Serial.println(mapped_level);

}

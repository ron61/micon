const int LED_PIN = 11; 

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED_PIN, 255);
  delay(15);
  analogWrite(LED_PIN, 0);
  delay(15);
}

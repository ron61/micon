const int intPin = A0;
int v = 0;

void setup() {
  pinMode(intPin, INPUT);  // デジタルピン2を入力に設定
  Serial.begin(9600);  
}

void loop() {
  v = analogRead(intPin);
  Serial.println(v);
  delay(50);
  

}

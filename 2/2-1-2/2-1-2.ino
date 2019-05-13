const int intPin = A0;
const int LED = 11;
int v = 0;
int prev_v  = 0;

void setup() {
  pinMode(intPin, INPUT);  // デジタルピン2を入力に設定
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  prev_v = v;
  v = analogRead(intPin);
  if (abs(prev_v - v) > 50)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }
  
  // Serial.println(v);
  delay(50);
  

}

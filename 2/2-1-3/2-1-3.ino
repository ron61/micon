const int intPin = A0;
const int LED = 11;
int v = 0;
int prev_v  = 0;
int state = 0;

void setup() {
  pinMode(intPin, INPUT);  // デジタルピン2を入力に設定
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  prev_v = v;
  v = analogRead(intPin);
  
  if (abs(prev_v - v) > 100)
  {
    state = 1 - state;
  }

  if(state)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  
  // Serial.println(v);
  delay(50);
  

}

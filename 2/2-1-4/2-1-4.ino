const int intPin = A0;
const int LED = 11;
int v = 0;
int prev_v  = 0;
int count = 0;
int blightness = 0;

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
    count ++;
    delay(100);
  }
  
  blightness = (count % 9) * 32 - 1;

  analogWrite(LED, blightness);

  Serial.println(count);
  Serial.println(blightness);
  delay(50);
}

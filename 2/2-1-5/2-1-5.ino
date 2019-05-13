const int intPin = A0;
const int LED = 11;
int v = 0;
int prev_v  = 0;
int count = 0;
int blightness = 0;
int t, prev_time;
int t_start,t_end;
int isCounting;

void setup() {
  pinMode(intPin, INPUT);  // デジタルピン2を入力に設定
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  
  t = 0;
  prev_time = 0;
  t_start = 0;
  t_end = 0;
  isCounting = 0;
}

void loop() {
  prev_time = t;
  prev_v = v;
  v = analogRead(intPin);

  if (abs(prev_v - v) > 100 && isCounting == 0)
  {
    isCounting = 1;
    t_start = micros();
    delayMicroseconds(1000);
  }
  else if(abs(prev_v - v) < 100 && isCounting == 1)
  {
    isCounting = 0;
    t_end = micros();
    t = t_end - t_start;
  }

  if (t != prev_time)
  {
    Serial.println(t);
    Serial.println("");
    delayMicroseconds(1000);
  }

}

const int intPin = A0;
const int LED = 11;
int v = 0;
int prev_v = 0;
int data = -1;

void setup() {
  // put your setup code here, to run once:
  pinMode(intPin, INPUT_PULLUP);  // デジタルピン2を入力に設定
  pinMode(LED, OUTPUT);  // デジタルピン2を入力に設定
  Serial.begin(9600);
}

void loop() {
  prev_v = v;
  // put your main code here, to run repeatedly:
  v = analogRead(intPin);
  //  Serial.println(v);

  delay(100);

  data = Serial.read();
  data -= 0x30;
  // Serial.println(data);
  
  if(data == 1)
  {
    digitalWrite(LED, HIGH);
  }
  else if(data == 0)
  {
    digitalWrite(LED, LOW);
  }

  if(v - prev_v > 10)
  {
    Serial.println("On");
  }
  else if(v - prev_v < -10)
  {
    Serial.println("Off");
  }

}

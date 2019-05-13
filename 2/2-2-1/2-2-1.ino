const int intPin = A0;
int v = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(intPin, INPUT_PULLUP);  // デジタルピン2を入力に設定
  Serial.begin(9600);  

}

void loop() {
  // put your main code here, to run repeatedly:
  v = analogRead(intPin);
  Serial.println(v);
  delay(100);
}

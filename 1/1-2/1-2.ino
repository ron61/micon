const int PIN = 11; 

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PIN, 255);
  // 440Hz
  // 周期：2272 micro sec
  delayMicroseconds(1136);
  analogWrite(PIN, 0);
  delayMicroseconds(1136);
}

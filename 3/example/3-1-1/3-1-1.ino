// シリアル通信プログラム(Arduino側)
// 5V-タクトスイッチ--プルダウン抵抗-GNDの順に接続
//                  |
//           デジタル入力ピン2(割り込み用ピン)

const int intPin = 2;  // 割り込みとしてデジタルピン2を使用
const int ledPin =  13;  // オンボードLEDのデジタルピン番号
volatile int state = LOW;         // タクトスイッチの状態変数

void setup() {
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);  // デジタルピン13を出力に設定
  pinMode(intPin, INPUT);  // デジタルピン2を入力に設定
  attachInterrupt(digitalPinToInterrupt(intPin), blink, CHANGE);  // 割り込み設定
}

void loop() {
  char  buf;
  // ProcessingからArduinoへの通信
  if(Serial.available()>0){
    buf = Serial.read();
    if(buf == 1)  digitalWrite(ledPin, HIGH);
    if(buf == 0)  digitalWrite(ledPin, LOW);
  }
  // ディレイ
  delay(17);
}

void blink() {
  // ArduinoからProcessingへの通信
  state = digitalRead(intPin);  // 1 or 0
  Serial.write(state);       // 値を送信
}

// シリアル通信プログラム
// 5V-タクトスイッチ--プルダウン抵抗-GNDの順に接続
//                  |
//           デジタル入力ピン2

const int buttonPin = 2;  // タクトスイッチのデジタルピン番号
int state = LOW;         // タクトスイッチの状態変数

void setup() {
  Serial.begin(9600);  
  pinMode(buttonPin, INPUT);  // デジタルピン2を入力に設定
}

void loop() {
  char  buf;
  // ArduinoからPCへの通信
  state = digitalRead(buttonPin);
  Serial.println(state);       // シリアルモニタに出力
  // ディレイ
  delay(500);
}

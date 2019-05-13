// オンボードLEDのON/OFFプログラム（タクトスイッチによる外部割込み）
// 5V-タクトスイッチ--プルダウン抵抗-GNDの順に接続
//                  |
//           デジタル入力ピン2(割り込み用ピン)

const int intPin = 2;  // 割り込みとしてデジタルピン2を使用
const int ledPin =  13;  // オンボードLEDのデジタルピン番号を指定
volatile int state = LOW;         // タクトスイッチの状態変数

void setup() {
  pinMode(ledPin, OUTPUT);  // デジタルピン13を出力に設定
  pinMode(intPin, INPUT);  // デジタルピン2を入力に設定
  attachInterrupt(digitalPinToInterrupt(intPin), blink, RISING);  // 割り込み設定
}

void loop() {
  
}

void blink() {
   state = !state;  // 状態反転
   digitalWrite(ledPin, state);
}

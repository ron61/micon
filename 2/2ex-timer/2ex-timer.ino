// オンボードLEDのON/OFFプログラム（タイマ割込み）

#include <MsTimer2.h>            // タイマー割り込み用ヘッダファイル
const int ledPin =  13;  // オンボードLEDのデジタルピン番号

void setup() {
  pinMode(ledPin, OUTPUT);           // デジタルピン13を出力に設定
  MsTimer2::set(1000, blink);     // 1000ms毎にblink( )割込み関数を呼び出し
  MsTimer2::start();             // タイマー割り込み開始
}

void loop() {
}

void blink() {
  static int state = HIGH;
  digitalWrite(ledPin, state);
  state = !state;              // 状態反転
}

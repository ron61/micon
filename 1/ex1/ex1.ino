// オンボードLEDの点滅プログラム

#define LED_PIN 13

void setup() {
  // put your setup code here, to run once:
    pinMode (LED_PIN, OUTPUT);  // デジタルピン13を出力に設定
}
 
void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite (LED_PIN, HIGH);  // LED点灯
    delay (100);                // 1秒(1000ミリ秒)待機
    digitalWrite (LED_PIN, LOW);  // LED消灯
    delay (100);                // 1秒(1000ミリ秒)待機
}

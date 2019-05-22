const int SOUND_PIN = 11;
const int LED = 13;
int recv_data,r;

void setup() {
  // put your setup code here, to run once:
  pinMode(SOUND_PIN, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() >= 3) {
    if (Serial.read() == 'H') {
      byte high = Serial.read();
      byte low  = Serial.read();
      recv_data = high * 256 + low;  // 受信データ
      digitalWrite(LED,HIGH);

    }
  }
  if(recv_data > 0) playScale(recv_data);

  /*
  Serial.write('H');           // ヘッダの送信
  Serial.write(highByte(recv_data)); // 上位バイトの送信
  Serial.write(lowByte(recv_data));  // 下位バイトの送信
  */

}


void playScale(int n) {
  // ド 3831
  if(n == 1){
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(1915);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(1915);
  }
  // レ 3412
  if(n == 2){
    
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(1706);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(1706);
  }
  if(n ==3){
  // ミ 3039
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(1519);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(1519);
  }
  if(n == 4){
  // ファ 2865
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(1432);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(1432);
  }
  if(n==5){
  // ソ 2557
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(1279);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(1279);
  }
  if(n==6){
  // ラ 2272
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(1136);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(1136);
  }
  // シ 2028
  if(n == 7){
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(1014);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(1014);
  }
  if(n==8){
  // ド 1912
    analogWrite(SOUND_PIN, 255);
    delayMicroseconds(956);
    analogWrite(SOUND_PIN, 0);
    delayMicroseconds(956);
  }
}

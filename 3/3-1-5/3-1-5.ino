const int BUTTON = 2;
const int led = 13;

int val = 0;
int prev_val = 0;
int state;
int t_now,t_start,t_1,t_2,t_total;
int count = 0;


void setup() {
  Serial.begin(9600);    
  pinMode(BUTTON, INPUT);
  state = 0;
  t_now = 0;
}

void loop() {
  val = digitalRead(BUTTON);

  if(count == 0 && val == 1 && prev_val == 0)
  {
    t_start = millis();
    count = 1;
  }
  else if(count == 1 && val == 1 && prev_val == 0)
  {
    t_1 = millis() - t_start;
    // t_1を送信
    Serial.write('A');             // ヘッダの送信
    Serial.write(highByte(t_1)); // 上位バイトの送信
    Serial.write(lowByte(t_1));  // 下位バイトの送信
    count = 0;
  }
  else if(count == 2 && val == 1 && prev_val == 0)
  {
    t_total = millis() - t_start;
    t_2 = millis() - t_1;

    // t_totalを送信
    Serial.write('B');             // ヘッダの送信
    Serial.write(highByte(t_total)); // 上位バイトの送信
    Serial.write(lowByte(t_total));  // 下位バイトの送信
    // t_2を送信
    Serial.write('C');             // ヘッダの送信
    Serial.write(highByte(t_2)); // 上位バイトの送信
    Serial.write(lowByte(t_2));  // 下位バイトの送信

    t_now = 0;
    count = 0;
  }

  if(count > 0) 
  {
    digitalWrite(led,HIGH);
    t_now = millis() - t_start;
    Serial.write('H');             // ヘッダの送信
    Serial.write(highByte(t)); // 上位バイトの送信
    Serial.write(lowByte(t));  // 下位バイトの送信
  }
  else
  {
    digitalWrite(led,LOW);
  }

  prev_val = val;
  delay(50);

}

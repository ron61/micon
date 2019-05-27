const int BUTTON = 2;
const int led = 13;

int val = 0;
int prev_val = 0;
int t_now,t_start,t_1,t_2,t_total;
int count = 0;

void sendToProcessing(int i,int t) {
  switch (i)
  {
  case 0:
    Serial.write('H');           // ヘッダの送信
    Serial.write(highByte(t)); // 上位バイトの送信
    Serial.write(lowByte(t));  // 下位バイトの送信
    break;
  
  case 1:
    Serial.write('H');           // ヘッダの送信
    Serial.write(highByte(65530)); // 上位バイトの送信
    Serial.write(lowByte(65530));  // 下位バイトの送信
    Serial.write('H');           // ヘッダの送信
    Serial.write(highByte(t)); // 上位バイトの送信
    Serial.write(lowByte(t));  // 下位バイトの送信
    break;

  case 2:
    Serial.write('H');           // ヘッダの送信
    Serial.write(highByte(65531)); // 上位バイトの送信
    Serial.write(lowByte(65531));  // 下位バイトの送信
    Serial.write('H');           // ヘッダの送信
    Serial.write(highByte(t)); // 上位バイトの送信
    Serial.write(lowByte(t));  // 下位バイトの送信
    break;

  case 3:
    Serial.write('H');           // ヘッダの送信
    Serial.write(highByte(65532)); // 上位バイトの送信
    Serial.write(lowByte(65532));  // 下位バイトの送信
    Serial.write('H');           // ヘッダの送信
    Serial.write(highByte(t)); // 上位バイトの送信
    Serial.write(lowByte(t));  // 下位バイトの送信
    break;
  }
}
 
void setup() {
  Serial.begin(9600);    
  pinMode(BUTTON, INPUT);
  pinMode(led,OUTPUT);
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
    sendToProcessing(1,t_1);
    count = 2;
  }
  else if(count == 2 && val == 1 && prev_val == 0)
  {
    t_total = millis() - t_start;
    t_2 = t_total - t_1;

    // t_2を送信
    sendToProcessing(2,t_2);

    // t_totalを送信
    sendToProcessing(3,t_total);

    t_now = 0;
    count = 0;
  }

  if(count > 0) 
  {
    t_now = millis() - t_start;
    sendToProcessing(0,t_now);
  }

  /*
  switch (count)
  {
  case 0:
    digitalWrite(led,LOW);
    break;

  case 1:
    digitalWrite(led,HIGH);
    break;

  case 2:
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
    break;
  }
  */

  prev_val = val;
  delay(50);
  
}

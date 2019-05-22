const int BUTTON = 2;
const int led = 13;

int val = 0;
int prev_val = 0;
int state;
int t,t_start,t_end;
int isCounting = 0;


void setup() {
  Serial.begin(9600);    
  pinMode(BUTTON, INPUT);
  state = 0;
  t = 0;
}

void loop() {
  val = digitalRead(BUTTON);

  if(isCounting == 0 && val == 1 && prev_val == 0)
  {
    t_start = millis();
    isCounting = 1;
  }
  else if(isCounting == 1 && val == 1 && prev_val == 0)
  {
    t = millis() - t_start;
    isCounting = 0;
  }

  if(isCounting) 
  {
    digitalWrite(led,HIGH);
    t = millis() - t_start;
    Serial.write('H');             // ヘッダの送信
    Serial.write(highByte(t)); // 上位バイトの送信
    Serial.write(lowByte(t));  // 下位バイトの送信
  }
  else
  {
    digitalWrite(led,LOW);
  }

  prev_val = val;

}

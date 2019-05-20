const int BUTTON = 2;
const int led = 13;

int val = 0;
int prev_val = 0;
int state;
int isCounting;
int t,t_start,now;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600); 
  state = 0;
  isCounting = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);


  if(isCounting == 0 && val == 1 && prev_val == 0)
  {
    t_start = millis();
    isCounting = 1;
    digitalWrite(led,LOW);
  }
  else if(isCounting == 1 && val == 1 && prev_val == 0)
  {
    t = millis() - t_start;
    if(abs(t-5000) < 1000) digitalWrite(led,HIGH);
    isCounting = 0;
  }

  now = millis() - t_start;
  Serial.println(now);
  // Serial.println(isCounting);
  

  prev_val = val;
  delay(50);

}

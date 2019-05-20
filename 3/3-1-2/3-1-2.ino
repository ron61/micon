const int BUTTON = 2;
const int led = 13;

int val = 0;
int prev_val = 0;
int state;
int isCounting;
int t,t_start,t_end;


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


  if(state == 0 && val == 1 && prev_val == 0)
  {
    t_start = millis();
  }
  else if(state == 0 && val == 1 && prev_val == 1)
  {
    t = millis() - t_start;
    Serial.println(t);
  }
  else if(val == 0 && prev_val == 1)
  {
    state = 1;
  }
  
  prev_val = val;

}

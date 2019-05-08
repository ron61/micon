const int LED = 11;
const int BUTTON = 7;

int val = 0;
int prev_val = 0;
int state;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600); 
  state = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);

  if (val == 1 && prev_val == 0)
  {
    state = 1- state;
    Serial.print("change"); 
  }

  if(state)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  
  prev_val = val;

}

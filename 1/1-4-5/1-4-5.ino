const int SOUND_PIN = 11;
const int BUTTON = 7;

int val = 0;
int prev_val = 0;
int state;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SOUND_PIN, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600); 
  state = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);

  if (val == 1 && prev_val == 0)
  {
    count += 1;
  }

  if(count > 8) count = 1;
  
  playScale(count);

  prev_val = val;
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

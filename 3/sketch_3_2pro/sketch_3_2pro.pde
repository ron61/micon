import processing.serial.*;
Serial port;
int prev,high,low,r;
int t_now,t_1,t_2,t_total = 0;
boolean one,two,three,four,five,six,seven,eight;

void setup(){
  size(512, 256);
  background(0);  noStroke();
  textSize(32);  textAlign(CENTER);

  println(Serial.list());
  port = new Serial(this,"/dev/tty.usbmodem143101", 9600);
}

void draw(){
    background(200);
    if (port.available() >= 3 && port.read() == 'H')
    {
        high = port.read();
        low = port.read();
        r = high*256 + low;
    }
    text(r, 300, 128);
    
}


void keyPressed() {
    if(key == '1') sendIntData(1);
    if(key == '2') sendIntData(2);
    if(key == '3') sendIntData(3);
    if(key == '4') sendIntData(4);
    if(key == '5') sendIntData(5);
    if(key == '6') sendIntData(6);
    if(key == '7') sendIntData(7);
    if(key == '8') sendIntData(8);
}

void keyReleased() {
    if(key == '1') sendIntData(0);
    if(key == '2') sendIntData(0);
    if(key == '3') sendIntData(0);
    if(key == '4') sendIntData(0);
    if(key == '5') sendIntData(0);
    if(key == '6') sendIntData(0);
    if(key == '7') sendIntData(0);
    if(key == '8') sendIntData(0);
}

// intデータの送信
void sendIntData(int value) {
  int high = (byte)((value & 0xFF00) >> 8);
  int low =  (byte)( value & 0x00FF);
  port.write('H');  // ヘッダの送信
  port.write(high); // 上位バイトの送信
  port.write(low);  // 下位バイトの送信
}

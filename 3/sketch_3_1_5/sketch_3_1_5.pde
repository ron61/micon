import processing.serial.*;
Serial port;
int prev,high,low;
int t_now,t_1,t_2,t_total = 0;

void setup(){
  size(512, 256);
  background(200);  noStroke();
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
    t_now = high*256 + low;
  }
  
  if(prev == 65530) {
    t_1 = t_now;
  }
  else if(prev == 65531) {
    t_2 = t_now;
  }
  else if(prev == 65532) {
    t_total = t_now;
  }

  text("total: ",200,98);
  text(t_now, 300, 98);
  text("1    : ",200,128);
  text(t_1, 300, 128);
  text("2    : ",200,158);
  text(t_2, 300, 158);

  prev = t_now;

}

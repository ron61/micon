// シリアル通信プログラム(Processing側)
import processing.serial.*;  // シリアルライブラリの読み込み
Serial port;  // Serialクラスのオブジェクト

void setup(){
  size(512, 256);    // 画面サイズ
  background(200);  noStroke();
  textSize(32);  textAlign(CENTER);
  // シリアルポートの設定
  // Arduninoで使用しているCOMポートの番号に合わせること
  println(Serial.list());  // シリアルポートのリストを表示
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw(){
  int  buf = 0;
  // ArduinoからProcessingへの通信
  if(port.available()>0){
    buf = port.read();
    if(buf == 1)  fill(0);  // 黒指定
    else if(buf == 0)  fill(255);  // 白指定
    rect(0, 0, 256, 256);  // 画面左半分
  }
}

void mousePressed(){
  if(mouseX>256){
    port.write(1);       // 値を送信
    fill(200);  rect(256, 0, 256, 256);  // 画面右半分
    fill(255, 0, 0);
    text("LED ON", 384, 128);
  }
}

void mouseReleased(){
  if(mouseX>256){
    port.write(0);       // 値を送信
    fill(200);
    rect(256, 0, 256, 256);  // 画面右半分
    fill(0, 0, 255);
    text("LED OFF", 384, 128);
  }
}

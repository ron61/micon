// シリアル通信プログラム(Processing側)
import processing.serial.*;  // シリアルライブラリの読み込み
Serial port;  // Serialクラスのオブジェクト
int prev,t,high,low;

void setup(){
  size(512, 256);    // 画面サイズ
  background(200);  noStroke();
  textSize(32);  textAlign(CENTER);
  // シリアルポートの設定
  // Arduninoで使用しているCOMポートの番号に合わせること
  println(Serial.list());  // シリアルポートのリストを表示
  port = new Serial(this,"/dev/tty.usbmodem143101", 9600);
}

void draw(){
    background(200);


    if (port.available() >= 3)
    {
        if (port.read() == 'H')
        {
            high = port.read();   // 上位バイト読み込み
            low = port.read();    // 下位バイト読み込み
            t = high*256 + low;  // 上位・下位を合体させる
        }
    }
    
    text(t, 200, 128);
    
    prev = t;

}

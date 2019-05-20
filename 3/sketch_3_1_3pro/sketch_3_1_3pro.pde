int t,t_start;
int isCounting;

void setup(){
  size(512, 256);    // 画面サイズ
  background(200);  noStroke();
  textSize(32);  textAlign(CENTER);
  t = 0;
  t_start = 0;
  isCounting = 0;
}

void draw(){
    if(isCounting == 1)
    {
        background(200);
        t = millis() - t_start;
        text(t,384,128);
    }
}

void mousePressed(){
    if(isCounting == 0)
    {
        t_start = millis();
        isCounting = 1;
        return;
    }
    else if(isCounting == 1)
    {
        isCounting = 0;
    }
}

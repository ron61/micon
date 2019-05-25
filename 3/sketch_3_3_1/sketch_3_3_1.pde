int prev,high,low;
int t_now,t_1,t_2,t_total = 0;

void setup(){
  size(512, 256);
  background(200);  noStroke();
  textSize(32);  textAlign(CENTER);
}

void draw(){
    text("x: ",200,128);
    text("y: ",200,158);

}

void mousePressed() {
    background(200);
    text(mouseX, 300, 128);
    text("x: ",200,128);
    text(mouseY, 300, 158);
    text("y: ",200,158);
}

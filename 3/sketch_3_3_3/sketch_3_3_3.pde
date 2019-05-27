void setup(){
  size(512, 256);
  background(200);  noStroke();
  textSize(32);  textAlign(CENTER);
}

void draw(){
  background(200);
  ellipse(mouseX,mouseY,30,30);
}

void mouseDragged(){
  background(200);
  stroke(#3CFF03);
  ellipse(mouseX,mouseY,30,30);
}

void mouseReleased() {
  background(200);
  noStroke();
  ellipse(mouseX,mouseY,30,30);
}

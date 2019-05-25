int r,g,b = 0;

void setup(){
  size(512, 256);
  background(200);  noStroke();
  textSize(32);  textAlign(CENTER);
}

void draw(){
  //background(200);
  ellipse(mouseX,mouseY,30,30);
}

void mouseDragged(){
  //background(200);
  fill(r,g,b);
  ellipse(mouseX,mouseY,30,30);
}

void mouseReleased() {
  //background(200);
  fill(255);
  ellipse(mouseX,mouseY,30,30);
}

void keyPressed(){
  if(key == 'q') {
    r =  255;
    g = 3;
    b = 7;
  }
  if(key == 'w') {
    r = 0;
    g = 70;
    b = 255;
  }if(key == 'e') {
    r = 0;
    g = 255;
    b = 31;
  }
  if(key == 'r') {
    r = 255;
    g = 234;
    b = 0;
  }if(key == 't') {
    r = 250;
    g = 255;
    b = 250;
  }
}

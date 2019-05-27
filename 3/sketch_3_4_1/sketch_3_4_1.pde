float radius = 0;
int centx,centy;
float x,y;
float lastx = -999;
float lasty = -999;
int ang = 0;
boolean one,two,three,four,five,six,seven,eight,nine = false;

void setup(){
  size(500,500);
  background(200);
  strokeWeight(3);
  smooth();
  frameRate(500);
  centx = width / 2;
  centy = height / 2;
}

void draw(){
  
  if(ang <= 360 * 10){
    ang += 4;
    radius += 0.3;
    float rad = radians(ang);
    x = centx + (radius * cos(rad));
    y = centy + (radius * sin(rad));
    
    if(lastx > -999){
      stroke(#90A9FF);
      fill(255);
      arc(centx,centy,radius,radius,rad,rad+0.1);
    }
    
    for(float x = radius;x > 50;x -= 27){
      noFill();
      stroke(#90A9FF);
      arc(centx,centy,x-27,x-27,rad,rad+0.1);
    }
    
    lastx = x;
    lasty = y;
  }
}

void keyPressed() {
  if(key == '0') zero = true;
  if(key == '1') one = true;
  if(key == '2') two = true;
  if(key == '3') three = true;
  if(key == '4') four = true;
  if(key == '5') five = true;
  if(key == '6') six = true;
  if(key == '7') seven = true;
  if(key == '8') eight = true;
  if(key == '9') nine = true;
}

void keyReleased() {
  if(key == '0') zero = false;
  if(key == '1') one = false;
  if(key == '2') two = false;
  if(key == '3') three = false;
  if(key == '4') four = false;
  if(key == '5') five = false;
  if(key == '6') six = false;
  if(key == '7') seven = false;
  if(key == '8') eight = false;
  if(key == '9') nine = false;
}

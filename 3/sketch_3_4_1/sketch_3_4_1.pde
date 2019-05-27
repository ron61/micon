float radius = 0;
int centx,centy;
float x,y;
float lastx = -999;
float lasty = -999;
int ang = 0;

void setup(){
  size(500,500);
  background(200);
  strokeWeight(3);
  smooth();
  frameRate(50000);
  centx = width / 2;
  centy = height / 2;

}

void draw(){
  if(ang <= 3600){
    ang +=4;
    radius += 0.3;
    float rad = radians(ang);
    x = centx + (radius * cos(rad));
    y = centy + (radius * sin(rad));
    
    if(lastx > -999){
      stroke(#90A9FF);
      fill(255);
      arc(centx,centy,radius,radius,rad-0.1,rad);
    }

    for(float r = radius;r > 27;r -= 27) {
      stroke(#90A9FF);
      fill(255);
      arc(centx,centy,r,r,rad-0.1,rad);
    }
    
    lastx = x;
    lasty = y;
    
  }
}

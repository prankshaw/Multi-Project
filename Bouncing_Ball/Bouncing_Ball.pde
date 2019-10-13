float circleX;
float circleY;
float xspeed = 4;
float yspeed = 4;
float ellipseWidth = 50;
float ellipseHeight = 50;

void setup() {
  size(640, 360);
  surface.setResizable(true);

  circleX = random(width);
  circleY = random(height);
}

void draw() {
  background(50);
  noStroke();
  ellipse(circleX, circleY, ellipseWidth, ellipseHeight);

  circleX = circleX + xspeed;
  circleY = circleY + yspeed;

  if (circleX + ellipseWidth/2  > width || circleX - ellipseWidth/2 < 0) {
    fill(random(255), random(255), random(255));
    xspeed = -xspeed;
  }

  if (circleY + ellipseWidth/2  > height || circleY - ellipseWidth/2 < 0) {
    fill(random(255), random(255), random(255));
    yspeed = -yspeed;
  }
}

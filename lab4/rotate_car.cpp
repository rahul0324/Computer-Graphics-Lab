#include <GL/glut.h>
#include <stdio.h>
#include <math.h>


GLfloat angle = 0.0f;  // rotational angle of the shapes
int refreshMills = 1; // refresh interval in milliseconds


void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-500,500,-500,500.0);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}
void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x,y;

  dx = x2-x1;
  dy = y2-y1;

  if (dx < 0) dx = -dx;
  if (dy < 0) dy = -dy;
  incx = 1;
  if (x2 < x1) incx = -1;
  incy = 1;
  if (y2 < y1) incy = -1;
  x = x1; y = y1;
  if (dx > dy) {
    draw_pixel(x, y);
    e = 2 * dy-dx;
    inc1 = 2*(dy-dx);
    inc2 = 2*dy;
    for (i=0; i<dx; i++) {
      if (e >= 0) {
        y += incy;
        e += inc1;
      }
      else
        e += inc2;
      x += incx;
      draw_pixel(x, y);
    }

  } else {
    draw_pixel(x, y);
    e = 2*dx-dy;
    inc1 = 2*(dx-dy);
    inc2 = 2*dx;
    for (i=0; i<dy; i++) {
      if (e >= 0) {
        x += incx;
        e += inc1;
      }
      else
        e += inc2;
      y += incy;
      draw_pixel(x, y);
    }
  }
}


void Circle(int xCenter,int yCenter,int r){
 
  int x=0,y=r;
  int d = 3 - 2*r;    // = 1 - r
  while(x<=y){
    setPixel(xCenter+x,yCenter+y);
    setPixel(xCenter+y,yCenter+x);  //find other points by symmetry
    setPixel(xCenter-x,yCenter+y);
    setPixel(xCenter+y,yCenter-x);
    setPixel(xCenter-x,yCenter-y);
    setPixel(xCenter-y,yCenter-x);
    setPixel(xCenter+x,yCenter-y);
    setPixel(xCenter-y,yCenter+x);

    if (d<0)
      d += (4*x)+6;
    else {
      d += (4*(x-y))+10;
        y -= 1;
    }
    x++;
  }

  // glFlush();
}

void halfCircle(int xCenter,int yCenter,int r){
 
  int x=0,y=r;
  int d = 3 - 2*r;    // = 1 - r
  while(x<=y){
    setPixel(xCenter+x,yCenter+y);
    setPixel(xCenter+y,yCenter+x);  //find other points by symmetry
    setPixel(xCenter-x,yCenter+y);
    //setPixel(xCenter+y,yCenter-x);
    //setPixel(xCenter-x,yCenter-y);
    //setPixel(xCenter-y,yCenter-x);
    //setPixel(xCenter+x,yCenter-y);
    setPixel(xCenter-y,yCenter+x);

    if (d<0)
      d += (4*x)+6;
    else {
      d += (4*(x-y))+10;
        y -= 1;
    }
    x++;
  }

  // glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 0 , 0, 0);
    // glRotatef(angle,0.0f,0.0f,1.0f);
    Circle(-200,-300,100);
    Circle(-200,-300,25);
    Circle(200,-300,100);
    Circle(200,-300,25);
    halfCircle(-200,-300,110);
    halfCircle(200,-300,110);
    glPushMatrix();
    /*glRotatef(angle,0.0f,0.0f,1.0f);
    draw_line(0,0,100,400);
    draw_line(0,0,-100,-400);
    draw_line(100,400,0,0);
    draw_line(-100,-400,0,0);
    draw_line(69,285,69,285);
    draw_line(-69,-285,-69,-285);
    draw_line(69,285,-69,-285);
    draw_line(-69,-285,69,285);
    glEnd();*/
    glPopMatrix();
    draw_line(-500,500,-400,-400);
    draw_line(-200,200,150,150);
    draw_line(-90,90,-300,-300);
    draw_line(-450,-310,-300,-300);
    draw_line(450,310,-300,-300);
    draw_line(-200,-200,-20,150);//v
    draw_line(200,200,-20,150);//v
    draw_line(-450,-200,-20,-20);
    draw_line(450,200,-20,-20);
    draw_line(-450,-450,-300,-20);//v
    draw_line(450,450,-300,-20);//v
    glFlush();

    angle += 0.3f;

}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, Timer, 0);     // First timer call immediately
    glutMainLoop();
    return 0;
}
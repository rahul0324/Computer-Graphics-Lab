#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}

void Circle(){
 
  int xcntr = 500, ycntr = 500, r = 100;
  int x=0,y=r;
  int d = 3 - 2*r;    // = 1 - r
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 0 ,0, 0);
  while(x<=y){ 
    setPixel(xcntr + x,ycntr + y);
    setPixel(xcntr + y,ycntr + x);  //find other points by symmetry
    setPixel(xcntr - x,ycntr + y);
    setPixel(xcntr + y,ycntr - x);
    setPixel(xcntr - x,ycntr - y);
    setPixel(xcntr - y,ycntr - x);
    setPixel(xcntr + x,ycntr - y);
    setPixel(xcntr - y,ycntr + x);

    if (d<0)
  d += (4*x)+6;
    else {
 d += (4*(x-y))+10;
 y -= 1;
    }
    x++;
  }

  glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc(Circle);
    glutMainLoop();
    return 0;
}
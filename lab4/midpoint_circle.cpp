  #include<stdio.h>  
  #include<GL/glut.h>  
  #include<math.h>  
  int ww=400,wh=400;  
  int first=0;  
  int xi,yi,xf,yf;  
  void putpixel(int x,int y)  
  {  
       glBegin(GL_POINTS);  
       glVertex2i(x,y);  
       glEnd();  
       glFlush();  
  }  
  void MidPoint_circle(int r)  
  {  
       int x=0,y=r,p=1-r;  
       while(x<=y){  
             //Here Transform each x,y coordinates by 250 pixels   
            putpixel(250+x, 250+y);  
            putpixel(250+y, 250+x);  
            putpixel(250-x, 250+y);  
            putpixel(250-x, 250-y);  
            putpixel(250-y, 250+x);  
            putpixel(250-y, 250-x);  
            putpixel(250+y, 250-x);  
            putpixel(250+x, 250-y);  
            if(p<0)  
                 p=p+2*x+3;  
            else{  
                 p=p+2*(x-y)+5;  
                 y--;  
            }  
            x++;  
       }  
  }  
  void display()  
  {  
       glClearColor(0,0,0,0);  
       glColor3f(1,1,1);  
       glClear(GL_COLOR_BUFFER_BIT);
       MidPoint_circle(100);
       glutSwapBuffers();  
       glFlush();  
  }   
  void myinit()  
  {  
       glViewport(0,0,ww,wh);  
       glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();  
       gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);  
       glMatrixMode(GL_MODELVIEW);  
  }  
  int main(int argc,char** argv)  
  {  
       glutInit(&argc,argv);  
       glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(ww,wh);  
       glutCreateWindow("MidPoint-Circle");  
       glutDisplayFunc(display);  
       myinit();  
       glutMainLoop();  
       return 0;  
  }  
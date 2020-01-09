#include <GL/glut.h>  
 
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
 
   // Define shapes enclosed within a pair of glBegin and glEnd
   glBegin(GL_QUADS);              
      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex2f(-0.8f, 0.1f);     
      glVertex2f(-0.2f, 0.1f);     
      glVertex2f(-0.2f, 0.7f);
      glVertex2f(-0.8f, 0.7f);
 
      // glColor3f(0.0f, 1.0f, 0.0f); // Green
      // glVertex2f(-0.7f, -0.6f);
      // glVertex2f(-0.1f, -0.6f);
      // glVertex2f(-0.1f,  0.0f);
      // glVertex2f(-0.7f,  0.0f);
 
      // glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
      // glVertex2f(-0.9f, -0.7f);
      // glColor3f(1.0f, 1.0f, 1.0f); // White
      // glVertex2f(-0.5f, -0.7f);
      // glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
      // glVertex2f(-0.5f, -0.3f);
      // glColor3f(1.0f, 1.0f, 1.0f); // White
      // glVertex2f(-0.9f, -0.3f);
   glEnd();
 
   glBegin(GL_TRIANGLES);          
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f(0.1f, -0.6f);
      glVertex2f(0.7f, -0.6f);
      glVertex2f(0.4f, -0.1f);
 
      // glColor3f(1.0f, 0.0f, 0.0f); // Red
      // glVertex2f(0.3f, -0.4f);
      // glColor3f(0.0f, 1.0f, 0.0f); // Green
      // glVertex2f(0.9f, -0.4f);
      // glColor3f(0.0f, 0.0f, 1.0f); // Blue
      // glVertex2f(0.6f, -0.9f);
   glEnd();
 
   glBegin(GL_POLYGON);            // These vertices form a closed polygon
      glColor3f(1.0f, 1.0f, 0.0f); // Yellow
      glVertex2f(0.4f, 0.2f);
      glVertex2f(0.6f, 0.2f);
      glVertex2f(0.7f, 0.4f);
      glVertex2f(0.6f, 0.6f);
      glVertex2f(0.4f, 0.6f);
      glVertex2f(0.3f, 0.4f);
   glEnd();
 
   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Vertex, Primitive & Color");  
   glutInitWindowSize(320, 320);   
   glutInitWindowPosition(50, 50); 
   glutDisplayFunc(display);       
   initGL();                       
   glutMainLoop();                 
   return 0;
}
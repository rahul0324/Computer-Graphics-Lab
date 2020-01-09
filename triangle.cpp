//#include <GLUT/glut.h>
#include <GL/glut.h>

void display() {

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1); 
    glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(1, 1, 1); 
    glVertex3f(0.6, -0.75, 0);
    glColor3f(1, 1, 1); 
    glVertex3f(0, 0.75, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-1, 1, 0);
    // glColor3f(1, 1, 1);
    glVertex3f(1, 1, 0);
    // glColor3f(1, 1, 1);
    glVertex3f(1, -1, 0);
    // glColor3f(1, 1, 1);
    glVertex3f(-1, -1, 0);
  glEnd();

  glFlush();
}

int main(int argc, char** argv) {


  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Position window at (80,80)-(480,380) and give it a title.
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 300);
  glutCreateWindow("A Simple Triangle");

  // Tell GLUT that whenever the main window needs to be repainted that it
  // should call the function display().
  glutDisplayFunc(display);

  // Tell GLUT to start reading and processing events.  This function
  // never returns; the program only exits when the user closes the main
  // window or kills the process.
  glutMainLoop();
}

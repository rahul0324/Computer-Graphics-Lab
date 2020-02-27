#include<stdio.h>
#include<GL/glut.h>

float x1,Y1,x2,y2;
float x1new,x2new,Y1new,y2new;
float xmin=-100;
float ymin=-100;
float xmax=100;
float ymax=100;
float xtop=0;
float ytop=150;
float xleft=-150;
float yleft=0;
float xright=150;
float yright=0;
float xbottom=-0;
float ybottom=-150;

int inside = 0;
int left =1;
int right=2;
int top = 8;
int bottom = 4;

void display()
{

    glBegin(GL_LINE_STRIP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmin,ymax);
        glVertex2f(xmax,ymax);
        glVertex2f(xmax,ymin);
        glVertex2f(xmin,ymin);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(xtop,ytop);
        glVertex2f(xright,yright);
        glVertex2f(xbottom,ybottom);
        glVertex2f(xleft,yleft);
        glVertex2f(xtop,ytop);
    glEnd();

    clipalgo(xtop,ytop,xright,yright);
    clipalgo(xright,yright,xbottom,ybottom);
    clipalgo(xbottom,ybottom,xleft,yleft);
    clipalgo(xleft,yleft,xtop,ytop);
    glFlush();
}

void display1(float x1new, float Y1new, float x2new, float y2new)
{
    

    glBegin(GL_LINES);

        glColor3f(0,1,0);
        glVertex2f(x1new,Y1new);
        glVertex2f(x2new,y2new);


        // glColor3f(1,0,0);
        // glVertex2f(x1new,Y1new);
        // glVertex2f(x2new,y2new);
    glEnd();

}

int detectquad(float x, float y)
{
    int code=inside;
    if(x<xmin)
        code|=left;
    if(y<ymin)
        code|=bottom;
    if(x>xmax)
        code|=right;
    if(y>ymax)
        code|=top;

    return code;
}

void clipalgo(float x1,float Y1,float x2,float y2)
{
    int code1=detectquad(x1,Y1);
    int code2=detectquad(x2,y2);
    //printf("%f %f %f %f\n",x1new,Y1new,x2new,y2new );
    while(1)
    {
        if((code1==0)&&(code2==0))
            break;
        else if(code1 & code2)
            break;
        else
        {
            int out;
            float x,y;

            if(code1!=0)
                out=code1;
            else
                out=code2;
            
            if(out & top)
            {
                y=ymax;
                x=x1 + (x2 - x1) * (ymax - Y1) / (y2 - Y1);
            }
            else if(out & bottom)
            {
                y=ymin;
                x=x1 + (x2 - x1) * (ymin - Y1) / (y2 - Y1);
            }
            else if(out & left)
            {
                x=xmin;
                y = Y1 + (y2 - Y1) * (xmin - x1) / (x2 - x1);
            }
            else if(out & right)
            {
                x=xmax;
                y = Y1 + (y2 - Y1) * (xmax - x1) / (x2 - x1);
            }

            if(out=code1)
            {
                x1new=x;
                Y1new=y;
                x2new=x2;
                y2new=y2;
                code1=detectquad(x1new,Y1new);
            }
            else
            {
                x2new=x;
                y2new=y;
                x1new=x1;
                Y1new=Y1;
                code2=detectquad(x2new,y2new);
            }
            
        }
        
    printf("%f %f %f %f\n",x1new,Y1new,x2new,y2new );
    }
    printf("%f %f %f %f\n",x1,Y1,x2,y2 );

    glBegin(GL_LINES);
        glColor3f(1,1,0);
        glVertex2f(x1new,Y1new);
        glVertex2f(x2new,y2new);
    glEnd();


}


void init(void)
{
    glClear ( GL_COLOR_BUFFER_BIT ) ;
    glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400,400,-400,400);
}

void main(int argc,char** argv)
{
    //printf("enter x1,Y1,x2,y2\n xmin=ymin=-100 xmax=ymax=100\n");
    //scanf("%f%f%f%f",&x1,&Y1,&x2,&y2);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cohen–Sutherland Algorithm");
    init ();
    //printf("%f %f %f %f\n",x1new,Y1new,x2new,y2new );
    glutDisplayFunc(display);
    glutMainLoop();
}
#include<stdio.h>
#include<GL/glut.h>

float x1,Y1,x2,y2;
float m;
float x1new,x2new,Y1new,y2new;
float xmax,xmin,ymax,ymin;
float xtop=0;
float ytop=100;
float xleft=-100;
float yleft=0;
float xright=100;
float yright=0;
float xbottom=-0;
float ybottom=-100;

int inside = 0;
int left =1;
int right=2;
int top = 8;
int bottom = 4;


void display()
{
    printf("dis:%f %f %f %f\n",x1new,Y1new,x2new,y2new );
    
    glBegin(GL_LINE_STRIP);
        glVertex2f(xtop,ytop);
        glVertex2f(xleft,yleft);
        glVertex2f(xbottom,ybottom);
        glVertex2f(xright,yright);
        glVertex2f(xtop,ytop);
    glEnd();

    printf("old:%f %f %f %f\n",x1,Y1,x2,y2);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2f(x1,Y1);
        glVertex2f(x2,y2);
    glEnd();

    glBegin(GL_LINES);

        glColor3f(0,1,0);
        glVertex2f(x1new,Y1new);
        glVertex2f(x2new,y2new);


        // glColor3f(1,0,0);
        // glVertex2f(x1new,Y1new);
        // glVertex2f(x2new,y2new);
    glEnd();

    glFlush();
}

int detectquad(float x, float y)
{
    int code=inside;
    if(y-x-100>0)
        code|=left;
    if(y+x+100<0)
        code|=bottom;
    if(y-x+100<0)
        code|=right;
    if(y+x-100)
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
                x=
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

    glutDisplayFunc(display);
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
    printf("enter x1,Y1,x2,y2\n xmin=ymin=-100 xmax=ymax=100\n");
    scanf("%f%f%f%f",&x1,&Y1,&x2,&y2);
    m=(y2-Y1)/(x2-x1);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cohen–Sutherland Algorithm");
    init ();
    clipalgo(x1,Y1,x2,y2);
    //printf("%f %f %f %f\n",x1new,Y1new,x2new,y2new );
    glutMainLoop();
}
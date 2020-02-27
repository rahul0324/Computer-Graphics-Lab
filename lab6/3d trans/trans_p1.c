#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

typedef float Matrix4 [4][4];

Matrix4 theMatrix;
GLfloat input[5][3]=
{
    {0,25,0},{-25,-25,25},{25,-25,25},{25,-25,-25},{-25,-25,-25}

};

float output[5][3];
float tx,ty,tz;
float sx,sy,sz;
float angle;

int choice,choiceRot;

void setIdentityM(Matrix4 m)
{
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        m[i][j]=(i==j);
}

void translate(int tx,int ty,int tz)
{

for(int i=0;i<8;i++)
{
output[i][0]=input[i][0]+tx;
output[i][1]=input[i][1]+ty;
output[i][2]=input[i][2]+tz;
}
}
void scale(int sx,int sy,int sz)
{
    theMatrix[0][0]=sx;
    theMatrix[1][1]=sy;
    theMatrix[2][2]=sz;
}
void RotateX(float angle) //Parallel to x
{

 angle = angle*3.142/180;
  theMatrix[1][1] = cos(angle);
 theMatrix[1][2] = -sin(angle);
 theMatrix[2][1] = sin(angle);
 theMatrix[2][2] = cos(angle);

}
void RotateY(float angle) //parallel to y
{

 angle = angle*3.14/180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][2] = -sin(angle);
 theMatrix[2][0] = sin(angle);
 theMatrix[2][2] = cos(angle);

}
void RotateZ(float angle) //parallel to z
{

 angle = angle*3.14/180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][1] = sin(angle);
 theMatrix[1][0] = -sin(angle);
 theMatrix[1][1] = cos(angle);

}

void ReflectX()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<3;j++)
        {   if(j==0)
            output[i][j]=-1*input[i][j];
            else
            output[i][j]=input[i][j];
        }
}

void ReflectY()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<3;j++)
        {   if(j==1)
            output[i][j]=-1*input[i][j];
            else
            output[i][j]=input[i][j];
        }
}

void ReflectZ()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<3;j++)
        {   if(j==2)
            output[i][j]=-1*input[i][j];
            else
            output[i][j]=input[i][j];
        }
}

void multiplyM()
{
for(int i=0;i<8;i++)
 {
    for(int j=0;j<3;j++)
    {
        output[i][j]=0;
        for(int k=0;k<3;k++)
        {
            output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];
            //printf("%f  ",output[i][j]+input[i][k]*theMatrix[k][j]);
        }
    }
}
}

void scalenew(int sx,int sy,int sz)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {   if(i==0)
            output[i][j]=input[i][j]*sx;
            if(i==1)
            output[i][j]=input[i][j]*sy;
            if(i==2)
            output[i][j]=input[i][j]*sz;
        }
    }
}


void Axes(void)
{
 glColor3f (0.0, 0.0, 0.0);               
 glBegin(GL_LINES);                       
 glVertex2s(-1000 ,0);
 glVertex2s( 1000 ,0);
 glEnd();
 glBegin(GL_LINES);                       
 glVertex2s(0 ,-1000);
 glVertex2s(0 , 1000);
 glEnd();
}

void draw2()
{
    glBegin(GL_TRIANGLES);           
      // Front
      glColor3f(1,0,0);
      glVertex3fv(input[0]);
      glVertex3fv(input[1]);
      glVertex3fv(input[2]);

      glColor3f(1,1,0);
      glVertex3fv(input[0]);
      glVertex3fv(input[2]);
      glVertex3fv(input[3]);

      glColor3f(0,1,0);
      glVertex3fv(input[0]);
      glVertex3fv(input[3]);
      glVertex3fv(input[4]);

      glColor3f(1,0,1);
      glVertex3fv(input[0]);
      glVertex3fv(input[4]);
      glVertex3fv(input[1]);
      
    //   glColor3f(1.0f, 0.0f, 0.0f);     // Red
    //   glVertex3f( 0.0f+sx, 1.0f+sy, 0.0f+sz);
    //   glVertex3f(-1.0f+sx, -1.0f+sy, 1.0f+sz);
    //   glVertex3f(1.0f+sx, -1.0f+sy, 1.0f+sz);
 
      // Right
    //   glColor3f(0.0f, 1.0f, 0.0f);     // Green
    //   glVertex3f(0.0f+sx, 1.0f+sy, 0.0f+sz);
    //   glVertex3f(1.0f+sx, -1.0f+sy, 1.0f+sz);
    //   glVertex3f(1.0f+sx, -1.0f+sy, -1.0f+sz);
 
    //   // Back
    //   glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    //   glVertex3f(0.0f+sx, 1.0f+sy, 0.0f+sz);
    //   glVertex3f(1.0f+sx, -1.0f+sy, -1.0f+sz);
    //   glVertex3f(-1.0f+sx, -1.0f+sy, -1.0f+sz);
 
    //   // Left
    //   glColor3f(1.0f,1.0f,0.0f);       // Yellow
    //   glVertex3f( 0.0f+sx, 1.0f+sy, 0.0f+sz);
    //   glVertex3f(-1.0f+sx,-1.0f+sy,-1.0f+sz);
    //   glVertex3f(-1.0f+sx,-1.0f+sy, 1.0f+sz);

   glEnd(); 
}

void draw1()
{glBegin(GL_TRIANGLES);           
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,1.0f,0.0f);       // Yellow
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd(); 
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0); //set backgrond color to white
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
Axes();
glColor3f(1.0,0.0,0.0);
draw1();
setIdentityM(theMatrix);
switch(choice)
{
case 1:
    draw2();
    break;
 case 2:{
     //scalenew(sx,sy,sz);
    scale(sx,sy,sz);
    multiplyM();
    break;}
 case 3:
        // ReflectX();
        // break;
    switch(choiceRot)
    {
        case 1:ReflectX();
                break;
        case 2:ReflectY();
                break;
        case 3:ReflectZ();
                break;
    }
    break;
}

draw2();
glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1362,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("3D TRANSFORMATIONS");
    init();
    printf("Enter your choice number:\n1.Translation\n2.Scaling\n3.Reflection\n=>");
    scanf("%d",&choice);
    switch (choice) {
    case 1:
        printf("\nEnter Tx,Ty &Tz: \n");
        scanf("%f%f%f",&sx,&sy,&sz);
        break;
    case 2:
        printf("\nEnter Sx,Sy & Sz: \n");
        scanf("%f%f%f",&sx,&sy,&sz);
        break;
    case 3:
        printf("axis:1.X-axis.2.Y-axis.3.Z-axis.\n");
        scanf("%d",&choiceRot);
        break;
    default:
        break;
    }
    glutDisplayFunc(display);
    glutMainLoop();
return 0;
}
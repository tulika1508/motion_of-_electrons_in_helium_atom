
//TULIKA CHATTERJEE
#include <GL/glut.h>
#include <math.h>
#define DEG2RAD 3.14159/180.0

double X, Y;
double Xc, Yc;

double X1=150.0,Y1=0.0,X2=-150.0,Y2=0.0;

int counter= 0;

void drawCircle()
{
    glBegin(GL_POLYGON);
    glVertex2d(Xc+X, Yc+Y);
    glVertex2d(Xc-X, Yc+Y);
    glVertex2d(Xc+X, Yc-Y);
    glVertex2d(Xc-X, Yc-Y);
    glVertex2d(Xc+Y, Yc+X);
    glVertex2d(Xc-Y, Yc+X);
    glVertex2d(Xc+Y, Yc-X);
    glVertex2d(Xc-Y, Yc-X);
    glEnd();
}

void bresenhamCircle(double xc, double yc, double R)
{
    Xc= xc; Yc= yc;
    X= 0.0; Y= R;
    double D= 3-(2*R);
    drawCircle();
    while(Y >= X)
    {
        X++;
        if(D > 0)
        {
            Y--;
            D+= 4*(X-Y)+10;
        }
        else
            D+= 4*X+6;
        drawCircle();
    }

}

void init()
{
    glClearColor(0.0, 0.3, 0.3,0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1.0, 0.0, 0.0);
    bresenhamCircle(0.0, 0.0, 40.0);
    glColor3f(1.0, 0.5, 0.0);
    bresenhamCircle(X1, Y1, 15.0);
    glColor3f(1.0, 0.5, 0.0);
    bresenhamCircle(X2, Y2, 15.0);
    glColor3f(1.0, 0.5, 0.0);
    
    glutSwapBuffers();
}

void animate()
{

    if(counter > 359)
        counter= 0;
    else
        counter+=2;

    X1= cos(counter*DEG2RAD)*180.0;
    Y1= sin(counter*DEG2RAD)*180.0;
    
    X2= cos((counter+180)*DEG2RAD)*180.0;
    Y2= sin((counter+180)*DEG2RAD)*180.0;
    

    glutPostRedisplay();
    glutTimerFunc(1000/24, animate, 0);
}
void animate2()
{

    if(counter > 359)
        counter= 0;
    else
        counter+=2;

    X1= cos(counter*DEG2RAD)*150.0;
    Y1= sin(counter*DEG2RAD)*150.0;
    
    X2= cos((counter+180)*DEG2RAD)*150.0;
    Y2= sin((counter+180)*DEG2RAD)*150.0;
    

    glutPostRedisplay();
    glutTimerFunc(1000/24, animate2, 0);
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Helium atom");
    glutDisplayFunc(display_callback);
    glutTimerFunc(0, animate, 0);
    glutTimerFunc(0, animate2, 0);
   
    init();
    glutMainLoop();
}

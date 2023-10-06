#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;
float _move = 0.0f;
void drawScene(){
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3d(1,0,0);
 glLoadIdentity(); //Reset the drawing perspective
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 //glTranslatef(_move, -.2f, 0.0f);
 glTranslatef(-0.4f, -.2f, 0.0f);
 glBegin(GL_POLYGON);
 glColor3f(0.0f, 0.0f, 1.0f);//Blue
 glVertex2f(0.0f, -0.5f);
 glVertex2f(0.8f, -0.5f);
 glVertex2f(0.8f, -0.7f);
 glVertex2f(-0.0f, -0.7f);
 glEnd();
 glPushMatrix();
 glBegin(GL_POLYGON);
 glColor3f(0.0f, 0.0f, 1.0f);//Blue
 glVertex2f(0.2f, -0.5f);
 glVertex2f(0.3f, -0.3f);
 glVertex2f(0.8f, -0.3f);
 glVertex2f(0.8f, -0.5f);
 glEnd();
 glPopMatrix();
 glPushMatrix();
 glRotatef(_move, 0.0f, 1.0f,0.2f);
 glTranslatef(-0.1, -0.9f, 0.0f);
 glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
 //glColor3f(0.5f, 1.5f, 0.0f);
 for(int i=0; i<200; i++)
 {
 glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
 float pi=3.1416;
 float A=(i*2*pi)/200;
 float r=0.085;
 float x = r * cos(A);
 float y = r * sin(A); glVertex2f(x,y );
 }
 glEnd();
 glPopMatrix();
 glPushMatrix();
 glRotatef(_move, 0.0f, 1.0f,0.2f);
 glTranslatef(0.2f, -0.9f, 0.0f);
 //glTranslatef(_move+0.3, -0.9f, 0.0f);
 glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
 //glColor3f(0.5f, 1.5f, 0.0f);
 for(int i=0; i<200; i++)
 {
glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
 float pi=3.1416;
 float A=(i*2*pi)/200;
 float r=0.085;
 float x = r * cos(A);
 float y = r * sin(A);
 glVertex2f(x,y );
 }
 glEnd();
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-0.4f, -.2f, 0.0f);
 //glTranslatef(_move, -.2f, 0.0f);
 glBegin(GL_POLYGON);
 glColor3f(0.0f, 0.0f, 0.0f);
 glVertex2f(0.3f, -0.5f);
 glVertex2f(0.4f, -0.33f);
 glVertex2f(0.5f, -0.33f);
 glVertex2f(0.5f, -0.5f);
 glEnd();

 glPopMatrix();
 glPushMatrix();
 glTranslatef(-0.1f, -0.9f, 0.0f);
 //glTranslatef(_move, -0.9f, 0.0f);
 glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
 //glColor3f(0.5f, 1.5f, 0.0f);
 for(int i=0; i<200; i++)
 {
 glColor3f(1.0,1.0,1.0);
 float pi=3.1416;
 float A=(i*2*pi)/200;
 float r=0.025;
 float x = r * cos(A);
 float y = r * sin(A);
 glVertex2f(x,y );
 }
 glEnd();
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0.2f, -0.9f, 0.0f);
 //glTranslatef(_move, -0.9f, 0.0f);
 glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
 //glColor3f(0.5f, 1.5f, 0.0f);
 for(int i=0; i<200; i++)
 {
 glColor3f(1.0,1.0,1.0);
 float pi=3.1416;
 float A=(i*2*pi)/200;
 float r=0.025;
 float x = r * cos(A);
 float y = r * sin(A);
 glVertex2f(x,y );
 }
 glEnd();
 glPopMatrix(); glutSwapBuffers();
}
void update(int value)
{
 _move += -.02;
 if(_move < -1.😎
 {
 _move=1;
 }
 glutPostRedisplay();
 glutTimerFunc(20, update, 0);
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(800, 800);
 glutCreateWindow("Mercedez-Benz");
 glutDisplayFunc(drawScene);
 gluOrtho2D(-2,2,-2,2);
 glutTimerFunc(20, update, 0); //Add a timer
 glutMainLoop();
 return 0;
}

#include <windows.h>
#include <GL/glut.h>
void display() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(3.0);

//1st Triangle
glBegin(GL_POLYGON);
glColor3ub(11,174,0);

glVertex2f(0.0f,80.0f);
glVertex2f(-20.0f,60.0f);
glVertex2f(20.0f,60.0f);

glEnd();

//2nd Triangle
glBegin(GL_POLYGON);
glColor3ub(11,174,0);

glVertex2f(0.0f,60.0f);
glVertex2f(-30.0f,40.0f);
glVertex2f(30.0f,40.0f);

glEnd();

//3rd Triangle
glBegin(GL_POLYGON);
glColor3ub(11,174,0);

glVertex2f(0.0f,40.0f);
glVertex2f(-40.0f,20.0f);
glVertex2f(40.0f,20.0f);

glEnd();

// Tree Perpendicular
glBegin(GL_POLYGON);
glColor3ub(162,131,22);

glVertex2f(-10.0f,20.0f);
glVertex2f(-10.0f,-60.0f);
glVertex2f(10.0f,-60.0f);
glVertex2f(10.0f,20.0f);
glEnd();


glFlush();
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutCreateWindow("Draw a tree");
glutInitWindowSize(320, 320);
gluOrtho2D(-120,120,-120,120);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

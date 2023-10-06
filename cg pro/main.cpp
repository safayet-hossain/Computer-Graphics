///Full project work
#include<windows.h>
#include <GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416
#include <iostream>
#include <mmsystem.h>
#include<stdio.h>
#include<conio.h>
#include <cstdio>
using namespace std;


float _tank = 0.0;


GLint i;


bool rainday = false;
float rain = 0.0;






void init() {

glClearColor(0.70, 0.10, 2.5, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0, 1300.0, 0.0, 1050.0);

}



void Idle()
{
    glutPostRedisplay();
}



///

void circle(GLdouble rad)                                        /// Circle function
{   int cl1=0;

    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}





void Rain(int value){
    int rn1=0;                                           ///Rain

if(rainday){

    rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1300; y%=1050;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(6, Rain, 0);

    glFlush();

    }
}








void playground()
{ int pg1=0;
//playground field 1

glBegin(GL_QUADS);
glColor3ub(99,91,91);
///upper side
glVertex2i(0,500);
glVertex2i(335,500);
glVertex2i(335,550);
glVertex2i(0,550);
glEnd();

///Lower playground
glBegin(GL_QUADS);
glColor3ub(5,179,20);
glVertex2i(0,250);
glVertex2i(300,250);
glVertex2i(330,500);
glVertex2i(0,500);
glEnd();



///center circle
    glBegin(GL_POLYGON);
    glColor3ub(181,181,181);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(148+cos(angle)*40,380+sin(angle)*20);
    }

    glEnd();


}







 ///Hospital                                                        ///Hospital
void hospital()
{
int hp=0;

    glPushMatrix();
    glTranslatef(-260, 0, 0);

    glBegin(GL_QUADS);
    glColor3ub(196,185,147);
    glVertex2i(1000,485);  //hospital
    glVertex2i(1120,485);
    glVertex2i(1120,550);
    glVertex2i(1000,550);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(202, 222, 209);
    glVertex2i(1000,550);                 //hospitalborder
    glVertex2i(1120,550);
    glVertex2i(1120,600);
    glVertex2i(1000,600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(00, 0, 0);       //cross-sign
    glVertex2i(1055,545);
    glVertex2i(1070,545);
    glVertex2i(1070,575);
    glVertex2i(1055,575);

    glVertex2i(1044,553);
    glVertex2i(1082,553);
    glVertex2i(1082,567);
    glVertex2i(1044,567);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(1045,530);
    glVertex2i(1045,485);
    glVertex2i(1080,485);
    glVertex2i(1080,530);

    glColor3ub(0, 0, 0);
    glVertex2i(1010,535);
    glVertex2i(1010,515);
    glVertex2i(1030,515);
    glVertex2i(1030,535);

    glColor3ub(0, 0, 0);
    glVertex2i(1110,515);
    glVertex2i(1110,535);
    glVertex2i(1090,535);
    glVertex2i(1090,515);
    glEnd();


    glPopMatrix();





}




 ///Tank                                                              ///Tank
void tank1()
{
int tk=0;
    //tank-start

    //tankbody1

    glPushMatrix();
    glTranslatef(30, 30, 0);

    glScalef(0.9, 0.9, 0);


   glBegin(GL_POLYGON);
    glColor3ub(50,56,6);
    glVertex2i(625,425);
    glVertex2i(635,425);
    glVertex2i(815,425);
    glVertex2i(825,425);
    glVertex2i(815,460);
    glVertex2i(635,460);

    glEnd();

    //tankbody2

    glBegin(GL_QUADS);
    glVertex2i(665,450);
    glVertex2i(775,450);
    glVertex2i(775,490);
    glVertex2i(665,490);
    //tankhead

    glColor3ub(34,36,34);
    glVertex2i(700,490);
    glVertex2i(740,490);
    glVertex2i(740,500);
    glVertex2i(700,500);

     //tankgun
     glColor3ub(34, 36, 34);
    glVertex2i(775,465);
    glVertex2i(855,470);
    glVertex2i(855,480);
    glVertex2i(775,485);

    glEnd();



    //tankbase

    glBegin(GL_POLYGON);
  glColor3ub(79,68,31);
  for(int i=180;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(725+cos(angle)*90,425+sin(angle)*35);
    }
    glEnd();

    //wheel-1

      glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(655+cos(angle)*10,415+sin(angle)*10);
    }
    glEnd();


//wheel-2
  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(790+cos(angle)*10,415+sin(angle)*10);

    }
    glEnd();

//whell3
      glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(683+cos(angle)*10,410+sin(angle)*10);

    }
    glEnd();


//wheel-4
  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(711+cos(angle)*10,405+sin(angle)*10);

    }

    glEnd();

    //wheel-5

  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(739+cos(angle)*10,405+sin(angle)*10);

    }

    glEnd();
    //whell-6

  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(767+cos(angle)*10,406+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();
            //tank-end

}








void goalbar()
{
 int gb=0;
    glColor3ub(250, 179, 0);
    glBegin(GL_POLYGON);

    glVertex2f(0.2,0.2);
    glVertex2f(0.6,0.2);
    glVertex2f(0.6,0.23);
    glVertex2f(0.2,0.23);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.2,0.0);
    glVertex2f(0.22,0.0);
    glVertex2f(0.22,0.2);
    glVertex2f(0.2,0.2);

    glEnd();

   glBegin(GL_POLYGON);

    glVertex2f(0.58,0.0);
    glVertex2f(0.6,0.0);
    glVertex2f(0.6,0.2);
    glVertex2f(0.58,0.2);

    glEnd();
}






void display() {

glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5.0);





///shafayet
hospital();
glPushMatrix();
    glTranslated(_tank, 0, 0);
tank1();
glPopMatrix();
playground();
goalbar();


glFlush();
}

void display2() {

glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5.0);



///shafayet
hospital();
glPushMatrix();
    glTranslated(_tank, 0, 0);
tank1();
glPopMatrix();
glPushMatrix();



///

glFlush();

}

void myKeyboard (unsigned char key, int x, int y)
{

  switch (key)
     {




    case 'z':
        _tank += 1.80;
    if (_tank > 1200)
    {
        _tank -= 1000;
    }
    break;

     case 'x':
        _tank -= 1.80;
    if (_tank < -1200)
    {
        _tank = 1000;
    }
     break;
    case 'n':
        rainday = false;
        break;


        case 27:
         exit(0);
        break;

    default:
    break;

    }

}



int main(int argc, char** argv) {
    cout << "Army Base Camp" << endl;
    cout << "Press f : To Forward Fly Helicopter" << endl << endl;
    cout << "Press g : To Backward Fly Helicopter" << endl << endl;
    cout << "Press h : To Stop Flying Helicopter" << endl << endl;
    cout << "Press d : To left Flying Helicopter" << endl << endl;
    cout << "Press s : To right Flying Helicopter" << endl << endl;
    cout << "Press w : To Forward Fly Helicopter2" << endl << endl;
    cout << "Press q : To Backward Fly Helicopter2" << endl << endl;
    cout << "Press e : To Stop Flying Helicopter2" << endl << endl;

    cout << "Click on mouse  left : To start sun rise and windmill rotation" << endl << endl;
    cout << "Click on mouse  right : To stop sun rise and windmill rotation and helicopter blade rotation" << endl << endl;
    cout << "push z contionusly to tank forward" << endl << endl;
    cout << "push x contionusly to tank backward" << endl << endl;
    cout << "Press b: rain" << endl << endl;
    cout << "Press n: To Stop rain" << endl << endl;
    cout << "Press k : night" << endl << endl;
    cout << "Press l : day" << endl << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (80, 80);
    glutCreateWindow ("Army Base Camp");
    glutDisplayFunc(display);

    glutKeyboardFunc(myKeyboard);





    init ();

glutMainLoop();
return 0;
}

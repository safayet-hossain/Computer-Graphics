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

//float run = 0.0;
float tri = 0.0;
bool onOff;
bool frd = false;
bool bck = false;

float _plane = 0.0;
float _boatOne = 0.0;
float _ship = 0.0;
float _heli2 = 0.0;
float _car = 0.0;
float _car2 = 0.0;
float _tank = 0.0;
float _heli = 0.0;

GLint i;
GLfloat sunSpin=0;
GLfloat ax=0,bx=0,cx=0,dx=0;
GLfloat spin = 0.0;
///

GLfloat spinHeli = 0.0;
float hc = 0.0;
GLfloat ax1=0,bx1=0,cx1=0,dx1=0;
bool frd1 = false;
bool bck1 = false;

GLfloat spinHeli2 = 0.0;
float hc2 = 0.0;
GLfloat ax2=0,bx2=0,cx2=0,dx2=0;
bool frd2 = false;
bool bck2 = false;

float _nt = 0.0;
bool night = false;

bool rainday = false;
float rain = 0.0;

///
float move0 = 0.0f;
float move1 = 0.0;
float move2 = 0.0;
float move3 = 0.0;
float move4 = 0.0;





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
{

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





void Rain(int value){                                            ///Rain

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





void Night(int value){                                    ///Night

    if(night){


        glClearColor(0.0,0.0,0.0,0.0);
        glutPostRedisplay();
        glutTimerFunc(5, Night, 0);
        glFlush();

    }
}






void base()                                         ///base
{
glBegin(GL_QUADS);
glColor3ub (0, 229, 204);
glVertex2i(300, 250);
glVertex2i(1300, 250);
glColor3ub (156, 120, 72);
glVertex2i(1300, 550);
glVertex2i(335, 550);
glEnd();

}






void river()                                    ///river

{

glBegin(GL_QUADS);
glColor3ub (158, 191, 247);

glVertex2i(0,10);
glVertex2i(1300,10);
glVertex2i(1300,430);
glVertex2i(0,430);


glEnd();

}







///Helicopter1


// Helicopter blade//
                                                               ///Helicopter1
void heliBlade()
{

    //Blade One
    glPushMatrix();
    glRotatef(spinHeli,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    //Blade Two
    glPushMatrix();
    glRotatef(spinHeli,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    //Blade Three
    glPushMatrix();
    glRotatef(spinHeli,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();


}
// heli
void helibackward(int value){


    if(bck1)
    {

        hc -= 3.2f;

        if (hc < -350)
        {
            hc = 1100;
        }

        glutPostRedisplay();
        glutTimerFunc(25, helibackward, 0);

    }
}


void heliforward(int value ) {


    if (frd1)
    {

        hc += 2.2f;

        if(hc > 1000)
        {

            hc -= 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, heliforward, 0);

    }

}

//heli
void update (int value)
{

    move0 -=0.01f;
    if(move0+1.966 < -1.0)
    {
        move0 = 1.0;
    }

    move1 += 1.5f;
    if (move1 > 1300)
    {
        move1 -= 1700;
    }


    move2 += 1.0f;

    if (move2 > 600)
    {

        move2 -= 1300;
    }

        move3 += 1.0f;

    if (move3 > 800)
    {

        move3 -= -1300;
    }

        move4 += 1.0f;
    if (move4 > 1000)
    {

        move4 -= -1300;
    }



    glutPostRedisplay();
    glutTimerFunc(25, update, 0);

}

void moveRightHeli(){

    spinHeli =  spinHeli +.1;
    ax1 = ax1 + .05;
    bx1 = bx1 + .08;
    cx1 = cx1 + .10;
    dx1 = dx1 + .15;

    if(cx1>1000){
        cx1 = -300;
    }
    if(bx1>1000){
            bx1= -400;

    }
    if(cx1>1000){
            cx1= -400;

    }
    if(dx1>1000){
            dx1= -500;

    }


    glutPostRedisplay();
}

void helicopter()
{


glPushMatrix();
glTranslatef(0.0, hc, 0.0);


    glBegin(GL_QUADS);      //Helicopter

    glColor3ub(50,56,6);        //base quad

    glVertex2i(1040,380);
    glVertex2i(1090,380);
    glVertex2i(1090,400);
    glVertex2i(1030,400);

    glVertex2i(1080,400);
    glVertex2i(1090,400);
    glVertex2i(1090,425);
    glVertex2i(1080,425);


    glVertex2i(1045,425);
    glVertex2i(1090,425);
    glVertex2i(1090,435);
    glVertex2i(1065,435);

    glColor3ub(128,166,163);     //Front

    glVertex2i(1030,400);
    glVertex2i(1080,400);
    glVertex2i(1080,425);
    glVertex2i(1045,425);


    glColor3ub(50,56,6);

    glVertex2i(1090,380);
    glVertex2i(1150,380);
    glVertex2i(1150,415);
    glVertex2i(1090,435);


    glColor3ub(128,166,163);      //Door

    glVertex2i(1088,385);
    glVertex2i(1115,385);
    glVertex2i(1115,420);
    glVertex2i(1088,420);

    glVertex2i(1122,395);       //Window
    glVertex2i(1132,395);
    glVertex2i(1132,410);
    glVertex2i(1122,410);

    glVertex2i(1137,395);       //Window
    glVertex2i(1147,395);
    glVertex2i(1147,410);
    glVertex2i(1137,410);



    glColor3ub(50,56,6);


    glVertex2i(1150,415);
    glVertex2i(1150,380);
    glVertex2i(1190,390);
    glVertex2i(1190,400);



    //////
    glColor3ub(50,56,6);      //Rear Blade

    glVertex2i(1188,390);
    glVertex2i(1198,390);
    glVertex2i(1208,420);
    glVertex2i(1190,420);

    glColor3ub(181,181,181);     //Top

    glVertex2i(1070,435);
    glVertex2i(1085,435);
    glVertex2i(1082,440);
    glVertex2i(1073,440);


    glVertex2i(1075,440);
    glVertex2i(1079,440);
    glVertex2i(1079,450);
    glVertex2i(1075,450);

    glEnd();

    ///
    //upper blades   //
    glPushMatrix();
    glTranslatef(1077,450,0);
    glRotatef(spinHeli,0,0,90);
    heliBlade();
    glPopMatrix();


    glBegin(GL_POLYGON);
    glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1077+cos(angle)*5,450+sin(angle)*5);
    }

    glEnd();



    glBegin(GL_QUADS);      //Landing Stand

    glColor3ub(99,96,96);

    glVertex2i(1065,365);       //1
    glVertex2i(1070,365);
    glVertex2i(1070,380);
    glVertex2i(1065,380);


    glVertex2i(1125,365);
    glVertex2i(1130,365);
    glVertex2i(1130,380);
    glVertex2i(1125,380);


    glVertex2i(1055,360);
    glVertex2i(1140,360);
    glVertex2i(1140,365);
    glVertex2i(1055,365);


    glVertex2i(1075,355);        //2
    glVertex2i(1080,355);
    glVertex2i(1080,380);
    glVertex2i(1075,380);


    glVertex2i(1135,355);
    glVertex2i(1140,355);
    glVertex2i(1140,380);
    glVertex2i(1135,380);


    glVertex2i(1065,350);
    glVertex2i(1150,350);
    glVertex2i(1150,355);
    glVertex2i(1065,355);


    glEnd();

glPopMatrix();

}






/// helicopter2
void helibackward2(int value){                                     /// helicopter2


    if(bck2)
    {

        hc2 -= 2.2f;

        if (hc2 < -150)
        {
            hc2 = 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, helibackward2, 0);

    }
}


void heliforward2(int value ) {


    if (frd2)
    {

        hc2 += 2.2f;

        if(hc2 > 1000)
        {

            hc2 -= -1100;
        }

        glutPostRedisplay();
        glutTimerFunc(25, heliforward2, 3);

    }

}


void update2 (int value)
{

    move0 -=0.01f;
    if(move0+1.966 < -1.0)
    {
        move0 = 1.0;
    }

    move1 += 1.5f;
    if (move1 > 1300)
    {
        move1 -= 1700;
    }


    move2 += 1.7f;

    if (move2 > 600)
    {

        move2 -= 300;
    }

        move3 += 1.0f;

    if (move3 > 800)
    {

        move3 -= -300;
    }

        move4 += 1.9f;

    if (move4 > 100)
    {

        move4 -= -1300;
    }






    glutPostRedisplay();
    glutTimerFunc(25, update2, 0);

}

void moveRightHeli2(){

    spinHeli2 =  spinHeli2 +.2;
    ax2 = ax2 + .05;
    bx2 = cx2 + .08;
    cx2 = bx2 + .20;
    dx2 = dx2 + .25;

    if(cx2>1000){
        cx2 = -300;
    }
    if(bx2>1000){
            bx2= 200;

    }
    if(cx2>1000){
            cx2= 300;

    }
    if(dx2>1000){
            dx2= 1100;

    }


    glutPostRedisplay();
}

void helicopter2()
{



    glBegin(GL_QUADS);              // Helipad
    glColor3ub(152, 154, 156);
    glVertex2i(1130,170);
    glVertex2i(1140,170);
    glVertex2i(1140,210);
    glVertex2i(1130,210);

    glVertex2i(1070,170);
    glVertex2i(1080,170);
    glVertex2i(1080,210);
    glVertex2i(1070,210);

    glVertex2i(1080,185);
    glVertex2i(1140,185);
    glVertex2i(1140,195);
    glVertex2i(1080,195);



    glEnd();

glPushMatrix();
glTranslatef(0.0, hc2, 0.0);


    glBegin(GL_QUADS);      //Helicopter

    glColor3ub(50,56,6);        //base quad

    glVertex2i(1040,180);
    glVertex2i(1090,180);
    glVertex2i(1090,200);
    glVertex2i(1030,200);

    glVertex2i(1080,200);
    glVertex2i(1090,200);
    glVertex2i(1090,225);
    glVertex2i(1080,225);


    glVertex2i(1045,225);
    glVertex2i(1090,225);
    glVertex2i(1090,235);
    glVertex2i(1065,235);

    glColor3ub(128,166,163);     //Front

    glVertex2i(1030,200);
    glVertex2i(1080,200);
    glVertex2i(1080,225);
    glVertex2i(1045,225);


    glColor3ub(50,56,6);

    glVertex2i(1090,180);
    glVertex2i(1150,180);
    glVertex2i(1150,215);
    glVertex2i(1090,235);


    glColor3ub(128,166,163);      //Door

    glVertex2i(1088,185);
    glVertex2i(1115,185);
    glVertex2i(1115,220);
    glVertex2i(1088,220);

    glVertex2i(1122,195);       //Window
    glVertex2i(1132,195);
    glVertex2i(1132,210);
    glVertex2i(1122,210);

    glVertex2i(1137,195);       //Window
    glVertex2i(1147,195);
    glVertex2i(1147,210);
    glVertex2i(1137,210);



    glColor3ub(50,56,6);


    glVertex2i(1150,215);
    glVertex2i(1150,180);
    glVertex2i(1190,190);
    glVertex2i(1190,200);



    //////
    glColor3ub(50,56,6);      //Rear Blade

    glVertex2i(1188,190);
    glVertex2i(1198,190);
    glVertex2i(1208,220);
    glVertex2i(1190,220);

    glColor3ub(181,181,181);     //Top

    glVertex2i(1070,235);
    glVertex2i(1085,235);
    glVertex2i(1082,240);
    glVertex2i(1073,240);


    glVertex2i(1075,240);
    glVertex2i(1079,240);
    glVertex2i(1079,250);
    glVertex2i(1075,250);

    glEnd();

    //
    //upper blades   //////////////
    glPushMatrix();
    glTranslatef(1077,250,0);
    glRotatef(spinHeli2,0,0,90);
    heliBlade();
    glPopMatrix();


    glBegin(GL_POLYGON);
    glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1077+cos(angle)*5,250+sin(angle)*5);
    }

    glEnd();



    glBegin(GL_QUADS);      //Landing Stand

    glColor3ub(99,96,96);

    glVertex2i(1065,165);       //1
    glVertex2i(1070,165);
    glVertex2i(1070,180);
    glVertex2i(1065,180);


    glVertex2i(1125,165);
    glVertex2i(1130,165);
    glVertex2i(1130,180);
    glVertex2i(1125,180);


    glVertex2i(1055,160);
    glVertex2i(1140,160);
    glVertex2i(1140,165);
    glVertex2i(1055,165);


    glVertex2i(1075,155);        //2
    glVertex2i(1080,155);
    glVertex2i(1080,180);
    glVertex2i(1075,180);


    glVertex2i(1135,155);
    glVertex2i(1140,155);
    glVertex2i(1140,180);
    glVertex2i(1135,180);


    glVertex2i(1065,150);
    glVertex2i(1150,150);
    glVertex2i(1150,155);
    glVertex2i(1065,155);


    glEnd();

glPopMatrix();

}

void helipad(){

//helipad
//
    glBegin(GL_POLYGON);            //helipad
    glColor3ub(0, 0, 0);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1100+cos(angle)*150,375+sin(angle)*30);

    }
    glEnd();

    glBegin(GL_QUADS);              // Helipad
    glColor3ub(152, 154, 156);
    glVertex2i(1130,370);
    glVertex2i(1140,370);
    glVertex2i(1140,410);
    glVertex2i(1130,410);

    glVertex2i(1070,370);
    glVertex2i(1080,370);
    glVertex2i(1080,410);
    glVertex2i(1070,410);

    glVertex2i(1080,385);
    glVertex2i(1140,385);
    glVertex2i(1140,395);
    glVertex2i(1080,395);



    glEnd();

}





                                                           ///plane
void drawPlane(void)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2i(40, 965);
    glVertex2i(90, 970);
    glVertex2i(90, 955);
    glVertex2i(20, 955);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,0);
    glVertex2i(90, 970);
    glVertex2i(90, 955);
    glVertex2i(100, 960);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 200);
    glVertex2i(45, 959);
    glVertex2i(60, 959);
    glVertex2i(15, 935);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 200);
    glVertex2i(70, 963);
    glVertex2i(55, 963);
    glVertex2i(45, 990);
    glEnd();

    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 200);
    glVertex2i(20, 957);
    glVertex2i(30, 959);
    glVertex2i(25, 980);
    glVertex2i(20, 980);
    glEnd();
}







void boat()                                           ///boat
{
    glPushMatrix();
glTranslatef(0.0, 0.0, 0.0);

 glBegin(GL_QUADS);   //gun boat lower part
glColor3ub (56,56,52);
glVertex2i(420,80);
glVertex2i(480,130);
glVertex2i(110,105);
glVertex2i(120,80);
glEnd();


glBegin(GL_QUADS);   //lower upper part
glColor3ub(132,132,130);
glVertex2i(130,105);
glVertex2i(327,117);
glVertex2i(320,140);
glVertex2i(135,125);
glEnd();

glBegin(GL_QUADS);    //middle upper part
glColor3ub(92,92,88);
glVertex2i(320,117);
glVertex2i(345,120);
glVertex2i(340,132);
glVertex2i(320,130);
glEnd();

glBegin(GL_QUADS);   //upper part
glColor3ub(69,69,68);
glVertex2i(160,160);
glVertex2i(270,130);
glVertex2i(250,160);
glVertex2i(165,120);
glEnd();

glBegin(GL_QUADS);   //bridge covering part
glColor3ub(69,69,68);
glVertex2i(180,150);
glVertex2i(250,145);
glVertex2i(250,180);
glVertex2i(185,170);
glEnd();


glBegin(GL_QUADS);    //gun
glColor3ub(54,54,54);
glVertex2i(257,150);
glVertex2i(310,170);
glVertex2i(305,175);
glVertex2i(253,155);
glEnd();



glPopMatrix();



}




                                                            ///windmill

// Windmill Stand
void WindmillStandDesign(){

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 55);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 55);
    glEnd();
}

//Windmill Blades
void WindmillBlade(){

    //Blade One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    //Blade Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    //Blade Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}


//Windmill Final Design
void Windmill(){

//Windmill Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    WindmillStandDesign();
    glPopMatrix();

    //Windmill Motor
    glColor3f(0.11, 0.23, 0.36);


    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    //Windmill rotation Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    WindmillBlade();
    glPopMatrix();


}

//Windmill
void WindmillOne(){

    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,-10,0);
    Windmill();
    glPopMatrix();

}

void WindmillTwo(){

    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();

}
void WindmillThree(){

    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,-90,0);
    Windmill();
    glPopMatrix();

}






                                                             /// Field
void field(){

    //Field
	glBegin(GL_POLYGON);
    glColor3ub(160,160,160);

	glVertex2i(0, 50);
	glVertex2i(0, 70);
	glVertex2i(1300, 70);
	glVertex2i(1300, 50);

	glEnd();


    //Shadow of the field
	glBegin(GL_POLYGON);
    glColor3ub(224,224,224);
	glVertex2i(0, 0);
	glVertex2i(0, 50);
	glVertex2i(1300, 50);
	glVertex2i(1300, 0);

	glEnd();


}


void playground()
{
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



void playground2()
{
//playground field 2

glBegin(GL_QUADS);
glColor3ub(5,179,20);
///upper side
glVertex2i(335,250);
glVertex2i(535,250);
glVertex2i(565,450);
glVertex2i(365,450);
glEnd();



///middle line
glBegin(GL_LINES);
glColor3ub(99,91,91);

glVertex2i(355,350);
glVertex2i(545,350);
glEnd();

///middle line
glBegin(GL_LINES);
glColor3ub(99,91,91);

glVertex2i(355,350);
glVertex2i(355,390);
glEnd();

glBegin(GL_LINES);
glColor3ub(99,91,91);
glVertex2i(545,350);
glVertex2i(545,390);
glEnd();

glBegin(GL_LINES);
glColor3ub(99,91,91);

glVertex2i(355,390);
glVertex2i(545,390);
glEnd();





}






                                                             ///Tilla Design


void TillaOneDesign(){
    int mh16=0;
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);

	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);

	glEnd();

}

void TillaTwoDesign(){

	glColor3f(0.1, 1.293, 0.0);

    /// Left Part
    glPushMatrix();
    glTranslatef(430,90,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,87,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,70,0);
    circle(30);
    glPopMatrix();

    ///Right Part
    glPushMatrix();
    glTranslatef(445,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,75,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,70,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,65,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,60,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,55,0);
    circle(20);
    glPopMatrix();



}

void TillaOne(){
    int mh26=0;
    glPushMatrix();
    glTranslatef(0,0,0);
    TillaOneDesign();
    glPopMatrix();

}
//Tilla Two design Two
void TillaTwo(){
    int mh27=0;
    glPushMatrix();
    glTranslatef(0,0,0);
    TillaTwoDesign();
    glPopMatrix();


}
//  Tilla Three design Two
void TillaThree(){
    int mh28=0;
    glPushMatrix();
    glTranslatef(400,0,0);
    TillaTwoDesign();
    glPopMatrix();


}
//Tilla Four design One
void TillaFour(){
    int mh29=0;
    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380,0,0);
    TillaOneDesign();
    glPopMatrix();


}








                                                                ///Tree design
void TreeDesignOne(){
    int mh20=0;

    glPushMatrix();
    glTranslatef(110,110,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(109, 70);
	glVertex2f(109, 90);
	glVertex2f(111, 90);
	glVertex2f(111, 70);

    glEnd();

}
void TreeDesignTwo(){
    int mh21=0;
    glPushMatrix();
    glTranslatef(130,130,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,125,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(129, 110);
	glVertex2f(129, 124);
	glVertex2f(131, 124);
	glVertex2f(131, 110);

    glEnd();
}

void TreeDesignThree(){
    int mh22=0;

    glBegin(GL_POLYGON);

	glVertex2f(125, 123);
	glVertex2f(133, 145);
	glVertex2f(141, 123);

	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(132, 110);
	glVertex2f(132, 124);
	glVertex2f(134, 124);
	glVertex2f(134, 110);

    glEnd();
}


///T1
void TreeOne(){
    int mh30=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    TreeDesignOne();
    glPopMatrix();
}





///T2
void TreeTwo(){
    int mh31=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540,0,0);
    TreeDesignOne();
    glPopMatrix();
}

///T3
void TreeThree(){
    int mh32=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    TreeDesignOne();
    glPopMatrix();
}
///T4
void TreeFour(){
    int mh33=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292,40,0);
    TreeDesignOne();
    glPopMatrix();
}

///T5
void TreeFive(){
    int mh34=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30,-20,0);
    TreeDesignTwo();
    glPopMatrix();
}

///T6
void TreeSix(){
    int mh35=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50,-10,0);
    TreeDesignTwo();
    glPopMatrix();
}
///T7
void TreeSeven(){
    int mh36=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322,0,0);
    TreeDesignTwo();
    glPopMatrix();
}

/// T8
void TreeEight(){
    int mh37=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350,-15,0);
    TreeDesignTwo();
    glPopMatrix();
}

///T9
void TreeNine(){
    int mh38=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760,-25,0);
    TreeDesignTwo();
    glPopMatrix();
}

///T10
void TreeTen(){
    int mh39=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90,-2,0);
    TreeDesignThree();
    glPopMatrix();
}

///T11
void TreeEleven(){
    int mh40=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125,0,0);
    TreeDesignThree();
    glPopMatrix();
}

///T12
void TreeTwelve(){
    int mh41=0;
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408,-22,0);
    TreeDesignThree();
    glPopMatrix();
}






//Field upper side tree
void tree()
{

    glLineWidth(2.0);

glBegin(GL_POLYGON);
glColor3ub(0.0f, 128.0f, 0.0f);


glVertex2f(-0.3f,0.0f);
glVertex2f(0.3f,0.0f);
glVertex2f(0.0f,0.3f);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(0.0f, 128.0f, 0.0f);


glVertex2f(-0.25f,-0.1f);
glVertex2f(0.25f,-0.1f);
glVertex2f(0.0f,0.25f);

glEnd();


glBegin(GL_POLYGON);
glColor3ub(0.0f, 128.0f, 0.0f);

glVertex2f(-0.05f,-0.5f);
glVertex2f(0.05f,-0.5f);
glVertex2f(0.05f,-0.1f);
glVertex2f(-0.05f,-0.1f);

glEnd();
}






 /// Sun Design                                                         /// Sun Design
void SunDesign(){

    glPushMatrix();
    glTranslatef(500,750,0);
    circle(35);
    glPopMatrix();

}
void MovingSunDesign(){

    glPushMatrix();
    glRotatef(-sunSpin, 0,0,-.139);
    SunDesign();
    glPopMatrix();

}

///Sun
void Sun(){

    glColor3f(1, 1, 0);
    glPushMatrix();
    MovingSunDesign();
    glPopMatrix();
}

/// Sun Move
void sunMove(){


    sunSpin = sunSpin + 0.0018;

}



void moveRight(){

    sunMove();

    spin = spin +.1;
    ax = ax + 11.05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }


    glutPostRedisplay();
}








///Road                                                        ///Road
void road(){

glBegin(GL_QUADS);

glColor3ub(0,0,0);
                   //road
glVertex2i(0,650);
glVertex2i(1300,650);
glVertex2i(1300,550);
glVertex2i(0,550);
glEnd();




}
void roadborder(){
glBegin(GL_QUADS);
glColor3ub(255,255,255);        //road border
glVertex2i(0,600);
glVertex2i(1300,600);
glVertex2i(1300,597);
glVertex2i(0,597);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);        //road border
glVertex2i(0,655);
glVertex2i(1300,655);
glVertex2i(1300,650);
glVertex2i(0,650);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);        //road border
glVertex2i(0,555);
glVertex2i(1300,555);
glVertex2i(1300,550);
glVertex2i(0,550);
glEnd();
}
///car
void car(void)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2i(95, 565);
    glVertex2i(185, 565);
    glVertex2i(180, 585);
    glVertex2i(100, 585);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2i(100, 585);
    glVertex2i(170, 585);
    glVertex2i(150, 595);
    glVertex2i(110, 595);

    glEnd();
    // wheel 1
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 115;
        float y = r * sin(A) + 565;
        glVertex2f(x, y);
    }

    glEnd();
    //wheel 2
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 165;
        float y = r * sin(A) + 565;
        glVertex2f(x, y);
    }

    glEnd();
}


void car2(void)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);
    glVertex2i(695, 625);
    glVertex2i(785, 625);
    glVertex2i(780, 645);
    glVertex2i(700, 645);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2i(710, 645);
    glVertex2i(780, 645);
    glVertex2i(770, 655);
    glVertex2i(730, 655);

    glEnd();
    // wheel 1
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 715;
        float y = r * sin(A) + 625;
        glVertex2f(x, y);
    }

    glEnd();
    //wheel 2
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 765;
        float y = r * sin(A) + 625;
        glVertex2f(x, y);
    }

    glEnd();
}













///watchtower                                                                 ///watchtower
void watchtower1()
{


glBegin(GL_QUADS);

glColor3ub(133,120,101);        //WatchTower 1

glVertex2i(340,570);
glVertex2i(340,565);      //base
glVertex2i(420,565);
glVertex2i(420,570);

glColor3ub(58,65,4);

glVertex2i(365,585);
glVertex2i(365,570);        //big quad
glVertex2i(395,570);
glVertex2i(395,585);

glColor3ub(58,65,4);     //border Right

glVertex2i(395,585);
glVertex2i(395,584);
glVertex2i(420,584);
glVertex2i(420,585);

glVertex2i(419,584);
glVertex2i(419,565);
glVertex2i(420,565);
glVertex2i(420,584);

glVertex2i(395,576);
glVertex2i(395,577);
glVertex2i(420,577);
glVertex2i(420,576);

glVertex2i(414,585);
glVertex2i(414,570);
glVertex2i(415,570);
glVertex2i(414,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);

glColor3ub(58,65,4);

glVertex2i(403,595);     //Big border
glVertex2i(403,570);
glVertex2i(406,570);
glVertex2i(406,595);

glVertex2i(392,595);
glVertex2i(392,585);
glVertex2i(395,585);
glVertex2i(395,595);

glColor3ub(58,65,4);     //border Left

glVertex2i(340,585);
glVertex2i(340,584);
glVertex2i(365,584);
glVertex2i(365,585);

glVertex2i(339,584);
glVertex2i(339,565);
glVertex2i(340,565);
glVertex2i(340,584);

glVertex2i(340,576);
glVertex2i(340,577);
glVertex2i(365,577);
glVertex2i(365,576);

glVertex2i(345,585);
glVertex2i(345,570);
glVertex2i(346,570);
glVertex2i(346,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);  //useless border

glColor3ub(58,65,4);

glVertex2i(354,595);
glVertex2i(354,570);   //big border
glVertex2i(357,570);
glVertex2i(357,595);

glVertex2i(365,595);
glVertex2i(365,585);
glVertex2i(369,585);
glVertex2i(369,595);
glEnd();

glBegin(GL_TRIANGLES);

glColor3ub(125,88,42);

glVertex2i(344,595);       //Triangle
glVertex2i(416,595);
glVertex2i(380,620);
glEnd();

glBegin(GL_QUADS);

glVertex2i(354,565);
glVertex2i(354,500);
glVertex2i(359,500);    //pillar
glVertex2i(359,565);

glVertex2i(401,565);
glVertex2i(401,500);
glVertex2i(406,500);
glVertex2i(406,565);
glEnd();

glBegin(GL_QUADS);      //Ladder

glColor3ub(0,0,0);

glVertex2i(375,565);
glVertex2i(375,500);
glVertex2i(377,500);
glVertex2i(377,565);

glVertex2i(385,565);
glVertex2i(385,500);
glVertex2i(387,500);
glVertex2i(387,565);

glVertex2i(377,562);
glVertex2i(377,561);
glVertex2i(385,561);
glVertex2i(385,562);

glVertex2i(377,557);
glVertex2i(377,556);
glVertex2i(385,556);
glVertex2i(385,557);

glVertex2i(377,552);
glVertex2i(377,551);
glVertex2i(385,551);
glVertex2i(385,552);

glVertex2i(377,547);
glVertex2i(377,546);
glVertex2i(385,546);
glVertex2i(385,547);

glVertex2i(377,542);
glVertex2i(377,541);
glVertex2i(385,541);
glVertex2i(385,542);

glVertex2i(377,537);
glVertex2i(377,536);
glVertex2i(385,536);
glVertex2i(385,537);

glVertex2i(377,532);
glVertex2i(377,531);
glVertex2i(385,532);
glVertex2i(385,531);

glVertex2i(377,527);
glVertex2i(377,526);
glVertex2i(385,526);
glVertex2i(385,527);

glVertex2i(377,522);
glVertex2i(377,521);
glVertex2i(385,521);
glVertex2i(385,522);

glVertex2i(377,517);
glVertex2i(377,516);
glVertex2i(385,516);
glVertex2i(385,517);

glVertex2i(377,512);
glVertex2i(377,511);
glVertex2i(385,511);
glVertex2i(385,512);

glVertex2i(377,507);
glVertex2i(377,506);
glVertex2i(385,506);
glVertex2i(385,507);

glVertex2i(377,502);
glVertex2i(377,501);
glVertex2i(385,501);
glVertex2i(385,502);


glEnd();
glPopMatrix();

}

void watchtower2()
{

glBegin(GL_QUADS);

glColor3ub(133,120,101);        //WatchTower 2

glVertex2i(1140,570);
glVertex2i(1140,565);      //base
glVertex2i(1220,565);
glVertex2i(1220,570);

glColor3ub(58,65,4);

glVertex2i(1165,585);
glVertex2i(1165,570);        //big quad
glVertex2i(1195,570);
glVertex2i(1195,585);

glColor3ub(58,65,4);     //border Right

glVertex2i(1195,585);
glVertex2i(1195,584);
glVertex2i(1220,584);
glVertex2i(1220,585);

glVertex2i(1219,584);
glVertex2i(1219,565);
glVertex2i(1220,565);
glVertex2i(1220,584);

glVertex2i(1195,576);
glVertex2i(1195,577);
glVertex2i(1220,577);
glVertex2i(1220,576);

glVertex2i(1214,585);
glVertex2i(1214,570);
glVertex2i(1215,570);
glVertex2i(1214,585);

glVertex2i(1214,585);
glVertex2i(1214,577);
glVertex2i(1215,577);
glVertex2i(1215,585);

glColor3ub(58,65,4);

glVertex2i(1203,595);     //Big border
glVertex2i(1203,570);
glVertex2i(1206,570);
glVertex2i(1206,595);

glVertex2i(1192,595);
glVertex2i(1192,585);
glVertex2i(1195,585);
glVertex2i(1195,595);

glColor3ub(58,65,4);     //border Left

glVertex2i(1140,585);
glVertex2i(1140,584);
glVertex2i(1165,584);
glVertex2i(1165,585);

glVertex2i(1139,584);
glVertex2i(1139,565);
glVertex2i(1140,565);
glVertex2i(1140,584);

glVertex2i(1140,576);
glVertex2i(1140,577);
glVertex2i(1165,577);
glVertex2i(1165,576);

glVertex2i(1145,585);
glVertex2i(1145,570);
glVertex2i(1146,570);
glVertex2i(1146,585);

glVertex2i(1214,585);
glVertex2i(1214,577);
glVertex2i(1215,577);
glVertex2i(1215,585);  //useless border

glColor3ub(58,65,4);

glVertex2i(1154,595);
glVertex2i(1154,570);   //big border
glVertex2i(1157,570);
glVertex2i(1157,595);

glVertex2i(1165,595);
glVertex2i(1165,585);
glVertex2i(1169,585);
glVertex2i(1169,595);

//Ladder
glColor3ub(0,0,0);

glVertex2i(1175,565);
glVertex2i(1175,500);
glVertex2i(1177,500);
glVertex2i(1177,565);

glVertex2i(1185,565);
glVertex2i(1185,500);
glVertex2i(1187,500);
glVertex2i(1187,565);

glVertex2i(1177,562);
glVertex2i(1177,561);
glVertex2i(1185,561);
glVertex2i(1185,562);

glVertex2i(1177,557);
glVertex2i(1177,556);
glVertex2i(1185,556);
glVertex2i(1185,557);

glVertex2i(1177,552);
glVertex2i(1177,551);
glVertex2i(1185,551);
glVertex2i(1185,552);

glVertex2i(1177,547);
glVertex2i(1177,546);
glVertex2i(1185,546);
glVertex2i(1185,547);

glVertex2i(1177,542);
glVertex2i(1177,541);
glVertex2i(1185,541);
glVertex2i(1185,542);

glVertex2i(1177,537);
glVertex2i(1177,536);
glVertex2i(1185,536);
glVertex2i(1185,537);

glVertex2i(1177,532);
glVertex2i(1177,531);
glVertex2i(1185,532);
glVertex2i(1185,531);

glVertex2i(1177,527);
glVertex2i(1177,526);
glVertex2i(1185,526);
glVertex2i(1185,527);

glVertex2i(1177,522);
glVertex2i(1177,521);
glVertex2i(1185,521);
glVertex2i(1185,522);

glVertex2i(1177,517);
glVertex2i(1177,516);
glVertex2i(1185,516);
glVertex2i(1185,517);

glVertex2i(1177,512);
glVertex2i(1177,511);
glVertex2i(1185,511);
glVertex2i(1185,512);

glVertex2i(1177,507);
glVertex2i(1177,506);
glVertex2i(1185,506);
glVertex2i(1185,507);

glVertex2i(1177,502);
glVertex2i(1177,501);
glVertex2i(1185,501);
glVertex2i(1185,502);
glEnd();

glBegin(GL_TRIANGLES);

glColor3ub(125,88,42);

glVertex2i(1144,595);       //Triangle
glVertex2i(1216,595);
glVertex2i(1180,620);
glEnd();

glBegin(GL_QUADS);

glVertex2i(1154,565);
glVertex2i(1154,500);
glVertex2i(1159,500);    //pillar
glVertex2i(1159,565);

glVertex2i(1201,565);
glVertex2i(1201,500);
glVertex2i(1206,500);
glVertex2i(1206,565);

glEnd();

}





 ///Hospital                                                        ///Hospital
void hospital()
{


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
    glColor3ub(232, 25, 12);       //cross-sign
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





  ///Tent                                                                ///Tent
void tent1()
{
     //Tent 1



glBegin(GL_TRIANGLES);
glColor3ub(85,89,67);
glVertex2i(710,480);
glVertex2i(660,565);
glVertex2i(610,480);
glEnd();

glBegin(GL_LINES);
glVertex2i(610,540);
glVertex2i(620,520);

glVertex2i(610,540);
glVertex2i(600,480);

glVertex2i(710,540);
glVertex2i(690,500);

glVertex2i(710,540);
glVertex2i(720,480);
glEnd();


glBegin(GL_QUADS);      //Tent 1 Door
glColor3ub(0,0,0);
glVertex2i(675,490);
glVertex2i(675,525);
glVertex2i(645,525);
glVertex2i(645,490);
glEnd();

}

void tent2()
{
 //tent2

glPushMatrix();
glTranslatef(160, 0, 0);



glBegin(GL_TRIANGLES);
glColor3ub(85,89,67);
glVertex2i(830,480);
glVertex2i(780,565);
glVertex2i(730,480);
glEnd();

glBegin(GL_LINES);
glVertex2i(830,540);
glVertex2i(810,500);

glVertex2i(830,540);
glVertex2i(840,480);

glVertex2i(730,540);
glVertex2i(750,500);

glVertex2i(730,540);
glVertex2i(720,480);
glEnd();



glBegin(GL_QUADS);          //Tent 2 Door
glColor3ub(0,0,0);
glVertex2i(795,490);
glVertex2i(795,525);
glVertex2i(765,525);
glVertex2i(765,490);
glEnd();

glPopMatrix();
}
void tent3()
{


glPushMatrix();
glTranslatef(160, 0, 0);

     //Tent 3



glBegin(GL_TRIANGLES);
glColor3ub(85,89,67);
glVertex2i(950,480);
glVertex2i(900,565);
glVertex2i(850,480);
glEnd();

glBegin(GL_LINES);
glVertex2i(950,540);
glVertex2i(940,520);

glVertex2i(950,540);
glVertex2i(960,480);

glVertex2i(850,540);
glVertex2i(860,520);

glVertex2i(850,540);
glVertex2i(840,480);
glEnd();


glBegin(GL_QUADS);      //Tent 3 Door
glColor3ub(0,0,0);
glVertex2i(915,490);
glVertex2i(915,525);
glVertex2i(885,525);
glVertex2i(885,490);
glEnd();



glPopMatrix();
}



void tent4()
{

    glPushMatrix();
    glTranslatef(-120, 0, 0);

     //Tent 4


glBegin(GL_TRIANGLES);
glColor3ub(85,89,67);
glVertex2i(710,480);
glVertex2i(660,565);
glVertex2i(610,480);
glEnd();

glBegin(GL_LINES);
glVertex2i(610,540);
glVertex2i(620,520);

glVertex2i(610,540);
glVertex2i(600,480);

glVertex2i(710,540);
glVertex2i(690,500);

glVertex2i(710,540);
glVertex2i(720,480);
glEnd();


glBegin(GL_QUADS);      //Tent 1 Door
glColor3ub(0,0,0);
glVertex2i(675,490);
glVertex2i(675,525);
glVertex2i(645,525);
glVertex2i(645,490);
glEnd();

glPopMatrix();

}





 ///Tank                                                              ///Tank
void tank1()
{

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






///Ship                                                                   ///Ship
void ship(){

 glBegin(GL_QUADS);
             //ship
    glColor3ub(152, 154, 156);//body
    glVertex2i(700,220);
    glVertex2i(1400,220);
    glVertex2i(1400,130);
    glVertex2i(700,130);

    glColor3ub(152, 154, 156);
    glVertex2i(700,130);
    glVertex2i(1400,130);
    glVertex2i(1400,100);
    glVertex2i(1000,100);

    glColor3ub(0, 0, 0);
    glVertex2i(700,130);
    glVertex2i(1400,130);
    glVertex2i(1400,125);
    glVertex2i(700,125);

    glVertex2i(700,220);
    glVertex2i(1400,210);
    glVertex2i(1400,205);
    glVertex2i(700,215);

    glColor3ub(152, 154, 156);//building
    glVertex2i(1200,240);
    glVertex2i(1400,240);
    glVertex2i(1400,220);
    glVertex2i(1200,220);
glEnd();

}






///Flag                                             ///Flag

void flag1()
{


    glPushMatrix();
    glScalef(0.8,0.8,0);
    glTranslatef(-20,200, 0);

     glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
     glVertex2i(494,560);      //flag-l
     glVertex2i(496,560);
     glVertex2i(496,600);
     glVertex2i(494,600);

     glColor3ub(7, 171, 15);
     glVertex2i(496,580);      //flag-green
     glVertex2i(530,580);
     glVertex2i(530,600);
     glVertex2i(496,600);




    glEnd();

  glBegin(GL_POLYGON);            //flag-cir
    glColor3ub(245, 25, 10);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(513+cos(angle)*7,590+sin(angle)*7);

    }
    glEnd();
   glPopMatrix();

}

void flag2()
{


    glPushMatrix();
    glScalef(0.8,0.8,0);
    glTranslatef(980,200, 0);

     glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
     glVertex2i(494,560);      //flag-l
     glVertex2i(496,560);
     glVertex2i(496,600);
     glVertex2i(494,600);

     glColor3ub(7, 171, 15);
     glVertex2i(496,580);      //flag-green
     glVertex2i(530,580);
     glVertex2i(530,600);
     glVertex2i(496,600);




    glEnd();

  glBegin(GL_POLYGON);            //flag-cir
    glColor3ub(245, 25, 10);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(513+cos(angle)*7,590+sin(angle)*7);

    }
    glEnd();
   glPopMatrix();

}










void goalbar()
{

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





///cloud


void cloud(){


    glPushMatrix();
    glTranslatef(move1, 0.0, 0.0);

    glBegin(GL_POLYGON);        //Cloud 1
    glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(600+cos(angle)*15,915+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(610+cos(angle)*15,925+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(620+cos(angle)*15,905+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(632+cos(angle)*15,930+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(645+cos(angle)*15,915+sin(angle)*10);
    }

    glEnd();
glPopMatrix();


glPushMatrix();
glTranslatef(move2, 0.0, 0.0);    //cloud-2

glBegin(GL_POLYGON);
glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(200+cos(angle)*15,915+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(210+cos(angle)*15,925+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(220+cos(angle)*15,905+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(232+cos(angle)*15,930+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(242+cos(angle)*15,915+sin(angle)*10);
    }

    glEnd();

    glPopMatrix();



    //cloud-3

glPushMatrix();
glTranslatef(move3, 0.0, 0.0);

glBegin(GL_POLYGON);
glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1100+cos(angle)*15,915+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1110+cos(angle)*15,925+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1120+cos(angle)*15,905+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1132+cos(angle)*15,930+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1142+cos(angle)*15,915+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();
//

    ////cloud-4
    glPushMatrix();
    glTranslatef(move4, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1100+cos(angle)*15,915+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1110+cos(angle)*15,925+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1120+cos(angle)*15,905+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1132+cos(angle)*15,930+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1142+cos(angle)*15,915+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();
//

//    // cloud-5
//
    glBegin(GL_POLYGON);
    glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(600+cos(angle)*15,915+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(610+cos(angle)*15,925+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(620+cos(angle)*15,905+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(632+cos(angle)*15,930+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(645+cos(angle)*15,915+sin(angle)*10);
    }

    glEnd();

glBegin(GL_POLYGON);
    glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(600+cos(angle)*15,915+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(610+cos(angle)*15,925+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(620+cos(angle)*15,905+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(632+cos(angle)*15,930+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(645+cos(angle)*15,915+sin(angle)*10);
    }

    glEnd();


}






void display() {

glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5.0);





///alif
river();

///alif

///abid
road();
roadborder();
Sun();
//car
glPushMatrix();
    glTranslated(_car, 0, 0);
    car();
    glPopMatrix();

    glPushMatrix();
    glTranslated(_car2, 0, 0);
    car2();
    glPopMatrix();
///

///chayon

   cloud();
 // plane with animation
    glPushMatrix();
    glTranslated(_plane, 0, 0);
    drawPlane();
    glPopMatrix();

base();

playground2();

helipad();
flag1();
flag2();
field();
playground();
glPushMatrix();
glScaled(200.0,130.0,0.0);
glTranslatef(0.5f,3.7f, 0.0f);

glPopMatrix();

glPushMatrix();
glScaled(200.0,130.0,0.0);
glTranslatef(0.4f,3.8f, 0.0f);
goalbar();
glPopMatrix();

glPushMatrix();
glScaled(200.0,130.0,0.0);
glTranslatef(0.3f,2.0f, 0.0f);
goalbar();
glPopMatrix();

///

///alif
tent1();
tent2();
tent3();
tent4();
watchtower1();
watchtower2();
///

///shafayet
glPushMatrix();
    glTranslated(_tank, 0, 0);
tank1();
glPopMatrix();
glPushMatrix();


glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(0.5f,11.0f, 0.0f);
tree();
glPopMatrix();


glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(1.0f,11.0f, 0.0f);
tree();
glPopMatrix();


glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(1.5f,11.0f, 0.0f);
tree();
glPopMatrix();

glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(2.0f,11.0f, 0.0f);
tree();
glPopMatrix();

glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(1.5f,11.0f, 0.0f);
tree();
glPopMatrix();

glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(2.5f,11.0f, 0.0f);
tree();
glPopMatrix();
///


///abid
glPushMatrix();
    glTranslated(_ship, 0, 0);
    glTranslated(_heli2, 0, 0);
ship();
helicopter2();
glPopMatrix();
glTranslated(_heli, 0, 0);
    helicopter();
    glPopMatrix();
hospital();

///abid

///alif
glPushMatrix();
    glTranslated(_boatOne, 0, 0);
    boat();
    glPopMatrix();


TreeOne();
TreeTwo();
TreeThree();
TreeFour();
TreeFive();
TreeSix();
TreeSeven();
TreeEight();
TreeNine();
TreeTen();
TreeEleven();
TreeTwelve();




TillaFour();
TillaOne();
TillaTwo();
TillaThree();


WindmillThree();
WindmillOne();
WindmillTwo();

///
glFlush();
}

void update3(int value)
{
    //plane move : Right
    _plane += 1.90;
    if (_plane > 1200)
    {
        _plane -= 1300;
    }
    // Boat one : Right
    _boatOne += 0.80;
    if (_boatOne > 1200)
    {
        _boatOne -= 1300;
    }


    _ship -= 0.80;
    if (_ship < -1200)
    {
        _ship = 900;
    }


    _heli2 -= 0.80;
    if (_heli2 < -1100)
    {
        _heli2 = 900;
    }

    _car += 1.80;
    if (_car > 1200)
    {
        _car -= 1000;
    }


    _car2 -= 1.80;
    if (_car2 < -1200)
    {
        _car2 = 600;
    }



    glutPostRedisplay();          // Update the GLUT
    glutTimerFunc (25, update3, 0); // Re-call it
}
void display2() {

glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5.0);


///alif
river();

///alif

///abid
road();
roadborder();
Sun();
//car
glPushMatrix();
    glTranslated(_car, 0, 0);
    car();
    glPopMatrix();

    glPushMatrix();
    glTranslated(_car2, 0, 0);
    car2();
    glPopMatrix();
///

///chayon

   cloud();
 // plane with animation
    glPushMatrix();
    glTranslated(_plane, 0, 0);
    drawPlane();
    glPopMatrix();

base();

playground2();

helipad();
flag1();
flag2();
field();
playground();
glPushMatrix();
glScaled(200.0,130.0,0.0);
glTranslatef(0.5f,3.7f, 0.0f);

glPopMatrix();

glPushMatrix();
glScaled(200.0,130.0,0.0);
glTranslatef(0.4f,3.8f, 0.0f);
goalbar();
glPopMatrix();

glPushMatrix();
glScaled(200.0,130.0,0.0);
glTranslatef(0.3f,2.0f, 0.0f);
goalbar();
glPopMatrix();

///

///alif
tent1();
tent2();
tent3();
tent4();
watchtower1();
watchtower2();
///

///shafayet
glPushMatrix();
    glTranslated(_tank, 0, 0);
tank1();
glPopMatrix();
glPushMatrix();


glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(0.5f,11.0f, 0.0f);
tree();
glPopMatrix();


glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(1.0f,11.0f, 0.0f);
tree();
glPopMatrix();


glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(1.5f,11.0f, 0.0f);
tree();
glPopMatrix();

glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(2.0f,11.0f, 0.0f);
tree();
glPopMatrix();

glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(1.5f,11.0f, 0.0f);
tree();
glPopMatrix();

glPushMatrix();
glScaled(50.0,50.0,0.0);
glTranslatef(2.5f,11.0f, 0.0f);
tree();
glPopMatrix();
///


///abid
glPushMatrix();
    glTranslated(_ship, 0, 0);
    glTranslated(_heli2, 0, 0);
ship();
helicopter2();
glPopMatrix();
glTranslated(_heli, 0, 0);
    helicopter();
    glPopMatrix();
hospital();

///abid

///alif
glPushMatrix();
    glTranslated(_boatOne, 0, 0);
    boat();
    glPopMatrix();


TreeOne();
TreeTwo();
TreeThree();
TreeFour();
TreeFive();
TreeSix();
TreeSeven();
TreeEight();
TreeNine();
TreeTen();
TreeEleven();
TreeTwelve();




TillaFour();
TillaOne();
TillaTwo();
TillaThree();


WindmillThree();
WindmillOne();
WindmillTwo();

///
glFlush();

}

void myKeyboard (unsigned char key, int x, int y)
{

  switch (key)
     {



        /// Helicopter//
    case 'g':
        frd1 = false;
        bck1 = true;
        helibackward (hc);
        glutIdleFunc(moveRightHeli);
        break;

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

     case 'f':
        frd1 = true;
        bck1 = false;
        heliforward (hc);
        glutIdleFunc(moveRightHeli);

        break;
        case 'd':
        _heli -= 6.80;
    if (_heli < -1100)
    {
        _heli = 900;
    }
     break;

     case 's':
      _heli += 5.80;
    if (_heli > 1200)
    {
        _heli -= 1000;
    }

     break;


     case 'h':
        frd1 = false;
        bck1 = false;
        glutIdleFunc(NULL);
        break;
        ///

        /// Helicopter2//
    case 'q':
        frd2 = false;
        bck2 = true;
        helibackward2 (hc2);
        glutIdleFunc(moveRightHeli2);
        break;


     case 'w':
        frd2 = true;
        bck2 = false;
        heliforward2 (hc2);
        glutIdleFunc(moveRightHeli2);
        break;

     case 'e':
        frd2 = false;
        bck2 = false;
        glutIdleFunc(NULL);
        break;
        ///
     case 'b':
        rainday = true;
        Rain(rain);
        break;


     case 'n':
        rainday = false;
        break;

    case 'k':
        night = true;
        Night(_nt);
        break;

    case 'l':
        night = false;
        glClearColor(0.45, 0.10, 1.5, 0.0);
        break;
       /// //
        case 27:
         exit(0);
        break;

    default:
    break;

    }

}
void mouse(int key, int state, int x, int y){
    int mh44=0;
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {

            glutIdleFunc(moveRight);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);

        }
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
    glutMouseFunc(mouse);

    glutTimerFunc(25, update, 0);
     glutTimerFunc(25, update2, 0);
glutTimerFunc(25, update3, 0);
    init ();

glutMainLoop();
return 0;
}


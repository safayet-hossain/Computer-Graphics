



#include <windows.h> // for MS Windows



#include <GL/glut.h> // GLUT, include glu.h and gl.h



/* Handler for window-repaint event. Call back when the window first appears and



whenever the window needs to be re-painted. */



void display() {



glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque



//glColor3ub(255,255,255);



glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)



glPointSize(5.0);



// Draw a Red 1x1 Square centered at origin



glBegin(GL_LINES);



glColor3ub(0, 0, 0); // Each set of 4 vertices form a quad// Red // x, y



glVertex2f(-9.0f,0.0f);



glVertex2f(9.0f,0.0f);



glEnd();



glBegin(GL_LINES);



glColor3ub(0, 0, 0); // Each set of 4 vertices form a quad// Red // x, y



glVertex2f(0.0f,9.0f);



glVertex2f(0.0f,-9.0f);



glEnd();



glBegin(GL_POLYGON);



glColor3ub(255, 0, 0); // Each set of 4 vertices form a quad// Red // x, y



glVertex2f(-7.0f,5.0f);



glVertex2f(-7.0f,2.0f);



glVertex2f(-2.0f,2.0f);



glVertex2f(-2.0f,5.0f);



glEnd();





glBegin(GL_POLYGON);



glColor3ub(160, 70, 168); // Each set of 4 vertices form a quad// Red // x, y



glVertex2f(-2.0f,-1.0f);



glVertex2f(-5.0f,-3.0f);



glVertex2f(-2.0f,-6.0f);



//glVertex2f(-2.0f,5.0f);



glEnd();



glBegin(GL_POLYGON);



glColor3ub(255, 255, 0); // Each set of 4 vertices form a quad// Red // x, y



glVertex2f(4.5f,-2.0f);



glVertex2f(2.0f,-6.0f);



glVertex2f(7.0f,-6.0f);



//glVertex2f(-2.0f,5.0f);



glEnd();



glBegin(GL_POLYGON);



glColor3ub(112, 146, 190); // Each set of 4 vertices form a quad// Red // x, y



glVertex2f(8.0f,4.0f);



glVertex2f(5.0f,6.0f);



glVertex2f(5.0f,5.0f);



glVertex2f(2.0f,5.0f);



glVertex2f(2.0f,3.0f);



glVertex2f(5.0f,3.0f);



glVertex2f(5.0f,2.0f);



glEnd();



/*glBegin(GL_POLYGON);



glColor3ub(225, 206, 132); // Each set of 4 vertices form a quad// Red // x, y



glVertex2f(-4.0f,-4.0f);



glVertex2f(4.0f,-4.0f);



glVertex2f(3.0f,3.0f);



glVertex2f(-2.0f,3.0f);



glEnd();*/



glFlush(); // Render now



}



/* Main function: GLUT runs as a console application starting at main() */



int main(int argc, char** argv) {



glutInit(&argc, argv); // Initialize GLUT



glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title



glutInitWindowSize(320, 320);



gluOrtho2D(-10,10,-10,10); // Set the window's initial width & height



glutDisplayFunc(display); // Register display callback handler for window re-paint



glutMainLoop(); // Enter the event-processing loop



return 0;



}


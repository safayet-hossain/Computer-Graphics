#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#include<math.h>>
# define PI           3.14159265358979323846

GLfloat j = 0.0f;


void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}


void display() {
	glClearColor(1.0f, 1.10f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(7.5);



	    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(245, 132, 66); // Red

	glVertex2f(-0.5f, 0.8f);    // x, y
	glVertex2f(-0.5f, -0.8f);
	glVertex2f(0.5f, -0.8f);    // x, y
	glVertex2f(0.5f, 0.8f);
	glEnd();

	   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, 0.7f);    // x, y
	glVertex2f(-0.4f, 0.6f);
	glVertex2f(-0.3f, 0.6f);    // x, y
	glVertex2f(-0.3f, 0.7f);
	glEnd();


glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, 0.7f);    // x, y
	glVertex2f(-0.2f, 0.6f);
	glVertex2f(-0.1f, 0.6f);    // x, y
	glVertex2f(-0.1f, 0.7f);
	glEnd();

	//lw3
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, 0.4f);    // x, y
	glVertex2f(-0.4f, 0.3f);
	glVertex2f(-0.3f, 0.3f);    // x, y
	glVertex2f(-0.3f, 0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, 0.4f);    // x, y
	glVertex2f(-0.2f, 0.3f);
	glVertex2f(-0.1f, 0.3f);    // x, y
	glVertex2f(-0.1f, 0.4f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, 0.1f);    // x, y
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(-0.3f, 0.0f);    // x, y
	glVertex2f(-0.3f, 0.1f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, 0.1f);    // x, y
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.1f, 0.0f);    // x, y
	glVertex2f(-0.1f, 0.1f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, -0.2f);    // x, y
	glVertex2f(-0.4f, -0.3f);
	glVertex2f(-0.3f, -0.3f);    // x, y
	glVertex2f(-0.3f, -0.2f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, -0.2f);    // x, y
	glVertex2f(-0.4f, -0.3f);
	glVertex2f(-0.3f, -0.3f);    // x, y
	glVertex2f(-0.3f, -0.2f);
	glEnd();


glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, -0.2f);    // x, y
	glVertex2f(-0.2f, -0.3f);
	glVertex2f(-0.1f, -0.3f);    // x, y
	glVertex2f(-0.1f, -0.2f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, -0.4f);    // x, y
	glVertex2f(-0.4f, -0.6f);
	glVertex2f(-0.3f, -0.6f);    // x, y
	glVertex2f(-0.3f, -0.4f);
	glEnd();



	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, -0.4f);    // x, y
	glVertex2f(-0.2f, -0.6f);
	glVertex2f(-0.1f, -0.6f);    // x, y
	glVertex2f(-0.1f, -0.4f);
	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.7f);    // x, y
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.2f, 0.6f);    // x, y
	glVertex2f(0.2f, 0.7f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, 0.7f);    // x, y
	glVertex2f(0.3f, 0.6f);
	glVertex2f(0.4f, 0.6f);    // x, y
	glVertex2f(0.4f, 0.7f);
	glEnd();

			glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.4f);    // x, y
	glVertex2f(0.1f, 0.3f);
	glVertex2f(0.2f, 0.3f);    // x, y
	glVertex2f(0.2f, 0.4f);
	glEnd();


			glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, 0.4f);    // x, y
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.4f, 0.3f);    // x, y
	glVertex2f(0.4f, 0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.1f);    // x, y
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.2f, 0.0f);    // x, y
	glVertex2f(0.2f, 0.1f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, 0.1f);    // x, y
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.4f, 0.0f);    // x, y
	glVertex2f(0.4f, 0.1f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.1f);    // x, y
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.2f, 0.0f);    // x, y
	glVertex2f(0.2f, 0.1f);
	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, -0.2f);    // x, y
	glVertex2f(0.1f, -0.3f);
	glVertex2f(0.2f, -0.3f);    // x, y
	glVertex2f(0.2f, -0.2f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, -0.2f);    // x, y
	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.4f, -0.3f);    // x, y
	glVertex2f(0.4f, -0.2f);
	glEnd();
			glBegin(GL_QUADS);
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, -0.4f);    // x, y
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.2f, -0.5f);    // x, y
	glVertex2f(0.2f, -0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, -0.4f);    // x, y
	glVertex2f(0.3f, -0.5f);
	glVertex2f(0.4f, -0.5f);    // x, y
	glVertex2f(0.4f, -0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.1f, -0.6f);    // x, y
	glVertex2f(-0.1f, -0.8f);
	glVertex2f(0.1f, -0.8f);    // x, y
	glVertex2f(0.1f, -0.6f);
	glEnd();

























	glFlush();  // Render now
}

void display2() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(7.5);



	    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(245, 132, 66); // Red

	glVertex2f(-0.5f, 0.8f);    // x, y
	glVertex2f(-0.5f, -0.8f);
	glVertex2f(0.5f, -0.8f);    // x, y
	glVertex2f(0.5f, 0.8f);
	glEnd();

	   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, 0.7f);    // x, y
	glVertex2f(-0.4f, 0.6f);
	glVertex2f(-0.3f, 0.6f);    // x, y
	glVertex2f(-0.3f, 0.7f);
	glEnd();


glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, 0.7f);    // x, y
	glVertex2f(-0.2f, 0.6f);
	glVertex2f(-0.1f, 0.6f);    // x, y
	glVertex2f(-0.1f, 0.7f);
	glEnd();

	//lw3
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, 0.4f);    // x, y
	glVertex2f(-0.4f, 0.3f);
	glVertex2f(-0.3f, 0.3f);    // x, y
	glVertex2f(-0.3f, 0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, 0.4f);    // x, y
	glVertex2f(-0.2f, 0.3f);
	glVertex2f(-0.1f, 0.3f);    // x, y
	glVertex2f(-0.1f, 0.4f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, 0.1f);    // x, y
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(-0.3f, 0.0f);    // x, y
	glVertex2f(-0.3f, 0.1f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, 0.1f);    // x, y
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.1f, 0.0f);    // x, y
	glVertex2f(-0.1f, 0.1f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, -0.2f);    // x, y
	glVertex2f(-0.4f, -0.3f);
	glVertex2f(-0.3f, -0.3f);    // x, y
	glVertex2f(-0.3f, -0.2f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, -0.2f);    // x, y
	glVertex2f(-0.4f, -0.3f);
	glVertex2f(-0.3f, -0.3f);    // x, y
	glVertex2f(-0.3f, -0.2f);
	glEnd();


glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, -0.2f);    // x, y
	glVertex2f(-0.2f, -0.3f);
	glVertex2f(-0.1f, -0.3f);    // x, y
	glVertex2f(-0.1f, -0.2f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.4f, -0.4f);    // x, y
	glVertex2f(-0.4f, -0.6f);
	glVertex2f(-0.3f, -0.6f);    // x, y
	glVertex2f(-0.3f, -0.4f);
	glEnd();



	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.2f, -0.4f);    // x, y
	glVertex2f(-0.2f, -0.6f);
	glVertex2f(-0.1f, -0.6f);    // x, y
	glVertex2f(-0.1f, -0.4f);
	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.7f);    // x, y
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.2f, 0.6f);    // x, y
	glVertex2f(0.2f, 0.7f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, 0.7f);    // x, y
	glVertex2f(0.3f, 0.6f);
	glVertex2f(0.4f, 0.6f);    // x, y
	glVertex2f(0.4f, 0.7f);
	glEnd();

			glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.4f);    // x, y
	glVertex2f(0.1f, 0.3f);
	glVertex2f(0.2f, 0.3f);    // x, y
	glVertex2f(0.2f, 0.4f);
	glEnd();


			glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, 0.4f);    // x, y
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.4f, 0.3f);    // x, y
	glVertex2f(0.4f, 0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.1f);    // x, y
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.2f, 0.0f);    // x, y
	glVertex2f(0.2f, 0.1f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, 0.1f);    // x, y
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.4f, 0.0f);    // x, y
	glVertex2f(0.4f, 0.1f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, 0.1f);    // x, y
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.2f, 0.0f);    // x, y
	glVertex2f(0.2f, 0.1f);
	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, -0.2f);    // x, y
	glVertex2f(0.1f, -0.3f);
	glVertex2f(0.2f, -0.3f);    // x, y
	glVertex2f(0.2f, -0.2f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, -0.2f);    // x, y
	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.4f, -0.3f);    // x, y
	glVertex2f(0.4f, -0.2f);
	glEnd();
			glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.1f, -0.4f);    // x, y
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.2f, -0.5f);    // x, y
	glVertex2f(0.2f, -0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(0.3f, -0.4f);    // x, y
	glVertex2f(0.3f, -0.5f);
	glVertex2f(0.4f, -0.5f);    // x, y
	glVertex2f(0.4f, -0.4f);
	glEnd();

glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
 glColor3ub(179, 245, 66); // Red

	glVertex2f(-0.1f, -0.6f);    // x, y
	glVertex2f(-0.1f, -0.8f);
	glVertex2f(0.1f, -0.8f);    // x, y
	glVertex2f(0.1f, -0.6f);
	glEnd();

























	glFlush();  // Render now
}




void display3() {
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
display();
display2();


}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

  case 'n':

  glutDisplayFunc(display2);
  glutPostRedisplay();
      //day();
    break;
 case 'd':
  glutDisplayFunc(display);
  glutPostRedisplay();
    break;


glutPostRedisplay();

	}
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup"); // Create a window with the given title
	glutInitWindowSize(1000, 400);   // Set the window's initial width & height
	glutDisplayFunc(display);
	glutKeyboardFunc(handleKeypress);

	glutMainLoop();           // Enter the event-processing loop
	return 0;
}



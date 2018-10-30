#include "OpenGLDraw.h"
#include <gl\GL.h>
#include <gl\glut.h>


OpenGLDraw::OpenGLDraw()
{
}


OpenGLDraw::~OpenGLDraw()
{
}


/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	// Draw a Red Test Square
	glBegin(GL_QUADS);             
	glColor3f(1.0f, 0.0f, 0.0f); 
	glVertex2f(-0.5f, -0.5f);   
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glFlush();  // Render now
}


void OpenGLDraw::OpenWindow(int argc, char ** argv)
{
	glutInit(&argc, argv);                 // Initialize GLUT
	//glutInitDisplayMode(GLUT_DOUBLE); //Sets double buffering 
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(500, 500);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return;
}

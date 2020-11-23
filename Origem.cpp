#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>

// Rotation Angle
float angle = 0.0f;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 5.0f;
// Colors
float red = 1.0f, blue = 1.0f, green = 1.0f;

void drawParallelepiped(float height, float widthx, float widthz) {
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	// Bottom
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(widthx, 0.0f, 0.0f);
	glVertex3f(widthx, 0.0f, widthz);
	glVertex3f(0.0, 0.0f, widthz);

	glColor3f(1.0f, 0.0f, 0.0f);
	// Top
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(widthx, height, 0.0f);
	glVertex3f(widthx, height, widthz);
	glVertex3f(0.0, height, widthz);

	glColor3f(0.2f, 0.2f, 0.2f);
	// Side 1
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, widthz);
	glVertex3f(0.0f, height, widthz);
	glVertex3f(0.0f, height, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	// Side 2
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(widthx, 0.0f, 0.0f);
	glVertex3f(widthx, height, 0.0f);
	glVertex3f(0.0f, height, 0.0f);

	// Side 3
	glVertex3f(widthx, 0.0f, widthz);
	glVertex3f(widthx, 0.0f, 0.0f);
	glVertex3f(widthx, height, 0.0f);
	glVertex3f(widthx, height, widthz);

	// Side 4
	glVertex3f(widthx, 0.0f, widthz);
	glVertex3f(0.0f, 0.0f, widthz);
	glVertex3f(0.0f, height, widthz);
	glVertex3f(widthx, height, widthz);

	glEnd();
}

void drawTableTop() {
	glColor3f(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	glTranslatef(-2.5f, 0.0f, 1.25f);
	drawParallelepiped(0.25f, 5.0f, 2.5f);
	glPopMatrix();
}

void drawTableLeg() {
	glColor3f(0.2f, 0.2f, 0.2f);
	drawParallelepiped(1.0f, 1.0f, 1.0f);
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(0.0f, 2.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	// Draw ground
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	drawTableTop();

	glutSolidCone(1.0f, 4.0f, 5, 5);

	angle += 0.5f;

	glFlush();
	glutSwapBuffers();
}

void processSpecial(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		angle -= 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	// glutKeyboardFunc(processKeyboard);
	glutSpecialFunc(processSpecial);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
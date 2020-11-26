#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>

// Rotation Angle
float angle = 0.0f;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 12.0f;

float deltaAngle = 0.0f;
int xOrigin = -1;

void drawParallelepiped(float height, float widthx, float widthz) {
	glBegin(GL_QUADS);

	// Bottom
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(widthx, 0.0f, 0.0f);
	glVertex3f(widthx, 0.0f, widthz);
	glVertex3f(0.0, 0.0f, widthz);

	// Top
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(widthx, height, 0.0f);
	glVertex3f(widthx, height, widthz);
	glVertex3f(0.0, height, widthz);

	// Side 1
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, widthz);
	glVertex3f(0.0f, height, widthz);
	glVertex3f(0.0f, height, 0.0f);

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
	glColor3f(0.545f, 0.271f, 0.075f);
	glPushMatrix();
	glTranslatef(-2.5f, 2.0f, 1.25f);
	drawParallelepiped(0.25f, 5.0f, 2.5f);
	glPopMatrix();
}

void drawTableLegs() {
	float legWidth = 0.25f;

	// 1
	glColor3f(0.627f, 0.322f, 0.176f);
	glPushMatrix();
	glTranslatef(-2.5f, 0.0f, 1.25f);
	drawParallelepiped(2.0f, legWidth, legWidth);
	glPopMatrix();
	// 2
	glColor3f(0.627f, 0.322f, 0.176f);
	glPushMatrix();
	glTranslatef(2.5f - legWidth, 0.0f, 1.25f);
	drawParallelepiped(2.0f, legWidth, legWidth);
	glPopMatrix();
	//// 3
	glColor3f(0.627f, 0.322f, 0.176f);
	glPushMatrix();
	glTranslatef(-2.5f, 0.0f, 3.75f - legWidth);
	drawParallelepiped(2.0f, legWidth, legWidth);
	glPopMatrix();
	//// 4
	glColor3f(0.627f, 0.322f, 0.176f);
	glPushMatrix();
	glTranslatef(2.5f - legWidth, 0.0f, 3.75f - legWidth);
	drawParallelepiped(2.0f, legWidth, legWidth);
	glPopMatrix();
}

void drawChairBase() {
	// Base
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
	drawParallelepiped(0.1f, 1.0f, 1.0f);
	glPopMatrix();

	// Encosto
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
	drawParallelepiped(1.0f, 1.0f, 0.1f);
	glPopMatrix();
}

void DrawChairLegs() {

	float chairLegWidth = 0.1f;

	// 1
	glColor3f(1.0f, 0.894f, 0.710f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	drawParallelepiped(1.0f, chairLegWidth, chairLegWidth);
	glPopMatrix();
	
	// 2
	glColor3f(1.0f, 0.894f, 0.710f);
	glPushMatrix();
	glTranslatef(1.0f - chairLegWidth, 0.0f, 0.0f);
	drawParallelepiped(1.0f, chairLegWidth, chairLegWidth);
	glPopMatrix();

	// 3
	glColor3f(1.0f, 0.894f, 0.710f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 1.0f - chairLegWidth);
	drawParallelepiped(1.0f, chairLegWidth, chairLegWidth);
	glPopMatrix();

	// 4
	glColor3f(1.0f, 0.894f, 0.710f);
	glPushMatrix();
	glTranslatef(1.0f - chairLegWidth, 0.0f, 1.0f - chairLegWidth);
	drawParallelepiped(1.0f, chairLegWidth, chairLegWidth);
	glPopMatrix();
}

void drawWalls() {

	// Parede esquerda
	glColor3f(0.663f, 0.663f, 0.663f);
	glPushMatrix();
	glTranslatef(-5.0f, 0.0f, -4.0f);
	drawParallelepiped(6.0f, 1.0f, 12.0f);
	glPopMatrix();

	// Parede direita
	glColor3f(0.663f, 0.663f, 0.663f);
	glPushMatrix();
	glTranslatef(5.0f, 0.0f, -4.0f);
	drawParallelepiped(6.0f, 1.0f, 12.0f);
	glPopMatrix();

	// Parede tras
	glColor3f(0.663f, 0.663f, 0.663f);
	glPushMatrix();
	glTranslatef(-5.0f, 0.0f, -4.0f);
	drawParallelepiped(6.0f, 11.0f, 1.0f);
	glPopMatrix();

	// Teto
	glColor3f(0.663f, 0.663f, 0.663f);
	glPushMatrix();
	glTranslatef(-5.0f, 6.0f, -4.0f);
	drawParallelepiped(1.0f, 11.0f, 12.0f);
	glPopMatrix();
}


void drawTable() {
	drawTableTop();
	drawTableLegs();
}

void drawChair() {
	drawChairBase();
	DrawChairLegs();
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
	gluLookAt(x, 3.0f, z,
		x + lx, 3.0f, z + lz,
		0.0f, 3.0f, 0.0f);

	//glRotatef(angle, 0.0f, 1.0f, 0.0f);

	// Draw ground
	glColor3f(0.1f, 0.1f, 0.1f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	// Desenha paredes
	drawWalls();

	// Desenha a mesa
	drawTable();

	// Desenha a cadeira 1
	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, 0.0f);
	drawChair();
	glPopMatrix();

	// Desenha a cadeira 2
	glPushMatrix();
	glTranslatef(0.5f, 0.0f, 0.0f);
	drawChair();
	glPopMatrix();

	// Desenha a cadeira 3
	glPushMatrix();
	glTranslatef(-0.5f, 0.0f, 5.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	drawChair();
	glPopMatrix();

	// Desenha a cadeira 4
	glPushMatrix();
	glTranslatef(1.5f, 0.0f, 5.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	drawChair();
	glPopMatrix();

	// angle += 0.5f;

	glFlush();
	glutSwapBuffers();
}

void processSpecial(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
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

void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("CG - Projeto Final");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecial);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}

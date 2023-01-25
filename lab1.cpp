//Andres Botello
//Lab1
//Followed this playlist on Youtube:
//https://tinyurl.com/4n23hyu5
#include <GL/glut.h>

void display();
void reshape(int, int);
void timer(int);
float x_position = 0.0;
int state = 1;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);

	glutCreateWindow("moving square");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	init();

	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_QUADS);
	glVertex2f(x_position, 1.0);
	glVertex2f(x_position, -1.0);
	glVertex2f(x_position + 2.0, -1.0);
	glVertex2f(x_position + 2.0, 1.0);

	glEnd();

	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	if (x_position > -8 && x_position < 6)
		glColor3f(0.0, 0.0, 1.0);
	switch (state)
	{
	case 1:
		if (x_position < 8)
		{
			x_position += 0.20;
		}

		else
		{
			state = -1;
			glColor3f(1.0, 0.0, 0.0);
		}
		break;
	case -1:
		if (x_position > -10)
		{
			x_position -= 0.20;
		}
		else
		{
			state = 1;
			glColor3f(1.0, 0.0, 0.0);
		}
		break;
	}
}

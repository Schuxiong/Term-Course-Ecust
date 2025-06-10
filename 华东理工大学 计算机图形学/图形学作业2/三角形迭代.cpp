#include <GL/freeglut.h>
#include <math.h>
#include <vector>
#define max_iteration_num 6
using namespace std;

struct Vertex {
	GLfloat x, y;
};
vector<Vertex> V[3][max_iteration_num + 1];
int iteration_num = 0;
GLfloat width = 800.0, height = 800.0;

void myinit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	Vertex Start[3], End[3];
	Start[0].x = 400.0;
	Start[0].y = 800.0;
	End[0].x = (800.0 - 400.0 * sqrt(3.0)) / 2;
	End[0].y = 200.0;
	Start[1].x = End[0].x;
	Start[1].y = End[0].y;
	End[1].x = 400 + 200 * sqrt(3.0);
	End[1].y = 200;
	Start[2].x = End[1].x;
	Start[2].y = End[1].y;
	End[2].x = Start[0].x;
	End[2].y = Start[0].y;
	for (int i = 0; i < 3; i++) {
		V[i][0].push_back(Start[i]);
		V[i][0].push_back(End[i]);
	}

}

void myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}
void compute()
{
	static int tmp = 0;
	int flag = 0;
	if (tmp < iteration_num) {
		int len = V[0][iteration_num - 1].size();
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < len - 1; i++) {
				V[j][iteration_num].push_back(V[j][iteration_num - 1][i]);
				Vertex tmp;
				tmp.x = V[j][iteration_num - 1][i].x + (V[j][iteration_num - 1][i + 1].x - V[j][iteration_num - 1][i].x) / 3;
				tmp.y = V[j][iteration_num - 1][i].y + (V[j][iteration_num - 1][i + 1].y - V[j][iteration_num - 1][i].y) / 3;
				V[j][iteration_num].push_back(tmp);
				tmp.x = (V[j][iteration_num - 1][i].x + V[j][iteration_num - 1][i + 1].x) / 2 - (V[j][iteration_num - 1][i].y - V[j][iteration_num - 1][i + 1].y) * sqrt(3.0) / 6;
				tmp.y = (V[j][iteration_num - 1][i].y + V[j][iteration_num - 1][i + 1].y) / 2 - (V[j][iteration_num - 1][i + 1].x - V[j][iteration_num - 1][i].x) * sqrt(3.0) / 6;
				V[j][iteration_num].push_back(tmp);
				tmp.x = V[j][iteration_num - 1][i].x + 2 * (V[j][iteration_num - 1][i + 1].x - V[j][iteration_num - 1][i].x) / 3;
				tmp.y = V[j][iteration_num - 1][i].y + 2 * (V[j][iteration_num - 1][i + 1].y - V[j][iteration_num - 1][i].y) / 3;
				V[j][iteration_num].push_back(tmp);
			}
			V[j][iteration_num].push_back(V[j][iteration_num - 1][len - 1]);
		}
		tmp = iteration_num;
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	compute();
	glColor3f(1.0, 1.0, 1.0);
	for (int j = 0; j < 3; j++) {
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < V[j][iteration_num].size(); i++) {
			glVertex2f(V[j][iteration_num][i].x, V[j][iteration_num][i].y);
		}
		glEnd();
	}
	glutSwapBuffers();
}
void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 97:	
		if (iteration_num < max_iteration_num) {
			iteration_num++;
		}
		break;
	case 100:	
		if (iteration_num > 0) {
			iteration_num--;
		}
		break;
	case 27:	
		exit(0);
	}
	glutPostRedisplay();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("kock curve");
	myinit();
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(processNormalKeys);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}



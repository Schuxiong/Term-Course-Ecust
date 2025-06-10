
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Model.h"
using namespace std;

#pragma comment(lib,"glew32.lib")

void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES,0,3);
	glFlush();
}

int main(int argc, char **argv)
{

	glutInit(&argc,argv);
	glutInitWindowSize(1000,750);
	glutInitWindowPosition(140,60);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("GPUProgramming");


	glewInit();

	//cout << glGetString(GL_VERSION) << endl; //²é¿´OpenGL°æ±¾ºÅ

	glClearColor(1.0,1.0,1.0,1.0);

	glLineWidth(10.0);

	Model model;
	model.DrawModel();


	glutDisplayFunc(display2);
	glutMainLoop();
	return 0;
}
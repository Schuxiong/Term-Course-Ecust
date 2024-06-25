#include <gl/glut.h>
#include <stdio.h>
#include <time.h>
#include <cmath>

// 表示旋转的角度
static int my_angle = 0;

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 太阳
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glutSolidSphere(0.15, 200, 200);
	glPopMatrix();

	// 地球
	glPushMatrix();
	glColor3f(0.2, 0.2, 1.0);
	glRotated(my_angle, 1.0, 1.0, 1.0);  //公转
	glTranslatef(0.5, 0.5, -0.5);        //平移
	glutSolidSphere(0.1, 200, 200);
	glPopMatrix();

	// 月亮
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRotated(my_angle, 1.0, 1.0, 1.0);  //然后移动到地球旁边旋转
	glTranslatef(0.5, 0.5, -0.5);        //平移
	glRotated(my_angle, 1.0, 1.0, 1.0);  //先假设原点为地球旋转
	glTranslatef(-0.15, -0.15, 0.15);    //平移
	glutSolidSphere(0.05, 200, 200);     //绘制月亮
	glPopMatrix();

	glutSwapBuffers();
}
/**
 * 计时增加角度
 */
void myIdle(void) {
	static int mm = 0;
	mm++;
	if (mm % 300000 == 0) {
		my_angle+=10;
		if (my_angle >= 360) my_angle = 0;
		myDisplay();
	}
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("太阳，地球和月亮");  // 改了窗口标题

	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);  // 表示在CPU空闲的时间调用某一函数
	// 在OpenGL中，默认是没有开启深度检测的，后绘制的物体覆盖先绘制的物体。
	// GL_DEPTH_TEST 用来开启更新深度缓冲区的功能
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

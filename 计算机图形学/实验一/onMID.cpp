#include <iostream>
#include<math.h>
using namespace std;
#include "onMidPointEllispe.h"

static GLsizei iMode = 0;
int iPointNum = 0;                     //已确定点的数目
int x_1 = 0, x_2 = 0, y_1 = 0, y_2 = 0;               //确定的两点坐标
int screenWidth = 600, screenHeight = 400;

void Initial(void)//初始化窗口
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //设置窗口背景颜色为白色
}

void ChangeSize(int w, int h)
{
    screenWidth = w;
    screenHeight = h;
    glViewport(0, 0, w, h);                       //指定窗口显示区域
    glMatrixMode(GL_PROJECTION);            //设置投影参数
    glLoadIdentity();
    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
}

void MousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)//左击绘制
    {
        if (iPointNum == 0 || iPointNum == 2)
        {
            iPointNum = 1;
            x_1 = xMouse;
            y_1 = screenHeight - yMouse;
        }
        else
        {
            iPointNum = 2;
            x_2 = xMouse;
            y_2 = screenHeight - yMouse;
            glutPostRedisplay();                  //窗口执行重新绘制操作
        }
    }
    if (button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN)//右击清除
    {
        iPointNum = 0;
        glutPostRedisplay();                      //窗口执行重新绘制操作
    }
}

void PassiveMouseMove(GLint xMouse, GLint yMouse)//鼠标移动过程中
{
    if (iPointNum == 1)
    {
        x_2 = xMouse;
        y_2 = screenHeight - yMouse;
    }
    glutPostRedisplay();                  //窗口执行重新绘制操作
}

void ProcessMenu(int value)//处理菜单响应
{
    iMode = value;
    glutPostRedisplay();
}

void onMidPointEllispe(int a, int b)//绘制椭圆(用长短半轴)用中点Bresenham算法扫描转换
{
    int x, y;
    float d1, d2;
    glBegin(GL_POINTS);
    x = 0; y = b;
    d1 = b * b + a * a * (-b + 0.25);
    glVertex2i(x, y);
    glVertex2i(-x, -y);
    glVertex2i(-x, y);
    glVertex2i(x, -y);
    while (b * b * (x + 1) < a * a * (y - 0.5))
    {
        if (d1 <= 0)
        {
            d1 += b * b * (2 * x + 3);
            x++;
        }
        else
        {
            d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
            x++; y--;
        }
        glVertex2f(x, y);
        glVertex2f(-x, -y);
        glVertex2f(-x, y);
        glVertex2f(x, -y);
    }
    d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
    while (y > 0)
    {
        if (d2 <= 0)
        {
            d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
            x++; y--;
        }
        else
        {
            d2 += a * a * (-2 * y + 3);
            y--;
        }
        glVertex2f(x, y);
        glVertex2f(-x, -y);
        glVertex2f(-x, y);
        glVertex2f(x, -y);
    }
    glEnd();
    glFlush();
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //用当前背景色填充窗口
    glColor3f(1.0f, 0.0f, 0.0f); //设置矩形颜色为红色

    switch (iMode)
    {
    case 1:	//椭圆菜单
        if (iPointNum == 1)           //绘制矩形
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            //参数GL_FRONT_AND_BACK：表示显示模式将适用于物体的所有面；
            //参数GL_LINE：表示显示线段，多边形用轮廓显示
            glRectf(x_1, y_1, x_2, y_2);
        }
        glColor3f(0.0f, 1.0f, 0.0f); //设置椭圆颜色为绿色
        glTranslated((x_1 + x_2) / 2, (y_1 + y_2) / 2, 0); //将世界坐标原点平移到矩形中心
        onMidPointEllispe(abs((x_2 - x_1) / 2), abs((y_2 - y_1) / 2)); //绘制椭圆，输入长短轴
        glTranslated(-(x_1 + x_2) / 2, -(y_1 + y_2) / 2, 0); //反平移
        break;
    case 2:	//空菜单
        break;
    default: break;
    }
    glutSwapBuffers(); //交换缓冲区
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //使用“双缓存”以及RGB模型
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("21013025");

    //创建菜单并定义菜单回调函数
    glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("Ellispe", 1);				//菜单1椭圆
    glutAddMenuEntry("Empty~", 2);				//菜单2设为空
    glutAttachMenu(GLUT_RIGHT_BUTTON);	 //将主菜单与鼠标右键关联

    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize);                //指定窗口在整形回调函数
    glutMouseFunc(MousePlot);                  //指定鼠标响应函数
    glutPassiveMotionFunc(PassiveMouseMove);    //指定鼠标移动响应函数

    Initial();
    glutMainLoop();
    return 0;
}

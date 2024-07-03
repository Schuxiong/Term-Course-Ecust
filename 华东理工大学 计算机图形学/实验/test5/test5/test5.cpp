//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include "Utils.h"
//
//GLuint buffer[1];
//GLuint simpleShaderProgram;
//
//void init() {
//    // 使用着色器程序
//    simpleShaderProgram = Utils::createShaderProgram("vertexShader.glsl", "fragmentShader.glsl");
//
//    // 创建一个缓冲对象用于存储顶点坐标
//    glGenBuffers(1, &buffer[0]);
//    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
//
//    float vertices[] = {
//        -0.5f, -0.5f,  // 左下角
//         0.5f, -0.5f,  // 右下角
//         0.5f,  0.5f,  // 右上角
//        -0.5f,  0.5f   // 左上角
//    };
//
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//}
//
//void drawQuad() {
//    glUseProgram(simpleShaderProgram);
//
//    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
//
//    // 设置顶点属性指针
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glDrawArrays(GL_TRIANGLE_FAN, 0, 4); // 绘制四边形
//
//    glUseProgram(0); // 停用着色器程序
//}
//
//int main(void) {
//    if (!glfwInit()) { exit(EXIT_FAILURE); }
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Quad Example", NULL, NULL);
//    glfwMakeContextCurrent(window);
//
//    if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
//
//    init();
//
//    while (!glfwWindowShouldClose(window)) {
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // 渲染循环中调用绘制四边形的函数
//        drawQuad();
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    exit(EXIT_SUCCESS);
//}

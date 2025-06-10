//#include <stdio.h>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include "Utils.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
//#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
//
//#define RAYTRACE_RENDER_WIDTH	512
//#define RAYTRACE_RENDER_HEIGHT	512
//
//int windowWidth = 512;   // or set to RAYTRACE_RENDER_WIDTH
//int windowHeight = 512;  // or set to RAYTRACE_RENDER_HEIGHT
//
//int workGroupsX = RAYTRACE_RENDER_WIDTH;
//int workGroupsY = RAYTRACE_RENDER_HEIGHT;
//int workGroupsZ = 1;
//
//GLuint screenTextureID;     // The texture ID of the fullscreen texture
//unsigned char *screenTexture;   // The screen texture RGBA8888 color data
//
//#define numVAOs 1
//#define numVBOs 2
//GLuint vao[numVAOs];
//GLuint vbo[numVBOs];
//
//GLuint screenQuadShader, raytraceComputeShader;
//GLuint marbleTexture;
//
//void init(GLFWwindow* window) {
//	Utils::displayComputeShaderLimits();
//
//	// Allocate the memory for the screen texture, and wipe its contacts
//	screenTexture = (unsigned char*)malloc(sizeof(unsigned char) * 4 * RAYTRACE_RENDER_WIDTH * RAYTRACE_RENDER_HEIGHT);
//	memset(screenTexture, 0, sizeof(char) * 4 * RAYTRACE_RENDER_WIDTH * RAYTRACE_RENDER_HEIGHT);
//
//	// Setting the initial texture colors to pink to reveal if error
//	for (int i = 0; i < RAYTRACE_RENDER_HEIGHT; i++) {
//		for (int j = 0; j < RAYTRACE_RENDER_WIDTH; j++) {
//			screenTexture[i * RAYTRACE_RENDER_WIDTH * 4 + j * 4 + 0] = 250;
//			screenTexture[i * RAYTRACE_RENDER_WIDTH * 4 + j * 4 + 1] = 128;
//			screenTexture[i * RAYTRACE_RENDER_WIDTH * 4 + j * 4 + 2] = 255;
//			screenTexture[i * RAYTRACE_RENDER_WIDTH * 4 + j * 4 + 3] = 255;
//		}
//	}
//
//	// Create the OpenGL Texture
//	glGenTextures(1, &screenTextureID);
//	glBindTexture(GL_TEXTURE_2D, screenTextureID);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, RAYTRACE_RENDER_WIDTH, RAYTRACE_RENDER_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, (const void *)screenTexture);
//
//	// Creating Fullscreen Quad Vertices and texture coordinates
//	const float windowQuadVerts[] =
//	{	-1.0f, 1.0f, 0.3f,  -1.0f,-1.0f, 0.3f,  1.0f, -1.0f, 0.3f,
//		1.0f, -1.0f, 0.3f,  1.0f,  1.0f, 0.3f,  -1.0f,  1.0f, 0.3f
//	};
//	const float windowQuadUVs[] =
//	{	0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
//		1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
//	};
//
//	glGenVertexArrays(1, vao);
//	glBindVertexArray(vao[0]);
//	glGenBuffers(numVBOs, vbo);
//
//	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);  // vertext positions
//	glBufferData(GL_ARRAY_BUFFER, sizeof(windowQuadVerts), windowQuadVerts, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);  // texture coordinates
//	glBufferData(GL_ARRAY_BUFFER, sizeof(windowQuadUVs), windowQuadUVs, GL_STATIC_DRAW);
//
//	raytraceComputeShader = Utils::createShaderProgram("raytraceComputeShader.glsl");
//	screenQuadShader = Utils::createShaderProgram("vertShader.glsl", "fragShader.glsl");
//
//	marbleTexture = Utils::loadTexture("ice.jpg");
//}
//
//void display(GLFWwindow* window, double currentTime) {
//	//=======================================================
//	// Call the Raytrace compute shader
//	//=======================================================
//	glUseProgram(raytraceComputeShader);
//
//	// Bind the screen_texture_id texture to an image unit as the compute shader's output
//	glBindImageTexture(0, screenTextureID, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA8);
//
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, marbleTexture);
//
//	glActiveTexture(GL_TEXTURE0);
//
//	glDispatchCompute(workGroupsX, workGroupsY, workGroupsZ);
//	glMemoryBarrier(GL_ALL_BARRIER_BITS);
//
//	//=======================================================
//	// Call the shader program that draws the resulting texture to the screen
//	//=======================================================
//	glUseProgram(screenQuadShader);
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, screenTextureID);
//
//	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
//	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
//	glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, 0);
//	glEnableVertexAttribArray(1);
//	glDrawArrays(GL_TRIANGLES, 0, 6);
//}
//
//void setWindowSizeCallback(GLFWwindow *win, int newWidth, int newHeight) {
//	glViewport(0, 0, newWidth, newHeight);
//}
//
//int main(void) {
//	if (!glfwInit()) { exit(EXIT_FAILURE); }
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Recursive ray tracing", NULL, NULL);
//	glfwMakeContextCurrent(window);
//	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
//	glfwSwapInterval(1);
//
//	glfwSetWindowSizeCallback(window, setWindowSizeCallback);
//
//	init(window);
//
//	while (!glfwWindowShouldClose(window)) {
//		display(window, glfwGetTime());
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	exit(EXIT_SUCCESS);
//}
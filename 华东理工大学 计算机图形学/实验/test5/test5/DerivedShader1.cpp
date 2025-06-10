#include "DerivedShader1.h"


DerivedShader1::DerivedShader1(void)
{
}


DerivedShader1::~DerivedShader1(void)
{
}

void DerivedShader1::CreateShader()
{
	const GLchar *vertexShaderSrc = 
		"#version 430\n"
		"uniform mat4 PMV;\n"
		"layout(location=0) in vec3 position;\n"
		"layout(location=1) in vec4 color;\n"
		"out vec4 ocolor;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = PMV * vec4(position,1.0);\n"
		"	ocolor = color;\n"
		"}\n";

	const GLchar *fragmentShaderSrc = 
		"#version 430\n"
		"in vec4 ocolor;\n"
		"out vec4 Fragment;\n"
		"void main()\n"
		"{\n"
		"	Fragment = ocolor;\n"
		"}\n";

	GLuint vertexShader = GenerateAndCompiler(GL_VERTEX_SHADER,vertexShaderSrc);
	GLuint fragmentShader = GenerateAndCompiler(GL_FRAGMENT_SHADER,fragmentShaderSrc);

	LinkProgram(vertexShader,fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
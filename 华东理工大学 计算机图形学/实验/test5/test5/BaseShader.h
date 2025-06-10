#pragma once
#include <GL/glew.h>
class BaseShader
{
public:
	BaseShader(void);
	virtual ~BaseShader(void);

	virtual void CreateShader() = 0;

	GLuint  GenerateAndCompiler(GLenum type, const GLchar *src);

	GLuint GetShaderProgram() const{return program;}

	void LinkProgram(GLuint vertex_shader, GLuint pixel_shader);

private:
	GLuint program;
};


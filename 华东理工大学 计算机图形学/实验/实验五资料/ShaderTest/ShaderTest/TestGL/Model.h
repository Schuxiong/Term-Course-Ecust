
#pragma once
#include <GL/glew.h>
#include <GL/glut.h>
#include "BaseShader.h"

class Model
{
public:
	Model(void);
	~Model(void);

	void InitModel();

	void DrawModel();

private:
	BaseShader *shader;
	GLuint vbo;
};


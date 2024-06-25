#include "Model.h"
#include <GL/GL.h>
#include "DerivedShader1.h"
#include "vmath.h"
#include <iostream>

Model::Model(void) : shader(NULL)
{
}


Model::~Model(void)
{
	if (shader != NULL)
	{
		delete shader;
		shader = NULL;
	}
}


void Model::InitModel()
{
	GLfloat vertices[21] = 
	{
		0,0,-5, 1,0,0,1,
		0,5,-5, 0,1,0,1,
		5,0,-5, 0,0,1,1,
	};

	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}

void Model::DrawModel()
{

	InitModel();

	shader = new DerivedShader1();
	shader->CreateShader();

	
	
	glUseProgram(shader->GetShaderProgram());
	Matrix4f modelView = Matrix4f::createLookAt(Vector3f(0,0,0),Vector3f(0,0,-1),Vector3f(0,1,0));
	Matrix4f proj = Matrix4f::createFrustum(-1,1,-1,1,1,50);

	Matrix4f combined = proj*modelView;
	//combined.identity();
	glUniformMatrix4fv(glGetUniformLocation(shader->GetShaderProgram(), "PMV"), 1, GL_FALSE, (float*)&combined);

	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(float)*7, (void*)(sizeof(float)*3));

}
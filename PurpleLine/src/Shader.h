#pragma once
#include "CommonTypes.h"
#include <GL/glew.h>

namespace PurpleLine{ namespace Graphics{

class Shader
{
public:
	Shader(String vertexShaderPath, String fragmentShaderPath);
	~Shader();

	GLuint GetID() const;
	void Enable() const;
	void Disable() const;
private:
	String vShaderPath, fShaderPath;
	GLuint programID;

	void Load();
	void CreateProgram(GLuint vertexID, GLuint fragmentID);
	GLuint CreateShader(GLenum shaderType, const GLchar* code);
};

}}
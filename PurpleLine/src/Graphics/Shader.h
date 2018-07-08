#pragma once
#include "../CommonTypes.h"
#include <GL/glew.h>
#include "../Maths/maths.h"

namespace PurpleLine{ namespace Graphics{

class Shader
{
public:
	Shader(String vertexShaderPath, String fragmentShaderPath);
	~Shader();

	GLuint GetID() const;
	void Enable() const;
	void Disable() const;
	bool Compiled() const;

	void SetUniform1i(String name, int a);
	void SetUniform1f(String name, float a);
	void SetUniform2f(String name, float a, float b);
	void SetUniform2f(String name, Math::Vector2 vector);
	void SetUniform3f(String name, float a, float b, float c);
	void SetUniform3f(String name, Math::Vector3 vector);
	void SetUniform4f(String name, float a, float b, float c, float d);
	void SetUniform4f(String name, Math::Vector4 vector);

private:
	String vShaderPath, fShaderPath;
	GLuint programID;
	bool compiled;

	void Load();
	void CreateProgram(GLuint vertexID, GLuint fragmentID);
	GLuint CreateShader(GLenum shaderType, const GLchar* code);

	GLint GetUniformLocation(const GLchar* name);
};

}}
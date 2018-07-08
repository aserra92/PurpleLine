#include "Shader.h"
#include "../Utils/FileUtils.h"
#include "../Utils/Log.h"
#include <vector>

namespace PurpleLine{ namespace Graphics{

Shader::Shader(String vertexShaderPath, String fragmentShaderPath) :
	vShaderPath(vertexShaderPath),
	fShaderPath(fragmentShaderPath),
	compiled(false)
{
	Load();
}

Shader::~Shader()
{
	glDeleteProgram(programID);
}

unsigned int Shader::GetID() const
{
	return programID;
}

void Shader::Enable() const
{
	glUseProgram(programID);
}

void Shader::Disable() const
{
	glUseProgram(0);
}

bool Shader::Compiled() const
{
	return compiled;
}

void Shader::SetUniform1i(String name, int a)
{
	glUniform1i(GetUniformLocation(name.c_str()), a);
}

void Shader::SetUniform1f(String name, float a)
{
	glUniform1f(GetUniformLocation(name.c_str()), a);
}

void Shader::SetUniform2f(String name, float a, float b)
{
	glUniform2f(GetUniformLocation(name.c_str()), a, b);
}

void Shader::SetUniform2f(String name, Math::Vector2 vector)
{
	glUniform2f(GetUniformLocation(name.c_str()), vector.x, vector.y);
}

void Shader::SetUniform3f(String name, float a, float b, float c)
{
	glUniform3f(GetUniformLocation(name.c_str()), a, b, c);
}

void Shader::SetUniform3f(String name, Math::Vector3 vector)
{
	glUniform3f(GetUniformLocation(name.c_str()), vector.x, vector.y, vector.z);
}

void Shader::SetUniform4f(String name, float a, float b, float c, float d)
{
	glUniform4f(GetUniformLocation(name.c_str()), a, b, c, d);
}

void Shader::SetUniform4f(String name, Math::Vector4 vector)
{
	glUniform4f(GetUniformLocation(name.c_str()), vector.x, vector.y, vector.z, vector.w);
}

void Shader::Load()
{
	String vertexCode = FileUtils::ReadFile(vShaderPath);
	String fragmentCode = FileUtils::ReadFile(fShaderPath);
	GLuint vertexShaderID = CreateShader(GL_VERTEX_SHADER, vertexCode.c_str());
	GLuint fragmentShaderID = CreateShader(GL_FRAGMENT_SHADER, fragmentCode.c_str());
	if (vertexShaderID != -1 && fragmentShaderID != -1)
	{
		CreateProgram(vertexShaderID, fragmentShaderID);
	}
	if (vertexShaderID != -1)
	{
		glDeleteShader(vertexShaderID);
	}
	if (fragmentShaderID != -1)
	{
		glDeleteShader(fragmentShaderID);
	}
}

void Shader::CreateProgram(GLuint vertexID, GLuint fragmentID)
{
	programID = glCreateProgram();
	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
	glLinkProgram(programID);
	glValidateProgram(programID);
	GLint success;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLint length;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &length);
		GLchar *infoLog = new GLchar(length);
		glGetProgramInfoLog(programID, length, &length, infoLog);
		LOG_ERROR("Error compiling program\n", infoLog);
	}
	else {
		compiled = true;
	}
}

GLuint Shader::CreateShader(GLenum shaderType, const GLchar* code)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &code, NULL);
	glCompileShader(shader);
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		GLchar *infoLog = new GLchar(length);
		glGetShaderInfoLog(shader, length, &length, infoLog);
		LOG_ERROR("Error compiling shader\n", infoLog);
		glDeleteShader(shader);
		return -1;
	}
	return shader;
}

GLint Shader::GetUniformLocation(const GLchar * name)
{
	return glGetUniformLocation(programID, name);
}

}}
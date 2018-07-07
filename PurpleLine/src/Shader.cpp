#include "Shader.h"
#include "Utils/FileUtils.h"
#include "Utils/Log.h"
#include <vector>

namespace PurpleLine{ namespace Graphics{

Shader::Shader(String vertexShaderPath, String fragmentShaderPath) :
	vShaderPath(vertexShaderPath),
	fShaderPath(fragmentShaderPath)
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
		std::vector<char> infoLog(length);
		glGetProgramInfoLog(programID, length, &length, &infoLog[0]);
		LOG_ERROR("Error compiling program\n", infoLog[0]);
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
		std::vector<char> infoLog(length);
		glGetShaderInfoLog(shader, length, &length, &infoLog[0]);
		LOG_ERROR("Error compiling shader\n", infoLog[0]);
		glDeleteShader(shader);
		return -1;
	}
	return shader;
}

}}
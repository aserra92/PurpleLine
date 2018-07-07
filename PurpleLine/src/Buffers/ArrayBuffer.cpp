#include "ArrayBuffer.h"

namespace PurpleLine{namespace Graphics{

	ArrayBuffer::ArrayBuffer(GLfloat * data, GLsizei count, GLuint componentCount) :
		componentCount(componentCount)
	{
		glGenBuffers(1, &bufferID);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GL_FLOAT), data, GL_STATIC_DRAW);
		Unbind();
	}

	ArrayBuffer::~ArrayBuffer()
	{
		glDeleteBuffers(1, &bufferID);
	}

	void ArrayBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	}

	void ArrayBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GLuint ArrayBuffer::GetComponentCount() const
	{
		return componentCount;
	}
} }
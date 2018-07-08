#include "ElementArrayBuffer.h"

namespace PurpleLine{namespace Graphics{

	ElementArrayBuffer::ElementArrayBuffer(GLushort * data, GLsizei count) :
		count(count)
	{
		glGenBuffers(1, &bufferID);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
		Unbind();
	}

	ElementArrayBuffer::ElementArrayBuffer(GLuint * data, GLsizei count) :
		count(count)
	{
		glGenBuffers(1, &bufferID);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLsizei), data, GL_STATIC_DRAW);
		Unbind();
	}

	ElementArrayBuffer::~ElementArrayBuffer()
	{
		glDeleteBuffers(1, &bufferID);
	}

	void ElementArrayBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	}

	void ElementArrayBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	GLuint ElementArrayBuffer::GetCount() const
	{
		return count;
	}
} }
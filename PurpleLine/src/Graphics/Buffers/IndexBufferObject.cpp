#include "IndexBufferObject.h"

namespace PurpleLine{namespace Graphics{

	IndexBufferObject::IndexBufferObject(GLushort * data, GLsizei count) :
		count(count)
	{
		glGenBuffers(1, &bufferID);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
		Unbind();
	}

	IndexBufferObject::IndexBufferObject(GLuint * data, GLsizei count) :
		count(count)
	{
		glGenBuffers(1, &bufferID);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLsizei), data, GL_STATIC_DRAW);
		Unbind();
	}

	IndexBufferObject::~IndexBufferObject()
	{
		glDeleteBuffers(1, &bufferID);
	}

	void IndexBufferObject::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	}

	void IndexBufferObject::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	GLuint IndexBufferObject::GetCount() const
	{
		return count;
	}
} }
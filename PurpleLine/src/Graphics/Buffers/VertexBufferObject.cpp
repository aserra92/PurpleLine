#include "VertexBufferObject.h"

namespace PurpleLine{namespace Graphics{

	VertexBufferObject::VertexBufferObject(GLfloat * data, GLsizei count, GLuint componentCount) :
		componentCount(componentCount)
	{
		glGenBuffers(1, &bufferID);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GL_FLOAT), data, GL_STATIC_DRAW);
		Unbind();
	}

	VertexBufferObject::~VertexBufferObject()
	{
		glDeleteBuffers(1, &bufferID);
	}

	void VertexBufferObject::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	}

	void VertexBufferObject::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GLuint VertexBufferObject::GetComponentCount() const
	{
		return componentCount;
	}
} }
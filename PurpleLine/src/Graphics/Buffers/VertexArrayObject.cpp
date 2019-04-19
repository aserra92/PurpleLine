#include "VertexArrayObject.h"

namespace PurpleLine{ namespace Graphics{
	
	VertexArrayObject::VertexArrayObject()
	{
		glGenVertexArrays(1, &bufferID);
	}

	VertexArrayObject::~VertexArrayObject()
	{
		for (size_t i = 0; i < listBuffers.size(); i++)
		{
			delete listBuffers[i];
		}
		glDeleteVertexArrays(1, &bufferID);
	}

	void VertexArrayObject::AddBuffer(VertexBufferObject * buffer, GLuint indexLayout)
	{
		Bind();
		buffer->Bind();
		glEnableVertexAttribArray(indexLayout);
		glVertexAttribPointer(indexLayout, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
		buffer->Unbind();
		Unbind();
		listBuffers.push_back(buffer);
	}

	void VertexArrayObject::Bind() const
	{
		glBindVertexArray(bufferID);
	}

	void VertexArrayObject::Unbind() const
	{
		glBindVertexArray(0);
	}
} }
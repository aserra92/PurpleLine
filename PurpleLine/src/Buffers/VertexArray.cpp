#include "VertexArray.h"

namespace PurpleLine{ namespace Graphics{
	
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &bufferID);
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < listBuffers.size(); i++)
		{
			delete listBuffers[i];
		}
		glDeleteVertexArrays(1, &bufferID);
	}

	void VertexArray::AddBuffer(ArrayBuffer * buffer, GLuint indexLayout)
	{
		Bind();
		buffer->Bind();
		glEnableVertexAttribArray(bufferID);
		glVertexAttribPointer(bufferID, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
		buffer->Unbind();
		Unbind();
		listBuffers.push_back(buffer);
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(bufferID);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
} }
#include "BatchRenderer2D.h"
#include "Renderable/Renderable2D.h"
#include "../Utils/Log.h"

namespace PurpleLine{namespace Graphics{

	BatchRenderer2D::BatchRenderer2D()
	{
		Init();
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		delete IBO;
		glDeleteBuffers(1, &VBO);
	}

	void BatchRenderer2D::Begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer2D::Submit(const Renderable2D* renderable) //TODO: make position take care of position of gameobject
	{
		const Math::Vector3& position = renderable->GetPosition();
		const Math::Vector3& parentPosition = renderable->GetParentPosition();
		const unsigned int color = renderable->GetColor();
		const Math::Vector2& size = renderable->GetSize();

		buffer->vertex = parentPosition * position;
		buffer->color = color;
		buffer++;

		buffer->vertex = parentPosition * Math::Vector3(position.x, position.y + size.y, position.z);
		buffer->color = color;
		buffer++;

		buffer->vertex = parentPosition * Math::Vector3(position.x + size.x, position.y + size.y, position.z);
		buffer->color = color;
		buffer++;

		buffer->vertex = parentPosition * Math::Vector3(position.x + size.x, position.y, position.z);
		buffer->color = color;
		buffer++;

		indexCount += 6;
	}

	void BatchRenderer2D::Flush()
	{
		glBindVertexArray(VAO);
		IBO->Bind();
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, NULL);
		IBO->Unbind();
		glBindVertexArray(0);
		indexCount = 0;
	}

	void BatchRenderer2D::End()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchRenderer2D::Init()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);

		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const void*)offsetof(VertexData, VertexData::color));
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		
		GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];
		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i+=6)
		{
			indices[i + 0] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
			offset += 4;
		}
		IBO = new IndexBufferObject(indices, RENDERER_INDICES_SIZE);
		glBindVertexArray(0);
	}

}}
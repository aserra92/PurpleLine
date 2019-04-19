#pragma once
#include <GL/glew.h>
#include <vector>
#include "VertexBufferObject.h"

namespace PurpleLine{ namespace Graphics{

	class VertexArrayObject
	{
	public:
		VertexArrayObject();
		~VertexArrayObject();

		void AddBuffer(VertexBufferObject *buffer, GLuint indexLayout);

		void Bind() const;
		void Unbind() const;

	private:
		GLuint bufferID;
		std::vector<VertexBufferObject*> listBuffers;
	};
} }
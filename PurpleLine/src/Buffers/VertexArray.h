#pragma once
#include <GL/glew.h>
#include <vector>
#include "ArrayBuffer.h"

namespace PurpleLine{ namespace Graphics{

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(ArrayBuffer *buffer, GLuint indexLayout);

		void Bind() const;
		void Unbind() const;

	private:
		GLuint bufferID;
		std::vector<ArrayBuffer*> listBuffers;
	};
} }
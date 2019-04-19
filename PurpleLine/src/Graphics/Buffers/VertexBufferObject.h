#pragma once
#include <GL/glew.h>

namespace PurpleLine{namespace Graphics{

	class VertexBufferObject
	{
	public:
		VertexBufferObject(GLfloat* data, GLsizei count, GLuint componentCount);
		~VertexBufferObject();

		void Bind() const;
		void Unbind() const;
		GLuint GetComponentCount() const;

	private:
		GLuint bufferID;
		GLuint componentCount;
	};
} }
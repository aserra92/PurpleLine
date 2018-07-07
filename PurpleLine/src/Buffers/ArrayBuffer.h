#pragma once
#include <GL/glew.h>

namespace PurpleLine{namespace Graphics{

	class ArrayBuffer
	{
	public:
		ArrayBuffer(GLfloat* data, GLsizei count, GLuint componentCount);
		~ArrayBuffer();

		void Bind() const;
		void Unbind() const;
		GLuint GetComponentCount() const;

	private:
		GLuint bufferID;
		GLuint componentCount;
	};
} }
#pragma once
#include <GL/glew.h>
namespace PurpleLine{namespace Graphics{

	class ElementArrayBuffer
	{
	public:
		ElementArrayBuffer(GLushort* data, GLsizei count);
		ElementArrayBuffer(GLuint* data, GLsizei count);
		~ElementArrayBuffer();

		void Bind() const;
		void Unbind() const;

		GLuint GetCount() const;

	private:
		GLuint bufferID;
		GLuint count;
	};

} }

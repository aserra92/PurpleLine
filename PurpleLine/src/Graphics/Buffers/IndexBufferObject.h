#pragma once
#include <GL/glew.h>
namespace PurpleLine{namespace Graphics{

	class IndexBufferObject
	{
	public:
		IndexBufferObject(GLushort* data, GLsizei count);
		IndexBufferObject(GLuint* data, GLsizei count);
		~IndexBufferObject();

		void Bind() const;
		void Unbind() const;

		GLuint GetCount() const;

	private:
		GLuint bufferID;
		GLuint count;
	};

} }

#include "StaticSprite.h"
#include <GL/glew.h>

namespace PurpleLine{namespace Graphics{

StaticSprite::StaticSprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color, Shader & shader) :
	Renderable2D(position, size, 0xffff00ff),
	shader(shader)
{
	vertexArray = new VertexArray();
	GLfloat vertices[] = {
		0, 0, 0,
		0, size.y, 0,
		size.x, size.y, 0,
		size.x, 0, 0
	};
	GLfloat colors[] = {
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w
	};
	GLushort indices[] = {
		0, 1, 3, 1, 2, 3
	};
	vertexArray->AddBuffer(new ArrayBuffer(vertices, 4 * 3, 3), 0);
	vertexArray->AddBuffer(new ArrayBuffer(colors, 4 * 4, 4), 1);
	indexBuffer = new ElementArrayBuffer(indices, 6);
}

StaticSprite::~StaticSprite()
{
	delete vertexArray;
	delete indexBuffer;
}

}}
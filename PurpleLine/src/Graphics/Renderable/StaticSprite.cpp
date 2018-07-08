#include "StaticSprite.h"
#include <GL/glew.h>

namespace PurpleLine{namespace Graphics{

StaticSprite::StaticSprite(float height, float width, Math::Vector4 color, Shader & shader) :
	Renderable2D(0xffff00ff),
	shader(shader)
{
	vertexArray = new VertexArray();
	GLfloat vertices[] = {
		0, 0, 0,
		0, height, 0,
		width, height, 0,
		width, 0, 0
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
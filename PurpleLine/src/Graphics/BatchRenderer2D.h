#pragma once
#include "Buffers/IndexBufferObject.h"

namespace PurpleLine{namespace Graphics{

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX		0
//#define SHADER_UV_INDEX			1
//#define SHADER_TEXID_INDEX		2
#define SHADER_COLOR_INDEX		1

	class Renderable2D;
	struct VertexData;
	class BatchRenderer2D 
	{
	private:
		VertexData* buffer;
		IndexBufferObject* IBO;
		GLuint VBO;
		GLuint VAO;
		GLsizei indexCount;
	public:
		BatchRenderer2D();
		~BatchRenderer2D();

		void Begin();
		void Submit(const Renderable2D* renderable);
		void Flush();
		void End();
	private:
		void Init();
	};
}}
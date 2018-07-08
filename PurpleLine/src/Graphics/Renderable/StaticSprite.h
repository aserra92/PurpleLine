#pragma once
#include "Renderable2D.h"
#include "../Shader.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/ElementArrayBuffer.h"

namespace PurpleLine{namespace Graphics{

	class StaticSprite : public Renderable2D
	{
	public:
		StaticSprite(float height, float width, Math::Vector4 color, Shader& shader);
		~StaticSprite();

		inline Shader& GetShader()const { return shader; }
		inline const VertexArray* GetVAO() const { return vertexArray; }
		inline const ElementArrayBuffer* GetIBO() const { return indexBuffer; }

	private:
		Shader & shader;
		VertexArray *vertexArray;
		ElementArrayBuffer *indexBuffer;
	};
} }
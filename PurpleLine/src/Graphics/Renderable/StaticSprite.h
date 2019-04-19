#pragma once
#include "Renderable2D.h"
#include "../Shader.h"
#include "../Buffers/VertexArrayObject.h"
#include "../Buffers/IndexBufferObject.h"

namespace PurpleLine{namespace Graphics{

	class StaticSprite : public Renderable2D
	{
	public:
		StaticSprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color, Shader& shader);
		~StaticSprite();

		inline Shader& GetShader()const { return shader; }
		inline const VertexArrayObject* GetVAO() const { return vertexArrayObject; }
		inline const IndexBufferObject* GetIBO() const { return indexBuffer; }

	private:
		Shader & shader;
		VertexArrayObject *vertexArrayObject;
		IndexBufferObject *indexBuffer;
	};
} }
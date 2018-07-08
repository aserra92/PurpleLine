#pragma once
#include "Renderable2D.h"
#include "../Shader.h"
namespace PurpleLine{namespace Graphics{

	class StaticSprite : Renderable2D
	{
	public:
		StaticSprite(Math::Vector4 color, Shader& shader);
		~StaticSprite();

	private:
		Shader & shader;
	};
} }
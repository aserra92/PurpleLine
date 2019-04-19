#pragma once
#include "Renderable2D.h"

namespace PurpleLine{namespace Graphics{

	class Sprite : public Renderable2D
	{
	public:
		Sprite(float x, float y, float height, float width, unsigned int color);
		Sprite(Math::Vector3 position, Math::Vector2 size, unsigned int color);
	};
}}
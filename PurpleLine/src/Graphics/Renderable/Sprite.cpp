#include "Sprite.h"

namespace PurpleLine{namespace Graphics{

	Sprite::Sprite(float x, float y, float height, float width, unsigned int color) :
		Renderable2D(Math::Vector3(x, y, 0), Math::Vector3::Zero(), Math::Vector2(height, width), color)
	{
	}

	Sprite::Sprite(Math::Vector3 position, Math::Vector2 size, unsigned int color) :
		Renderable2D(position, Math::Vector3::Zero(), size, color)
	{}
}}
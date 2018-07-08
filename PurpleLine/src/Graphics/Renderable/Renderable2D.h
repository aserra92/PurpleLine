#pragma once
#include "../../Maths/maths.h"

namespace PurpleLine{namespace Graphics{
class Renderable2D {
protected:
	unsigned int color;

	Renderable2D() {

	}

public:
	Renderable2D(Math::Vector3 position, Math::Vector2 size, unsigned int color) :
		color(color)
	{
	}

	virtual ~Renderable2D()
	{}

	void SetColor(unsigned int color) 
	{
		this->color = color;
	}

	void SetColor(Math::Vector4 color)
	{
		int r = (int)(color.x * 255.0f);
		int g = (int)(color.y * 255.0f);
		int b = (int)(color.z * 255.0f);
		int a = (int)(color.w * 255.0f);

		this->color = a << 24 | b << 16 | g << 8 | r;
	}

	inline const unsigned int GetColor() { return color; }
};

}}
#include "Transform.h"
#include "../../../Maths/maths.h"

namespace PurpleLine{namespace GameObjects{
Transform::Transform() :
	position(0, 0, 0),
	rotation(0, 0, 0),
	scale(1, 1, 1)
{
}

Transform::Transform(Math::Vector3 position) :
	position(position),
	rotation(0, 0, 0),
	scale(1, 1, 1)
{
}

Transform::Transform(Math::Vector3 position, Math::Vector3 rotation) :
	position(position),
	rotation(rotation),
	scale(1, 1, 1)
{
}

Transform::Transform(Math::Vector3 position, Math::Vector3 rotation, Math::Vector3 scale) :
	position(position),
	rotation(rotation),
	scale(scale)
{
}

Transform::~Transform()
{
}
}}
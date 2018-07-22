#include "TransformComponent.h"
#include "../../../Maths/maths.h"

namespace PurpleLine{namespace GameObjects{
TransformComponent::TransformComponent(GameObject* gObject) :
	ComponentBase(gObject),
	position(0, 0, 0),
	rotation(0, 0, 0),
	scale(1, 1, 1)
{
}

TransformComponent::TransformComponent(GameObject* gObject, Math::Vector3 position) :
	ComponentBase(gObject),
	position(position),
	rotation(0, 0, 0),
	scale(1, 1, 1)
{
}

TransformComponent::TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation) :
	ComponentBase(gObject),
	position(position),
	rotation(rotation),
	scale(1, 1, 1)
{
}

TransformComponent::TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation, Math::Vector3 scale) :
	ComponentBase(gObject),
	position(position),
	rotation(rotation),
	scale(scale)
{
}

TransformComponent::~TransformComponent()
{
}
}}
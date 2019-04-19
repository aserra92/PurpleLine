#include "TransformComponent.h"
#include "../../../Maths/maths.h"

namespace PurpleLine{namespace GameObjects{
TransformComponent::TransformComponent(GameObject* gObject) :
	ComponentBase(gObject),
	Transform()
{
}

TransformComponent::TransformComponent(GameObject* gObject, Math::Vector3 position) :
	ComponentBase(gObject),
	Transform(position, Math::Vector3::Zero(), Math::Vector3::One())
{
}

TransformComponent::TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation) :
	ComponentBase(gObject),
	Transform(position, rotation, Math::Vector3::One())
{
}

TransformComponent::TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation, Math::Vector3 scale) :
	ComponentBase(gObject),
	Transform(position, rotation, scale)
{
}

TransformComponent::~TransformComponent()
{
}
}}
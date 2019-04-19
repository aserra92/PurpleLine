#pragma once
#include "ComponentBase.h"
#include "../../../Graphics/Renderable/Transform.h"

namespace PurpleLine{namespace GameObjects{

	using namespace Graphics;
	class TransformComponent : public ComponentBase, public Transform
	{
	public:
		TransformComponent(GameObject* gObject);
		TransformComponent(GameObject* gObject, Math::Vector3 position);
		TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation);
		TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation, Math::Vector3 scale);
		~TransformComponent();

		inline virtual const ComponentType GetComponentType() const override  { return ComponentType::TransformComponentType; }
		inline virtual ComponentBase* Clone(GameObject* gObject) override { return new TransformComponent(gObject, position, rotation, scale); }
	private:

	};
} }
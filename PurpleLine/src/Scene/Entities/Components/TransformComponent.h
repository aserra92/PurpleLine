#pragma once
#include "ComponentBase.h"
#include "../../../Maths/maths.h"
namespace PurpleLine{namespace GameObjects{

	class TransformComponent : public ComponentBase
	{
	public:
		TransformComponent(GameObject* gObject);
		TransformComponent(GameObject* gObject, Math::Vector3 position);
		TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation);
		TransformComponent(GameObject* gObject, Math::Vector3 position, Math::Vector3 rotation, Math::Vector3 scale);
		~TransformComponent();

		inline void SetPosition(const Math::Vector3& newPosition) { position = newPosition; }
		inline void SetRotation(const Math::Vector3& newRotation) { rotation = newRotation; }
		inline void SetScale(const Math::Vector3& newScale) { scale = newScale; }

		const Math::Vector3& GetPosition()const { return position; }
		const Math::Vector3& GetRotation()const { return rotation; }
		const Math::Vector3& GetScale()const { return scale; }

		inline virtual const ComponentType& GetComponentType() const override  { return ComponentType::TransformComponentType; }
	private:
		Math::Vector3 position;
		Math::Vector3 rotation;
		Math::Vector3 scale;
	};
} }
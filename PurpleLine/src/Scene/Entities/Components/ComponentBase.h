#pragma once
#include "../../../Utils/String.h"
#include "ComponentType.h"

namespace PurpleLine{namespace GameObjects{

	class GameObject;
	class ComponentBase
	{
	public:
		ComponentBase(GameObject* gObject) :
			gameObject(gObject)
		{}

		virtual GameObject * GetGameObject() { return gameObject; }
		virtual const ComponentType GetComponentType() const { return ComponentType::None; }

		virtual ComponentBase* Clone(GameObject* gObject) { return new ComponentBase(gObject); }

	protected:
		GameObject *gameObject;
	};
} }
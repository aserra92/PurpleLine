#pragma once
#include "../../../Utils/String.h"
#include "ComponentType.h"

namespace PurpleLine{namespace GameObjects{

	class GameObject;
	class ComponentBase
	{
	public:
		virtual GameObject * GetGameObject() { return gameObject; }
		virtual const ComponentType& GetComponentType() const { return ComponentType::None; }

	private:
		GameObject *gameObject;
	};
} }
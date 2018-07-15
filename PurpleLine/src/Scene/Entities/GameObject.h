#pragma once
#include "../../Utils/String.h"
#include "Components/Transform.h"
#include <vector>

namespace PurpleLine {namespace GameObjects{

	class GameObject
	{
	public:
		GameObject(String name);
		~GameObject();

		Transform* GetTransform() const { return transform; }
		void SetTransform(const Transform& newTransform) { *transform = newTransform; }
	private:
		String name;
		Transform* transform;
		std::vector<GameObject*> children;
		std::vector<ComponentBase*> components;
	};
}}
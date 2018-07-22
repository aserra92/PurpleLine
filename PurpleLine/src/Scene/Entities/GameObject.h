#pragma once
#include "../../Utils/String.h"
#include "Components/Components.h"
#include "../../Graphics/SimpleRenderer2D.h"
#include <vector>

namespace PurpleLine {namespace GameObjects{

	class GameObject
	{
	public:
		GameObject(String name);
		~GameObject();

		void Update();
		void Render(Graphics::SimpleRenderer2D* renderer);

		void AddComponent(ComponentBase* newComponent);
		inline TransformComponent* GetTransform() const { return transform; }
		inline void SetTransform(const TransformComponent& newTransform) { *transform = newTransform; }
		inline bool HasChilds() const { return children.size(); }
		bool HasComponent(ComponentType type) const;
		ComponentBase* GetComponent(ComponentType type) const;
		ComponentBase* GetComponent(unsigned int position) const;
	private:
		String name;
		TransformComponent* transform;
		std::vector<GameObject*> children;
		std::vector<ComponentBase*> components;
	};
}}
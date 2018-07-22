#include "GameObject.h"

namespace PurpleLine {namespace GameObjects{

	GameObject::GameObject(String name) :
		name(name)
	{
		transform = new	TransformComponent(this);
		components.push_back(transform);
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
	}

	void GameObject::Render(Graphics::SimpleRenderer2D* renderer)
	{
		for (unsigned int i = 0; i < children.size(); i++)
		{
			children[i]->Render(renderer);
		}
		ComponentBase * component = GetComponent(ComponentType::SpriteComponentType);
		if (component != nullptr)
		{
			((SpriteComponent*)component)->Render(renderer);
		}
	}

	void GameObject::AddComponent(ComponentBase * newComponent)
	{
		components.push_back(newComponent);
	}

	bool GameObject::HasComponent(ComponentType type) const
	{
		bool result = false;
		for (unsigned int i = 0; i < components.size(); i++)
		{
			result = components[i]->GetComponentType() == type;
			if (result)
				return result;
		}
		return result;
	}

	ComponentBase * GameObject::GetComponent(ComponentType type) const
	{
		for (unsigned int i = 0; i < components.size(); i++)
		{
			if (components[i]->GetComponentType() == type)
			{
				return components[i];
			}
		}
		return nullptr;
	}

	ComponentBase * GameObject::GetComponent(unsigned int position) const
	{
		if (position < components.size())
		{
			return components[position];
		}
		return nullptr;
	}
}}
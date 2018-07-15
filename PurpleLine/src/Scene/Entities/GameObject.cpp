#include "GameObject.h"

namespace PurpleLine {namespace GameObjects{

	GameObject::GameObject(String name) :
		name(name)
	{
		transform = new	Transform();
		components.push_back(transform);
	}

	GameObject::~GameObject()
	{
	}
}}
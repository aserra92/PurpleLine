#pragma once
#include "../Utils/String.h"
#include "Entities/GameObject.h"
#include <vector>

namespace PurpleLine {
	using namespace GameObjects;
	class Scene2D
	{
	public:
		Scene2D(String name);
		~Scene2D();

		void AddGameObject(GameObject* entity);
	private:
		String name;
		std::vector<GameObject*> gameObjects;
	};
}
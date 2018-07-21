#pragma once
#include "../Utils/String.h"
#include "Entities/GameObject.h"
#include "../Graphics/SimpleRenderer2D.h"
#include <vector>

namespace PurpleLine {
	using namespace GameObjects;
	class Scene2D
	{
	public:
		Scene2D(String name);
		~Scene2D();

		void AddGameObject(GameObject* entity);
		inline Graphics::SimpleRenderer2D* GetRenderer() const { return renderer; }
	private:
		String name;
		std::vector<GameObject*> gameObjects;
		Graphics::SimpleRenderer2D *renderer;
	};
}
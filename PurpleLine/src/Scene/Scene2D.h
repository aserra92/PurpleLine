#pragma once
#include "../Utils/String.h"
#include "Entities/GameObject.h"
#include "../Graphics/BatchRenderer2D.h"
#include "Layers/Layer.h"
#include <vector>

namespace PurpleLine {
	using namespace GameObjects;
	using namespace Layers;
	class Scene2D
	{
	public:
		Scene2D(String name);
		~Scene2D();

		virtual void Update();
		virtual void Render();

		void AddGameObject(GameObject* entity);
		void AddLayer(Layer* layer);
		inline Graphics::BatchRenderer2D *GetRenderer() const { return renderer; }
	private:
		String name;
		std::vector<GameObject*> gameObjects;
		std::vector<Layer*> layers;
		Graphics::BatchRenderer2D *renderer;
	};
}
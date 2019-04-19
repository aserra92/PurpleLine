#pragma once
#include "../../CommonTypes.h"
#include "../../Maths/maths.h"
#include "../Entities/GameObject.h"

namespace PurpleLine{ namespace Layers {
	using namespace GameObjects;
	class Layer
	{
	protected:
		String name;
		std::vector<GameObject*> listGameObjects;
		Math::Matrix4 projectionMatrix;
		BatchRenderer2D* renderer;
	public:
		Layer(String name, Math::Matrix4 projectionMatrix, BatchRenderer2D* renderer);
		~Layer();

		void AddGameObject(GameObject* gameObject);
		void Draw();
	};

} }
#include "Scene2D.h"

namespace PurpleLine {
	Scene2D::Scene2D(String name) :
		name(name)
	{
	}

	Scene2D::~Scene2D()
	{
	}
	void Scene2D::AddGameObject(GameObject * entity)
	{
		gameObjects.push_back(entity);
	}
}
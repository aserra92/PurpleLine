#include "Scene2D.h"

namespace PurpleLine {
	using namespace Graphics;
	Scene2D::Scene2D(String name) :
		name(name)
	{
		renderer = new SimpleRenderer2D();
	}

	Scene2D::~Scene2D()
	{
	}

	void Scene2D::AddGameObject(GameObject * entity)
	{
		gameObjects.push_back(entity);
	}
}
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

	void Scene2D::Update()
	{
		for (unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update();
		}
	}

	void Scene2D::Render()
	{
		for(unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Render(renderer);
		}
		renderer->Flush();
	}

	void Scene2D::AddGameObject(GameObject * entity)
	{
		gameObjects.push_back(entity);
	}
}
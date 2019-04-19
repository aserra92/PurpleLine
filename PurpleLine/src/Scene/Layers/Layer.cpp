#include "Layer.h"

namespace PurpleLine{ namespace Layers {

	Layer::Layer(String name, Math::Matrix4 projectionMatrix, BatchRenderer2D* renderer) :
		name(name),
		projectionMatrix(projectionMatrix),
		renderer(renderer)
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::AddGameObject(GameObject * gameObject)
	{
		listGameObjects.push_back(gameObject);
	}
}}
#include "SpriteComponent.h"
#include "../GameObject.h"

namespace PurpleLine{namespace GameObjects{

	using namespace Graphics;

	SpriteComponent::SpriteComponent(GameObject* gObject) :
		ComponentBase(gObject)
	{
		//sprite = new StaticSprite(gameObject->GetTransform()->GetPosition(), gameObject->GetTransform()->GetScale(), );
	}

	SpriteComponent::SpriteComponent(GameObject* gObject, Sprite* sprite) :
		ComponentBase(gObject),
		sprite(sprite)
	{
	}

	SpriteComponent::~SpriteComponent()
	{
	}

	void SpriteComponent::Render(BatchRenderer2D* renderer)
	{
		renderer->Submit(sprite);
	}
}}
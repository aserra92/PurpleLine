#pragma once
#include "ComponentBase.h"
#include "../../../Graphics/Renderable/StaticSprite.h"
#include "../../../Graphics/SimpleRenderer2D.h"

namespace PurpleLine{namespace GameObjects{

	class SpriteComponent : public ComponentBase
	{
	public:
		SpriteComponent(GameObject* gObject);
		SpriteComponent(GameObject* gObject, Graphics::StaticSprite* sprite);
		~SpriteComponent();

		void Render(Graphics::SimpleRenderer2D* renderer);

		inline virtual const ComponentType& GetComponentType() const override { return ComponentType::SpriteComponentType; }
	private:
		Graphics::StaticSprite *sprite;
	};
} }
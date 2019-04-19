#pragma once
#include "ComponentBase.h"
#include "../../../Graphics/Renderable/Sprite.h"
#include "../../../Graphics/BatchRenderer2D.h"

namespace PurpleLine{namespace GameObjects{

	class SpriteComponent : public ComponentBase
	{
	public:
		SpriteComponent(GameObject* gObject);
		SpriteComponent(GameObject* gObject, Graphics::Sprite* sprite);
		~SpriteComponent();

		void Render(Graphics::BatchRenderer2D* renderer);

		inline virtual const ComponentType GetComponentType() const override { return ComponentType::SpriteComponentType; }
		inline virtual ComponentBase* Clone(GameObject* gObject) override { return new SpriteComponent(gObject, sprite); }
		inline void SetColor(Math::Vector4 color) { sprite->SetColor(color); }
		Graphics::Sprite* GetSprite() const { return sprite; }
	private:
		Graphics::Sprite *sprite;
	};
} }
#pragma once
#include "Renderer2D.h"
#include "Renderable/StaticSprite.h"
#include <deque>

namespace PurpleLine{namespace Graphics{

	class SimpleRenderer2D : public Renderer2D
	{
	public:
		void Submit(const Renderable2D* renderable) override;
		void Flush() override;
	private:
		std::deque<const StaticSprite*> queueToRender;
	};
}}
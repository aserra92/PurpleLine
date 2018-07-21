#pragma once
#include "Renderable/StaticSprite.h"
#include <deque>

namespace PurpleLine{namespace Graphics{

	class SimpleRenderer2D
	{
	public:
		void Submit(const Renderable2D* renderable);
		void Flush();
	private:
		std::deque<const StaticSprite*> queueToRender;
	};
}}
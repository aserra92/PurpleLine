#pragma once

namespace PurpleLine{namespace Graphics{

	class Renderable2D;
	class Renderer2D
	{
	public:
		Renderer2D()
		{}

		virtual void Submit(const Renderable2D* renderable) = 0;
		virtual void Flush() = 0;
	private:

	};
} }
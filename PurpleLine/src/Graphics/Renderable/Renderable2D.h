#pragma once
#include "../../Maths/maths.h"
#include "../BatchRenderer2D.h"
#include "Transform.h"

namespace PurpleLine{namespace Graphics{

	struct VertexData
	{
		Math::Vector3 vertex;
		unsigned int color;
	};


	class Renderable2D {
	protected:
		Math::Vector3 position;
		Math::Vector3 rotation;
		Math::Vector2 size;		
		unsigned int color;
		Transform *gObjectTransform;

		Renderable2D() 
		{}

	public:
		Renderable2D(Math::Vector3 position, Math::Vector3 rotation, Math::Vector2 size, unsigned int color) :
			position(position),
			rotation(rotation),
			size(size),
			color(color)
		{
		}

		virtual ~Renderable2D()
		{}

		virtual void Submit(BatchRenderer2D * renderer) const
		{
			renderer->Submit(this);
		}

		void SetColor(unsigned int color) 
		{
			this->color = color;
		}

		void SetColor(Math::Vector4 color)
		{
			int r = (int)(color.x * 255.0f);
			int g = (int)(color.y * 255.0f);
			int b = (int)(color.z * 255.0f);
			int a = (int)(color.w * 255.0f);

			this->color = a << 24 | b << 16 | g << 8 | r;
		}

		inline const Math::Vector3& GetPosition() const { return position; }
		inline const Math::Vector3& GetRotation() const { return rotation; }
		inline const Math::Vector2& GetSize() const { return size; }
		inline Transform* GetTransform() const { return gObjectTransform; }
		inline const Math::Vector3& GetParentPosition() const { return gObjectTransform->GetPosition(); }
		void SetTransform(Transform* transform) { gObjectTransform = transform; }
		inline const unsigned int GetColor() const { return color; }
	};

}}
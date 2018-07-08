#include "SimpleRenderer2D.h"
#include "Renderable/Renderable2D.h"

namespace PurpleLine{namespace Graphics{
	
	void SimpleRenderer2D::Submit(const Renderable2D* renderable)
	{
		queueToRender.push_back((const StaticSprite*)renderable);
	}
	void SimpleRenderer2D::Flush()
	{
		while (!queueToRender.empty())
		{
			const StaticSprite* sprite = queueToRender.front();
			sprite->GetVAO()->Bind();
			sprite->GetIBO()->Bind();
			glDrawElements(GL_TRIANGLES, sprite->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, nullptr);
			sprite->GetIBO()->Unbind();
			sprite->GetVAO()->Unbind();
			queueToRender.pop_front();
		}
	}
}}
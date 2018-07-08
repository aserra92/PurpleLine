#include "StaticSprite.h"

namespace PurpleLine{namespace Graphics{

StaticSprite::StaticSprite(Math::Vector4 color, Shader & shader) :
	Renderable2D(0xffff00ff),
	shader(shader)
{
}

StaticSprite::~StaticSprite()
{
}

}}
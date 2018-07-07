#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace PurpleLine{namespace Math{
	inline float ToRadians(float degrees)
	{
		return (float)(degrees * (M_PI / 180.0f));
	}
} }
#pragma once
#include <iostream>
#include "../Utils/String.h"

namespace PurpleLine{namespace Math{

	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(const float& x, const float& y);
		
		static Vector2 Zero();

		Vector2& Add(const Vector2& other);
		Vector2& Subtract(const Vector2& other);
		Vector2& Multiply(const Vector2& other);
		Vector2& Divide(const Vector2& other);

		friend Vector2 operator+(Vector2 left, const Vector2& right);
		friend Vector2 operator-(Vector2 left, const Vector2& right);
		friend Vector2 operator*(Vector2 left, const Vector2& right);
		friend Vector2 operator/(Vector2 left, const Vector2& right);

		bool operator==(const Vector2& other);
		bool operator!=(const Vector2& other);

		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(const Vector2& other);
		Vector2& operator/=(const Vector2& other);


		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
	};
} }
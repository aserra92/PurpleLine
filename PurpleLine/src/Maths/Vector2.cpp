#include "Vector2.h"
namespace PurpleLine{namespace Math{

	Vector2::Vector2() :
		x(0),
		y(0)
	{}

	Vector2::Vector2(const float& x, const float& y) :
		x(x),
		y(y)
	{}

	Vector2& Vector2::Add(const Vector2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2& Vector2::Subtract(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vector2& Vector2::Multiply(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vector2& Vector2::Divide(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}

	Vector2 operator+(Vector2 left, const Vector2& right)
	{
		return left.Add(right);
	}

	Vector2 operator-(Vector2 left, const Vector2& right)
	{
		return left.Subtract(right);
	}

	Vector2 operator*(Vector2 left, const Vector2& right)
	{
		return left.Multiply(right);
	}

	Vector2 operator/(Vector2 left, const Vector2& right)
	{
		return left.Divide(right);
	}

	bool Vector2::operator==(const Vector2& other)
	{
		return x == other.x && y == other.y;
	}

	bool Vector2::operator!=(const Vector2& other)
	{
		return !(*this == other);
	}

	Vector2& Vector2::operator+=(const Vector2& other)
	{
		return Add(other);
	}

	Vector2& Vector2::operator-=(const Vector2& other)
	{
		return Subtract(other);
	}

	Vector2& Vector2::operator*=(const Vector2& other)
	{
		return Multiply(other);
	}

	Vector2& Vector2::operator/=(const Vector2& other)
	{
		return Divide(other);
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2& vec)
	{
		stream << "(" << vec.x << ", " << vec.y << ")";
		return stream;
	}

} }
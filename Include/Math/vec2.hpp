#pragma once
#include "Base.hpp"
#include <cmath>

namespace Comet {

	struct vec2
	{
		f32 x, y;

		// Constructors
		vec2() : x(0), y(0) {}
		vec2(float x, float y) : x(x), y(y) {}
		explicit vec2(float value) : x(value), y(value) {}

		// Constructors with other types
		static const vec2 zero;
		static const vec2 one;
		static const vec2 unit_X;
		static const vec2 unit_Y;

		// Bace operations
		vec2 operator+(const vec2& other) const { return vec2(x + other.x, y + other.y); }
		vec2 operator-(const vec2& other) const { return vec2(x - other.x, y - other.y); }
		vec2 operator*(float scalar) const { return vec2(x * scalar, y * scalar); }
		vec2 operator/(float scalar) const { return vec2(x / scalar, y / scalar); }

		vec2 operator*(f32 other) { return vec2(x * other, y * other); }
		vec2 operator/(f32 other) { return vec2(x / other, y / other); }

		// Assignment operations
		vec2& operator+=(const vec2& other) { x += other.x; y += other.y; return *this; }
		vec2& operator-=(const vec2& other) { x -= other.x; y -= other.y; return *this; }
		vec2& operator*=(float scalar) { x *= scalar; y *= scalar; return *this; }
		vec2& operator/=(float scalar) { x /= scalar; y /= scalar; return *this; }

		// Conparison operations
		bool operator==(const vec2& other) const { return x == other.x && y == other.y; }
		bool operator!=(const vec2& other) const { return !(*this == other); }

		// Math functions
		f32 length() const { return std::sqrt(x * x + y * y); }
		f32 lengthSquared() const { return x * x + y * y; }
		f32 dot(const vec2& other) const { return x * other.x + y * other.y; }
		f32 distance(const vec2& other) const { return (*this - other).length(); }

		vec2 normalized() const
		{
			f32 len = length();
			return len > EPSILON ? *this / len : zero;
		}

		// Practical functions
		bool isZero() const { return lengthSquared() < EPSILON; }
		vec2 min(const vec2& other) const { return vec2(std::fmin(x, other.x), std::fmin(y, other.y)); }
		vec2 max(const vec2& other) const { return vec2(std::fmax(x, other.x), std::fmax(y, other.y)); }
		vec2 clamp(const vec2& minVec, const vec2& maxVec) const
		{
			return vec2(
				std::fmax(minVec.x, std::fmin(x, maxVec.x)),
				std::fmax(minVec.y, std::fmin(y, maxVec.y))
			);
		}
	};

	// Global constants
	inline vec2 operator*(float scalar, const vec2& vec)
	{
		return vec2(vec.x * scalar, vec.y * scalar);
	}

}
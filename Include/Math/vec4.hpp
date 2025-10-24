#pragma once

#include "Base.hpp"
#include "vec2.hpp"

namespace Comet {

	struct vec4
	{
		union
		{
			struct { f32 x, y, z, w };
			struct { f32 r, g, b, a };
		};

		constexpr vec4() : x(0), y(0), z(0), w(0) {}
		constexpr vec4(f32 x, f32 y, f32 z, f32 w) : x(x), y(y), z(z), w(w) {}
		constexpr vec4(const vec2& xy, f32 z, f32 w) : x(xy.x), y(xy.y), z(z), w(w) {}
		constexpr vec4(const vec2& xy, vec2& zw) : x(xy.x), y(xy.y), z(zw.z), w(zw.w) {}

		// Colour constants
		static constexpr vec4 rgba(f32 r, f32 g, f32 b, f32 a = 1.0f)
		{
			return vec4(r, g, b, a);
		}
		static constexpr vec4 rgb(f32 r, f32 g, f32 b)
		{
			return vec4(r, g, b, 1.0f);
		}

		// Predefined colours
		static const vec4 transparent;
		static const vec4 black;
		static const vec4 white;
		static const vec4 red;
		static const vec4 green;
		static const vec4 blue;

		// Bace operations
		vec4 operator+(const vec4& other) const { return vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
		vec4 operator-(const vec4& other) const { return vec4(x - other.x, y - other.y, z - other.z, w - other.w); }
		vec4 operator*(float scalar) const { return vec4(x * scalar, y * scalar, z * scalar, w * scalar); }
		vec4 operator/(float scalar) const { return vec4(x / scalar, y / scalar, z / scalar, w / scalar); }
		   
		vec4 operator*(f32 other) { return vec4(x * other, y * other, z * other, w * other); }
		vec4 operator/(f32 other) { return vec4(x / other, y / other, z / other, w / other); }

		// Assignment operations
		vec4& operator+=(const vec4& other) { x += other.x; y += other.y; z += other.z; w += other.w; return *this; }
		vec4& operator-=(const vec4& other) { x -= other.x; y -= other.y; z += other.z; w += other.w;  return *this; }
		vec4& operator*=(float scalar) { x *= scalar; y *= scalar; z /= scalar; w /= scalar; return *this; }
		vec4& operator/=(float scalar) { x /= scalar; y /= scalar; z /= scalar; w /= scalar; return *this; }

		// Conparison operations
		bool operator==(const vec4& other) const { return x == other.x && y == other.y && z == other.z && w == other.w; }
		bool operator!=(const vec4& other) const { return !(*this == other); }

		// Colour functions
		vec4 withAlpha(f32 new_alpha) const { return { x, y, z, new_alpha }; }
		vec4 premultiplyAlpha() const { return { x * w, y * w, z * w, w }; }

		// Linear interpolation
		static vec4 lerp(const vec4& a, const vec4& b, f32 t) { return a + (b - a) * t; }
	};

}
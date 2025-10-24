#pragma once

#include "Base.hpp"
#include "vec2.hpp"
#include "rect.hpp"

namespace Comet {

	// Interpolation function
	template<typename T>
	T lerp(const T& a, const T& b, f32 t)
	{
		return a + (b - a) * t;
	}

	// Remapping function
	template<typename T>
	T remap(const T& value, const T& inMin, const T& inMax, const T& outMin, const T& outMax)
	{
		return outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
	}

	// Angle conversion
	constexpr f32 deg_to_rad(f32 degrees) { return degrees * PI / 180.0f; }
	constexpr f32 rad_to_deg(f32 radians) { return radians * 180.0f / PI; }

	// Clamp function
	template<typename T>
	constexpr T clamp(T value, T min_val, T max_val)
	{
		return value < min_val ? min_val : (value > max_val ? max_val : value);
	}

	// Sign function
	template<typename T>
	constexpr T sign(T value)
	{
		return static_cast<T>((T(0) < value) - (value < T(0)));
	}

	// 2D distance function
	namespace geometry {

		vec2 closestPointOnSegment(const vec2& point, const vec2& lineStart, const vec2& lineEnd)
		{
			vec2 lineVec = lineEnd - lineStart;
			f32 lineLenSq = lineVec.lengthSquared();
			if (lineLenSq < EPSILON)
			{
				return lineStart; // Line segment is a point
			}
			f32 t = (point - lineStart).dot(lineVec) / lineLenSq;
			t = Comet::clamp(t, 0.0f, 1.0f);
			return lineStart + lineVec * t;
		}

		enum class Alignment
		{
			Left,
			Center,
			Right,
			Top,
			Middle,
			Bottom
		};

		vec2 getAlignedPosition(const Rect& container, const vec2& size, Alignment alignment)
		{
			vec2 position = container.min;
			switch (alignment)
			{
			case Alignment::Left:
				position.x = container.min.x;
				break;
			case Alignment::Center:
				position.x = container.min.x + (container.width() - size.x) * 0.5f;
				break;
			case Alignment::Right:
				position.x = container.max.x - size.x;
				break;
			case Alignment::Top:
				position.y = container.min.y;
				break;
			case Alignment::Middle:
				position.y = container.min.y + (container.height() - size.y) * 0.5f;
				break;
			case Alignment::Bottom:
				position.y = container.max.y - size.y;
				break;
			}
			return position;
		}

	}

}
#pragma once

#include "vec2.hpp"
#include "Base.hpp"

namespace Comet {

	struct Rect 
	{
		vec2 min; // Left-top corner
		vec2 max; // Right-bottom corner

		// Constructors
		constexpr Rect() : min(vec2::zero), max(vec2::zero) {}
		constexpr Rect(const vec2& min, const vec2& max) : min(min), max(max) {}

		// Factory functions
		static Rect fromPositionAndSize(const vec2& position, const vec2& size) 
		{
			return Rect(position, position + size);
		}

		// Properties
		vec2 size() const { return max - min; }
		f32 width() const { return max.x - min.x; }
		f32 height() const { return max.y - min.y; }
		vec2 center() const { return (min + max) * 0.5f; }
		vec2 top_left() const { return min; }
		vec2 bottom_right() const { return max; }
		vec2 top_right() const { return { max.x, min.y }; }
		vec2 bottom_left() const { return { min.x, max.y }; }

		// Check
		bool contains(const vec2& point) const
		{
			return point.x >= min.x && point.x <= max.x &&
				point.y >= min.y && point.y <= max.y;
		}

		bool contains(const Rect& other) const
		{
			return contains(other.min) && contains(other.max);
		}

		bool overlaps(const Rect& other) const
		{
			return !(other.max.x < min.x || other.min.x > max.x || other.max.y < min.y || other.min.y > max.y);
		}

		// Transform
		Rect translate(const vec2& offset) const
		{
			return { min + offset, max + offset };
		}

		Rect scale(const vec2& scale) const
		{
			vec2 center = this->center();
			vec2 new_size = size() * scale;
			return fromPositionAndSize(center, new_size);
		}

		Rect expand(f32 amount) const
		{
			return { min - vec2(amount), max + vec2(amount) };
		}

		Rect intersect(const Rect& other) const
		{
			vec2 new_min = min.max(other.min);
			vec2 new_max = max.min(other.max);
			if (new_min.x < new_max.x && new_min.y < new_max.y)
			{
				return { new_min, new_max };
			}
			return {}; // Empty rectangle
		}

		// Practical functions
		bool isValid() const
		{
			return max.x > min.x && max.y > min.y;
		}
		bool isEmpty() const
		{
			return !isValid();
		}
		bool isZero() const
		{
			return width() < EPSILON && height() < EPSILON;
		}
	};

}
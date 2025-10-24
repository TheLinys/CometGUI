#pragma once
#include <cstdint>
#include <cstdlib>
#include <limits>

#ifndef MATH_BASE_HPP
#define MATH_BASE_HPP

namespace Comet {

	// Base types
	using i8 = std::int8_t;
	using i16 = std::int16_t;
	using i32 = std::int32_t;
	using i64 = std::int64_t;
	using u8 = std::uint8_t;
	using u16 = std::uint16_t;
	using u32 = std::uint32_t;
	using u64 = std::uint64_t;
	using f32 = float;
	using f64 = double;

	// Mathematical limits
	constexpr f32 f32_max = std::numeric_limits<f32>::max();
	constexpr f32 f32_min = std::numeric_limits<f32>::lowest();
	constexpr f64 f64_max = std::numeric_limits<f64>::max();
	constexpr f64 f64_min = std::numeric_limits<f64>::lowest();
	constexpr f32 PI = 3.14159265358979323846f;
	constexpr f32 EPSILON = 1e-6f;

	// Mathematical functions
	constexpr inline bool isEqual(f32 a, f32 b, f32 epsilon = EPSILON)
	{
		return abs(a - b) <= epsilon;
	}

}

#endif

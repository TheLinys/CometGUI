#pragma once

#include "Base.hpp"
#include "vec2.hpp"
#include "Rect.hpp"

namespace Comet {

	class Matrix3
	{
		f32 m_Data[9]; // 3x3 matrix stored in column-major order
	public:
		// Constructors
		Matrix3();
		explicit Matrix3(const f32 m_Data[9]);
		Matrix3(f32 m00, f32 m01, f32 m02,
			f32 m10, f32 m11, f32 m12,
			f32 m20, f32 m21, f32 m22);

		// Special Matrices
		static Matrix3 identity();
		static Matrix3 translation(const vec2& translation);
		static Matrix3 rotation(f32 angle_radians);
		static Matrix3 scale(const vec2& scale);
		static Matrix3 transform(const vec2& translation, f32 rotation, const vec2& scale);

		// Accessor
		f32* data() { return m_Data; }
		const f32* data() const { return m_Data; }

		f32& operator()(size_t row, size_t col) { return m_Data[col * 3 + row]; }
		f32 operator()(size_t row, size_t col) const { return m_Data[col * 3 + row]; }

		// Matrix operations
		Matrix3 operator*(const Matrix3& other) const;
		vec2 operator*(const vec2& vec) const;
		Matrix3& operator*=(const Matrix3& other);

		// Transform operations
		vec2 transform_point(const vec2& point) const;
		vec2 transform_vector(const vec2& vector) const;
		Rect transform_rect(const Rect& rect) const;

		// Inverse matrix
		Matrix3 inverse() const;
		f32 determinant() const;

		// Decompose matrix
		vec2 get_translation() const;
		vec2 get_scale() const;
		f32 get_rotation() const;
	};

}
#pragma once
#include "../Math/vec2.hpp"
#include "../Math/rect.hpp"

namespace Comet {

    enum class LayoutDirection
    {
        Horizontal,
        Vertical
    };

    struct Layout
    {
        LayoutDirection direction;
		Rect bounds;
        vec2 cursor;
        vec2 availableSize;

        Rect allocateRect(const vec2& size)
        {
            Rect result;
			if (direction == LayoutDirection::Horizontal)
            {
                result = Rect::fromPositionAndSize(cursor, size);
                cursor.x += size.x;
            }
            else // Vertical
            {
                result = Rect::fromPositionAndSize(cursor, size);
                cursor.y += size.y;
            }
			return result;
		}
	};

}
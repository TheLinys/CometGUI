#pragma once
#include "../GUI/UIContext.hpp"
#include <Rect.hpp>
#include <vec2.hpp>

namespace Comet {

    inline void label(UIContext& ctx, const char* text)
    {
        vec2 text_size = ctx.calcTextSize(text);
        Rect text_rect = ctx.allocateRect(text_size);
        ctx.drawText(text_rect, ctx.getStyle().text_color, text);
    }

}
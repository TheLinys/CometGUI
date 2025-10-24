#pragma once
#include "../GUI/UIContext.hpp"
#include <Rect.hpp>
#include <cstdint>
#include <vec2.hpp>
#include <vec4.hpp>

namespace Comet {

    inline bool button(UIContext& ctx, const char* label)
    {
        const auto& style = ctx.getStyle();

		// Calculate button size based on text size and padding
        vec2 text_size = ctx.calcTextSize(label);
        vec2 button_size = text_size + style.frame_padding * 2.0f;

        // 分配布局空间
        Rect button_rect = ctx.allocateRect(button_size);

        // 输入检测
        bool hovered = button_rect.contains(ctx.getMousePosition());
        bool clicked = hovered && ctx.isMouseClicked(0);

        // Create ID
        uint32_t id = ctx.getID(label);

		// Update hovered ID
        if (hovered)
        {
            ctx.setHoveredID(id);
        }

        // Style choose
        vec4 bg_color = style.button_bg;
        if (ctx.isActive(id))
        {
            bg_color = style.button_active_bg;
        }
        else if (hovered)
        {
            bg_color = style.button_hover_bg;
        }

        // Draw
        ctx.drawRectFilled(button_rect, bg_color, style.border_radius);

		// Text draw
        vec2 text_pos = button_rect.min + style.frame_padding;
        Rect text_rect(text_pos, text_pos + text_size);
        ctx.drawText(text_rect, style.text_color, label);

        if (clicked)
        {
            ctx.setActiveID(id);
        }

        if (ctx.isActive(id) && ctx.isMouseReleased(0)) 
        {
            ctx.setActiveID(0);
            if (hovered)
            {
                return true;
            }
        }

        return false;
    }

}
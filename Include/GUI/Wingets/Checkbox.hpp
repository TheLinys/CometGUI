#pragma once
#include "../GUI/UIContext.hpp"

namespace Comet {

    inline bool checkbox(UIContext& ctx, const char* label, bool* value)
    {
        const auto& style = ctx.getStyle();

        vec2 text_size = ctx.calcTextSize(label);
        float box_size = text_size.y;
        vec2 total_size = vec2(box_size + style.item_inner_spacing + text_size.x, box_size);

        ctx.begin_layout(LayoutDirection::Horizontal);

        // Checkbox box
        Rect box_rect = ctx.allocateRect(vec2(box_size));
        bool hovered = box_rect.contains(ctx.getMousePosition());
        bool clicked = hovered && ctx.isMouseClicked(0);

        if (clicked)
        {
            *value = !*value;
        }

        // Draw checkbox
        ctx.drawRectFilled(box_rect, style.button_bg, style.border_radius);
        if (*value)
        {
            // 绘制勾选标记
            Rect check_rect = box_rect.expand(-4.0f);
            ctx.draw_rect_filled(check_rect, style.text_color, 2.0f);
        }

        // 标签
        Rect label_rect = ctx.allocateRect(text_size);
        ctx.drawText(label_rect, style.text_color, label);

        ctx.endLayout();

        return clicked;
    }

}
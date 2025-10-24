#pragma once
#include "../Math/rect.hpp"
#include "../Math/vec4.hpp"
#include <string>

namespace Comet {

    class RenderBackend
    {
    public:
        virtual ~RenderBackend() = default;

        virtual bool initialize() = 0;
        virtual void shutdown() = 0;

        // Frame control
        virtual void begin_frame() = 0;
        virtual void end_frame() = 0;

        // Draw commands
        virtual void draw_rect(const Rect& rect, const vec4& color, float rounding = 0.0f) = 0;
        virtual void draw_rect_filled(const Rect& rect, const vec4& color, float rounding = 0.0f) = 0;
        virtual void draw_text(const Rect& rect, const vec4& color, const std::string& text) = 0;

		// Viewport and clipping
        virtual void set_viewport(const Rect& viewport) = 0;
        virtual void set_clip_rect(const Rect& clip_rect) = 0;
    };

}
#pragma once
#include "../math/rect.hpp"
#include "../math/vec4.hpp"
#include <vector>
#include <string>

namespace Comet {

    enum class DrawCommandType
    {
        Rect,
        RectFilled,
        Text,
        Triangle
    };

    struct DrawCommand
    {
        DrawCommandType type;
        Rect bounds;
        vec4 color;
        std::string text; 
        float rounding;
    };

    class DrawList
    {
    public:
        void Clear() { m_commands.clear(); }

        void addRect(const Rect& rect, const vec4& color, float rounding = 0.0f)
        {
            m_commands.push_back({ DrawCommandType::Rect, rect, color, "", rounding });
        }
        void addRectFilled(const Rect& rect, const vec4& color, float rounding = 0.0f)
        {
            m_commands.push_back({ DrawCommandType::RectFilled, rect, color, "", rounding });
		}

        void add_text(const Rect& rect, const vec4& color, const std::string& text)
        {
            m_commands.push_back({ DrawCommandType::Text, rect, color, text, 0.0f });
        }

        const std::vector<DrawCommand>& get_commands() const { return m_commands; }
    private:
        std::vector<DrawCommand> m_commands;
    };

}
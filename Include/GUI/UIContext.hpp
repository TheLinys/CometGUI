#pragma once
#include "../Input/InputState.hpp"
#include "../Math/rect.hpp"
#include "../Math/vec2.hpp"
#include "../Rendering/DrawList.hpp"
#include "Layout.hpp"
#include "style.hpp"
#include <Base.hpp>
#include <vector>

namespace Comet {

	class UIContext
	{
	public:
		void beginFrame();
		void endFrame();

		void pushStyle(const Style& style);
		void popStyle();

		void pushLayout(const Layout& layout);
		void popLayout();

		u32 getID(const char* str);
	private:
		vec2 m_cursor;
		Rect m_clipRect;
		float m_scale;

		std::vector<Style> m_styleStack;

		std::vector<Layout> m_layoutStack;

		InputState m_input;

		DrawList m_drawList;
	};

}
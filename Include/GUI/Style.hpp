#pragma once
#include "../Math/vec4.hpp"
#include "../Math/vec2.hpp"

namespace Comet {

	struct Style
	{
		// Colour
		vec4 window_bg;
		vec4 button_bg;
		vec4 button_hover_bg;
		vec4 button_active_bg;
		vec4 text_color;

		// Size
		vec2 window_padding;
		vec2 frame_padding;
		float item_spacing;
		float item_inner_spacing;

		// Border
		float border_width;
		float border_radius;

		// Font
		float fontSize;

		Style()
		{
			window_bg = vec4::rgba(0.15f, 0.15f, 0.15f, 0.95f);
			button_bg = vec4::rgba(0.3f, 0.3f, 0.3f, 1.0f);
			button_hover_bg = vec4::rgba(0.4f, 0.4f, 0.4f, 1.0f);
			text_color = vec4::rgba(1.0f, 1.0f, 1.0f, 1.0f);

			window_padding = vec2(8, 8);
			frame_padding = vec2(4, 4);
			item_spacing = 8.0f;
			item_inner_spacing = 4.0f;

			border_width = 1.0f;
			border_radius = 4.0f;
			fontSize = 16.0f;
		}
	};

}

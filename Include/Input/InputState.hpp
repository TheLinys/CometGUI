#pragma once
#include "../Math/vec2.hpp"
#include <string.h>

namespace Comet {

	struct InputState
	{
		vec2 mousePosition;
		vec2 mouseDelta;
		bool mouseButton[3];
		bool mouseButtonPrev[3];

		bool isKeyDown(int key) const
		{
			return false;
		}
		bool isKeyPressed(int key) const
		{
			return !isKeyDown(key) && isKeyDown(key);
		}
		bool isKeyReleased(int key) const
		{
			return isKeyDown(key) && !isKeyDown(key);
		}
		
		bool isMouseClick(int button) const
		{
			return mouseButton[button] && !mouseButtonPrev[button];
		}

		void Update()
		{
			memcpy(mouseButtonPrev, mouseButton, sizeof(mouseButton));
		}
	};

}
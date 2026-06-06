#pragma once

#include "core.h"
#include "core/key_codes.h"
#include "core/mouse_codes.h"

namespace Pandora {

	class PANDORA_API Input {
	public:
		static bool IsKeyPressed(const KeyCode keycode);
		static bool IsMouseButtonPressed(const MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}
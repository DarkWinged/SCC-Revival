#pragma once

#include <sdl.h>

namespace SCC_R{
	class KeyState
	{
	public:
		KeyState(SDL_Keycode init_key);
		~KeyState();
		const SDL_Keycode key;
		bool evaluate(SDL_Event event);
		const bool pressed();
	private:
		bool state;
	};
}
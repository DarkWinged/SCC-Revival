#pragma once

#include <sdl.h>

namespace SCC_R{
	class KeyState
	{
	public:
		KeyState(SDL_Keycode init_key);
		~KeyState();
		const SDL_Keycode key;
		//checks if the event is for the same key then updates the state accordingly
		bool evaluate(SDL_Event event);
		//returns the pressed state of the key
		const bool pressed();
		//overides equality operators 
		bool operator==(const SDL_Event &other);
		bool operator!=(const SDL_Event &other);
	private:
		//state is true if key is pressed false if released 
		bool state;
	};
}
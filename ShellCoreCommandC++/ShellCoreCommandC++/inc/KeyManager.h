#pragma once

#include <KeyState.h>
#include <sdl.h>
#include <vector>
#include <memory>

namespace SCC_R {
	class KeyManager
	{
	public:
		//initalizes keylist
		KeyManager();
		~KeyManager();
		//list of special keys that need to be added manually
		const enum ID { ESC, TAB, CAPSS_LOCK, SHIFT, CTRL, ALT, SPACE_BAR, UP, DOWN, LEFT, RIGHT };
		//a vector of shared_ptrs that hold the key states
		std::vector<std::shared_ptr<KeyState>> keys;
		//searchs through key list until the correct key is found or the end of the list is reached
		//if correct key is found it's state is updated
		bool evaluate(SDL_Event event);
		//gets the state of the key
		bool getState(char keyID);
		//overload for numeral keys 0-9
		bool getState(int keyID);
		//overload for special keys like the up, down, left, and right arrow keys
		bool getState(ID keyID);
	};
}
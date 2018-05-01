#pragma once

#include <KeyState.h>
#include <sdl.h>
#include <vector>
#include <memory>

namespace SCC_R {
	class KeyManager
	{
	public:
		KeyManager();
		~KeyManager();
		const enum ID { UP, DOWN, LEFT, RIGHT };
		//an array of shared_ptrs that hold the address to keystates
		std::vector<std::shared_ptr<KeyState>> keys;
		//passes event to the correct key
		bool evaluate(SDL_Event event);
		//gets the state of the key
		bool getState(char keyID);
		//overload for numeral keys 0-9
		bool getState(int keyID);
		//overload for special key like up, down, left, right arrow keys
		bool getState(ID keyID);
	};
}
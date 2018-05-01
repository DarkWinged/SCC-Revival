#pragma once

#include <KeyState.h>
#include <sdl.h>
#include <vector>
#include <string>

namespace SCC_R {
	class KeyManager
	{
	public:
		KeyManager();
		~KeyManager();
		std::vector<KeyState> keys;
		//passes event to the correct key
		bool evaluate(SDL_Event event);
		//gets the state of the key
		bool getState(char keyID);
		//overload for special key like up, down, left, right arrow keys
		bool getState(std::string keyID);
	};
}
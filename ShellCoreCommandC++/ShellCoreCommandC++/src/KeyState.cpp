#include <KeyState.h>

namespace SCC_R{

	KeyState::KeyState(SDL_Keycode init_key):key(init_key)
{
}


	KeyState::~KeyState()
{
}

bool KeyState::evaluate(SDL_Event event)
{
	if (event.key.state == SDL_PRESSED)
		state = true;
	else
		state = false;
	return state;
}

const bool KeyState::pressed()
{
	return state;
}

}
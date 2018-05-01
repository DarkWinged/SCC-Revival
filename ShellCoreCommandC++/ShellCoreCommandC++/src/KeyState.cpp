#include <KeyState.h>

namespace SCC_R{

	KeyState::KeyState(SDL_Keycode init_key):key(init_key)
{
	state = false;
}


	KeyState::~KeyState()
{
}

bool KeyState::evaluate(SDL_Event event)
{
	if (this->operator==(event)) {
		if (event.key.state == SDL_PRESSED) {
			state = true;
			return true;
		}
		else {
			state = false;
			return true;
		}
	}
	else
		return false;
}

const bool KeyState::pressed()
{
	return state;
}

bool KeyState::operator==(const SDL_Event &other)
{
	if (key == other.key.keysym.sym) {
		return true;
	}
	else {
		return false;
	}
}

bool KeyState::operator!=(const SDL_Event &other)
{
	if (key == other.key.keysym.sym)
		return false;
	else
		return true;
}

}
#include <KeyManager.h>

namespace SCC_R {

	KeyManager::KeyManager()
	{
		//allows std to be used for the rest of the scope
		using namespace std;

		//shared_ptr is a pointer wrapper class that helps with object clean up http://en.cppreference.com/w/cpp/memory/shared_ptr
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_0)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_1)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_2)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_3)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_4)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_5)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_6)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_7)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_8)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_9)));
		
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_a)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_b)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_c)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_d)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_e)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_f)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_g)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_h)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_i)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_j)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_k)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_l)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_m)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_n)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_o)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_p)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_q)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_r)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_s)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_t)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_u)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_v)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_w)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_x)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_y)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_z)));

		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_UP)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_DOWN)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_LEFT)));
		keys.push_back(shared_ptr<KeyState>(new KeyState(SDLK_RIGHT)));
	}


	KeyManager::~KeyManager()
	{
		//calls vector destructor
		keys.~vector();
	}

	bool KeyManager::evaluate(SDL_Event event)
	{
		bool result = false;
		unsigned int index = 0;
		
		do {
			index++;
			result = keys[index]->evaluate(event);
		} while (index < keys.size() && !result);

		return result;
	}
	bool KeyManager::getState(char keyID)
	{
		bool result = false;

		result = keys[keyID - 87]->pressed();
		
		return result;
	}
	bool KeyManager::getState(int keyID)
	{
		bool result = false;

		result = keys[keyID]->pressed();

		return result;
	}
	bool KeyManager::getState(ID keyID)
	{
		bool result = false;

		switch (keyID)
		{
		case UP:
			result = keys[keys.size() - 4]->pressed();
			break;
		case DOWN:
			result = keys[keys.size() - 3]->pressed();
			break;
		case LEFT:
			result = keys[keys.size() - 2]->pressed();
			break;
		case RIGHT:
			result = keys[keys.size() - 1]->pressed();
			break;
		default:
			result = false;
		}

		return result;
	}
}

#include <KeyManager.h>

namespace SCC_R {

	KeyManager::KeyManager()
	{
		SCC_R::KeyState zero(SDLK_0);
		keys.push_back(zero);
		SCC_R::KeyState one(SDLK_1);
		keys.push_back(one);
		SCC_R::KeyState two(SDLK_2);
		keys.push_back(two);
		SCC_R::KeyState three(SDLK_3);
		keys.push_back(three);
		SCC_R::KeyState four(SDLK_4);
		keys.push_back(four);
		SCC_R::KeyState five(SDLK_5);
		keys.push_back(five);
		SCC_R::KeyState six(SDLK_6);
		keys.push_back(six);
		SCC_R::KeyState seven(SDLK_7);
		keys.push_back(seven);
		SCC_R::KeyState eight(SDLK_8);
		keys.push_back(eight);
		SCC_R::KeyState nine(SDLK_9);
		keys.push_back(nine);
		SCC_R::KeyState a(SDLK_a);
		keys.push_back(a);
		SCC_R::KeyState b(SDLK_b);
		keys.push_back(b);
		SCC_R::KeyState c(SDLK_c);
		keys.push_back(c);
		SCC_R::KeyState d(SDLK_d);
		keys.push_back(d);
		SCC_R::KeyState e(SDLK_e);
		keys.push_back(e);
		SCC_R::KeyState f(SDLK_f);
		keys.push_back(f);
		SCC_R::KeyState g(SDLK_g);
		keys.push_back(g);
		SCC_R::KeyState h(SDLK_h);
		keys.push_back(h);
		SCC_R::KeyState j(SDLK_j);
		keys.push_back(j);
		SCC_R::KeyState l(SDLK_l);
		keys.push_back(l);
		SCC_R::KeyState m(SDLK_m);
		keys.push_back(m);
		SCC_R::KeyState n(SDLK_n);
		keys.push_back(n);
		SCC_R::KeyState o(SDLK_o);
		keys.push_back(o);
		SCC_R::KeyState p(SDLK_p);
		keys.push_back(p);
		SCC_R::KeyState q(SDLK_q);
		keys.push_back(q);
		SCC_R::KeyState r(SDLK_r);
		keys.push_back(r);
		SCC_R::KeyState s(SDLK_s);
		keys.push_back(h);
		SCC_R::KeyState t(SDLK_t);
		keys.push_back(t);
		SCC_R::KeyState u(SDLK_u);
		keys.push_back(u);
		SCC_R::KeyState v(SDLK_v);
		keys.push_back(v);
		SCC_R::KeyState w(SDLK_w);
		keys.push_back(w);
		SCC_R::KeyState x(SDLK_x);
		keys.push_back(x);
		SCC_R::KeyState y(SDLK_y);
		keys.push_back(y);
		SCC_R::KeyState z(SDLK_z);
		keys.push_back(z);
		SCC_R::KeyState up(SDLK_UP);
		keys.push_back(up);
		SCC_R::KeyState down(SDLK_DOWN);
		keys.push_back(down);
		SCC_R::KeyState left(SDLK_LEFT);
		keys.push_back(left);
		SCC_R::KeyState right(SDLK_RIGHT);
		keys.push_back(right);
	}


	KeyManager::~KeyManager()
	{
		for (int i = keys.size; i > 0; i--)
			delete &keys[i];
	}

	bool KeyManager::evaluate(SDL_Event event)
	{
		return false;
	}
	bool KeyManager::getState(char keyID)
	{
		return false;
	}
	bool KeyManager::getState(int keyID)
	{
		bool result = false;
		result = keys[keyID].pressed();
		return result;
	}
	bool KeyManager::getState(std::string keyID)
	{
		return false;
	}
}
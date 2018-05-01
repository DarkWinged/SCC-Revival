#pragma once

#define Game_hpp

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <KeyManager.h>

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };

//private:
	//int cnt;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SCC_R::KeyManager key_manager;
};
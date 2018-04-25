#pragma once

#include "Game.h"
#include "Image.h"

class GameObject {

public:
	GameObject(const char *textureSheet, SDL_Renderer *ren, int xpos, int ypos);
	~GameObject();

	void Update();
	void Render();
	
//private: why not public?

	int xPos;
	int yPos;
	int xVel;
	int yVel;
	int rotation;

	Image *tex;
	SDL_Rect srcRect, destRect;

	int destinyRot;

};
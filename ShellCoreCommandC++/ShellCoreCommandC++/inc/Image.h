#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Image {

public:
	Image(const char *textureSheet);
	Image(const char *textureSheet, SDL_Renderer *ren);
	~Image();

	SDL_Renderer *renderer;
	SDL_Texture *image;

	int xSize;
	int ySize;
};
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace SCC_R{
	class Image {

	public:
		Image();
		Image(const char *textureSheet, SDL_Renderer *ren);
		//loads image asset into memory
		bool setImage(std::string textureSheet, SDL_Renderer * ren);
		~Image();

		SDL_Renderer *renderer;
		SDL_Texture *image;

		int xSize;
		int ySize;
	};
}
#include <Image.h>
//#include "Game.h"
//Game game;
namespace SCC_R {
	/*Image::Image(const char *textureSheet)
	{
		SDL_Surface *tempSurface = IMG_Load(textureSheet);

		xSize = tempSurface->w;
		ySize = tempSurface->h;

		SDL_Texture *tex = SDL_CreateTextureFromSurface(game.renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		image = tex;
	}*/

	Image::Image()
	{
	}

	Image::Image(const char *textureSheet, SDL_Renderer *ren)
	{
		renderer = ren;

		SDL_Surface* tempSurface = IMG_Load(textureSheet);

		xSize = tempSurface->w;
		ySize = tempSurface->h;

		SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
		SDL_FreeSurface(tempSurface);

		image = tex;
	}

	bool Image::setImage(std::string textureSheet, SDL_Renderer *ren)
	{
		renderer = ren;

		SDL_Surface* tempSurface = IMG_Load(textureSheet.c_str());
		//checks if image exists
		if (tempSurface == NULL) {
			printf("Unable to load image %s! SDL_image Error: %s\n", textureSheet.c_str(), IMG_GetError());
			return false;
		}
		else {
			xSize = tempSurface->w;
			ySize = tempSurface->h;

			SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
			SDL_FreeSurface(tempSurface);

			image = tex;
			return true;
		}
	}
	Image::~Image()
	{
	}
}
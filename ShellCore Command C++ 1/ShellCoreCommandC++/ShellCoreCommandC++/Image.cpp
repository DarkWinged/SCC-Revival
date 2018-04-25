#include "Image.h"
//#include "Game.h"
//Game game;

/*Image::Image(const char *textureSheet)
{
	SDL_Surface *tempSurface = IMG_Load(textureSheet);

	xSize = tempSurface->w;
	ySize = tempSurface->h;

	SDL_Texture *tex = SDL_CreateTextureFromSurface(game.renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	image = tex;
}*/

Image::Image(const char *textureSheet, SDL_Renderer *ren)
{
	renderer = ren;

	SDL_Surface *tempSurface = IMG_Load(textureSheet);

	xSize = tempSurface->w;
	ySize = tempSurface->h;

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	image = tex;
}
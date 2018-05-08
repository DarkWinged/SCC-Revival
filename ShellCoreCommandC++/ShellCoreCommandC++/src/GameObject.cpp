#include <GameObject.h>

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren, int xpos, int ypos)
{
	destinyRot = 0;
	rotation = 0;

	xPos = xpos;
	yPos = ypos;

	xVel = 0;
	yVel = 0;

	/*SDL_Surface *tempSurface = IMG_Load(textureSheet);

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);
	
	//it's better to do this... (since you know the width and height of a picture)
	objTexture = tex;*/

	tex = new SCC_R::Image(textureSheet, ren);
	srcRect.w = tex->xSize;
	srcRect.h = tex->ySize;

	//objTexture = TextureManager::LoadTexture(textureSheet, ren);
}

void GameObject::Update()
{
	xPos += xVel;
	yPos += yVel;

	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::Render()
{
	SDL_RenderCopyEx(tex->renderer, tex->image, NULL, &destRect, rotation, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
}
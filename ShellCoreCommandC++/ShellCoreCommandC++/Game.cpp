#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

#include "Ship.h"

Game::Game()
{}
Game::~Game()
{}

/*class Image2D {

public:

	Image2D(SDL_Surface *surf, SDL_Renderer *renderer)
	{
		 SDL_Texture *tempTex = SDL_CreateTextureFromSurface(renderer, surf);
		 //rectSize = new SDL_Rect();

		 rectSize.w = surf->w;
		 rectSize.h = surf->h;

		 SDL_FreeSurface(surf);
	};

	SDL_Rect srcR, rectSize;
	SDL_Texture *texture;

};*/

//Image2D *coreTex;
//SDL_Texture *coreTex;
//SDL_Rect srcR, destR;


// The ID 0 would be the player's shellcore
//GameObject *coreTex;

Ship *playerShip;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//cnt = 0;

	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("Subsystems initialized!! :) \n");

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window)
		{
			printf("Window successfully created!! :D \n");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			printf("Renderer successfully created!! 8D \n");
		}

		isRunning = true;
	} 
	else 
	{
		isRunning = false;
	}

	//SDL_Surface *tmpSurface = IMG_Load("assets/images/SmallCore1.png");
	//destR.w = tmpSurface->w;
	//destR.h = tmpSurface->h;

	//coreTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	//SDL_FreeSurface(tmpSurface);

	//coreTex = new GameObject("assets/images/SmallCore1.png", renderer, 100, 50);
	playerShip = new Ship(renderer);
}

void Game::handleEvents()
{
	SDL_Event sdlevent;
	SDL_PollEvent(&sdlevent);
	switch( sdlevent.type ){
            /* Look for a keypress */
		case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
            switch(sdlevent.key.keysym.sym)
			{
				case SDLK_LEFT:
					playerShip->xVel = -1;
					playerShip->xTarPos = -1;
					break;
				case SDLK_RIGHT:
					playerShip->xVel = 1;
					playerShip->xTarPos = 1;
					break;
				case SDLK_UP:
					playerShip->yVel = -1;
					playerShip->yTarPos = -1;
					break;
				case SDLK_DOWN:
					playerShip->yVel = 1;
					playerShip->yTarPos = 1;
					break;
				default:
					break;
            }
			break;
        case SDL_KEYUP:
			switch(sdlevent.key.keysym.sym)
			{
				case SDLK_LEFT:
					playerShip->xVel = 0;
					playerShip->xTarPos = 0;
					break;
				case SDLK_RIGHT:
					playerShip->xVel = 0;
					playerShip->xTarPos = 0;
					break;
				case SDLK_UP:
					playerShip->yVel = 0;
					playerShip->yTarPos = 0;
					break;
				case SDLK_DOWN:
					playerShip->yVel = 0;
					playerShip->yTarPos = 0;
					break;
				default:
					break;
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

int rot = 0;
void Game::update()
{
	//cnt++;

	//destR.x++;
	//destR.y++;

	//coreTex->rotation++;
	//coreTex->Update();
	playerShip->Update();

	//printf("%d\n", cnt);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	//SDL_RenderCopyEx(renderer, coreTex->objTexture, NULL, &coreTex->destRect, coreTex->rotation, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
	//coreTex->Render();
	playerShip->Render();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	printf("Game: *roblox death sound* \n");
	printf("Oof Man! \n");
}
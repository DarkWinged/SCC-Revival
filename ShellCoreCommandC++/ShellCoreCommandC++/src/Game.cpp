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

// Key input
int movingHorizontally = 0;
int movingVertically = 0;

bool pressingW = false;
bool pressingA = false;
bool pressingS = false;
bool pressingD = false;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//cnt = 0;
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("Subsystems initialized!! :) \n");

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			printf("Window successfully created!! :D \n");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			printf("Renderer successfully created!! >:D \n");
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

	//key_manager usage example
	if (sdlevent.type == SDL_KEYUP || sdlevent.type == SDL_KEYDOWN){
		key_manager.evaluate(sdlevent);
		if (key_manager.getState('a'))
			std::cout << "a key pressed\n";
		else
			std::cout << "a key not pressed\n";
	}

	switch (sdlevent.type) {
		/* Look for a keypress */
	case SDL_KEYDOWN:
		/* Check the SDLKey values and move change the coords */
		switch (sdlevent.key.keysym.sym)
		{
		case SDLK_LEFT:
			//playerShip->xVel = -1;
			//playerShip->xVel--;
			//playerShip->xTarPos = -1;

			movingHorizontally = -1;
			pressingA = true;
			break;
		case SDLK_RIGHT:
			//playerShip->xVel = 1;
			//playerShip->xVel++;
			//playerShip->xTarPos = 1;

			movingHorizontally = 1;
			pressingD = true;
			break;
		case SDLK_UP:
			//playerShip->yVel = -1;
			//playerShip->yVel--;
			//playerShip->yTarPos = -1;

			movingVertically = -1;
			pressingW = true;
			break;
		case SDLK_DOWN:
			//playerShip->yVel = 1;
			//playerShip->yVel++;
			//playerShip->yTarPos = 1;

			movingVertically = 1;
			pressingS = true;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (sdlevent.key.keysym.sym)
		{
		case SDLK_LEFT:
			pressingA = false;
			//playerShip->xVel = 0;
			//playerShip->xTarPos = 0;

			if (pressingA == false && pressingD == false) movingHorizontally = 0;
			break;
		case SDLK_RIGHT:
			pressingD = false;
			//playerShip->xVel = 0;
			//playerShip->xTarPos = 0;

			if (pressingA == false && pressingD == false) movingHorizontally = 0;
			break;
		case SDLK_UP:
			pressingW = false;
			//playerShip->yVel = 0;
			//playerShip->yTarPos = 0;

			if (pressingW == false && pressingS == false) movingVertically = 0;
			break;
		case SDLK_DOWN:
			pressingS = false;
			//playerShip->yVel = 0;
			//playerShip->yTarPos = 0;

			if (pressingW == false && pressingS == false) movingVertically = 0;
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

void Game::update()
{
	if (movingVertically != 0)
	{
		if ((playerShip->yVel < playerShip->Speed * movingVertically)
			| (playerShip->yVel > playerShip->Speed * movingVertically)) // If we're still below the ship's Speed, 
		{
			// Increase the ship's velocity by the acceleration.
			playerShip->yVel += movingVertically * playerShip->Acceleration;

			// If the velocity goes through the ship's Speed after we've increased the velocity by acceleration
			if (SDL_abs(playerShip->yVel) > playerShip->Speed)
			{
				// then divide the actual velocity by the ship's Speed
				playerShip->yVel /= (SDL_abs(playerShip->yVel) / playerShip->Speed);
			}
		}
		playerShip->yTarPos = movingVertically;
	}
	else
	{
		// If we're not moving vertically, apply friction (friction is also acceleration too?)

		// If the velocity is smaller than the friction, set velocity to zero.
		if (SDL_abs(playerShip->yVel) < playerShip->Acceleration)
		{
			playerShip->yVel = 0;
		}

		if (playerShip->yVel > 0) { playerShip->yVel -= playerShip->Acceleration; }
		if (playerShip->yVel < 0) { playerShip->yVel += playerShip->Acceleration; }

		playerShip->yTarPos = 0; // also set this to 0
	}

	if (movingHorizontally != 0)
	{
		if ((playerShip->xVel < playerShip->Speed * movingHorizontally)
			| (playerShip->xVel > playerShip->Speed * movingHorizontally)) // If we're still below the ship's Speed, 
		{
			// Increase the ship's velocity by the acceleration.
			playerShip->xVel += movingHorizontally * playerShip->Acceleration;

			// If the velocity goes through the ship's Speed after we've increased the velocity by acceleration
			if (SDL_abs(playerShip->xVel) > playerShip->Speed)
			{
				// then divide the actual velocity by the ship's Speed
				playerShip->xVel /= (SDL_abs(playerShip->xVel) / playerShip->Speed);
			}
		}
		playerShip->xTarPos = movingHorizontally;
	}
	else
	{
		// If we're not moving horizontally, apply friction (friction is also acceleration too?)

		// If the velocity is smaller than the friction, set velocity to zero.
		if (SDL_abs(playerShip->xVel) < playerShip->Acceleration)
		{
			playerShip->xVel = 0;
		}

		if (playerShip->xVel > 0) { playerShip->xVel -= playerShip->Acceleration; }
		if (playerShip->xVel < 0) { playerShip->xVel += playerShip->Acceleration; }

		playerShip->xTarPos = 0; // also set this to 0
	}

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
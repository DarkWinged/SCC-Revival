#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

#include "Ship.h"

Game::Game()
{}
Game::~Game()
{}

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
	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	asset_manager.initalize(renderer,"assets/images/");
	playerShip = new Ship(renderer);
}

void Game::handleEvents()
{
	SDL_Event sdlevent;
	SDL_PollEvent(&sdlevent);

	if (sdlevent.type == SDL_QUIT) isRunning = false;

	//key_manager usage example
	if (sdlevent.type == SDL_KEYUP || sdlevent.type == SDL_KEYDOWN){
		key_manager.evaluate(sdlevent);
		//if (key_manager.getState('a'))
		//	std::cout << "a key pressed\n";
		//else
		//	std::cout << "a key not pressed\n";
	}

	movingHorizontally = 0;
	movingVertically = 0;
	
	if (key_manager.getState('a') || key_manager.getState(key_manager.LEFT)) movingHorizontally--;
	if (key_manager.getState('d') || key_manager.getState(key_manager.RIGHT)) movingHorizontally++;
	if (key_manager.getState('w') || key_manager.getState(key_manager.UP)) movingVertically--;
	if (key_manager.getState('s') || key_manager.getState(key_manager.DOWN)) movingVertically++;
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
	
	playerShip->Update();
	//printf("%d\n", cnt); i'll leave this here
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
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
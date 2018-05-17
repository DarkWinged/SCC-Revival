#include <SDL.h>
#include <Game.h>

//Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	int FPSTime = 0;
	int FPSTimeStart = 0;
	int actualFPS = 0;

	Uint32 frameStart;
	int frameTime;

	Game *game = new Game();
	// gotta init it first...
	game->init("Cool Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		
		// Measure FPS
		actualFPS++;
		FPSTime = SDL_GetTicks() - FPSTimeStart;
		if (FPSTime > 1000)
		{
			FPSTimeStart = SDL_GetTicks();
			printf("FPS: %d\n", actualFPS);
			actualFPS = 0;
		}
		//
	}

	game->clean();

	return 0;
}
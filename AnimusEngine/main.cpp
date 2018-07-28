#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	game = new Game();
	game->Init("AnimusEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 854, 480, false);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	while (game->Running()) {

		frameStart = SDL_GetTicks();

		game->EventManager();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Clean();

	return 0;
}
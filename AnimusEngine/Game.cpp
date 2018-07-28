#include "Game.h"

SDL_Texture *playerTexture;
SDL_Rect srcRect, destRect;

Game::Game()
{}


Game::~Game()
{}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "subsystem initialized" << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) {
			std::cout << "window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			std::cout << "renderer created!" << std::endl;
		}
		isRunning = true;
	
	}

	SDL_Surface *tmpSurface = IMG_Load("Assets/player.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Game::EventManager()
{
	SDL_Event event;
	SDL_PollEvent(&event); 
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update()
{
	cnt++;
	destRect.h = 32;
	destRect.w = 32;
	destRect.x = cnt;
	std::cout << cnt << std::endl;
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, &destRect);
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}


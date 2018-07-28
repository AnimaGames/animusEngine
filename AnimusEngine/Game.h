#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

	void EventManager();
	
	void Update();

	void Render();

	void Clean();

	bool Running() { return isRunning; }
private:
	int cnt;
	
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};


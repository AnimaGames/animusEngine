#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renPtr)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* newTex = SDL_CreateTextureFromSurface(renPtr, tempSurface);
	SDL_FreeSurface(tempSurface);

	return newTex;
}
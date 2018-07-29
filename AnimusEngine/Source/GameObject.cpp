#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);
	xPos = x;
	yPos = y;

}

void GameObject::Update()
{
	xPos++;
	yPos++;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 32;
	srcRect.w = 32;

	destRect.x = xPos;
	destRect.y = yPos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

GameObject::~GameObject()
{
}

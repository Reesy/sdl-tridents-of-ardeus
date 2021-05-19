#pragma once
#include <SDL.h>
#include <Component.hpp>

class GameEntity;

class Graphics: public Component
{
protected:
	SDL_Texture* texture = nullptr;
public:
	SDL_Rect positionRect = {0, 0, 0, 0};
	SDL_Rect textureRect = {0, 0, 0, 0};
	Graphics();
	Graphics(SDL_Texture* _texture);
	virtual ~Graphics();
	virtual void render(GameEntity& _gameEntity, SDL_Renderer* _renderer) = 0;
	void receive(int message);
};
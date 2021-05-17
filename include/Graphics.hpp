#pragma once
#include <SDL.h>
#include <Component.hpp>

class GameEntity;

class Graphics: public Component
{
protected:
	SDL_Texture* texture = nullptr;
public:
	Graphics();
	Graphics(SDL_Texture* _texture);
	virtual ~Graphics();
	virtual void render(GameEntity& _gameEntity, SDL_Renderer* _renderer) = 0;
	void receive(int message);
};
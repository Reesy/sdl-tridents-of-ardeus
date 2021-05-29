#pragma once
#include <SDL.h>
#include <interfaces/ComponentInterface.hpp>

class GameEntity;

class GraphicsInterface: public ComponentInterface
{
protected:
	SDL_Texture* texture = nullptr;
public:
	SDL_Rect positionRect = {0, 0, 0, 0};
	SDL_Rect textureRect = {0, 0, 0, 0};
	GraphicsInterface();
	GraphicsInterface(SDL_Texture* _texture);
	virtual ~GraphicsInterface();
	virtual void render(GameEntity& _gameEntity, SDL_Renderer* _renderer) = 0;
	void receive(int message);
};
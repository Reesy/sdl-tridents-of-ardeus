
#include <Graphics.hpp>
#pragma once

class GameEntity
{
	int x;
	int y;

public:
	GameEntity();
	GameEntity(Graphics _graphicsComponent);
	~GameEntity();
};
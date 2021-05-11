#pragma once
#include <Component.hpp>
#include <Graphics.hpp>

class GameEntity
{
	int x;
	int y;
	Component* components[10];
public:
	GameEntity();
	GameEntity(Graphics _graphicsComponent);
	~GameEntity();
	void send(int message);
};
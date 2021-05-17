#pragma once
#include <Components.hpp>

class GameEntity
{
public:
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	Components* components = NULL;
	GameEntity(Components* _components);
	GameEntity(Components* _components, int _x, int _y);
	GameEntity(Components* _components, int _x, int _y, int _w, int _h);
	~GameEntity();
	void send(int message);
};
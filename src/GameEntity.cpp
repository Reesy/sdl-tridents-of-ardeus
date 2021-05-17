#include <iostream>
#include <GameEntity.hpp>

GameEntity::GameEntity(Components* _components)
{	
	this->components = _components;
};

GameEntity::GameEntity(Components* _components, int _x, int _y)
{	
	this->components = _components;
	this->x = _x;
	this->y = _y;
};

GameEntity::GameEntity(Components* _components, int _x, int _y, int _w, int _h)
{	
	this->components = _components;
	this->x = _x;
	this->y = _y;
	this->w = _w;
	this->h = _h;
};

GameEntity::~GameEntity()
{
	std::cout << "Game Entity destroyed" << std::endl;
};

void GameEntity::send(int _message)
{	

	if (this->components->AIComponent != nullptr)
	{
		this->components->AIComponent->receive(_message);
	}

	
	if (this->components->ColliderComponent != nullptr)
	{
		this->components->ColliderComponent->receive(_message);
	}

	
	if (this->components->GraphicsComponent != nullptr)
	{
		this->components->GraphicsComponent->receive(_message);
	}

	return;
}
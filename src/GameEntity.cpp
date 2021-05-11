#include <GameEntity.hpp>
#include <iostream>


GameEntity::GameEntity()
{
	x = 0;
	y = 0;
}

GameEntity::GameEntity(Graphics _graphicsComponent)
{	
	this->components[0] = &_graphicsComponent;
	x = 0;
	y = 0;
	std::cout << "Game Entity created" << std::endl;
};

GameEntity::~GameEntity()
{
	std::cout << "Game Entity destroyed" << std::endl;
};

void GameEntity::send(int _message)
{
	for (int i = 0; i < sizeof(this->components); i++)
	{
		this->components[0]->receive(_message);
	}
	return;
}
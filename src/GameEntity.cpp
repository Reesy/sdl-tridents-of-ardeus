#include <GameEntity.hpp>
#include <iostream>


GameEntity::GameEntity()
{
	x = 0;
	y = 0;
	std::cout << "Game Entity created" << std::endl;
};

GameEntity::~GameEntity()
{
	std::cout << "Game Entity destroyed" << std::endl;
};